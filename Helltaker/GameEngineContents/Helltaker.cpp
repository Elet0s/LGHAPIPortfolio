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
	//������ â ����(��ġ)(ũ��)
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0, 0 }, { 1920, 1080 });


	// ���� ���丮(���丮 ��� ���� �� �������� ���� �� ��)
	{

		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("Image");

		// �����ȿ� ��� �̹��� ������ ã�´�.
		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			//�̹��� �Ŵ����� ���� �����ϴ� ����� ���� ����
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}

	}

	
	{

		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Helltaker");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("Sound");

		// �����ȿ� ��� ���� ������ ã�´�.
		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			//����� �Ŵ������� �����ϴ� ����� �������� �׷��� inst���� static���� �ٷ� �����ؼ� ������
			GameEngineSound::LoadRes(AllImageFileList[i].GetFullPath());

		}

	}

	
	//�ִϸ��̼��� ���� ������ �̹����� �ڸ��� �κ�
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