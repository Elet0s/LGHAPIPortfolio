#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngineImageManager.h>

#include "Helltaker.h"
#include "TitleLevel.h"
#include "MenuLevel.h"
#include "Chapter01.h"

Helltaker::Helltaker()
{
}

Helltaker::~Helltaker()
{
}

void Helltaker::GameInit()
{
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0, 0 }, { 1920, 1080 });

	{
		//현재 디렉토리 설정
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
	}

	{
		//Level
	}
	{
		//UI
	}
//	GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Plyer01.bmp");
//	Image->Cut({ 89, 92 });


	if (false == GameEngineInput::GetInst()->IsKey("Start"))
	{
		GameEngineInput::GetInst()->CreateKey("Start", VK_SPACE);
	}

	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<MenuLevel>("MenuLevel");
	CreateLevel<Chapter01>("Chapter01");
	ChangeLevel("TitleLevel");
}

void Helltaker::GameLoop()
{

}
void Helltaker::GameEnd()
{

}