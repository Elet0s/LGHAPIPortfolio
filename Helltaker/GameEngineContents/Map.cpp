#include"Map.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>

Map::Map()
{

}
Map::~Map()
{

}



void Map::Start()
{
	SetPosition({640, 360 });
	SetScale({ 1280, 720 });

	CreateRenderer("chapterBG0001.bmp");
}

void Map::Render()
{
	//GameEngineImage* FindImage = GameEngineImageManager::GetInst()->Find("assets100V20058.bmp");
	//if (nullptr == FindImage)
	//{
	//	MsgBoxAssert("CCCCC!");
	//}
	//GameEngine::BackBufferImage()->BitCopyBot(FindImage, GetPosition());
}