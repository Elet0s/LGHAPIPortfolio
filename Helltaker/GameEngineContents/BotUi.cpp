#include "BotUI.h"

BotUI::BotUI()
{
}

BotUI::~BotUI()
{
}


void BotUI::Start()
{
	SetPosition({ 960,1080 });
	SetScale({ 1920, 200 });
}

void BotUI::Render()
{
	DebugRectRender();
}