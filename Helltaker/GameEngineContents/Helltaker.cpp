#include "Helltaker.h"
#include "TitleLevel.h"
#include "MenuLevel.h"
#include "PlayLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineSound.h>

Helltaker::Helltaker()
{
}

Helltaker::~Helltaker()
{
}

void Helltaker::GameInit()
{
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0, 0 }, { 1280, 720 });


	// 현재 디렉토리(디렉토리 경로 설정 및 참조설정 잊지 말 것)
	{

		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("Image");

		// 폴더안에 모든 이미지 파일을 찾는다.
		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			//이미지 매니저를 만들어서 관리하는 방법을 적용 했음
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}


	GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Plyer01.bmp");
	Image->Cut({ 256, 256 });

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