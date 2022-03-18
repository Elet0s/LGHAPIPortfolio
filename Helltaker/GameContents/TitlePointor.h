#pragma once
class TitlePointor
{
private:
	// constrcuter destructer
	TitlePointor();
	~TitlePointor();

	// delete Function
	TitlePointor(const TitlePointor& _Other) = delete;
	TitlePointor(TitlePointor&& _Other) noexcept = delete;
	TitlePointor& operator=(const TitlePointor& _Other) = delete;
	TitlePointor& operator=(TitlePointor&& _Other) noexcept = delete;
};