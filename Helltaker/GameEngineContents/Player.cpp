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
	KeySet();
	ColSet();
;
}

void Player::Update()
{
	float4 MyPosition_ = GetPosition();
	int Color = ChapterCol_->GetImagePixel(MyPosition_);
	if (RGB(0, 0, 0) != Color)
	{
		if (true == GameEngineInput::GetInst()->IsPress("LeftMove"))
		{
			MyPosition_ += (float4::LEFT * GameEngineTime::GetDeltaTime() * Speed_);
		}
		if (true == GameEngineInput::GetInst()->IsPress("RightMove"))
		{
			MyPosition_ += (float4::RIGHT * GameEngineTime::GetDeltaTime() * Speed_);
		}
		if (true == GameEngineInput::GetInst()->IsPress("UpMove"))
		{
			MyPosition_ += (float4::UP * GameEngineTime::GetDeltaTime() * Speed_);
		}

		if (true == GameEngineInput::GetInst()->IsPress("DownMove"))
		{
			MyPosition_ += (float4::DOWN * GameEngineTime::GetDeltaTime() * Speed_);
		}
		SetPosition(MyPosition_);
	}
	
}
void Player::Render()
{

}

void Player::ColSet()
{
	ChapterCol_ = GameEngineImageManager::GetInst()->Find("ChapterBG01C.bmp");
}
void Player::KeySet()
{
	if (false == GameEngineInput::GetInst()->IsKey("MoveLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("LeftMove", VK_LEFT);
		GameEngineInput::GetInst()->CreateKey("RightMove", VK_RIGHT);
		GameEngineInput::GetInst()->CreateKey("UpMove", VK_UP);
		GameEngineInput::GetInst()->CreateKey("DownMove", VK_DOWN);
	}
}