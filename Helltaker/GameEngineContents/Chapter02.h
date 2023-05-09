#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineSound.h>
#include "ChapterBackGound.h"

class GmaeEngineSound;

class Chapter02 : public GameEngineLevel
{
public:
	Chapter02();
	~Chapter02();

	Chapter02(const Chapter02& _Other) = delete;
	Chapter02(Chapter02&& _Other) noexcept = delete;
	Chapter02& operator=(const Chapter02& _Other) = delete;
	Chapter02& operator=(Chapter02&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _NextLevel) override;
	void LevelChangeEnd(GameEngineLevel* _PrevLevel) override;

};