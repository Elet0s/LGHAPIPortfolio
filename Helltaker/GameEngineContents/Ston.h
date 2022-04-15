#pragma once
class Ston
{
private:
	// constrcuter destructer
	Ston();
	~Ston();

	// delete Function
	Ston(const Ston& _Other) = delete;
	Ston(Ston&& _Other) noexcept = delete;
	Ston& operator=(const Ston& _Other) = delete;
	Ston& operator=(Ston&& _Other) noexcept = delete;
};