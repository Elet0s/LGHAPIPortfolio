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
#include"MenuText001.h"
#include"Booper.h"

MenuLevel::MenuLevel()
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
	//CreateActor<BeelFly>(2);
	CreateActor<MenuText001>(3);
	CreateActor<Booper>(3);
	CreateActor<MenuTopUi>(4);
	CreateActor<MenuBotUI>(4);
}
void MenuLevel::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("Start"))
	{
			GameEngine::GetInst().ChangeLevel("Chapter01");
	}
}
void MenuLevel::LevelChangeStart(GameEngineLevel* _NextLevel)
{
	BgmPlayer = GameEngineSound::SoundPlayControl("Menu.wav");
}

void MenuLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}