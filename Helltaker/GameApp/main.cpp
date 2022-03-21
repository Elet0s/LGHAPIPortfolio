#include<Windows.h>
#include<GameEngineBase/GameEngineWindow.h>
#include<GameEngineBase/GameEngineDebug.h>
//추가 포함디렉토리 설정을  "..\;" 로 경로 지정 참조기본위치가 저 설정을 따라감 
#include<GameEngineContents/Helltaker.h>

int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char* lpCmdLine, //wchar char로 바꿔줌 w들어가면 유니코드 우리는 멀티바이트로 쓸거임
    _In_ int       nCmdShow)
{
    GameEngine::Start<Helltaker>();
} 