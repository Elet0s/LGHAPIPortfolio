#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineDebug.h>

#include"MenuLevel.h"
#include"Chapter01.h"
#include"MenuBackGround00.h"
#include"MenuBackGround01.h"
#include"MenuBackGround02.h"
#include"BeelFly.h"
#include"MenuTopUi.h"
#include"MenuBotUI.h"
#include"MenuText.h"
#include"Booper.h"
#include"MenuSelcet.h"
#include"StartText.h"
#include"StartBackGround.h"
#include"StartEvent.h"
#include"Loding.h"

MenuLevel::MenuLevel()
	:NextCount_(0)
{

}
MenuLevel::~MenuLevel()
{

}

void MenuLevel::Loading()
{
	CreateActor<MenuBackGround00>(0);
	MenuBackGround01_ = CreateActor<MenuBackGround01>(1);
	MenuBackGround02_ = CreateActor<MenuBackGround02>(1);
	CreateActor<MenuText>(3);
	CreateActor<Booper>(3);
	CreateActor<MenuTopUi>(4);
	CreateActor<MenuBotUI>(4);

	if (false == GameEngineInput::GetInst()->IsKey("Next"))
	{
		GameEngineInput::GetInst()->CreateKey("Next", VK_SPACE);	
	}
	if (false == GameEngineInput::GetInst()->IsKey("SelectUp"))
	{
		GameEngineInput::GetInst()->CreateKey("SelectUp", 'w');
	}
	if (false == GameEngineInput::GetInst()->IsKey("SelectDown"))
	{
		GameEngineInput::GetInst()->CreateKey("SelectDown", 's');
	}
}

void MenuLevel::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("Next")) //타이틀 끝나고 대사
	{
		if (NextCount_ == 0)
		{
			BeelFly_ = CreateActor<BeelFly>(2);
			NextCount_ += 1;
		}
		else if (NextCount_ == 1)
		{
			MenuSelcet_ = CreateActor<MenuSelcet>(4);
			NextCount_ += 1;
		}
		else if (NextCount_ == 2)
		{
			if (MenuSelcet_->GetMenuSelcetCount() == 1)//1.게임시작
			{
				StartText_ = CreateActor<StartText>(4);
				MenuSelcet_->Death();
				NextCount_ += 1;
			}
			if (MenuSelcet_->GetMenuSelcetCount() == 2)//2.챕터선택
			{		
				NextCount_ += 1;
			}
			if (MenuSelcet_->GetMenuSelcetCount() == 3)//3.게임종료
			{
				NextCount_ += 1;
			}
		}
		else if (NextCount_ == 3)//Start누르고 대사
		{
			if (StartText_->GetStartTextCount() == 2)
			{
				BeelFly_->Death();
				MenuBackGround01_->Death();
				MenuBackGround02_->Death();
			}
			else if (StartText_->GetStartTextCount() == 3)
			{
				StartBackGround_ = CreateActor<StartBackGround>(3);
				StartEvent_ = CreateActor<StartEvent>(2);
				NextCount_ += 1;
			}
		}
		else if (NextCount_ == 4)
		{
			if (StartText_->GetStartTextCount() == 6)
			{
				GameEngine::GetInst().ChangeLevel("Chapter01");
			}
		}
	}


}
void MenuLevel::LevelChangeStart(GameEngineLevel* _NextLevel)
{
	BgmPlayer = GameEngineSound::SoundPlayControl("Menu.wav");
}

void MenuLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	BgmPlayer.Stop();
}
