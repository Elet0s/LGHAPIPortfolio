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
void Player::IdleStart()
{
	// �ִϸ��̼��� �ٲ��.

	// AnimationName = "Idle_"
}
void Player::IdleUpdate()
{
	PlayerRender_->ChangeAnimation("PlayerLeft");
}

void Player::MoveStart()
{

}

void Player::MoveUpdate()
{

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