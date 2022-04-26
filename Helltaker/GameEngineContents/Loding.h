#pragma once
class Loding
{
private:
	// constrcuter destructer
	Loding();
	~Loding();

	// delete Function
	Loding(const Loding& _Other) = delete;
	Loding(Loding&& _Other) noexcept = delete;
	Loding& operator=(const Loding& _Other) = delete;
	Loding& operator=(Loding&& _Other) noexcept = delete;
};