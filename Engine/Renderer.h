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
			void RemoveRenderable(const Renderable& renderable);
		private:
			std::thread mRenderThread;
			std::list<const Renderable&> mRenderables;
			std::mutex mRenderablesMutex;
			std::condition_variable mIsEmpty;
			
			void gotoxy(const Vector2& pos);
	};
}

