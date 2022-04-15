#pragma once
#include "GameEngineActorSubObject.h"
#include "GameEngineEnum.h"
// 설명 :
class GameEngineImage;
class GameEngineFolderImage;
class GameEngineRenderer : public GameEngineActorSubObject
{
	friend GameEngineActor;
	friend GameEngineLevel;

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

	inline float4 GetPivot()
	{
		return RenderPivot_;
	}

	inline void SetPivotType(const RenderPivot& _Type)
	{
		PivotType_ = _Type;
	}

	inline void SetScaleMode(const RenderScaleMode& _Mode)
	{
		ScaleMode_ = _Mode;
	}

	void SetImageScale();

	inline void SetScale(const float4& _Scale)
	{
		ScaleMode_ = RenderScaleMode::User;
		RenderScale_ = _Scale;
	}

	inline float4 GetScale()
	{
		return RenderScale_;
	}

	inline float4 GetImagePivot()
	{
		return RenderImagePivot_;
	}

	inline float4 GetImageScale()
	{
		return RenderImageScale_;
	}

	inline GameEngineImage* GetImage()
	{
		return Image_;
	}

	inline void SetAlpha(unsigned int _Alpha)
	{
		Alpha_ = _Alpha;

		if (Alpha_ >= 255)
		{
			Alpha_ = 255;
		}
	}

	void CameraEffectOff()
	{
		IsCameraEffect_ = false;
	}

	void CameraEffectOn()
	{
		IsCameraEffect_ = true;
	}

	void SetPause(bool _Value)
	{
		Pause_ = _Value;
	}

	void PauseOn() 
	{
		Pause_ = true;
	}

	void PauseOff()
	{
		Pause_ = false;
	}

	void PauseSwitch()
	{
		Pause_ = !Pause_;
	}

	void SetImageScale();

	void SetImage(const std::string& _Name);
	void SetIndex(size_t _Index);

protected:
	// EngineImage의 TransCopy 로 이미지를 백버퍼에 그린다.
	void Render();

private:
	GameEngineImage* Image_;
	RenderPivot PivotType_; // 센터 bot
	RenderScaleMode ScaleMode_;
	float4 RenderPivot_;
	float4 RenderScale_;
	float4 RenderImageScale_;
	float4 RenderImagePivot_;
	unsigned int TransColor_;

};

