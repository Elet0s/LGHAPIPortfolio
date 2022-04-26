#include"BeelFly.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>

BeelFly::BeelFly()
	: Width_(1911)
	, Hight_(748)
	, BeelFlyRender_(nullptr)
{

}

BeelFly::~BeelFly()
{

}

void BeelFly::Start()
{
	SetPosition({ 1005,375 });
	BeelFlyRender_ = CreateRendererToScale("BeelFly.bmp", { Width_ ,Hight_ });
	BeelFlyRender_->SetScale({ Width_, Hight_ });

}

void BeelFly::Render()
{

}		
void BeelFly::DeathActor()
{
	Death();
}