#include"StartText.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineInput.h>

StartText::StartText()
	:TextCount_(0)
	, StartTextRender01(nullptr)
	, StartTextRender02(nullptr)
	, StartTextRender03(nullptr)
	, StartTextRender04(nullptr)
	, StartTextRender05(nullptr)
	, StartTextRender06(nullptr)
{

}
StartText::~StartText()
{

}
void StartText::Start()
{
}
void StartText::Render()
{


}
void StartText::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("Next"))
	{
		if (TextCount_ == 0)
		{
			SetPosition({ 963,825 });
			StartTextRender01 = CreateRendererToScale("StartText01.bmp", { 834 ,135 });
			TextCount_+=1;
		}
		else if(TextCount_ == 1)
		{
			StartTextRender01->Death();
			SetPosition({ 955,815 });
			StartTextRender02 = CreateRendererToScale("StartText02.bmp", { 541 ,107 });
			TextCount_+=1;
		}
		else if (TextCount_ == 2)
		{
			StartTextRender02->Death();
			SetPosition({ 960,815 });
			StartTextRender03 = CreateRendererToScale("StartText03.bmp", { 457 ,76 });
			TextCount_ += 1;
		}
		else if (TextCount_ == 3)
		{
			StartTextRender03->Death();
			SetPosition({ 960,830 });
			StartTextRender04 = CreateRendererToScale("StartText04.bmp", { 651 ,113 });
			TextCount_ += 1;
		}
		else if (TextCount_ == 4)
		{
			StartTextRender04->Death();
			SetPosition({ 960,825 });
			StartTextRender05 = CreateRendererToScale("StartText05.bmp", { 638 ,120 });
			TextCount_ += 1;
		}
		else if (TextCount_ == 5)
		{
			StartTextRender05->Death();
			SetPosition({ 960,830 });
			StartTextRender06 = CreateRendererToScale("StartText06.bmp", { 719 ,104 });
			TextCount_ += 1;
		}
		
	}
}