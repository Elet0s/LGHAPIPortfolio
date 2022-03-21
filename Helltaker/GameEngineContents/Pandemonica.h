#pragma once
class Pandemonica
{
private:
	// constrcuter destructer
	Pandemonica();
	~Pandemonica();

	// delete Function
	Pandemonica(const Pandemonica& _Other) = delete;
	Pandemonica(Pandemonica&& _Other) noexcept = delete;
	Pandemonica& operator=(const Pandemonica& _Other) = delete;
	Pandemonica& operator=(Pandemonica&& _Other) noexcept = delete;
};