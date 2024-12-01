#pragma once

#include "Engine/Component.h"

namespace Game {
	class PlayerController : public MyEngine::Component {
		const float MovementSpeed = 5;
		float RotationSpeed = 0;
		glm::vec2 MovementDirection = glm::vec2(0, 0);

		// makes it possible to only call GetInstance once, guess its a memory vs. computation tradeoff
		MyEngine::Engine* engine;
		MyEngine::GameObject* parent;

	public:
		glm::vec2 position;
		float rotaiton;

		void Init() override;
		void Update(float) override;
		void KeyEvent(SDL_Event& e) override;
	};
}
