#include"MenuSelcet.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineInput.h>
#include<GameEngineContents/MenuLevel.h>

MenuSelcet::MenuSelcet()
	: MenuSelcetCount_(1)
	, MenuSelcetRenderer01_(nullptr)
	, MenuSelcetRenderer02_(nullptr)
	, MenuSelcetRenderer03_(nullptr)

{

}
MenuSelcet::~MenuSelcet()
{

}
void MenuSelcet::Start()
{
	SetPosition({ 959,881 });
	MenuSelcetRenderer01_ = CreateRendererToScale("MenuSelect01.bmp", { 968 ,312 });
}

void MenuSelcet::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("SelectUp"))
	{
		if(MenuSelcetCount_ > 1)
		{
			MenuSelcetCount_ -= 1;
			if (MenuSelcetCount_ == 1)
			{
				MenuSelcetRenderer02_->Death();
				SetPosition({ 959,881 });
				MenuSelcetRenderer01_ = CreateRendererToScale("MenuSelect01.bmp", { 968 ,312 });
			}
			else if (MenuSelcetCount_ == 2)
			{
				MenuSelcetRenderer03_->Death();
				SetPosition({ 960,880 });
				MenuSelcetRenderer02_ = CreateRendererToScale("MenuSelect02.bmp", { 968 ,312 });
			}
		}
		else if (MenuSelcetCount_ == 1)
		{
			MenuSelcetRenderer01_->Death();
			MenuSelcetCount_ = 3;
			SetPosition({ 961,880 });
			MenuSelcetRenderer03_ = CreateRendererToScale("MenuSelect03.bmp", { 968 ,312 });
		}
	}
	if (true == GameEngineInput::GetInst()->IsDown("SelectDown"))
	{
		if (MenuSelcetCount_ < 3)
		{
			MenuSelcetCount_ += 1;
			if (MenuSelcetCount_ == 2)
			{
				MenuSelcetRenderer01_->Death();
				SetPosition({ 960,880 });
				MenuSelcetRenderer02_ = CreateRendererToScale("MenuSelect02.bmp", { 968 ,312 });
			}
			else if (MenuSelcetCount_ == 3)
			{
				MenuSelcetRenderer02_->Death();
				SetPosition({ 961,880 });
				MenuSelcetRenderer03_ = CreateRendererToScale("MenuSelect03.bmp", { 968 ,312 });
			}
		}
		else if (MenuSelcetCount_ == 3)
		{
			MenuSelcetRenderer03_->Death();
			MenuSelcetCount_ = 1;
			SetPosition({ 959,881 });
			MenuSelcetRenderer01_ = CreateRendererToScale("MenuSelect01.bmp", { 968 ,312 });
		}
	}
}

