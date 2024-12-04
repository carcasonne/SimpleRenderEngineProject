#pragma once

#include "Engine/Component.h"

namespace Game {
	class LaserController : public MyEngine::Component {
		const float MovementSpeed = 10;
		const float MovementAmount = 20;

		glm::vec2 MovementDirection = glm::vec2(0, 0);

		MyEngine::Engine* engine;
		MyEngine::GameObject* parent;

	public:
		glm::vec2 position;
		float rotation;
		float lifetime; // seconds

		void Init() override;
		void Update(float) override;
		void KeyEvent(SDL_Event& e) override;
	};
}