#include "TitleLogo.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>

TitleLogo::TitleLogo()
: Width_(460)
, Hight_(230)
, FadeCount_(150)
, FadeReverce_(false)
, TitleLogoRender_(nullptr)
{
}

TitleLogo::~TitleLogo()
{
}



void TitleLogo::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	TitleLogoRender_ = CreateRendererToScale("TitleLogo.bmp", { Width_, Hight_ });
}

void TitleLogo::Update()
{
	{//Logo Alpha값 변하는 부분
		TitleLogoRender_->SetAlpha(FadeCount_);
		if (FadeReverce_ == false)
		{
			if (FadeCount_ <= 255)
			{
				FadeCount_ += 180.0f * GameEngineTime::GetDeltaTime();
			}
			else
			{
				FadeReverce_ = true;
			}
		}
		else if (FadeReverce_ == true)
		{
			if (FadeCount_ >= 0)
			{
				FadeCount_ -= 180.0f * GameEngineTime::GetDeltaTime();
			}
		}
	}
	{//Logo Size값 변하는 부분
		TitleLogoRender_->SetScale({ Width_, Hight_ });
		Width_ += 5.0f * GameEngineTime::GetDeltaTime();
		Hight_ += 5.0f * GameEngineTime::GetDeltaTime();
	}
}
void TitleLogo::Render()
{
}
