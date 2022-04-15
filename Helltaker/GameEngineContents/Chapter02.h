#pragma once
class Chapter02
{
private:
	// constrcuter destructer
	Chapter02();
	~Chapter02();

	// delete Function
	Chapter02(const Chapter02& _Other) = delete;
	Chapter02(Chapter02&& _Other) noexcept = delete;
	Chapter02& operator=(const Chapter02& _Other) = delete;
	Chapter02& operator=(Chapter02&& _Other) noexcept = delete;
};