#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRendererTileMap.h>

class GameObjectTile :public Tile
{
public:
	GameObjectTile()
	{
	}
	~GameObjectTile()
	{
	}

	GameEngineRenderer* Monster_;
	GameEngineRenderer* Helper_;
	GameEngineRenderer* Ston_;
	GameEngineRenderer* Wall_;
	GameEngineRenderer* Trap_;
	GameEngineRenderer* Key_;
	GameEngineRenderer* Lock_;
};

class GameObjectManager : public GameEngineActor
{
public:
	GameObjectManager();
	~GameObjectManager();

	GameObjectManager(const GameObjectManager& _Other) = delete;
	GameObjectManager(GameObjectManager&& _Other) noexcept = delete;
	GameObjectManager& operator=(const GameObjectManager& _Other) = delete;
	GameObjectManager& operator=(GameObjectManager&& _Other) noexcept = delete;

	static GameObjectManager* GameObjectManager_;
	bool RLState_;
	bool MakeCheak_;
	int ChapterLevel_;

private:
	GameEngineRendererTileMap* GameObjectTileMap_;
	void Start() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void CreateMonster(int _Posx, int _Posy, int _index);
	void CreateHellper(int _Posx, int _Posy, int _index);
	void CreateSton(int _Posx, int _Posy, int _index);
	void CreateWall(int _Posx, int _Posy, int _index);
	void CreateTrap(int _Posx, int _Posy, int _index);
	void CreateKey(int _Posx, int _Posy, int _index);
	void CreateLock(int _Posx, int _Posy, int _index);

	std::vector< GameObjectTile* > Monster;
	std::vector< GameObjectTile* >Hellper;
	std::vector< GameObjectTile* >Ston;
	std::vector< GameObjectTile* >Wall;
	std::vector< GameObjectTile* >Trap;
	std::vector< GameObjectTile* >Key;
	std::vector< GameObjectTile* >Lock;
public:
	inline void SetTileMap(GameEngineRendererTileMap* _TileMap)
	{
		GameObjectTileMap_ = _TileMap;
	}
	inline void CheakChapter(int _ChapterLevel)
	{
		ChapterLevel_ = _ChapterLevel;
	}
};