#include "Player.h"
#include "ContentsEnums.h"
#include "GameObjectManager.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include<GameEngineBase/GameEngineInput.h>
#include<GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineLevel.h> 

Player* Player::PlayerObject_ = nullptr;

Player::Player()
	: Speed_(150.0f)
	, LifePoint_(0)
	, MakeCheak_(false)
	, CurState_(PlayerState::Idle)
	, RLState_(true)
	, PlayerX_(0)
	, PlayerY_(0)
	, MoveSet_(false)
	, MoveStart_(false)
	, MoveEnd_(false)
	, ShiftX_(0)
	, ShiftY_(0)
	, LTUD_(0)
	, WinCheak_(false)
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
	PlayerS_->CreateAnimation("PlayerMoveL.bmp", "PlayerMoveL", 0, 5, 0.1f, true);
	PlayerS_->CreateAnimation("PlayerMoveR.bmp", "PlayerMoveR", 0, 5, 0.1f, true);
	PlayerS_->CreateAnimation("PlayerKickL.bmp", "PlayerKickL", 7, 12, 0.065f, true);
	PlayerS_->CreateAnimation("PlayerKickR.bmp", "PlayerKickR", 0, 6, 0.065f, true);
	PlayerS_->CreateFolderAnimation("PlayerWinL", "PlayerWinLPlay", 0, 18, 0.065f, false);
	PlayerS_->CreateFolderAnimation("PlayerWinR", "PlayerWinRPlay", 0, 18, 0.065f, false);
	PlayerS_->CreateFolderAnimation("PlayerDieL", "PlayerDieLPlay", 0, 17, 0.065f, false);
	PlayerS_->CreateFolderAnimation("PlayerDieR", "PlayerDieRPlay", 0, 17, 0.065f, false);
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
	LifeTestSet();
}

void Player::ClearConditionCheak()
{
	if(TileMap_->GetTile<PlayerTile>(PlayerX_+1, PlayerY_) != nullptr)
	{
		if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ + 1, PlayerY_)->TileState_ == MapObject::Helper)
		{
			WinCheak_ = true;
		}
	}

	if (TileMap_->GetTile<PlayerTile>(PlayerX_ - 1, PlayerY_) != nullptr)
	{
		if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ - 1, PlayerY_)->TileState_ == MapObject::Helper)
		{
			WinCheak_ = true;
		}
	}

	if (TileMap_->GetTile<PlayerTile>(PlayerX_, PlayerY_ - 1) != nullptr)
	{
		if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_, PlayerY_ - 1)->TileState_ == MapObject::Helper)
		{
			WinCheak_ = true;
		}
	}

	if (TileMap_->GetTile<PlayerTile>(PlayerX_, PlayerY_ + 1) != nullptr)
	{
		if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_, PlayerY_ + 1)->TileState_ == MapObject::Helper)
		{
			WinCheak_ = true;
		}
	}


}

void Player::SetLifePoint(int _LifePoint)
{
	LifePoint_  = _LifePoint;
}

int Player::GetLifePoint()
{
	return LifePoint_;
}

void Player::ChangeState(PlayerState _State) //특정 조건이 만족하면 호출하여 상태를 바꿔줌
{
	if (CurState_ != _State)
	{
		CurState_ = _State;
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
			DieStart();
			break;
		case PlayerState::Win:
			WinStart();
			break;
		default:
			break;
		}
	}


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
		KickUpdate();
		break;

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
void Player::CheakChapter(int _ChapterLevel)
{
	ChapterLevel_ = _ChapterLevel;
	switch (_ChapterLevel == 1)
	{
	case 1:
		LifePoint_ = 23;
		break;
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
		GameEngineInput::GetInst()->CreateKey("LifeTestSet", 'Y');
	}
}

void Player::LifeTestSet()
{
	if (true == GameEngineInput::GetInst()->IsDown("LifeTestSet"))
	{
		LifePoint_ = 1;
	}
}

