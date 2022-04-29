#include"EndText.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineInput.h>

EndText::EndText()
	:TextCount_(0)
	, EndTextRender01(nullptr)
{

}
EndText::~EndText()
{

}
void EndText::Start()
{
	SetPosition({ 960,818 });
	EndTextRender01 = CreateRendererToScale("EndText.bmp", { 972 ,127 });

}
void EndText::Render()
{


}
void EndText::Update()
{

}