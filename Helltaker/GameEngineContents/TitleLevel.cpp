#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineInput.h>

#include "ContentsEnums.h"
#include "TitleLevel.h"
#include "TitleLogo.h"
#include "TitleBackGround.h"
#include "MenuLevel.h"

TitleLevel::TitleLevel()
	:	 LevelChangeTime_(3.0f)
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
	LevelChangeTime_ -= GameEngineTime::GetDeltaTime();
	if (LevelChangeTime_<=0)
	{
		GameEngine::GetInst().ChangeLevel("MenuLevel");
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
