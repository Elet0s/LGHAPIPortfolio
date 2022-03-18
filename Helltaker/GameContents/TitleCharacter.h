#pragma once
class TitleCharacter
{
private:
	// constrcuter destructer
	TitleCharacter();
	~TitleCharacter();

	// delete Function
	TitleCharacter(const TitleCharacter& _Other) = delete;
	TitleCharacter(TitleCharacter&& _Other) noexcept = delete;
	TitleCharacter& operator=(const TitleCharacter& _Other) = delete;
	TitleCharacter& operator=(TitleCharacter&& _Other) noexcept = delete;
};