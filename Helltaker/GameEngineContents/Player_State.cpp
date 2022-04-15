#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineLevel.h>

void Player::IdleUpdate()
{
	if (true == IsMoveKey())
	{
		Render1->SetOrder(1000);
		ChangeState(PlayerState::Move);
		return;
	}


	if (true == GameEngineInput::GetInst()->IsDown("Fire"))
	{
		ChangeState(PlayerState::Attck);
		return;
	}
}

void Player::AttackUpdate()
{

}
int A_ = 0;
int B_ = 0;
void Player::MoveUpdate()
{

	if (A_ == 0)
	{
		if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
		{
			A_ = 1;

		}
		if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
		{
			A_ = 2;

		}
		if (true == GameEngineInput::GetInst()->IsPress("MoveUp"))
		{
			A_ = 3;

		}

		if (true == GameEngineInput::GetInst()->IsPress("MoveDown"))
		{
			A_ = 4;

		}
	}
	else if (B_ <= 100)
	{
		if (A_ == 1)
		{
			SetMove(float4::RIGHT * GameEngineTime::GetDeltaTime() * Speed_);
			++B_;
		}
		if (A_ == 2)
		{
			SetMove(float4::LEFT * GameEngineTime::GetDeltaTime() * Speed_);
			++B_;
		}
		if (A_ == 3)
		{
			SetMove(float4::UP * GameEngineTime::GetDeltaTime() * Speed_);
			++B_;
		}
		if (A_ == 4)
		{
			SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * Speed_);
			++B_;
		}
	}
	else if (B_ >= 100)
	{
		A_ = 0;
		B_ = 0;
	}

	if (true == GameEngineInput::GetInst()->IsDown("Fire"))
	{
		ChangeState(PlayerState::Attck);
		//Bullet* Ptr = GetLevel()->CreateActor<Bullet>();
		//Ptr->SetPosition(GetPosition());
	}

}


//////////////////////////////////////// State

void Player::IdleStart()
{
	// 애니메이션이 바뀐다.

	// AnimationName = "Idle_"
}

void Player::AttackStart()
{

}

void Player::MoveStart()
{

}

