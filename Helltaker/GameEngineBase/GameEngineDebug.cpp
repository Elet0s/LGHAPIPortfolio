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
	//window handle �־�޶�� �ϴµ� �ȳ־��ָ� �ڱ��ڽ����� ��� �˾Ƽ� �ڵ����� �������
	//c_ser�� �ڷᱸ���� ArrData_�� �������� �� 
	assert(false);
}
*/