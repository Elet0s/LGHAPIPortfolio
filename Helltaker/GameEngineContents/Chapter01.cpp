#include "ContentsEnums.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineWindow.h>

#include "Chapter01.h"
#include "Player.h"
#include "BotUI.h"
#include "ChapterBackGound.h"


Chapter01::Chapter01()
{

}

Chapter01::~Chapter01()
{

}

void Chapter01::Loading()
{
	CreateActor<ChapterBackGound>(0);
	CreateActor<Player>(1);
}

void Chapter01::Update()
{

}
void Chapter01::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
}

void Chapter01::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}