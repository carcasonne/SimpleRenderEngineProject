#pragma once

#include "Engine/Component.h"

namespace Game {
	class AsteroidController : public MyEngine::Component {
		const float RotationSpeed = (std::rand() % 100) + 50;
		const float MovementSpeed = (std::rand() % 5) + 1;
		const float MovementBase = 30;
		const glm::vec2 MovementDirection = glm::vec2(0, -1);
		bool IsMoving = false;

		// makes it possible to only call GetInstance once, guess its a memory vs. computation tradeoff
		MyEngine::Engine* engine;
		MyEngine::GameObject* parent;

	public:
		glm::vec2 position;
		float rotation;

		void Init() override;
		void Update(float) override;
		void KeyEvent(SDL_Event& e) override;
	};
}