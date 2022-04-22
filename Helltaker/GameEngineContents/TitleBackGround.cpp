#include "TitleBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>

TitleBackGround::TitleBackGround()
	:Width_(1920)
	,Hight_(1080)
	, TitleBackGroundRender_(nullptr)
{
	// Level_ = nullptr;
}

TitleBackGround::~TitleBackGround()
{
}

void TitleBackGround::Start()
{
	SetPosition({ GameEngineWindow::GetScale().Half() });
	TitleBackGroundRender_ = CreateRendererToScale("TitleBackGround.bmp", { Width_ ,Hight_ });
}
void TitleBackGround::Update()
{
	{//BackGround Size값 변하는 부분
		TitleBackGroundRender_->SetScale({ Width_, Hight_ });
		Width_ += 10.0f * GameEngineTime::GetDeltaTime();
		Hight_ += 10.0f * GameEngineTime::GetDeltaTime();
	}
}
void TitleBackGround::Render()
{
}