#pragma once
class Key
{
private:
	// constrcuter destructer
	Key();
	~Key();

	// delete Function
	Key(const Key& _Other) = delete;
	Key(Key&& _Other) noexcept = delete;
	Key& operator=(const Key& _Other) = delete;
	Key& operator=(Key&& _Other) noexcept = delete;
};