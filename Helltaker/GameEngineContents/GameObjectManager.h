
#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRendererTileMap.h>
#include "ContentsEnums.h"
class GameObjectTile : public Tile
{
public:
	GameObjectTile()
		:Off_(false)
		, IsLKick_(false)
		, IsRKick_(false)
		, IsUKick_(false)
		, IsDKick_(false)
		, TileObjectX_(0)
		, TileObjectY_(0)
		,Key_()
		,Helper_()
		, Lock_()
		, Monster_()
	{
	}
	~GameObjectTile()
	{

	}
	float TileObjectX_;
	float TileObjectY_;

	MapObject TileState_;
	bool IsLKick_;
	bool IsRKick_;
	bool IsUKick_;
	bool IsDKick_;
	bool Off_;

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
	GameEngineRendererTileMap* GameObjectTileMap_;
	bool RLState_;
	bool MakeCheak_;
	int ChapterLevel_;
	void ObjectCheakChapter(int _ChapterLevel);
	bool GetChapterClear();
	void Start() override;
private:

	template<class ObjectClass>
	void CreateObject(MapObject TileState_)
	{
		switch (TileState_)
		{
		case MapObject::Trap:
			break;
		case MapObject::Ston:
			break;
		case MapObject::Helper:
			break;
		case MapObject::Monster:
			break;
		case MapObject::Lock:
			break;
		case MapObject::Key:
			break;
		case MapObject::Player:
			break;
		default:
			break;
		}

	}

	void SetPositionObject(int _x, int _y)
	{

	}


	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void CreateMonster(int _x, int _y, int _index);
	void CreateHelper(int _x, int _y, int _index);
	void CreateSton(int _x, int _y, int _index);
	void CreateWall(int _x, int _y, int _index);
	void CreateTrap(int _x, int _y, int _index);
	void CreateKey(int _x, int _y, int _index);
	void CreateLock(int _x, int _y, int _index);
	void CheakMonsterAni();
	void CheakStonAni();
	void CheakHelper();
	bool ShiftCheak_;
	bool ChapterClear_;



	std::vector< GameObjectTile* > Mon;
	std::vector< GameObjectTile* >Helper;
	std::vector< GameObjectTile* >Ston;
	std::vector< GameObjectTile* >Wall;
	std::vector< GameObjectTile* >Trap;
	std::vector< GameObjectTile* >Key;
	std::vector< GameObjectTile* >Lock;


	float ShiftX_;
	float ShiftY_;
public:
	inline void SetTileMap(GameEngineRendererTileMap* _TileMap)
	{
		GameObjectTileMap_ = _TileMap;
	}
	inline GameEngineRendererTileMap* ReturnGameTileObejctMap_()
	{
		return GameObjectTileMap_;
	}
};