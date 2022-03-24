#include "Helltaker.h"
#include"TitleLevel.h"
#include"MenuLevel.h"
#include"PlayLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include<GameEngineBase/GameEngineDirectory.h>
#include<GameEngineBase/GameEngineFile.h>
#include <GameEngine/GameEngineImageManager.h>

Helltaker::Helltaker()
{
}

Helltaker::~Helltaker()
{
}

void Helltaker::GameInit()
{
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0, 0 }, { 1280, 720 });


	// 현재 디렉토리
	GameEngineDirectory ResourcesDir;
	ResourcesDir.MoveParent("Helltaker");
	ResourcesDir.Move("Resource");
	ResourcesDir.Move("Image");

	// 폴더안에 모든 이미지 파일을 찾는다.
	std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}


	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	ChangeLevel("Play");
}

void Helltaker::GameLoop()
{

}
void Helltaker::GameEnd()
{

}