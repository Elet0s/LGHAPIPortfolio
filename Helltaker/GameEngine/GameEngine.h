#pragma once
#include <map>
#include <string>
#include <GameEngineBase/GameEngineDebug.h>

// ���ӿ����̶� ���� ����ü�� �������� ���� �������� ����ϴ� �༮�̴�.
// ���� :
class GameEngineImage;
class GameEngineLevel;
class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	// delete Function
	GameEngine(const GameEngine& _Other) = delete;
	GameEngine(GameEngine&& _Other) noexcept = delete;
	GameEngine& operator=(const GameEngine& _Other) = delete;
	GameEngine& operator=(GameEngine&& _Other) noexcept = delete;

	static inline GameEngineImage* BackBufferImage()
	{
		return BackBufferImage_;
	}

	static HDC BackBufferDC();

	virtual void GameInit() = 0;
	virtual void GameLoop() = 0;
	virtual void GameEnd() = 0;

	template<typename GameType>
	static void Start()
	{
		GameEngineDebug::LeekCheakOn();

		GameType UserGame;
		UserContents_ = &UserGame;

		WindowCreate();
		EngineEnd();
	}

	static GameEngine& GlobalEngine()
	{
		if (nullptr == UserContents_)
		{
			MsgBoxAssert("GEngine ERROR Engine Is Not Start ");
		}

		return *UserContents_;
	}

	void ChangeLevel(const std::string& _Name);

protected:
	template<typename LevelType>
	void CreateLevel(const std::string& _Name)
	{
		LevelType* NewLevel = new LevelType();
		NewLevel->SetName(_Name);
		GameEngineLevel* Level = NewLevel;
		Level->Loading();
		AllLevel_.insert(std::make_pair(_Name, NewLevel));
	}


private:
	static std::map<std::string, GameEngineLevel*> AllLevel_;
	static GameEngineLevel* CurrentLevel_;
	static GameEngineLevel* NextLevel_;
	static GameEngine* UserContents_;

	static GameEngineImage* WindowMainImage_; // �׷����� ȭ�鿡 ��¥ ������ �Ǵ� �̹���
	static GameEngineImage* BackBufferImage_; // �������� �ذ��Ϸ��� ���۷� ����ϴ� �̹���

	static void WindowCreate();
	static void EngineInit();
	static void EngineLoop();
	static void EngineEnd();


};

//class IGameEngineInstance
//{
//	virtual void GameInit() = 0;
//	virtual void GameLoop() = 0;
//	virtual void GameEnd() = 0;
//};