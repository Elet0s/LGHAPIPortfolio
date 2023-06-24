#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineWindow.h>
#include<GameEngineBase/GameEngineTime.h>

#include "ContentsEnums.h"
#include "Chapter01.h"
#include "Player.h"
#include "BotUI.h"
#include "TopUi.h"
#include "ChapterBackGound.h"
#include "LodingManager.h"
#include "GameObjectManager.h"
#include "ClearEvent.h"
#include"ChapterCounter.h"


Chapter01::Chapter01()
	:ChapterCount_(1)
	, BotUi_()
	, ChapterBackGound_()
	, ChapterBgm_()
	, TopUi_()
	, LodingManager_()
	, ClearEvent_()
	, ChapterCounter_()
	,LifeCounter_()
	,  ReloadTimer_(0.0f)
, ReloadCheaker_(false)
{

}

Chapter01::~Chapter01()
{

}

void Chapter01::Start()
{

	////키 세팅////
	if (false == GameEngineInput::GetInst()->IsKey("Reload"))
	{
		GameEngineInput::GetInst()->CreateKey("Reload", 'R');
	}
	if (false == GameEngineInput::GetInst()->IsKey("OfenMenu"))
	{
		GameEngineInput::GetInst()->CreateKey("OfenMenu", VK_ESCAPE);
	}
	if (false == GameEngineInput::GetInst()->IsKey("Advice"))
	{
		GameEngineInput::GetInst()->CreateKey("Advice", 'L');
	}

	////Actor 생성////
	LodingManager_ = CreateActor<LodingManager>(10);
	ChapterBackGound_ = CreateActor<ChapterBackGound>((int)ORDER::BACKGROUND);


	GameObjectManager::GameObjectManager_ = CreateActor<GameObjectManager>(1);
	GameObjectManager::GameObjectManager_-> SetTileMap(&ChapterBackGound_->ChapterBackGoundTileMap_);
	GameObjectManager::GameObjectManager_->ObjectCheakChapter(ChapterCount_);

	Player::PlayerObject_ = CreateActor<Player>(2);
	Player::PlayerObject_-> SetTileMap(&ChapterBackGound_->ChapterBackGoundTileMap_);
	Player::PlayerObject_->CheakChapter(ChapterCount_);
	Player::PlayerObject_->PlayerPositionSet();
	Player::PlayerObject_->SetLifePoint(23);


	LifeCounter_ = CreateActor<LifeCounter>(9);
	ChapterCounter_ = CreateActor<ChapterCounter>(9);
	ChapterCounter_->SetChapterPoint(ChapterCount_);

	BotUi_ = CreateActor<BotUi>(4);
	TopUi_ = CreateActor<TopUi>(3);
	
}

void Chapter01::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("Reload"))
	{
		ReloadCheaker_ = true;

	}
	if (ReloadCheaker_ == true)
	{
		ReloadTimer_ += GameEngineTime::GetDeltaTime();
		if (ReloadTimer_ >= 1.0f)
		{
			Player::PlayerObject_->ReloadSet();
			ReloadCheaker_ = false;
			ReloadTimer_ = 0.0f;
		}

	}
}

void Chapter01::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	LodingManager_->Shoot("End");
}

void Chapter01::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
}
bool Chapter01::ChapterClear()
{
	return GameObjectManager::GameObjectManager_->GetChapterClear();
}