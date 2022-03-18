#include<Windows.h>
#include<GameEngineBase/GameEngineWindow.h>
#include<GameEngineBase/GameEngineDebug.h>
//�߰� ���Ե��丮 ������  "..\;" �� ��� ���� �����⺻��ġ�� �� ������ ���� 


int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char* lpCmdLine, //wchar char�� �ٲ��� w���� �����ڵ� �츮�� ��Ƽ����Ʈ�� ������
    _In_ int       nCmdShow)
{
    GameEngineDebug::LeekCheakOn();
    GameEngineWindow::GetInst().CreateGameWindow(hInstance, "Helltaker"); // static�̶� �����ϴ�. 1.class���� static������ �ϰԵǸ� ��� ��ü���� static����� �κ��� �����ؼ� ���� �ȴ�.(�������μ��� ����), 2.��ü�� ��� ��밡���ϴ�.
    //GameEngineBase�� cpp���� �˱��� ���� 
    //�׷��� Ž���� ���� ��Ŭ������ �����߰�������Ѵ�. ���⼭ �����߰����ִ� ������ exe�� ����� ������ �ƴϴ�(�̸� ���̺귯�� ����)�Ӽ����� �������̺귯���� �ٲ������

    GameEngineWindow::GetInst().ShowGameWindow();
    GameEngineWindow::Destroy();
} 