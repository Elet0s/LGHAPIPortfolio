#include "TitleLogo.h"
#include <GameEngineBase/GameEngineWindow.h>

TitleLogo::TitleLogo()
: Width_(500)
, Hight_(250)
{
}

TitleLogo::~TitleLogo()
{
}



void TitleLogo::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	CreateRendererToScale("TitleLogo.bmp", { Width_, Hight_ });
}

void TitleLogo::Render()
{
}