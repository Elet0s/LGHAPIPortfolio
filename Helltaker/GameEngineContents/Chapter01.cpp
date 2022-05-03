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
#include "Ston.h"
#include "Monster.h"
#include "Helper.h"


Chapter01::Chapter01()
	:ChapterCount_(1)
{

}

Chapter01::~Chapter01()
{

}

void Chapter01::Loading()
{
	ChapterBackGound_ = CreateActor<ChapterBackGound>(0);//Actor �����
	ChapterBackGound_->GetRenderer()->SetImage("ChapterBG01.bmp");//Actor�� �̹��� �������ְ�
	float4 ChapterBackGoundScale = ChapterBackGound_->GetRenderer()->GetImage()->GetScale();//�̹��� ũ�� ���ϰ�
	ChapterBackGound_->GetRenderer()->SetPivot(ChapterBackGoundScale.Half());//��������� �׷��� ��ġ �����ְ�
	ChapterBackGound_->ChapterBackGoundTileMap_.TileRangeSetting(19, 11, { 100,93 });// Ÿ�ϸ� �������

	ChapterBackGound_->ChapterBackGoundTileMap_.CreateTile<Ston>(7,7, "Ston.bmp", 1, static_cast<int>(ORDER::STON));//Ÿ�ϸ� ������Ʈ ���� ����
	ChapterBackGound_->ChapterBackGoundTileMap_.CreateTile<Ston>(10, 7, "Ston.bmp", 4, static_cast<int>(ORDER::STON));
	ChapterBackGound_->ChapterBackGoundTileMap_.CreateTile<Ston>(9, 8, "Ston.bmp", 3, static_cast<int>(ORDER::STON));
	ChapterBackGound_->ChapterBackGoundTileMap_.CreateTile<Ston>(7, 8, "Ston.bmp", 2, static_cast<int>(ORDER::STON));
	
	ChapterBackGound_->ChapterBackGoundTileMap_.CreateTile<Monster>(8, 5, "MonsterR.bmp", 0, static_cast<int>(ORDER::MONSTER));//Ÿ�ϸ� ������Ʈ ���� ����
	ChapterBackGound_->ChapterBackGoundTileMap_.CreateTile<Monster>(10, 5, "MonsterR.bmp", 0, static_cast<int>(ORDER::MONSTER));
	ChapterBackGound_->ChapterBackGoundTileMap_.CreateTile<Monster>(9, 4, "MonsterR.bmp", 0, static_cast<int>(ORDER::MONSTER));

	ChapterBackGound_->ChapterBackGoundTileMap_.CreateTile<Helper>(12, 8, "Pandemonica.bmp", 0, static_cast<int>(ORDER::HELPER));

	Player_ = CreateActor<Player>(1);
	Player_->ColSet(ChapterCount_);


	BotUi_ = CreateActor<BotUi>(3);
	TopUi_ = CreateActor<TopUi>(2);
	LodingNext_ = CreateActor<LodingNext>(4);
}

void Chapter01::Update()
{

}
void Chapter01::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	ChpterBgmPlayer_ = GameEngineSound::SoundPlayControl("Chapter.wav");
	GameEngineSound::SoundPlayOneShot("LodingN.wav", 0);
}

void Chapter01::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}