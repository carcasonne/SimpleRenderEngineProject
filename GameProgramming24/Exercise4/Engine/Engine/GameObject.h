#pragma once

#include <list>
#include <memory>
#include <string>

#include "sre/SpriteBatch.hpp"

namespace MyEngine {
	class Component;

	class GameObject {
		friend class Engine;

		// public API
	public:
		glm::vec2 position;
		float rotation;
		bool warp;
		bool kill;
		float radius;

		void Init();
		void Update(float);
		void Render(sre::SpriteBatch::SpriteBatchBuilder&);
		void KeyEvent(SDL_Event&);

		void AddChild(std::shared_ptr<GameObject>);
		void AddComponent(std::shared_ptr<Component>);

		bool collidesWith(std::shared_ptr<GameObject>);

		bool operator == (const GameObject& o) const { return _name == o._name; }
		bool operator != (const GameObject& o) const { return !operator==(o); }

		std::string GetName();
		void SetName(std::string);

		// private fields
	private:
		std::weak_ptr<GameObject> _parent;
		std::weak_ptr<GameObject> _self;
		std::list<std::shared_ptr<GameObject>> _children = {};
		std::list< std::shared_ptr<Component>> _components = {};
		std::string _name;
	};
}