#include"ChapterBackGound.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>


ChapterBackGound::ChapterBackGound()
	:ChapterBackGoundRender_(nullptr)
{

}
ChapterBackGound::~ChapterBackGound()
{

}

void ChapterBackGound::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	ChapterBackGoundRender_ = CreateRendererToScale("chapterBG01.bmp", { 1920 ,1080 });

	//ChapterBackGoundTileMap_->TileRangeSetting(19, 11, { 100,95 });
}

void ChapterBackGound::Render()
{
}