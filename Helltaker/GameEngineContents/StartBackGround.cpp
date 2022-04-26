#include"StartBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineInput.h>

StartBackGround::StartBackGround()
	:BgCount_(0)
	,StartBackGround01_(nullptr)
{

}
StartBackGround::~StartBackGround()
{

}
void StartBackGround::Start()
{
	SetPosition({ 960,430 });
}
void StartBackGround::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("Next")) {
		if (BgCount_ == 0)
		{
			StartBackGround01_ = CreateRendererToScale("StartEvent01.bmp", { 1280  ,652 });
			BgCount_ += 1;
		}
		else if (BgCount_ == 1)
		{
			StartBackGround01_ = CreateRendererToScale("StartEvent02.bmp", { 1280  ,652 });
			BgCount_ += 1;
		}
		else if (BgCount_ == 2) {
			StartBackGround01_ = CreateRendererToScale("StartEvent03.bmp", { 1280  ,652 });
			BgCount_ += 1;
		}
	}
}