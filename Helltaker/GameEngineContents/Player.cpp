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
	, LifePoint_(0)
{
}

Player::~Player()
{
}

void Player::Start()
{

	PlayerRender_ = CreateRendererToScale("PlayerLeft.bmp", { 100 ,100 });
	PlayerRender_->CreateAnimation("PlayerLeft.bmp", "PlayerLeft", 0, 11, 0.069f, true);
	PlayerRender_->CreateAnimation("PlayerRight.bmp", "PlayerRight", 0, 11, 0.069f, true);
	PlayerRender_->ChangeAnimation("PlayerLeft");
	KeySet();
;
}
void Player::Update()
{
	
}
void Player::Render()
{

}
void Player::ChangeState(PlayerState _State)
{
	if (NextState_ == _State)
	{
	}
	else if (NextState_ != _State)
	{

	}
}
void Player::StateUpdate()
{

}
void Player::ColSet(int _ChapterCount)
{	
	if(_ChapterCount==1)
	{
		SetPosition({ 1160,290 });
		ChapterCol_ = GameEngineImageManager::GetInst()->Find("ChapterBG01C.bmp");
		LifePoint_ = 23;
	}

}
void Player::KeySet()
{
	if (false == GameEngineInput::GetInst()->IsKey("MoveLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("LeftMove", VK_LEFT);
		GameEngineInput::GetInst()->CreateKey("RightMove", VK_RIGHT);
		GameEngineInput::GetInst()->CreateKey("UpMove", VK_UP);
		GameEngineInput::GetInst()->CreateKey("DownMove", VK_DOWN);
		GameEngineInput::GetInst()->CreateKey("Esc", VK_ESCAPE);
		GameEngineInput::GetInst()->CreateKey("Reload", 'R');
		GameEngineInput::GetInst()->CreateKey("Helper", 'L');
	}
}