#pragma once

#include <thread>
#include <list>
#include <mutex>
#include "Renderable.h"

namespace Engine
{
	class Renderer
	{
		public:
			Renderer();
			~Renderer(); 
			void RenderLoop();
			void PushRenderable(const Renderable& renderable);
			//remove 할 원소들을 queue에 저장해두고 한번에 삭제하는 방식 필요
			void RemoveRenderable(const Renderable& renderable);
		private:
			std::thread mRenderThread;
			//pointer로 바꿔야함 
			std::list<const Renderable&> mRenderables;
			std::mutex mRenderablesMutex;
			std::condition_variable mIsEmpty;
			
			void gotoxy(const Vector2& pos);
			void Render(const Renderable& renderable);
	};
}

