#pragma once

#include "Feijoa/Scene/Scene.h"
#include <entt.hpp>

namespace Feijoa
{
	class Entity
	{
	public:
		Entity() = default;
		Entity(entt::entity handle, Scene* scene);
		Entity(const Entity&) = default;

		template <typename T, typename ... Args>
		T& AddComponent(Args&& ... args)
		{
			FJ_CORE_ASSERT(!HasComponent<T>(), "Entity already has component!");
			return m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
		}

		template <typename T>
		T& GetComponent()
		{
			FJ_CORE_ASSERT(HasComponent<T>(), "Entity does not have component!");
			return m_Scene->m_Registry.get<T>(m_EntityHandle);
		}

		template <typename T>
		bool HasComponent()
		{
			return m_Scene->m_Registry.any_of<T>(m_EntityHandle);
		}

		template <typename T>
		void RemoveComponent()
		{
			FJ_CORE_ASSERT(HasComponent<T>(), "Entity does not have component!");
			m_Scene->m_Registry.remove<T>(m_EntityHandle);
		}

		operator bool() const { return m_Scene->m_Registry.valid(m_EntityHandle); }
		
	private:
		entt::entity m_EntityHandle;
		Scene* m_Scene;
	};
}