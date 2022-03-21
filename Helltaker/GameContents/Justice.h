#pragma once
class Justice
{
private:
	// constrcuter destructer
	Justice();
	~Justice();

	// delete Function
	Justice(const Justice& _Other) = delete;
	Justice(Justice&& _Other) noexcept = delete;
	Justice& operator=(const Justice& _Other) = delete;
	Justice& operator=(Justice&& _Other) noexcept = delete;
};