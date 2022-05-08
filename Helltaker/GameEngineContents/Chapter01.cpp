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

	GameObjectManager::GameObjectManager_ = CreateActor<GameObjectManager>();
	GameObjectManager::GameObjectManager_-> SetTileMap(&ChapterBackGound_->ChapterBackGoundTileMap_);

	
	Player_ = CreateActor<Player>(1);
	Player_->ColSet(ChapterCount_);


	BotUi_ = CreateActor<BotUi>(3);
	TopUi_ = CreateActor<TopUi>(2);
	LodingNext_ = CreateActor<LodingNext>(9);
}

void Chapter01::Update()
{

}
void Chapter01::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	ChapterBgm_ = GameEngineSound::SoundPlayControl("Chapter.wav");
	GameEngineSound::SoundPlayOneShot("LodingN.wav", 0);
}

void Chapter01::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}