#include "BotUI.h"

BotUI::BotUI()
{
}

BotUI::~BotUI()
{
}


void BotUI::Start()
{
	SetPosition({ 640,600 });
	SetScale({ 1280, 200 });
}

void BotUI::Render()
{
	DebugRectRender();
}