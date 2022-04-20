#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineInput.h>

#include "TitleLevel.h"
#include "TitleLogo.h"
#include "TitleBackGround.h"
#include "MenuLevel.h"

TitleLevel::TitleLevel()
	:count(0)
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Loading()
{
	CreateActor<TitleBackGround>(0);
	CreateActor<TitleLogo>(1);
}

void TitleLevel::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("Start"))
	{
		if (count == 1)
		{
			GameEngine::GetInst().ChangeLevel("MenuLevel");
		}
		count++;
	}

	//TitleLogo 투명도 변하는 것 백그라운드랑 로고 크기 점점 커지는 것 구현해야함
}

void TitleLevel::LevelChangeStart(GameEngineLevel* _NextLevel)
{
//bgm넣어줄 곳

}

void TitleLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}