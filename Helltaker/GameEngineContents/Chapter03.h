#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineSound.h>
#include "ChapterBackGound.h"

class GmaeEngineSound;

class Chapter03 :public GameEngineLevel
{
public:
	Chapter03();
	~Chapter03();

	Chapter03(const Chapter03& _Other) = delete;
	Chapter03(Chapter03&& _Other) noexcept = delete;
	Chapter03& operator=(const Chapter03& _Other) = delete;
	Chapter03& operator=(Chapter03&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _NextLevel) override;
	void LevelChangeEnd(GameEngineLevel* _PrevLevel) override;

};