#pragma once

#include "Engine/Component.h"

namespace Game {
	class AsteroidController : public MyEngine::Component {
		const float RotationSpeed = 100;
		const float Radius;
		bool IsMoving = false;

		// makes it possible to only call GetInstance once, guess its a memory vs. computation tradeoff
		MyEngine::Engine* engine;
		MyEngine::GameObject* parent;

	public:
		glm::vec2 position;
		float rotation;

		AsteroidController(float radius)
			: MyEngine::Component()
			, rotation(0.0f)
			, Radius(radius)
		{}

		void Init() override;
		void Update(float) override;
		void KeyEvent(SDL_Event& e) override;
	};
}