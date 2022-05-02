#include"TopUi.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
TopUi::TopUi()
	:TopUiRender01_(nullptr)
	, TopUiRender02_(nullptr)
{
}
TopUi::~TopUi()
{

}
void TopUi::Start()
{
	TopUiRender01_ = CreateRendererToScale("ChapterTopUI01.bmp", { 320 ,580 });
	TopUiRender01_->SetPivot({ 160,290 });
	TopUiRender02_ = CreateRendererToScale("ChapterTopUI02.bmp", { 320 ,580 });
	TopUiRender02_->SetPivot({ 1760,290 });

}

void TopUi::Render()
{
}