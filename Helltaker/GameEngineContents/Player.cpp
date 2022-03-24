#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>

Player::Player()
{
}

Player::~Player()
{
}


void Player::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale(GameEngineWindow::GetScale());

	CreateRenderer("Plyer01.bmp");
	CreateRendererToScale("lovesign.bmp", float4(30.0f, 30.0f), RenderPivot::CENTER, float4(-30.0f, -30.0f));

}

void Player::Render()
{
}