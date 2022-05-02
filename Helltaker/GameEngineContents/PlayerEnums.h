#pragma once
enum class MapObject
{
	Trap,
	Stone,
	Helper,
	Monster,
	Lock,
	Key
};
enum class PlayerState
{
	Idle,
	Move,
	Kick,
	Die,
	Win
};