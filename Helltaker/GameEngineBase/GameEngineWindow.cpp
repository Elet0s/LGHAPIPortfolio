#include"GameEngineWindow.h"
#include"GameEngineDebug.h"

LRESULT CALLBACK MessageProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) //wcex.lpfnWndProc �� �κ� ä�� �ֱ� ���� ���� (�޼��� ó���� ���� �ݹ��Լ� ������)
{
    switch (message)
    {
    case WM_DESTROY:
    {
        // �����츦 �����ϰ� ��� 
        GameEngineWindow::GetInst().Off();
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
        EndPaint(hWnd, &ps);
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    default:
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

GameEngineWindow* GameEngineWindow::Inst_ = new GameEngineWindow();//�����Ҵ�

GameEngineWindow::GameEngineWindow()
    :hInst_(nullptr)
    ,hWnd_(nullptr)
    ,WindowOn_(true)
    ,HDC_(nullptr)
{

}

GameEngineWindow::~GameEngineWindow()
{
     // ���� ������ذ� �ƴ϶�� �� ������� �մϴ�.
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
    // ������ Ŭ���� ���
    WNDCLASSEXA wcex; // typedef�� ������ ����ü ����, Window�� c���� ���ƾ� �ϱ� ������ ����ü�� ����Ǿ� �ִ�.
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = MessageProcess; //�Լ������� �־������
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = _hInst;//�ν��Ͻ� ��, �츮�� �ν��Ͻ� ���� �ܺο��� �޾ƿ;��ϴϱ� ���ڰ����� �޴����·� ������ش�. //�ڵ�
    wcex.hIcon = nullptr;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2); //��׶��� �÷�
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "GameEngineWindowClass"; //L"text" ���´� �����ڵ� ���  
    wcex.hIconSm = nullptr;
    RegisterClassExA(&wcex); //return�� �ʿ� ����
}

void GameEngineWindow::CreateGameWindow(HINSTANCE _hInst, const std::string& _Title)
{
    if (nullptr != hInst_) // Ŭ���� ����� �ѹ��� 2�� ����� ������
    {
        MsgBoxAssert("������ �ߺ� ȣ��");
        return;
    }

    Title_ = _Title;

    hInst_ = _hInst;
    RegClass(_hInst);

    
    //�̹غκк��� ������ ����ִ� �κ�
    hWnd_ = CreateWindowExA(0L, "GameEngineWindowClass", Title_.c_str(), WS_OVERLAPPEDWINDOW,//�Ű�������CreateWindowExAȣ�� Ŭ������ ,������ â ����, ws �� ������â ������ �ɼ�
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, _hInst, nullptr);//0���� x,y��ġ, cw�� ũ��, _hInst(�����쿡�� �ʿ��� ���α׷� ��ȣ) �������� ���ʿ����

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
        MsgBoxAssert("�����찡 �������� �ʽ��ϴ�.");
        return;
    }
    ShowWindow(hWnd_, SW_SHOW); //ó���� ���ö� � ���·� ��� ���ΰ��� ������ �� ����
    UpdateWindow(hWnd_);// hWnd�� window���� ����ϴ� ������ �츮�� ������ �� ���� �츮�� �޾Ƽ� ����ϱ⸸ �ϸ�ȴ�.
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

        // ���⼭ ���������� �������?

        if (nullptr == _LoopFunction)
        {
            continue;
        }

        _LoopFunction();
    }
}

void GameEngineWindow::SetWindowScaleAndPosition(float4 _Pos, float4 _Scale)
{
    // �޴��� 

    RECT Rc = { 0, 0,  _Scale.ix(),  _Scale.iy() };

    // 1280 + �޴���

    AdjustWindowRect(&Rc, WS_OVERLAPPEDWINDOW, FALSE);

    Scale_ = _Scale;

    SetWindowPos(hWnd_, nullptr, _Pos.ix(), _Pos.iy(), Rc.right - Rc.left, Rc.bottom - Rc.top, SWP_NOZORDER);
}