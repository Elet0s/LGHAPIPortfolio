#include "TitleLogo.h"
#include <GameEngineBase/GameEngineWindow.h>

TitleLogo::TitleLogo()
{
}

TitleLogo::~TitleLogo()
{
}



void TitleLogo::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	CreateRendererToScale("TitleLogo.bmp", { 380, 280 });
}

void TitleLogo::Render()
{
}