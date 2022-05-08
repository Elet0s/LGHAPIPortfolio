#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include<GameEngineBase/GameEngineInput.h>
#include<GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineLevel.h> 

Player::Player()
	: Speed_(150.0f)
	, LifePoint_(0)
,	CurState_(PlayerState::Idle)
{
}

Player::~Player()
{
}

void Player::Start()
{
	SetPosition({ 1160,290 });
	PlayerRender_ = CreateRendererToScale("PlayerLeft.bmp", { 100 ,100 });
	PlayerRender_->CreateAnimation("PlayerLeft.bmp", "PlayerLeft", 0, 11, 0.065f, true);
	PlayerRender_->CreateAnimation("PlayerRight.bmp", "PlayerRight", 0, 11, 0.065f, true);
	PlayerRender_->CreateAnimation("PlayerMoveL.bmp", "PlayerMoveL", 0, 5, 0.065f, true);
	PlayerRender_->CreateAnimation("PlayerMoveR.bmp", "PlayerMoveR", 0, 5, 0.065f, true);
	PlayerRender_->CreateAnimation("PlayerKickL.bmp", "PlayerKickL", 0, 12, 0.065f, true);
	PlayerRender_->CreateAnimation("PlayerKickR.bmp", "PlayerKickR", 0, 12, 0.065f, true);

	KeySet();
;
}
void Player::Update()
{
	StateUpdate();
}
void Player::Render()
{

}
void Player::ChangeState(PlayerState _State) //Ư�� ������ �����ϸ� ȣ���Ͽ� ���¸� �ٲ���
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
void Player::StateUpdate()// ��� ���¸� üũ�ϸ鼭 ���� ���¿� �´� ������Ʈ�� ����
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
void Player::ColSet(int _ChapterCount) // é�Ϳ��� ȣ���Ͽ� ������ �°� �ݸ����� �� ���� ����
{	
	if(_ChapterCount==1)
	{

		ChapterCol_ = GameEngineImageManager::GetInst()->Find("ChapterBG01C.bmp");
		LifePoint_ = 23;
	}

}
void Player::KeySet() // Ű����
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