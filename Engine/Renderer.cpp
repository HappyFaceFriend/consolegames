#include "Renderer.h"

#include <iostream>
#include <windows.h>
#include <cstring>

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
				//renderable member하나하나에 락 다 걸었음 
				lock.unlock();
				for(iter = mRenderables.begin(); iter != mRenderables.end(); ++iter)
				{
					//순회 중에 renderable이 제거될수도 있음. 이에대한 대책필요 
					lock.lock();
					Render(*iter);
					lock.unlock();
				} 
			}
		}
	}
	
	void Renderer::gotoxy(const Vector2& pos)
	{
		COORD p={pos.x,pos.y};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	}
	
	void Renderer::Render(const Renderable& renderable)
	{
		const char* image = renderable.GetImage();
		gotoxy(renderable.GetPrevPosition());
		for(int i=0; i<strlen(image); i++)
			std::cout << " ";
		gotoxy(renderable.GetPosition());
		std::cout << image;
	}
}