void Player::CreatePlayer(int _x, int _y, int _index)
{
	PlayerTileBase = TileMap_ ->CreateTile<PlayerTile>(_x, _y, "TileBase.bmp", static_cast<int>(ORDER::PLAYER));
	PlayerTileBase->TileState_ = MapObject::Player;
	PlayerS_->SetPivot({(float)_x * 100 + 50 , (float)_y * 90 +20 });
	PlayerS_->SetOrder(6);
}

bool Player::MoveCheak()
{
	if (false == GameEngineInput::GetInst()->IsDown("LeftMove") &&
		false == GameEngineInput::GetInst()->IsDown("RightMove") &&
		false == GameEngineInput::GetInst()->IsDown("UpMove") &&
		false == GameEngineInput::GetInst()->IsDown("DownMove"))
	{// 입력이 없으면
		if (CurState_ == PlayerState::Idle)//대기 상태이면
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
	if (MoveSet_ == false)
	{
		ShiftX_ = PlayerX_ * 100 + 50; // 원래위치
		ShiftY_ = PlayerY_ * 90 + 20;
		MoveSet_ = true;
	}

	if (ShiftY_ > (PlayerY_ - 1) * 90 + 20)
	{
		ShiftY_ -= 100 * GameEngineTime::GetDeltaTime() * 10.0f;
		PlayerS_->SetPivot({ ShiftX_ ,  ShiftY_ });
	}
	else if (ShiftY_ <= (PlayerY_ - 1) * 90 + 20)
	{
		MoveSet_ = false;
		MoveStart_ = false;
		MoveEnd_ = true;
	}
}
void Player::DownMoveShift()
{
	if (MoveSet_ == false)
	{
		ShiftX_ = PlayerX_ * 100 + 50; // 원래위치
		ShiftY_ = PlayerY_ * 90 + 20;
		MoveSet_ = true;
	}

	if (ShiftY_ <= (PlayerY_ + 1) * 90 + 20)
	{
		ShiftY_ += 100 * GameEngineTime::GetDeltaTime() * 10.0f;
		PlayerS_->SetPivot({ ShiftX_ ,  ShiftY_ });
	}
	else if (ShiftY_ > (PlayerY_ + 1) * 90 + 20)
	{
		MoveSet_ = false;
		MoveStart_ = false;
		MoveEnd_ = true;
	}
}

bool Player::ClearChapter()
 {
	if (TileMap_->GetTile<PlayerTile>(PlayerX_ + 1, PlayerY_) == nullptr)
	{
		return false;
	}
	else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ + 1, PlayerY_)->TileState_ == MapObject::Helper)
	{
		return true;
	}
}


void Player::PlayerPositionSet()//챕터별 플레이어 초기위치 설정
{
	if (ChapterLevel_ == 1)
	{
		Player::PlayerObject_->ReturnPlayerTileMap_()->DeleteTile(PlayerX_, PlayerY_);
		PlayerX_ = 11;
		PlayerY_ = 3;
		Player::PlayerObject_->ReturnPlayerTileMap_()->CreateTile<PlayerTile>(PlayerX_, PlayerY_, "TileBase.bmp", static_cast<int>(ORDER::BASETILE)); // 이동할곳에 새로 만들어줘라
		PlayerS_->SetPivot({ PlayerX_ * 100 + 50 , PlayerY_ * 90 + 30 });
	}

}

void Player::ReloadSet()//리로드시 플레이어 위치 및 라이프 초기화
{
	if (ChapterLevel_ == 1)
	{
		Player::PlayerObject_->ReturnPlayerTileMap_()->DeleteTile(PlayerX_, PlayerY_);
		PlayerX_ = 11;
		PlayerY_ = 3;
		Player::PlayerObject_->ReturnPlayerTileMap_()->CreateTile<PlayerTile>(PlayerX_, PlayerY_, "TileBase.bmp", static_cast<int>(ORDER::BASETILE)); // 이동할곳에 새로 만들어줘라
		PlayerS_->SetPivot({ PlayerX_ * 100 + 50 , PlayerY_ * 90 + 30 });
		LifePoint_ = 23;
		ChangeState(PlayerState::Idle);

			PlayerS_->PauseOff();

	}
}