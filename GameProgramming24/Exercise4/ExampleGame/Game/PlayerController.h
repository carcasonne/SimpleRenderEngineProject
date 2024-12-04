#pragma once

#include "Engine/Component.h"

namespace Game {
	class PlayerController : public MyEngine::Component {
		const float MovementSpeed = 5;
		const float MovementBase = 30;
		const float RotationSpeed = 100;
		float RotationAmount = 0;
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
