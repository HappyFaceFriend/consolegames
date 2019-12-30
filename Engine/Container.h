#pragma once

#include <mutex>

namespace Engine
{
	template <typename ElementType, template<typename T, typename Allocator = std::allocator<T>> class stlContainer>
	class Container
	{
		public:
			void push_back
		private:
			std::mutex mMutex;
	};
}
