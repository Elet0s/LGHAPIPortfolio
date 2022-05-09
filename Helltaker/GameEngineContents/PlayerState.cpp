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
		switch (LTUD_) {
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
		LifePoint_ -= 1;
		RLState_ = true;//true�ϱ� ����

		if (TileMap_->GetTile<PlayerTile>(PlayerX_ - 1, PlayerY_) == nullptr)//�̵��������� ������Ʈ�� ������
		{
			PlayerS_->ChangeAnimation("PlayerMoveL");//�̵�������� �ٲ���

			if (MoveEnd_ == false) // ������ �̵�ȿ�� ��� ��������
			{
				MoveStart_ = true;
				LTUD_ = 1;
			}
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ - 1, PlayerY_)->TileState_ == MapObject::Monster)//�����̸�
		{
			ChangeState(PlayerState::Kick);//�÷��̾� ű ���
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ - 1, PlayerY_); //���� ������Ʈ Ÿ�� ȣ��.
			TileChanger_->IsLKick_ = true;// ���;� �� �����ʿ��� ������
		
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ - 1, PlayerY_)->TileState_ == MapObject::Ston)
		{
			ChangeState(PlayerState::Kick);
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ - 1, PlayerY_);
			TileChanger_->IsLKick_ = true;
		}
	}


	else if (true == GameEngineInput::GetInst()->IsDown("RightMove"))
	{
		LifePoint_ -= 1;
		RLState_ = false;
		if (TileMap_->GetTile<PlayerTile>(PlayerX_ + 1, PlayerY_) == nullptr)//�̵��������� ������Ʈ�� ������
		{
			PlayerS_->ChangeAnimation("PlayerMoveR");//�̵�������� �ٲ���

			if (MoveEnd_ == false) // ������ �̵�ȿ�� ��� ��������
			{
				MoveStart_ = true;
				LTUD_ = 2;
			}
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ + 1, PlayerY_)->TileState_ == MapObject::Monster)//�����̸�
		{
			ChangeState(PlayerState::Kick);//�÷��̾� ű ���
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ + 1, PlayerY_); //���� ������Ʈ Ÿ�� ȣ��.
			TileChanger_->IsRKick_ = true;// ���;� �� ���ʿ��� ������
			
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ + 1, PlayerY_)->TileState_ == MapObject::Ston)
		{
			ChangeState(PlayerState::Kick);
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ + 1, PlayerY_); 
			TileChanger_->IsRKick_ = true;
		}
	}


	else if (true == GameEngineInput::GetInst()->IsDown("UpMove"))
	{
		LifePoint_ -= 1;
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

			if (MoveEnd_ == false) 
			{
				MoveStart_ = true;
				LTUD_ = 3;
			}
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ , PlayerY_ - 1)->TileState_ == MapObject::Monster)//�����̸�
		{
			ChangeState(PlayerState::Kick);//�÷��̾� ű ���
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ , PlayerY_ - 1); //���� ������Ʈ Ÿ�� ȣ��.
			TileChanger_->IsUKick_ = true;// ���;� �� �Ʒ����� ������

		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ , PlayerY_-1)->TileState_ == MapObject::Ston)
		{
			ChangeState(PlayerState::Kick);
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_, PlayerY_ - 1); 
			TileChanger_->IsUKick_ = true;
		}
	}


	else if (true == GameEngineInput::GetInst()->IsDown("DownMove"))
	{
		LifePoint_ -= 1;
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

			if (MoveEnd_ == false)
			{
				MoveStart_ = true;
				LTUD_ = 4;
			}
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_, PlayerY_ + 1)->TileState_ == MapObject::Monster)//�����̸�
		{
			ChangeState(PlayerState::Kick);//�÷��̾� ű ���
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_, PlayerY_ + 1); //���� ������Ʈ Ÿ�� ȣ��.
			TileChanger_->IsDKick_ = true;// ���;� �� ������ ������
		}
		else if (GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_, PlayerY_ + 1)->TileState_ == MapObject::Ston)
		{
			ChangeState(PlayerState::Kick);
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

}
void Player::WinUpdate()
{

}