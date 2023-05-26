#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngineBase/GameEngineInput.h>
#include<GameEngineContents/ContentsEnums.h>
#include"LodingManager.h"

LodingManager::LodingManager()
	:LodingStartRender_(nullptr),
	LodingEndRender_(nullptr),
	SafeLoding_(false),
	ChapterReload_(false)
{

}
LodingManager::~LodingManager()
{

}

void LodingManager::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());

	LodingStartRender_ = CreateRenderer();
	LodingStartRender_->CreateFolderAnimation("Loding", "LodingStart", 0, 19, 0.04f, false);
	LodingStartRender_->ChangeAnimation("LodingStart");
	LodingStartRender_->PauseOn();
	LodingStartRender_->Off();

	LodingEndRender_ = CreateRenderer();
	LodingEndRender_->CreateFolderAnimation("Loding", "LodingEnd", 19, 27, 0.04f, false);
	LodingEndRender_->ChangeAnimation("LodingEnd");
	LodingEndRender_->PauseOn();
	LodingEndRender_->Off();
}

void LodingManager::Update()
{
	if (LodingStartRender_->IsEndAnimation() == true) 
	{
		if (ChapterReload_ == false)
		{
			Reload();
			if (this->GetLevel()->GetNameConstRef() == "MenuLevel")
			{
				GameEngine::GetInst().ChangeLevel("Chapter01");
			}
			else if (this->GetLevel()->GetNameConstRef() == "Chapter01")
			{
				GameEngine::GetInst().ChangeLevel("Chapter02");
			}
			else if (this->GetLevel()->GetNameConstRef() == "Chapter02")
			{
				GameEngine::GetInst().ChangeLevel("Chapter03");
			}
		}
		if (ChapterReload_ == true)
		{
			Reload();
			Shoot("End");
			ChapterReload_ = false;
		}
	}
	if (LodingEndRender_->IsEndAnimation() == true)
	{
		Reload();
	}

	if (true == GameEngineInput::GetInst()->IsDown("Reload") && SafeLoding_ == false)
	{
		Shoot("All");
	}
}

void LodingManager::Shoot(const std::string& _Text)
{
	if (_Text == "Start")
	{
		if (LodingStartRender_->IsUpdate() == false)//랜더러꺼져있으면 켜주기
		{
			LodingStartRender_->On();
		}
		if (LodingStartRender_->IsPause() == true)// 멈춰있다면 
		{
			LodingStartRender_->PauseOff(); //움직이고
			GameEngineSound::SoundPlayOneShot("Loding.wav", 0);
		}

		SafeLoding_ = true;
	}
	else if (_Text == "End")
	{
		if (LodingEndRender_->IsUpdate() == false)//랜더러꺼져있으면 켜주기
		{
			LodingEndRender_->On();
		}
		if (LodingEndRender_->IsPause() == true)// 멈춰있다면 
		{
			LodingEndRender_->PauseOff(); //움직이고
			GameEngineSound::SoundPlayOneShot("LodingN.wav", 0);
		}

		SafeLoding_ = true;
	}
	else if (_Text == "All")
	{
		if (LodingStartRender_->IsUpdate() == false)//랜더러꺼져있으면 켜주기
		{
			LodingStartRender_->On();
		}
		if (LodingStartRender_->IsPause() == true)// 멈춰있다면 
		{
			LodingStartRender_->PauseOff(); //움직이고
			GameEngineSound::SoundPlayOneShot("Loding.wav", 0);
		}
		ChapterReload_ = true;
		SafeLoding_ = true;
	}
}

void LodingManager::Reload()
{
	if (LodingStartRender_->IsUpdate() == true)//업데이트 돌고있다면 꺼주기
	{
		LodingStartRender_->Off();
	}
	if (LodingStartRender_->IsPause() == false)// 멈추지 않았다면
	{
		LodingStartRender_->PauseOn(); //멈추고
		LodingStartRender_->FrameReset();//프레임 리셋
	}

	if (LodingEndRender_->IsUpdate() == true)//업데이트 돌고있다면 꺼주기
	{
		LodingEndRender_->Off();
	}
	if (LodingEndRender_->IsPause() == false)// 멈추지 않았다면
	{
		LodingEndRender_->PauseOn(); //멈추고
		LodingEndRender_->FrameReset();//프레임 리셋
	}
	SafeLoding_ = false;
}