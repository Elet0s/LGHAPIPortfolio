#pragma once
class TitleBackGround
{
private:
	// constrcuter destructer
	TitleBackGround();
	~TitleBackGround();

	// delete Function
	TitleBackGround(const TitleBackGround& _Other) = delete;
	TitleBackGround(TitleBackGround&& _Other) noexcept = delete;
	TitleBackGround& operator=(const TitleBackGround& _Other) = delete;
	TitleBackGround& operator=(TitleBackGround&& _Other) noexcept = delete;
};