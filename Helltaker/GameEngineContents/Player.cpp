#include "Player.h"
#include "ContentsEnums.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include<GameEngineBase/GameEngineInput.h>
#include<GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineLevel.h> 
#include <GameEngineBase/GameEngineTime.h>

Player* Player::PlayerObject_ = nullptr;

Player::Player()
	: Speed_(150.0f)
	, LifePoint_(0)
	, MakeCheak_(false)
	, CurState_(PlayerState::Idle)
	, RLState_(true)
	, PlayerX_(11)
	, PlayerY_(3)
	, MoveSet_(false)
	, MoveStart_(false)
	, MoveEnd_(false)
	, ShiftX_(0)
	, ShiftY_(0)
	, LTUD_(0)
{
}

Player::~Player()
{
}

void Player::Start()
{
	PlayerS_ = CreateRenderer("TileBase.bmp");
	PlayerS_->CreateAnimation("PlayerLeft.bmp", "PlayerLeft", 0, 11, 0.065f, true);
	PlayerS_->CreateAnimation("PlayerRight.bmp", "PlayerRight", 0, 11, 0.065f, true);
	PlayerS_->CreateAnimation("PlayerMoveL.bmp", "PlayerMoveL", 0, 5, 0.065f, true);
	PlayerS_->CreateAnimation("PlayerMoveR.bmp", "PlayerMoveR", 0, 5, 0.065f, true);
	PlayerS_->CreateAnimation("PlayerKickL.bmp", "PlayerKickL", 0, 12, 0.065f, true);
	PlayerS_->CreateAnimation("PlayerKickR.bmp", "PlayerKickR", 0, 12, 0.065f, true);

	KeySet();
}
void Player::Update()
{
	if(MakeCheak_ == false)
	{
	CreatePlayer(PlayerX_, PlayerY_, 0);//챕터 정보 받아서 스위치문으로 인자값 바꿔줄것
	MakeCheak_ = true;
	}

	StateUpdate();
}
void Player::Render()
{

}
void Player::ChangeState(PlayerState _State) //특정 조건이 만족하면 호출하여 상태를 바꿔줌
{
	if (CurState_ != _State)
	{

		switch (_State)
		{
		case PlayerState::Idle:
			IdleStart();
			break;
		case PlayerState::Kick:
			KickStart();
			break;
		case PlayerState::Move:
			MoveStart();
			break;
		case PlayerState::Die:
			break;
			DieStart();
		case PlayerState::Win:
			WinStart();
			break;
		default:
			break;
		}
	}

	CurState_ = _State;
}
void Player::StateUpdate()// 계속 상태를 체크하면서 현재 상태에 맞는 업데이트를 해줌
{
	switch (CurState_)
	{
	case PlayerState::Idle:
		IdleUpdate();
		break;

	case PlayerState::Move:
		MoveUpdate();
		break;
	case PlayerState::Kick:
		break;
		KickUpdate();
	case PlayerState::Die:
		DieUpdate();
		break;
	case PlayerState::Win:
		WinUpdate();
		break;
	default:
		break;
	}
}
void Player::ColSet(int _ChapterCount) // 챕터에서 호출하여 레벨에 맞게 콜리전과 맵 인자 세팅
{	
	if(_ChapterCount==1)
	{

		ChapterCol_ = GameEngineImageManager::GetInst()->Find("ChapterBG01C.bmp");
		LifePoint_ = 23;
	}

}
void Player::KeySet() // 키세팅
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
void Player::CreatePlayer(int _x, int _y, int _index)
{
	PlayerTileBase = TileMap_ ->CreateTile<PlayerTile>(_x, _y, "TileBase.bmp", static_cast<int>(ORDER::BASETILE));
	PlayerS_->SetPivot({(float)_x * 100 + 50 , (float)_y * 90 +20 });
}

bool Player::MoveCheak()
{
	if (false == GameEngineInput::GetInst()->IsDown("LeftMove") &&
		false == GameEngineInput::GetInst()->IsDown("RightMove") &&
		false == GameEngineInput::GetInst()->IsDown("UpMove") &&
		false == GameEngineInput::GetInst()->IsDown("DownMove"))
	{
		if (CurState_ == PlayerState::Idle)
		{
			return false;

		}
	}
	return true;

}
void Player::LeftMoveShift()
{
	if (MoveSet_ == false)
	{
		ShiftX_ = PlayerX_ * 100 + 50; // 원래위치
		ShiftY_ = PlayerY_ * 90 + 20;
		MoveSet_ = true;
	}

	if (ShiftX_ > (PlayerX_ - 1) * 100 + 50)
	{
		ShiftX_ -= 100 * GameEngineTime::GetDeltaTime() *10.0f;
		PlayerS_->SetPivot({ ShiftX_ ,  ShiftY_ });
	}
	else if (ShiftX_ <= (PlayerX_ - 1) * 100 + 50)
	{
		MoveSet_ = false;
		MoveStart_ = false;
		MoveEnd_ = true;
	}
}
void Player::RightMoveShift()
{
	if (MoveSet_ == false)
	{
		ShiftX_ = PlayerX_ * 100 + 50; // 원래위치
		ShiftY_ = PlayerY_ * 90 + 20;
		MoveSet_ = true;
	}

	if (ShiftX_ <= (PlayerX_ + 1) * 100 + 50)
	{
		ShiftX_ += 100 * GameEngineTime::GetDeltaTime() * 10.0f;
		PlayerS_->SetPivot({ ShiftX_ ,  ShiftY_ });
	}
	else if (ShiftX_ > (PlayerX_ + 1) * 100 + 50)
	{
		MoveSet_ = false;
		MoveStart_ = false;
		MoveEnd_ = true;
	}
}
void Player::UpMoveShift()
{

}
void Player::DownMoveShift()
{

}


