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
#include"StartEvent.h"

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
	CreateActor<MenuBackGround01>(1);
	CreateActor<MenuBackGround02>(1);
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
	if (true == GameEngineInput::GetInst()->IsDown("Start"))
	{
			GameEngine::GetInst().ChangeLevel("Chapter01");
	}
	if (true == GameEngineInput::GetInst()->IsDown("Next"))
	{
		if (NextCount_ == 0)
		{
			CreateActor<BeelFly>(2);
			NextCount_ += 1;
		}
		else if (NextCount_==1)
		{
			MenuSelcet_ =CreateActor<MenuSelcet>(4);
			NextCount_ += 1;
		}
		else if (NextCount_ == 2)
		{
			if (MenuSelcet_->GetMenuSelcetCount() == 1)
			{
				MenuSelcet_->Death();
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
