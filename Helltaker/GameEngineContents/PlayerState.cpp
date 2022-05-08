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
void Player::IdleStart()
{
	// 애니메이션이 바뀐다.

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