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

	if (LifePoint_ <= 0)
	{
		ChangeState(PlayerState::Win);
		return;
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
		switch (LTUD_) 
		{
		case 1:

			LeftMoveShift();
			if (MoveEnd_ == true)// 랜더러 이동효과 끝났으면
			{
				Player::PlayerObject_->ReturnPlayerTileMap_()->DeleteTile(PlayerX_, PlayerY_);
				PlayerX_ -= 1; // 이동한곳에 맞게 변수 바꿔주고
				Player::PlayerObject_->ReturnPlayerTileMap_()->CreateTile<PlayerTile>(PlayerX_, PlayerY_, "TileBase.bmp", static_cast<int>(ORDER::BASETILE)); // 이동할곳에 새로 만들어줘라
				PlayerS_->SetPivot({ PlayerX_ * 100 + 50 , PlayerY_ * 90 +30 });
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
				PlayerS_->SetPivot({ PlayerX_ * 100 + 50 , PlayerY_ * 90 + 30 });
				MoveEnd_ = false;
				ChangeState(PlayerState::Idle);
				LifePoint_ -= 1;
			}
			break;

		case 3:

			UpMoveShift();
			if (MoveEnd_ == true)// 랜더러 이동효과 끝났으면
			{
				Player::PlayerObject_->ReturnPlayerTileMap_()->DeleteTile(PlayerX_, PlayerY_);
				PlayerY_ -= 1; // 이동한곳에 맞게 변수 바꿔주고
				Player::PlayerObject_->ReturnPlayerTileMap_()->CreateTile<PlayerTile>(PlayerX_, PlayerY_, "TileBase.bmp", static_cast<int>(ORDER::BASETILE)); // 이동할곳에 새로 만들어줘라
				PlayerS_->SetPivot({ PlayerX_ * 100 + 50 , PlayerY_ * 90 + 30 });
				MoveEnd_ = false;
				ChangeState(PlayerState::Idle);
				LifePoint_ -= 1;
			}
			break;

		case 4:

			DownMoveShift();
			if (MoveEnd_ == true)// 랜더러 이동효과 끝났으면
			{
				Player::PlayerObject_->ReturnPlayerTileMap_()->DeleteTile(PlayerX_, PlayerY_);
				PlayerY_ += 1; // 이동한곳에 맞게 변수 바꿔주고
				Player::PlayerObject_->ReturnPlayerTileMap_()->CreateTile<PlayerTile>(PlayerX_, PlayerY_, "TileBase.bmp", static_cast<int>(ORDER::BASETILE)); // 이동할곳에 새로 만들어줘라
				PlayerS_->SetPivot({ PlayerX_ * 100 + 50 , PlayerY_ * 90 + 30 });
				MoveEnd_ = false;
				ChangeState(PlayerState::Idle);
				LifePoint_ -= 1;
			}
			break;

		}
	}


	if (true == GameEngineInput::GetInst()->IsDown("LeftMove"))
	{
		RLState_ = true;//true니까 왼쪽
		
		if (TileMap_->GetTile<PlayerTile>(PlayerX_ - 1, PlayerY_) == nullptr)//이동할지점에 오브젝트가 없으면
		{
			PlayerS_->ChangeAnimation("PlayerMoveL");//이동모션으로 바꿔줌
			GameEngineSound::SoundPlayOneShot("PlayerMove.wav", 0);
			if (MoveEnd_ == false) // 랜더러 이동효과 재생 안했으면
			{
				MoveStart_ = true;
				LTUD_ = 1;
			}
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ - 1, PlayerY_)->TileState_ == MapObject::Monster)//몬스터이면
		{
			LifePoint_ -= 1;
			ChangeState(PlayerState::Kick);//플레이어 킥 재생
			GameEngineSound::SoundPlayOneShot("MonsterKick.wav", 0);
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ - 1, PlayerY_); //게임 오브젝트 타일 호출.
			TileChanger_->IsLKick_ = true;//몬스터야 너 오른쪽에서 차였어
			
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ - 1, PlayerY_)->TileState_ == MapObject::Ston)
		{
			LifePoint_ -= 1;
			ChangeState(PlayerState::Kick);
			GameEngineSound::SoundPlayOneShot("StoneKick.wav", 0);
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ - 1, PlayerY_);
			TileChanger_->IsLKick_ = true;
		}
	}


	else if (true == GameEngineInput::GetInst()->IsDown("RightMove"))
	{
		RLState_ = false;
		if (TileMap_->GetTile<PlayerTile>(PlayerX_ + 1, PlayerY_) == nullptr)//이동할지점에 오브젝트가 없으면
		{
			PlayerS_->ChangeAnimation("PlayerMoveR");//이동모션으로 바꿔줌
			GameEngineSound::SoundPlayOneShot("PlayerMove.wav", 0);
			if (MoveEnd_ == false) // 랜더러 이동효과 재생 안했으면
			{
				MoveStart_ = true;
				LTUD_ = 2;
			}
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ + 1, PlayerY_)->TileState_ == MapObject::Monster)//몬스터이면
		{
			LifePoint_ -= 1;
			ChangeState(PlayerState::Kick);//플레이어 킥 재생
			GameEngineSound::SoundPlayOneShot("MonsterKick.wav", 0);
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ + 1, PlayerY_); //게임 오브젝트 타일 호출.
			TileChanger_->IsRKick_ = true;// 몬스터야 너 왼쪽에서 차였어
			
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ + 1, PlayerY_)->TileState_ == MapObject::Ston)
		{
			LifePoint_ -= 1;
			ChangeState(PlayerState::Kick);
			GameEngineSound::SoundPlayOneShot("StoneKick.wav", 0);
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ + 1, PlayerY_); 
			TileChanger_->IsRKick_ = true;
		}
	}


	else if (true == GameEngineInput::GetInst()->IsDown("UpMove"))
	{
		if (TileMap_->GetTile<PlayerTile>(PlayerX_ , PlayerY_ -1) == nullptr)
		{
			if (RLState_ == true)
			{
				PlayerS_->ChangeAnimation("PlayerMoveL");
			}
			else if (RLState_ == false)
			{
				PlayerS_->ChangeAnimation("PlayerMoveR");
			}
			GameEngineSound::SoundPlayOneShot("PlayerMove.wav", 0);
			if (MoveEnd_ == false) 
			{
				MoveStart_ = true;
				LTUD_ = 3;
			}
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ , PlayerY_ - 1)->TileState_ == MapObject::Monster)//몬스터이면
		{
			LifePoint_ -= 1;
			ChangeState(PlayerState::Kick);//플레이어 킥 재생
			GameEngineSound::SoundPlayOneShot("MonsterKick.wav", 0);
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ , PlayerY_ - 1); //게임 오브젝트 타일 호출.
			TileChanger_->IsUKick_ = true;// 몬스터야 너 아래에서 차였어

		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ , PlayerY_-1)->TileState_ == MapObject::Ston)
		{
			LifePoint_ -= 1;
			ChangeState(PlayerState::Kick);
			GameEngineSound::SoundPlayOneShot("StoneKick.wav", 0);
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_, PlayerY_ - 1); 
			TileChanger_->IsUKick_ = true;
		}
	}


	else if (true == GameEngineInput::GetInst()->IsDown("DownMove"))
	{
		if (TileMap_->GetTile<PlayerTile>(PlayerX_, PlayerY_ + 1) == nullptr)
		{
			if (RLState_ == true)
			{
				PlayerS_->ChangeAnimation("PlayerMoveL");
			}
			else if (RLState_ == false)
			{
				PlayerS_->ChangeAnimation("PlayerMoveR");
			}
			GameEngineSound::SoundPlayOneShot("PlayerMove.wav", 0);
			if (MoveEnd_ == false)
			{
				MoveStart_ = true;
				LTUD_ = 4;
			}
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_, PlayerY_ + 1)->TileState_ == MapObject::Monster)//몬스터이면
		{
			LifePoint_ -= 1;
			ChangeState(PlayerState::Kick);//플레이어 킥 재생
			GameEngineSound::SoundPlayOneShot("MonsterKick.wav", 0);
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_, PlayerY_ + 1); //게임 오브젝트 타일 호출.
			TileChanger_->IsDKick_ = true;// 몬스터야 너 위에서 차였어
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_, PlayerY_ + 1)->TileState_ == MapObject::Ston)
		{
			LifePoint_ -= 1;
			ChangeState(PlayerState::Kick);
			GameEngineSound::SoundPlayOneShot("StoneKick.wav", 0);
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_, PlayerY_ + 1);
			TileChanger_->IsDKick_ = true;
		}
	}

	//플레이어 좌표기준 이동 하는 타일 확인
	//타일안의 내용물에 따라 다른 행동
}

void Player::KickStart()
{
	if (RLState_ == true)
	{
		PlayerS_->ChangeAnimation("PlayerKickL");
	}
	else if (RLState_ == false)
	{
		PlayerS_->ChangeAnimation("PlayerKickR");
	}
	
}
void Player::KickUpdate()
{
		if (PlayerS_->IsEndAnimation() == true)
		{
			ChangeState(PlayerState::Idle);
		}
}
void Player::DieStart()
{

}
void Player::DieUpdate()
{

}
void Player::WinStart()
{
	PlayerS_->ChangeAnimation("PlayerWinPlay");
}
void Player::WinUpdate()
{
	if (PlayerS_->IsEndAnimation() == true)
	{
		PlayerS_->PauseOn();
	}
}