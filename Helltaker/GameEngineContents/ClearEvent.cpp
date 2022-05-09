#include"ClearEvent.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
ClearEvent::ClearEvent()
	:ClearBackGroundRender_(nullptr)
{

}
ClearEvent::~ClearEvent()
{

}

void ClearEvent::Start()
{
	SetPosition({ 960,540 });
	ClearBackGroundRender_ = CreateRendererToScale("MenuBG.bmp", { 1920 ,1080 });

}

void ClearEvent::Render()
{

}

void ClearEvent::Update()
{
	
}