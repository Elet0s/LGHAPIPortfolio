#pragma once
#include<filesystem>


class GameEnginePath //절대경로말고 상대경로로 이미지를 로드하기 위해서 만든 경로 지정 클래스
{
public:
	GameEnginePath();
	GameEnginePath(const std::filesystem::path& _Path);
	~GameEnginePath();


	GameEnginePath(const GameEnginePath& _Other) = delete;
	GameEnginePath(GameEnginePath&& _Other) noexcept = delete;
	GameEnginePath& operator=(const GameEnginePath& _Other) = delete;
	GameEnginePath& operator=(GameEnginePath&& _Other) noexcept = delete;
	
	void SetCurrentPath();
	
	bool IsExits();

	std::string GetExtension();

	std::string GetFileName();

	std::string GetFullPath();

protected:
	std::filesystem::path Path_;
private:
};