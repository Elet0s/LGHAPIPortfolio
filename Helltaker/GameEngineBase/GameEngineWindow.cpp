#include"GameEngineWindow.h"
#include"GameEngineDebug.h"

LRESULT CALLBACK MessageProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) //wcex.lpfnWndProc 이 부분 채워 주기 위한 값임 (메세지 처리를 위한 콜백함수 포인터)
{
    switch (message)
    {
    case WM_DESTROY:
    {
        // 윈도우를 종료하고 모든 
        GameEngineWindow::GetInst().Off();
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        EndPaint(hWnd, &ps);
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    default:
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

GameEngineWindow* GameEngineWindow::Inst_ = new GameEngineWindow();//동적할당

GameEngineWindow::GameEngineWindow()
    :hInst_(nullptr)
    ,hWnd_(nullptr)
    ,WindowOn_(true)
    ,HDC_(nullptr)
{

}

GameEngineWindow::~GameEngineWindow()
{
     // 내가 만들어준게 아니라면 다 지워줘야 합니다.
    if (nullptr != HDC_)
    {
        ReleaseDC(hWnd_, HDC_);
        HDC_ = nullptr;
    }

    if (nullptr != hWnd_)
    {
        DestroyWindow(hWnd_);
        hWnd_ = nullptr;
    }
}

void GameEngineWindow::Off()
{
    WindowOn_ = false;
}

void GameEngineWindow::RegClass(HINSTANCE _hInst)
{
    // 윈도우 클래스 등록
    WNDCLASSEXA wcex; // typedef로 생략된 구조체 변수, Window는 c에서 돌아야 하기 때문에 구조체로 설계되어 있다.
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = MessageProcess; //함수포인터 넣어줘야함
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = _hInst;//인스턴스 값, 우리는 인스턴스 값을 외부에서 받아와야하니까 인자값으로 받는형태로 만들어준다. //핸들
    wcex.hIcon = nullptr;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2); //백그라운드 컬러
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "GameEngineWindowClass"; //L"text" 형태는 유니코드 방식  
    wcex.hIconSm = nullptr;
    RegisterClassExA(&wcex); //return할 필요 없음
}

void GameEngineWindow::CreateGameWindow(HINSTANCE _hInst, const std::string& _Title)
{
    if (nullptr != hInst_) // 클래스 등록은 한번만 2번 만들면 터진다
    {
        MsgBoxAssert("윈도우 중복 호출");
        return;
    }

    Title_ = _Title;

    hInst_ = _hInst;
    RegClass(_hInst);

    
    //이밑부분부터 윈도우 띄워주는 부분
    hWnd_ = CreateWindowExA(0L, "GameEngineWindowClass", Title_.c_str(), WS_OVERLAPPEDWINDOW,//매개변수로CreateWindowExA호출 클래스명 ,윈도우 창 제목, ws 는 윈도우창 오른쪽 옵션
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, _hInst, nullptr);//0들어간건 x,y위치, cw는 크기, _hInst(윈도우에서 필요한 프로그램 번호) 나머지는 알필요없음

    HDC_ = GetDC(hWnd_);
    
    if (!hWnd_)
    {
        return;
    }
}
void GameEngineWindow::ShowGameWindow()
{
    if (nullptr == hWnd_)
    {
        MsgBoxAssert("윈도우가 존재하지 않습니다.");
        return;
    }
    ShowWindow(hWnd_, SW_SHOW); //처음에 나올때 어떤 상태로 띄울 것인가를 설정할 수 있음
    UpdateWindow(hWnd_);// hWnd는 window에서 사용하는 변수임 우리가 간섭할 수 없음 우리는 받아서 사용하기만 하면된다.
}

void GameEngineWindow::MessageLoop(void(*_InitFunction)(), void(*_LoopFunction)())
{
    if (nullptr != _InitFunction)
    {
        _InitFunction();
    }

    MSG msg;

    while (WindowOn_)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // 여기서 무슨게임을 돌릴까요?

        if (nullptr == _LoopFunction)
        {
            continue;
        }

        _LoopFunction();
    }
}

void GameEngineWindow::SetWindowScaleAndPosition(float4 _Pos, float4 _Scale)
{
    // 메뉴바 

    RECT Rc = { 0, 0,  _Scale.ix(),  _Scale.iy() };

    // 1280 + 메뉴바

    AdjustWindowRect(&Rc, WS_OVERLAPPEDWINDOW, FALSE);

    Scale_ = _Scale;

    SetWindowPos(hWnd_, nullptr, _Pos.ix(), _Pos.iy(), Rc.right - Rc.left, Rc.bottom - Rc.top, SWP_NOZORDER);
}