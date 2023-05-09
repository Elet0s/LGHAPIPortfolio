#include"ChapterBackGound.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>


ChapterBackGound::ChapterBackGound()
	:BackGoundRender_(nullptr)
	, ChapterBackGoundTileMap_(this)
{
}

ChapterBackGound::~ChapterBackGound()
{
}

void ChapterBackGound::Start()
{
	BackGoundRender_ = CreateRenderer();
	if (this->GetLevel()->GetNameConstRef() == "Chapter01")
	{
		BackGoundRender_->SetImage("ChapterBG01.bmp");
		ChapterBackGoundScale_ = BackGoundRender_->GetImage()->GetScale();
		BackGoundRender_->SetPivot(ChapterBackGoundScale_.Half());
		ChapterBackGoundTileMap_.TileRangeSetting(19, 12, { 100,90 });
	}
	else if (this->GetLevel()->GetNameConstRef() == "Chapter02")
	{
		BackGoundRender_->SetImage("ChapterBG02.bmp");
		ChapterBackGoundScale_ = BackGoundRender_->GetImage()->GetScale();
		BackGoundRender_->SetPivot(ChapterBackGoundScale_.Half());
		ChapterBackGoundTileMap_.TileRangeSetting(19, 12, { 100,90 });
	}
	else if (this->GetLevel()->GetNameConstRef() == "Chapter03")
	{
		BackGoundRender_->SetImage("ChapterBG03.bmp");
		ChapterBackGoundScale_ = BackGoundRender_->GetImage()->GetScale();
		BackGoundRender_->SetPivot(ChapterBackGoundScale_.Half());
		ChapterBackGoundTileMap_.TileRangeSetting(19, 12, { 100,90 });
	}
}

void ChapterBackGound::Update()
{

}

void ChapterBackGound::SetChaterLevel(int _CurChapterLevel_)
{
	CurChapterLevel_ = _CurChapterLevel_;
}