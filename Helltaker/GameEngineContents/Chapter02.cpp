#include<GameEngineBase/GameEngineInput.h>

#include"Chapter02.h"

Chapter02::Chapter02()
{

}
Chapter02::~Chapter02()
{

}

void Chapter02::Start()
{

	////키 세팅////
	if (false == GameEngineInput::GetInst()->IsKey("Reload"))
	{
		GameEngineInput::GetInst()->CreateKey("Reload", 'R');
	}
	if (false == GameEngineInput::GetInst()->IsKey("OfenMenu"))
	{
		GameEngineInput::GetInst()->CreateKey("OfenMenu", VK_ESCAPE);
	}
	if (false == GameEngineInput::GetInst()->IsKey("Advice"))
	{
		GameEngineInput::GetInst()->CreateKey("Advice", 'L');
	}
	////ACtor 생성////
}
void Chapter02::Update()
{

}
void Chapter02::LevelChangeStart(GameEngineLevel* _NextLevel)
{

}
void Chapter02::LevelChangeEnd(GameEngineLevel* _PrevLevel)
{

}