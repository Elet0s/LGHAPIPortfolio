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
	:count_(0)
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
		if (count_ == 1)
		{
			GameEngine::GetInst().ChangeLevel("MenuLevel");
		}
		count_++;
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
