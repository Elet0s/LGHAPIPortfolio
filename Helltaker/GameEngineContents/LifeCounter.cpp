#include"LifeCounter.h"
#include<GameEngine/GameEngineFont.h>
#include"Player.h"
LifeCounter::LifeCounter()
	:LifeFont_()
	,LifePoint_(0)
	, LifePointStr_()
{

}
LifeCounter::~LifeCounter()
{

}

void LifeCounter::Start()
{
	LifeFont_.Load("arial.ttf");

}

void LifeCounter::Update()
{

}

void LifeCounter::Render()
{
	LifePoint_ = Player::PlayerObject_->GetLifePoint();
	LifePointStr_ = std::to_string(LifePoint_);
	if (LifePointStr_.size() == 1)
	{
		LifeFont_.Draw(LifePointStr_, { 160.0f, 730.0f }, RGB(255, 255, 255), 200, 50);
	}
	else if(LifePointStr_.size()==2)
	{
		LifeFont_.Draw(LifePointStr_, { 130.0f, 730.0f }, RGB(255, 255, 255), 200, 50);
	}

}