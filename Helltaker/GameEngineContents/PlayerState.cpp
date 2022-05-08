#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineLevel.h> // 레벨을 통해서

#include "Player.h"
#include "ChapterBackGound.h"
#include "ContentsEnums.h"
#include "GameObjectManager.h"
void Player::IdleStart()
{

}
void Player::IdleUpdate()
{
	if (RLState_ == true)
	{
		PlayerS_->ChangeAnimation("PlayerLeft");
	}
	else if (RLState_ == false)
	{
		PlayerS_->ChangeAnimation("PlayerRight");
	}

	if (MoveCheak() == true)
	{
		ChangeState(PlayerState::Move);
		MoveUpdate();
		return;
	}
}

void Player::MoveStart()
{

}

void Player::MoveUpdate()
{

	if (MoveStart_ == true)//랜더러 이동효과
	{
		switch (LTUD_) {
		case 1:

			LeftMoveShift();
			if (MoveEnd_ == true)// 랜더러 이동효과 끝났으면
			{
				Player::PlayerObject_->ReturnPlayerTileMap_()->DeleteTile(PlayerX_, PlayerY_);
				PlayerX_ -= 1; // 이동한곳에 맞게 변수 바꿔주고
				Player::PlayerObject_->ReturnPlayerTileMap_()->CreateTile<PlayerTile>(PlayerX_, PlayerY_, "TileBase.bmp", static_cast<int>(ORDER::BASETILE)); // 이동할곳에 새로 만들어줘라
				PlayerS_->SetPivot({ PlayerX_ * 100 + 50 , PlayerY_ * 90 +20 });
				MoveEnd_ = false;
				ChangeState(PlayerState::Idle);
				LifePoint_ -= 1;
			}
			break;

		case 2:

			RightMoveShift();
			if (MoveEnd_ == true)// 랜더러 이동효과 끝났으면
			{
				Player::PlayerObject_->ReturnPlayerTileMap_()->DeleteTile(PlayerX_, PlayerY_);
				PlayerX_ += 1; // 이동한곳에 맞게 변수 바꿔주고
				Player::PlayerObject_->ReturnPlayerTileMap_()->CreateTile<PlayerTile>(PlayerX_, PlayerY_, "TileBase.bmp", static_cast<int>(ORDER::BASETILE)); // 이동할곳에 새로 만들어줘라
				PlayerS_->SetPivot({ PlayerX_ * 100 + 50 , PlayerY_ * 90 + 20 });
				MoveEnd_ = false;
				ChangeState(PlayerState::Idle);
				LifePoint_ -= 1;
			}
			break;

		case 3:

			UpMoveShift();
			break;

		case 4:

			DownMoveShift();
			break;

		}
	}


	if (true == GameEngineInput::GetInst()->IsDown("LeftMove"))
	{
		RLState_ = true;//true니까 왼쪽

		if (TileMap_->GetTile<PlayerTile>(PlayerX_ - 1, PlayerY_) == nullptr)//이동할지점에 오브젝트가 없으면
		{
			PlayerS_->ChangeAnimation("PlayerMoveL");//이동모션으로 바꿔줌

			if (MoveEnd_ == false) // 랜더러 이동효과 재생 안했으면
			{
				MoveStart_ = true;
				LTUD_ = 1;
			}
		}
		else if (TileMap_->GetTile<PlayerTile>(PlayerX_ - 1, PlayerY_)->TileState_ == MapObject::Monster)//몬스터이면
		{
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ - 1, PlayerY_); //게임 오브젝트 타일 호출.
			TileChanger_->TileObjectX_ - 1;
			TileChanger_->IsLKick_ = true;// 킥하고 몬스터 지워짐
					//PlayerS_->ChangeAnimation("PlayerKickL");
		}
		else if (TileMap_->GetTile<PlayerTile>(PlayerX_ - 1, PlayerY_)->TileState_ == MapObject::Ston)
		{

		}
	}


	else if (true == GameEngineInput::GetInst()->IsDown("RightMove"))
	{
		RLState_ = false;
		if (TileMap_->GetTile<PlayerTile>(PlayerX_ + 1, PlayerY_) == nullptr)//이동할지점에 오브젝트가 없으면
		{
			PlayerS_->ChangeAnimation("PlayerMoveR");//이동모션으로 바꿔줌

			if (MoveEnd_ == false) // 랜더러 이동효과 재생 안했으면
			{
				MoveStart_ = true;
				LTUD_ = 2;
			}
		}
		else if (TileMap_->GetTile<PlayerTile>(PlayerX_ + 1, PlayerY_)->TileState_ == MapObject::Monster)//몬스터이면
		{
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ + 1, PlayerY_); //게임 오브젝트 타일 호출.
			TileChanger_->TileObjectX_ + 1;
			TileChanger_->IsLKick_ = true;// 킥하고 몬스터 지워짐
					//PlayerS_->ChangeAnimation("PlayerKickL");
		}
		else if (TileMap_->GetTile<PlayerTile>(PlayerX_ - 1, PlayerY_)->TileState_ == MapObject::Ston)
		{

		}
	}


	else if (true == GameEngineInput::GetInst()->IsDown("UpMove"))
	{

	}


	else if (true == GameEngineInput::GetInst()->IsDown("DownMove"))
	{

	}

	//플레이어 좌표기준 이동 하는 타일 확인
	//타일안의 내용물에 따라 다른 행동
}

void Player::KickStart()
{

}
void Player::KickUpdate()
{

}
void Player::DieStart()
{

}
void Player::DieUpdate()
{

}
void Player::WinStart()
{

}
void Player::WinUpdate()
{

}