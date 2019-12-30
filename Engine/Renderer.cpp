#include "Renderer.h"

#include <iostream>
#include <cwindows>

namespace Engine
{
	Renderer::Renderer()
	{
		mRenderThread = std::thread { &Renderer::RenderLoop, this };
	}
	
	Renderer::~Renderer()
	{
		mRenderThread.join();
	}
	
	void Renderer::PushRenderable(const Renderable& renderable)
	{
		std::unique_lock lock(mListMutex);
		mRenderables.push(renderable);
		if(mRenderables.size() == 1)
			mIsEmpty.notify_all();
	}
	
	void RemoveRenderable(const Renderable& renderable)
	{
		std::unique_lock lock(mListMutex);
		mRenderables.remove(renderable);
	}
	
	
	void Renderer::RenderLoop()
	{
		std::unique_lock lock(mListMutex);
		std::list<const Renderable&>::iterator iter;
		while(true)
		{
			mIsEmpty.wait(mListMutex);
			lock.unlock();
			while(true)
			{
				lock.lock();
				if(mRenderables.empty())
					break;
				//Renderable들을 순회하면서 렌더하면됨.
				//그런데 Render 작업중 Renderable의 내용이 바뀔수도 있음. 어떡할거 ???
				//Render 작업중엔 Renderable의 내용이 바뀌지 않게 해야함. = lock걸어야함.
				lock.unlock();
			}
		}
	}
	
	void gotoxy(const Vector2& pos)
	{
		COORD p={pos.x,pos.y};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	}
}
