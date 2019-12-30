#pragma once

#include "Vector2.h"

#include <mutex>
 
namespace Engine
{
	class Renderable
	{
		public:
			Renderable(const char* image, const Vector2& prevPosition, const Vector2& position);
			void SetImage(const char* image);
			void SetPosition(const Vector2& pos);
			void SetPosition(const Vector2& pos, const Vector2& prevPos);
			
		private:
			const char* mImage;
			Vector2 mPrevPosition;
			Vecotr2 mPosition;
			std::mutex mMutex;
			//�ܺο��� �� ���ؽ� ��ۼ� �ְ� ���ؽ� ���� �������� 
	};
	
}