#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngine.h>

#include"LodingNext.h"

LodingNext::LodingNext()
	:LodingNextRender_(nullptr)
{

}
LodingNext::~LodingNext()
{

}
void LodingNext::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	LodingNextRender_ = CreateRenderer();
	LodingNextRender_->CreateFolderAnimation("Loding", "LodingNext", 19, 27, 0.04f, false);
	LodingNextRender_->ChangeAnimation("LodingNext");
}
void LodingNext::Update()
{
	if (LodingNextRender_->IsEndAnimation())
	{
		Death();
	}
}