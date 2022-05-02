#include "BotUi.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
BotUi::BotUi()
:BotUiRender01_(nullptr)
, BotUiRender02_(nullptr)
{
}

BotUi::~BotUi()
{
}


void BotUi::Start()
{	
	BotUiRender01_ = CreateRendererToScale("ChapterBotUI01.bmp", { 483 ,688 });
BotUiRender01_->SetPivot({ 241,736 });
BotUiRender02_ = CreateRendererToScale("ChapterBotUI02.bmp", { 483 ,688 });
BotUiRender02_->SetPivot({ 1679,736 });
}

void BotUi::Render()
{
}