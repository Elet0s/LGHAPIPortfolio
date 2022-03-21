#include "GameEngine.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GameEngineLevel.h"
#include "GameEngineImageManager.h"

std::map<std::string, GameEngineLevel*> GameEngine::AllLevel_;
GameEngineLevel* GameEngine::CurrentLevel_ = nullptr;
GameEngineLevel* GameEngine::NextLevel_ = nullptr;
GameEngine* GameEngine::UserContents_ = nullptr;
GameEngineImage* GameEngine::BackBufferImage_ = nullptr;
GameEngineImage* GameEngine::WindowMainImage_ = nullptr; // �׷����� ȭ�鿡 ��¥ ������ �Ǵ� �̹���

HDC GameEngine::BackBufferDC()
{
    return BackBufferImage_->ImageDC();
}

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{

}

void GameEngine::GameInit()
{

}

void GameEngine::GameLoop()
{

}

void GameEngine::GameEnd()
{

}

void GameEngine::WindowCreate()
{
    GameEngineWindow::GetInst().CreateGameWindow(nullptr, "GameWindow");
    GameEngineWindow::GetInst().ShowGameWindow();
    GameEngineWindow::GetInst().MessageLoop(EngineInit, EngineLoop);
}

void GameEngine::EngineInit()
{
    // ���⼭ �������� ũ�Ⱑ �����ɰ� �̹Ƿ�
    UserContents_->GameInit();

    // ����۸� ����� ����.
    WindowMainImage_ = GameEngineImageManager::GetInst()->Create("WindowMain", GameEngineWindow::GetHDC());
    BackBufferImage_ = GameEngineImageManager::GetInst()->Create("BackBuffer", GameEngineWindow::GetScale());

}
void GameEngine::EngineLoop()
{
    // �������ؿ��� �� �����Ӹ��� üũ�ϰ� ������
    UserContents_->GameLoop();

    // �����Լ���� �ϴµ�
    // ��� ����
    if (nullptr != NextLevel_)
    {
        if (nullptr != CurrentLevel_)
        {
            CurrentLevel_->LevelChangeEnd();
        }

        CurrentLevel_ = NextLevel_;

        if (nullptr != CurrentLevel_)
        {
            CurrentLevel_->LevelChangeStart();
        }

        NextLevel_ = nullptr;
    }

    if (nullptr == CurrentLevel_)
    {
        MsgBoxAssert("Level is nullptr => GameEngine Loop Error");
    }


    // �������� �ð������� �ִ� �����̶��
    // �� �����Ӹ��� �ð��� üũ�ؾ��ϴµ� �׷����� 
    CurrentLevel_->Update();
    CurrentLevel_->ActorUpdate();
    CurrentLevel_->ActorRender();
    WindowMainImage_->BitCopy(BackBufferImage_);

}

void GameEngine::EngineEnd()
{
    UserContents_->GameEnd();

    std::map<std::string, GameEngineLevel*>::iterator StartIter = AllLevel_.begin();
    std::map<std::string, GameEngineLevel*>::iterator EndIter = AllLevel_.end();

    for (; StartIter != EndIter; ++StartIter)
    {
        if (nullptr == StartIter->second)
        {
            continue;
        }
        delete StartIter->second;
    }


    GameEngineImageManager::Destroy();

    GameEngineWindow::Destroy();
}

void GameEngine::ChangeLevel(const std::string& _Name)
{
    std::map<std::string, GameEngineLevel*>::iterator FindIter = AllLevel_.find(_Name);

    if (AllLevel_.end() == FindIter)
    {
        MsgBoxAssert("Level Find Error");
        return;
    }
    NextLevel_ = FindIter->second;
}