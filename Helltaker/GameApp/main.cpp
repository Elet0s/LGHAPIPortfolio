#include<Windows.h>
#include<GameEngineBase/GameEngineWindow.h>
#include<GameEngineBase/GameEngineDebug.h>
//�߰� ���Ե��丮 ������  "..\;" �� ��� ���� �����⺻��ġ�� �� ������ ���� 
#include<GameEngineContents/Helltaker.h>

int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char* lpCmdLine, //wchar char�� �ٲ��� w���� �����ڵ� �츮�� ��Ƽ����Ʈ�� ������
    _In_ int       nCmdShow)
{
    GameEngine::Start<Helltaker>();
} 