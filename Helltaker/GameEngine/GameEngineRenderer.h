#pragma once
#include "GameEngineActorSubObject.h"
#include "GameEngineEnum.h"


// 설명 : 그리는걸 도와주는 클래스
class GameEngineImage;
class GameEngineRenderer : public GameEngineActorSubObject
{
	friend GameEngineActor;

public:
	// constrcuter destructer
	GameEngineRenderer();
	~GameEngineRenderer();

	// delete Function
	GameEngineRenderer(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer(GameEngineRenderer&& _Other) noexcept = delete;
	GameEngineRenderer& operator=(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer& operator=(GameEngineRenderer&& _Other) noexcept = delete;

	inline void SetTransColor(unsigned int _Color)
	{
		TransColor_ = _Color;
	}

	inline void SetPivot(const float4& _Pos)
	{
		RenderPivot_ = _Pos;
	}

	inline void SetType(const RenderPivot& _Type)
	{
		PivotType_ = _Type;
	}

	inline void SetScaleMode(const RenderScaleMode& _Mode)
	{
		ScaleMode_ = _Mode;
	}

	// 렌더러 스케일 뿐 아니라 이미지 스케일도 같이 맞춰줌
	void SetImageScale();

	inline void SetScale(const float4& _Scale)
	{
		ScaleMode_ = RenderScaleMode::User;
		RenderScale_ = _Scale;
	}

	void SetImage(const std::string& _Name);

	// 
	void SetIndex(size_t _Index);



protected:
	void Render();

private:
	GameEngineImage* Image_;
	RenderPivot PivotType_; // 센터 / bot
	RenderScaleMode ScaleMode_;


	float4 RenderPivot_;


	float4 RenderScale_;

	float4 RenderImageScale_;
	float4 RenderImagePivot_;

	unsigned int TransColor_;

};
