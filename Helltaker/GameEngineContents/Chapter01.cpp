#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineWindow.h>


#include "ContentsEnums.h"
#include "Chapter01.h"
#include "Player.h"
#include "BotUI.h"
#include "TopUi.h"
#include "ChapterBackGound.h"
#include "Loding.h"
#include "LodingNext.h"
#include "GameObjectManager.h"
#include "ClearEvent.h"


Chapter01::Chapter01()
	:ChapterCount_(1)
{

}

Chapter01::~Chapter01()
{

}

void Chapter01::Loading()
{
	ChapterBackGound_ = CreateActor<ChapterBackGound>((int)ORDER::BACKGROUND);//Actor 만들고
	ChapterBackGound_->GetRenderer()->SetImage("ChapterBG01.bmp");//Actor에 이미지 세팅해주고
	float4 ChapterBackGoundScale = ChapterBackGound_->GetRenderer()->GetImage()->GetScale();//이미지 크기 구하고
	ChapterBackGound_->GetRenderer()->SetPivot(ChapterBackGoundScale.Half());//윈도우기준 그려줄 위치 정해주고
	ChapterBackGound_->ChapterBackGoundTileMap_.TileRangeSetting(19, 12, { 100,90 });// 타일맵 만들어줌

	GameObjectManager::GameObjectManager_ = CreateActor<GameObjectManager>(1);
	GameObjectManager::GameObjectManager_-> SetTileMap(&ChapterBackGound_->ChapterBackGoundTileMap_);
	GameObjectManager::GameObjectManager_->ObjectCheakChapter(ChapterCount_);

	Player::PlayerObject_ = CreateActor<Player>(2);
	Player::PlayerObject_-> SetTileMap(&ChapterBackGound_->ChapterBackGoundTileMap_);
	Player::PlayerObject_->CheakChapter(ChapterCount_);

	BotUi_ = CreateActor<BotUi>(4);
	TopUi_ = CreateActor<TopUi>(3);
	LodingNext_ = CreateActor<LodingNext>(9);

}

void Chapter01::Update()
{
	if (Player::PlayerObject_->ClearChapter() == true)
	{
		ClearEvent_ =	CreateActor<ClearEvent>(9);

		if (true == GameEngineInput::GetInst()->IsDown("Next"))
		{

		}
	}
}
void Chapter01::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	ChapterBgm_ = GameEngineSound::SoundPlayControl("Chapter.wav");
	GameEngineSound::SoundPlayOneShot("LodingN.wav", 0);
}

void Chapter01::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	Loding_ = CreateActor<Loding>(9);
	GameEngineSound::SoundPlayOneShot("Loding.wav", 0);
}
bool Chapter01::ChapterClear()
{
	return GameObjectManager::GameObjectManager_->GetChapterClear();
}