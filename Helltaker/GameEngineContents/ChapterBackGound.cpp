#include"ChapterBackGound.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>

ChapterBackGound::ChapterBackGound()
{

}
ChapterBackGound::~ChapterBackGound()
{

}

void ChapterBackGound::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale(GameEngineWindow::GetScale());
	CreateRenderer("chapterBG0001.bmp");
}

void ChapterBackGound::Render()
{
	//GameEngineImage* FindImage = GameEngineImageManager::GetInst()->Find("assets100V20058.bmp");
	//if (nullptr == FindImage)
	//{
	//	MsgBoxAssert("CCCCC!");
	//}
	//GameEngine::BackBufferImage()->BitCopyBot(FindImage, GetPosition());
}