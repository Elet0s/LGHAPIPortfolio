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
}

void TitleLevel::LevelChangeStart()
{
//bgm넣어줄때

}