#include"StartEvent.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>

StartEvent::StartEvent()
	:BgCount_(0)
	, StartEvent_(nullptr)
{

}
StartEvent::~StartEvent()
{

}
void StartEvent::Start()
{
	SetPosition({ 960,430 });
	StartEvent_ = CreateRendererToScale("StartBg.bmp", { 1313  ,719 });

}
void StartEvent::Update()
{

}