#include "GameUi.h"

GameUi::GameUi()
{
}

GameUi::~GameUi()
{
}


void GameUi::Start()
{
	SetPosition({ 640, 600 });
	SetScale({ 1280, 200 });
}

void GameUi::Render()
{
	DebugRectRender();
}