#pragma once
class Key
{
public:
	Key();
	~Key();


	Key(const Key& _Other) = delete;
	Key(Key&& _Other) noexcept = delete;
	Key& operator=(const Key& _Other) = delete;
	Key& operator=(Key&& _Other) noexcept = delete;
protected:

private:

};