#pragma once
class Chapter03
{
private:
	// constrcuter destructer
	Chapter03();
	~Chapter03();

	// delete Function
	Chapter03(const Chapter03& _Other) = delete;
	Chapter03(Chapter03&& _Other) noexcept = delete;
	Chapter03& operator=(const Chapter03& _Other) = delete;
	Chapter03& operator=(Chapter03&& _Other) noexcept = delete;
};