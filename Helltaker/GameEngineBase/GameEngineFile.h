#pragma once
#include"GameEnginePath.h"


class GameEngineFile : public GameEnginePath
{
public:
	GameEngineFile();
	GameEngineFile(const std::string& _Path);
	GameEngineFile(std::filesystem::path _Path);
	GameEngineFile(const GameEngineFile& _Other);
	~GameEngineFile();

	//GameEngineFile(const GameEngineFile& _Other) = delete;
	//GameEngineFile(GameEngineFile&& _Other) noexcept = delete;
	GameEngineFile& operator=(const GameEngineFile& _Other) = delete;
	GameEngineFile& operator=(GameEngineFile&& _Other) noexcept = delete;
protected:

private:

};