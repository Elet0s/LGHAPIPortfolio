#pragma once
#include"PlayerEnums.h"
#include"ContentsEnums.h"
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRendererTileMap.h>
#include <GameEngineBase/GameEngineSound.h>
#include"LifeCounter.h"

class PlayerTile: public Tile
{
public:
	PlayerTile()
		:TileState_(MapObject::none)
	{
	}
	~PlayerTile()
	{
	}

	MapObject TileState_;
};


class Player : public GameEngineActor
{
public:

	static Player* PlayerObject_;
	float PlayerX_;
	float PlayerY_;

protected:


	int LifePoint_;
private:
	PlayerTile* PlayerTileBase;
	GameEngineSoundPlayer BgmPlayer_;
	GameEngineRendererTileMap* TileMap_;
	GameEngineRenderer* PlayerS_;
	GameEngineImage* ChapterCol_;
	bool RLState_;
	bool MakeCheak_;
	int ChapterLevel_;

	float Speed_;
	PlayerState CurState_;
	PlayerState 	PreState_;
	float ShiftX_;
	float ShiftY_;
	bool MoveStart_;
	bool MoveEnd_;
	bool MoveSet_;
	int LTUD_;
	LifeCounter* LifeCount_;

	bool WinCheak_;

public:
	Player();
	~Player();
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	inline void SetTileMap(GameEngineRendererTileMap* _TileMap)
	{
		TileMap_ = _TileMap;
	}

	inline GameEngineRendererTileMap* ReturnPlayerTileMap_()
	{
		return TileMap_;
	}
	void Start() override;
	void SetLifePoint(int _LifePoint);
	int GetLifePoint();
	void ChangeState(PlayerState _State);
	void StateUpdate();
	void CheakChapter(int _ChapterLevel);
	bool ClearChapter();

	void PlayerPositionSet();
	void ReloadSet();
private:

	void CreatePlayer(int _x, int _y, int _index);
	void Update() override;
	void KeySet();

	void LeftMoveShift();
	void RightMoveShift();
	void UpMoveShift();
	void DownMoveShift();
	



 //State
	void IdleStart();
	void IdleUpdate();
	void MoveStart();
	void MoveUpdate();
	void KickStart();
	void KickUpdate();
	void DieStart();
	void DieUpdate();
	void WinStart();
	void WinUpdate();
 //Cheak
	bool MoveCheak();



};


