#include"GameEngineDebug.h"

GameEngineDebug::GameEngineDebug()
{
	
}
GameEngineDebug::~GameEngineDebug()
{

}

void GameEngineDebug::LeekCheakOn()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
}
/*
void GameEngineDebug::MsgBoxAssert(const std::string& _Text)
{	
	MessageBeep(0);	
	MessageBoxA(nullptr, _Text.c_str(),"Error", MB_OK);		
	//window handle 넣어달라고 하는데 안넣어주면 자기자신으로 띄움 알아서 자동으로 만들어줌
	//c_ser은 자료구조의 ArrData_를 가져오는 것 
	assert(false);
}
*/