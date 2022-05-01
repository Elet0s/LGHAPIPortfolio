#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include<GameEngineBase/GameEngineInput.h>
#include<GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineLevel.h> 

Player::Player()
	: Speed_(150.0f)
{
}

Player::~Player()
{
}

void Player::Start()
{
	SetPosition({ 1160,290 });
	PlayerRender_ = CreateRendererToScale("PlayerRight.bmp", { 100 ,100 });
	PlayerRender_->CreateAnimation("PlayerRight.bmp", "Player", 0, 11, 0.069f, true);
	PlayerRender_->ChangeAnimation("Player");


	if (false == GameEngineInput::GetInst()->IsKey("MoveLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("LeftMove", 'A');
		GameEngineInput::GetInst()->CreateKey("RightMove", 'D');
		GameEngineInput::GetInst()->CreateKey("UpMove", 'W');
		GameEngineInput::GetInst()->CreateKey("DownMove", 'S');
	}
}

void Player::Update()
{
	if (true == GameEngineInput::GetInst()->IsPress("LeftMove"))
	{
		SetMove(float4::LEFT * GameEngineTime::GetDeltaTime() * Speed_);
	}
	if (true == GameEngineInput::GetInst()->IsPress("RightMove"))
	{
		SetMove(float4::RIGHT * GameEngineTime::GetDeltaTime() * Speed_);
	}
	if (true == GameEngineInput::GetInst()->IsPress("UpMove"))
	{
		SetMove(float4::UP * GameEngineTime::GetDeltaTime() * Speed_);
	}

	if (true == GameEngineInput::GetInst()->IsPress("DownMove"))
	{
		SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * Speed_);
	}
}
void Player::Render()
{

}
void Player::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}
void Player::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}