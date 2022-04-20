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

}

void Chapter01::Update()
{

}
void Chapter01::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	CreateActor<Player>((int)ORDER::PLAYER);
	CreateActor<BotUI>((int)ORDER::UI);
}

void Chapter01::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}