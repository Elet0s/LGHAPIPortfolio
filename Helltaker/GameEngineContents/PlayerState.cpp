#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineLevel.h> // ������ ���ؼ�

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
	if (MoveStart_ == true)//������ �̵�ȿ��
	{
		switch (LTUD_) 
		{
		case 1:

			LeftMoveShift();
			if (MoveEnd_ == true)// ������ �̵�ȿ�� ��������
			{
				Player::PlayerObject_->ReturnPlayerTileMap_()->DeleteTile(PlayerX_, PlayerY_);
				PlayerX_ -= 1; // �̵��Ѱ��� �°� ���� �ٲ��ְ�
				Player::PlayerObject_->ReturnPlayerTileMap_()->CreateTile<PlayerTile>(PlayerX_, PlayerY_, "TileBase.bmp", static_cast<int>(ORDER::BASETILE)); // �̵��Ұ��� ���� ��������
				PlayerS_->SetPivot({ PlayerX_ * 100 + 50 , PlayerY_ * 90 +30 });
				MoveEnd_ = false;
				ChangeState(PlayerState::Idle);
				LifePoint_ -= 1;
			}
			break;

		case 2:

			RightMoveShift();
			if (MoveEnd_ == true)// ������ �̵�ȿ�� ��������
			{
				Player::PlayerObject_->ReturnPlayerTileMap_()->DeleteTile(PlayerX_, PlayerY_);
				PlayerX_ += 1; // �̵��Ѱ��� �°� ���� �ٲ��ְ�
				Player::PlayerObject_->ReturnPlayerTileMap_()->CreateTile<PlayerTile>(PlayerX_, PlayerY_, "TileBase.bmp", static_cast<int>(ORDER::BASETILE)); // �̵��Ұ��� ���� ��������
				PlayerS_->SetPivot({ PlayerX_ * 100 + 50 , PlayerY_ * 90 + 30 });
				MoveEnd_ = false;
				ChangeState(PlayerState::Idle);
				LifePoint_ -= 1;
			}
			break;

		case 3:

			UpMoveShift();
			if (MoveEnd_ == true)// ������ �̵�ȿ�� ��������
			{
				Player::PlayerObject_->ReturnPlayerTileMap_()->DeleteTile(PlayerX_, PlayerY_);
				PlayerY_ -= 1; // �̵��Ѱ��� �°� ���� �ٲ��ְ�
				Player::PlayerObject_->ReturnPlayerTileMap_()->CreateTile<PlayerTile>(PlayerX_, PlayerY_, "TileBase.bmp", static_cast<int>(ORDER::BASETILE)); // �̵��Ұ��� ���� ��������
				PlayerS_->SetPivot({ PlayerX_ * 100 + 50 , PlayerY_ * 90 + 30 });
				MoveEnd_ = false;
				ChangeState(PlayerState::Idle);
				LifePoint_ -= 1;
			}
			break;

		case 4:

			DownMoveShift();
			if (MoveEnd_ == true)// ������ �̵�ȿ�� ��������
			{
				Player::PlayerObject_->ReturnPlayerTileMap_()->DeleteTile(PlayerX_, PlayerY_);
				PlayerY_ += 1; // �̵��Ѱ��� �°� ���� �ٲ��ְ�
				Player::PlayerObject_->ReturnPlayerTileMap_()->CreateTile<PlayerTile>(PlayerX_, PlayerY_, "TileBase.bmp", static_cast<int>(ORDER::BASETILE)); // �̵��Ұ��� ���� ��������
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
		RLState_ = true;//true�ϱ� ����
		
		if (TileMap_->GetTile<PlayerTile>(PlayerX_ - 1, PlayerY_) == nullptr)//�̵��������� ������Ʈ�� ������
		{
			PlayerS_->ChangeAnimation("PlayerMoveL");//�̵�������� �ٲ���
			GameEngineSound::SoundPlayOneShot("PlayerMove.wav", 0);
			if (MoveEnd_ == false) // ������ �̵�ȿ�� ��� ��������
			{
				MoveStart_ = true;
				LTUD_ = 1;
			}
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ - 1, PlayerY_)->TileState_ == MapObject::Monster)//�����̸�
		{
			LifePoint_ -= 1;
			ChangeState(PlayerState::Kick);//�÷��̾� ű ���
			GameEngineSound::SoundPlayOneShot("MonsterKick.wav", 0);
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ - 1, PlayerY_); //���� ������Ʈ Ÿ�� ȣ��.
			TileChanger_->IsLKick_ = true;//���;� �� �����ʿ��� ������
			
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
		if (TileMap_->GetTile<PlayerTile>(PlayerX_ + 1, PlayerY_) == nullptr)//�̵��������� ������Ʈ�� ������
		{
			PlayerS_->ChangeAnimation("PlayerMoveR");//�̵�������� �ٲ���
			GameEngineSound::SoundPlayOneShot("PlayerMove.wav", 0);
			if (MoveEnd_ == false) // ������ �̵�ȿ�� ��� ��������
			{
				MoveStart_ = true;
				LTUD_ = 2;
			}
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ + 1, PlayerY_)->TileState_ == MapObject::Monster)//�����̸�
		{
			LifePoint_ -= 1;
			ChangeState(PlayerState::Kick);//�÷��̾� ű ���
			GameEngineSound::SoundPlayOneShot("MonsterKick.wav", 0);
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ + 1, PlayerY_); //���� ������Ʈ Ÿ�� ȣ��.
			TileChanger_->IsRKick_ = true;// ���;� �� ���ʿ��� ������
			
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
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ , PlayerY_ - 1)->TileState_ == MapObject::Monster)//�����̸�
		{
			LifePoint_ -= 1;
			ChangeState(PlayerState::Kick);//�÷��̾� ű ���
			GameEngineSound::SoundPlayOneShot("MonsterKick.wav", 0);
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ , PlayerY_ - 1); //���� ������Ʈ Ÿ�� ȣ��.
			TileChanger_->IsUKick_ = true;// ���;� �� �Ʒ����� ������

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
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_, PlayerY_ + 1)->TileState_ == MapObject::Monster)//�����̸�
		{
			LifePoint_ -= 1;
			ChangeState(PlayerState::Kick);//�÷��̾� ű ���
			GameEngineSound::SoundPlayOneShot("MonsterKick.wav", 0);
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_, PlayerY_ + 1); //���� ������Ʈ Ÿ�� ȣ��.
			TileChanger_->IsDKick_ = true;// ���;� �� ������ ������
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

	//�÷��̾� ��ǥ���� �̵� �ϴ� Ÿ�� Ȯ��
	//Ÿ�Ͼ��� ���빰�� ���� �ٸ� �ൿ
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