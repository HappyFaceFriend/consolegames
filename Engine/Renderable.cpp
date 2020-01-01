#include "Renderable.h"

namespace Engine
{
	Renderable::Renderable(const char* image, const Vector2& prevPosition, const Vector2& position)
	: mImage(image), mPrevPosition(prevPosition), mPosition(position)
	{}
	
	void Renderable::SetImage(const char* image)
	{
		std::unique_lock lock(mMutex);
		mImage = image;
	}
	void Renderable::SetPosition(const Vector2& pos)
	{
		std::unique_lock lock(mMutex);
		mPrevPosition = mPosition;
		mPosition = pos;
	}
	void Renderable::SetPosition(const Vector2& pos, const Vector2& prevPos)
	{
		std::unique_lock lock(mMutex);
		mPrevPosition = prevPos;
		mPosition = pos;
	}
	
	const char* Renderable::GetImage()
	{
		std::unique_lock lock(mMutex);
		return mImage;
	}
	const Vector2& Renderable::GetPosition()
	{
		std::unique_lock lock(mMutex);
		return mPosition;
	}
	const Vector2& Renderable::GetPrevPosition()
	{
		std::unique_lock lock(mMutex);
		return mPrevPosition;
	}
}
