#include "LaserController.h"
#include <iostream>

#include "Engine/MyEngine.h"

namespace Game {
	void LaserController::Init() {
		engine = MyEngine::Engine::GetInstance();
		parent = GetGameObject();

		float rotation = parent->rotation + 270;
		if (rotation > 360) rotation -= 360;
		MovementDirection.x = -glm::cos(rotation * 0.0174532925);
		MovementDirection.y = -glm::sin(rotation * 0.0174532925);
		parent->position = parent->position + MovementDirection * MovementAmount * MovementSpeed * 0.3f;
	}

	void LaserController::Update(float deltaTime) {
		parent->position = parent->position + MovementDirection * MovementAmount * MovementSpeed * deltaTime;

		lifetime += deltaTime;
		if (lifetime > 2) {
			parent->kill = true;
		}
	}

	void LaserController::KeyEvent(SDL_Event& e) {

	}
}