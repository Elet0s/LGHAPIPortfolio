#include "Helltaker.h"
#include "TitleLevel.h"
#include "MenuLevel.h"
#include "Chapter01.h"
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
	//윈도우 창 생성(위치)(크기)
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0, 0 }, { 1920, 1080 });


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

	}

	
	{

		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("Sound");

		// 폴더안에 모든 사운드 파일을 찾는다.
		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			//사운드는 매니저없이 관리하는 방법을 적용했음 그래서 inst없이 static으로 바로 설정해서 가져옴
			GameEngineSound::LoadRes(AllImageFileList[i].GetFullPath());

		}

	}

	
	//애니메이션을 위해 합쳐진 이미지를 자르는 부분
//	GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Plyer01.bmp");
//	Image->Cut({ 89, 92 });



	CreateLevel<TitleLevel>("Title");
	CreateLevel<Chapter01>("Chapter01");
	ChangeLevel("Chapter01");
}

void Helltaker::GameLoop()
{

}
void Helltaker::GameEnd()
{

}