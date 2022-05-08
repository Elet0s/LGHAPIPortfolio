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
				PlayerS_->SetPivot({ PlayerX_ * 100 + 50 , PlayerY_ * 90 +20 });
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
		else if (TileMap_->GetTile<PlayerTile>(PlayerX_ - 1, PlayerY_)->TileState_ == MapObject::Monster)//�����̸�
		{
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ - 1, PlayerY_); //���� ������Ʈ Ÿ�� ȣ��.
			TileChanger_->TileObjectX_ - 1;
			TileChanger_->IsLKick_ = true;// ű�ϰ� ���� ������
					//PlayerS_->ChangeAnimation("PlayerKickL");
		}
		else if (TileMap_->GetTile<PlayerTile>(PlayerX_ - 1, PlayerY_)->TileState_ == MapObject::Ston)
		{

		}
	}


	else if (true == GameEngineInput::GetInst()->IsDown("RightMove"))
	{
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
		else if (TileMap_->GetTile<PlayerTile>(PlayerX_ + 1, PlayerY_)->TileState_ == MapObject::Monster)//�����̸�
		{
			GameObjectTile* TileChanger_ = GameObjectManager::GameObjectManager_->ReturnGameTileObejctMap_()->GetTile<GameObjectTile>(PlayerX_ + 1, PlayerY_); //���� ������Ʈ Ÿ�� ȣ��.
			TileChanger_->TileObjectX_ + 1;
			TileChanger_->IsLKick_ = true;// ű�ϰ� ���� ������
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

	//�÷��̾� ��ǥ���� �̵� �ϴ� Ÿ�� Ȯ��
	//Ÿ�Ͼ��� ���빰�� ���� �ٸ� �ൿ
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