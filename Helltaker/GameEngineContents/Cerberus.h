#pragma once
class Cerberus
{
private:
	// constrcuter destructer
	Cerberus();
	~Cerberus();

	// delete Function
	Cerberus(const Cerberus& _Other) = delete;
	Cerberus(Cerberus&& _Other) noexcept = delete;
	Cerberus& operator=(const Cerberus& _Other) = delete;
	Cerberus& operator=(Cerberus&& _Other) noexcept = delete;
};