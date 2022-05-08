#pragma once
enum class PlayerState
{
	Idle,
	Move,
	Kick,
	Die,
	Win
};
enum class MoveState
{
	Left
	, Right
	, Up
	, Down
};