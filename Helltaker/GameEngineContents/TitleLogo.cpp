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
	SetScale({ 5,5 });
	CreateRenderer("TitleLogo.bmp");
}

void TitleLogo::Render()
{
}