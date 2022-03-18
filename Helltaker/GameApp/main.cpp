#include<Windows.h>
#include<GameEngineBase/GameEngineWindow.h>
#include<GameEngineBase/GameEngineDebug.h>
//추가 포함디렉토리 설정을  "..\;" 로 경로 지정 참조기본위치가 저 설정을 따라감 


int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char* lpCmdLine, //wchar char로 바꿔줌 w들어가면 유니코드 우리는 멀티바이트로 쓸거임
    _In_ int       nCmdShow)
{
    GameEngineDebug::LeekCheakOn();
    GameEngineWindow::GetInst().CreateGameWindow(hInstance, "Helltaker"); // static이라 가능하다. 1.class에서 static선언을 하게되면 모든 객체에서 static선언된 부분을 공유해서 쓰게 된다.(전역으로서의 역할), 2.객체가 없어도 사용가능하다.
    //GameEngineBase의 cpp까지 알길이 없음 
    //그래서 탐색기 참조 우클릭으로 참조추가해줘야한다. 여기서 참조추가해주는 파일이 exe를 만드는 파일이 아니다(이를 라이브러리 파일)속성에서 정적라이브러리로 바꿔줘야함

    GameEngineWindow::GetInst().ShowGameWindow();
    GameEngineWindow::Destroy();
} 