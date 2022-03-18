#include"GameEngineWindow.h"
#include"GameEngineDebug.h"

GameEngineWindow* GameEngineWindow::Inst_ = new GameEngineWindow();//�����Ҵ�


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) //wcex.lpfnWndProc �� �κ� ä�� �ֱ� ���� ���� (�޼��� ó���� ���� �ݹ��Լ� ������)
{
    return DefWindowProc(hWnd, message, wParam, lParam);
}

GameEngineWindow::GameEngineWindow()
    :hInst_(nullptr)
    ,hWnd_(nullptr)
{

}

GameEngineWindow::~GameEngineWindow()
{

}

void GameEngineWindow::RegClass(HINSTANCE _hInst)
{
    // ������ Ŭ���� ���
    WNDCLASSEXA wcex; // typedef�� ������ ����ü ����, Window�� c���� ���ƾ� �ϱ� ������ ����ü�� ����Ǿ� �ִ�.
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc; //�Լ������� �־������
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
    hInst_ = _hInst;
    RegClass(_hInst);

    Title_ = _Title;
    //�̹غκк��� ������ ����ִ� �κ�
    hWnd_ = CreateWindowExA(0L, "GameEngineWindowClass", Title_.c_str(), WS_OVERLAPPEDWINDOW,//�Ű�������CreateWindowExAȣ�� Ŭ������ ,������ â ����, ws �� ������â ������ �ɼ�
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, _hInst, nullptr);//0���� x,y��ġ, cw�� ũ��, _hInst(�����쿡�� �ʿ��� ���α׷� ��ȣ) �������� ���ʿ����

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