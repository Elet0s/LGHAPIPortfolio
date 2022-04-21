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
	//TitleLogo ���� ���ϴ� �� ��׶���� �ΰ� ũ�� ���� Ŀ���� �� �����ؾ���

}

void TitleLevel::LevelChangeStart(GameEngineLevel* _NextLevel)
{
//bgm�־��� ��

}

void TitleLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}
