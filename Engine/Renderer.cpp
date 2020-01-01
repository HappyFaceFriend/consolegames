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
				//Renderable���� ��ȸ�ϸ鼭 �����ϸ��.
				//�׷��� Render �۾��� Renderable�� ������ �ٲ���� ����. ��Ұ� ???
				//Render �۾��߿� Renderable�� ������ �ٲ��� �ʰ� �ؾ���. = lock�ɾ����.
				//renderable member�ϳ��ϳ��� �� �� �ɾ��� 
				lock.unlock();
				for(iter = mRenderables.begin(); iter != mRenderables.end(); ++iter)
				{
					//��ȸ �߿� renderable�� ���ŵɼ��� ����. �̿����� ��å�ʿ� 
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
