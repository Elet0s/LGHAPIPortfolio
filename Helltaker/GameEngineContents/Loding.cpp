#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineSound.h>
#include"Loding.h"


Loding::Loding()
	:LodingRender_(nullptr)
{

}
Loding::~Loding()
{

}
void Loding::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half() );
	LodingRender_ = CreateRenderer();
	LodingRender_->CreateFolderAnimation("Loding", "Loding", 0, 19, 0.04f, false);
	LodingRender_->ChangeAnimation("Loding");
	GameEngineSound::SoundPlayOneShot("Loding.wav", 0);
}
void Loding::Update()
{
	if (LodingRender_->IsEndAnimation())
	{
		GameEngine::GetInst().ChangeLevel("Chapter01");
	}
}
