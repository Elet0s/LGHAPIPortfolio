#include"Booper.h"
#include <GameEngine/GameEngineRenderer.h>

Booper::Booper()
	:BooperRender_(nullptr)
{

}
Booper::~Booper()
{

}

void Booper::Start()
{
	SetPosition({ 960,930 });
	BooperRender_ = CreateRendererToScale("Booper.bmp", { 100 ,100 });
	BooperRender_->CreateAnimation("Booper.bmp", "Booper", 0, 16, 0.04f, true);
	BooperRender_->ChangeAnimation("Booper");
}
void Booper::Update()
{

}