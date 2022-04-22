#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineDebug.h>

#include"MenuLevel.h"
#include"MenuBackGround01.h"
#include"MenuBackGround02.h"

MenuLevel::MenuLevel()
{

}
MenuLevel::~MenuLevel()
{

}

void MenuLevel::Loading()
{
	CreateActor<MenuBackGround01>(1);
	CreateActor<MenuBackGround02>(0);
}
void MenuLevel::Update()
{

}
void MenuLevel::LevelChangeStart(GameEngineLevel* _NextLevel)
{
	BgmPlayer = GameEngineSound::SoundPlayControl("Menu.wav");
}

void MenuLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}