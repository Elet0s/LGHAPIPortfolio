#pragma once

// 설명 :
class GameEngineTime
{

private:
	static GameEngineTime* Inst_;

public:
	static GameEngineTime* GetInst()
	{
		return Inst_;
	}


	// 마지막에 지우더라도 내가 의도한 순서에서 지우고 싶기 때문에 pointer로 삭제
	static void Destroy()
	{
		if (nullptr != Inst_)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}

public:
	void Reset();
	void Update();

	static inline float GetDeltaTime()
	{
		//if (nullptr == Inst_)
		//{
		//	Inst_ = new GameEngineTime();
		//}

		return Inst_->DeltaTime_;
	}



protected:

private:
	__int64 SecondCount_;
	__int64 CurrentCount_;
	__int64 PrevCount_;
	float DeltaTime_;
	double RealDeltaTime_;


	GameEngineTime();
	~GameEngineTime();
	GameEngineTime(const GameEngineTime& _Other) = delete;
	GameEngineTime(GameEngineTime&& _Other) noexcept = delete;
	GameEngineTime& operator=(const GameEngineTime& _Other) = delete;
	GameEngineTime& operator=(GameEngineTime&& _Other) noexcept = delete;

};

