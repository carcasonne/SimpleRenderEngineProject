#include "PlayerController.h"
#include "ComponentRendererSprite.h"

#include "Engine/MyEngine.h"

namespace Game {
	void PlayerController::Init() {
		engine = MyEngine::Engine::GetInstance();
		parent = GetGameObject();

		parent->position = engine->GetScreenSize() / 2.f;
		parent->warp = true;
	}

	void PlayerController::Update(float deltaTime) {
		auto screenSize = engine->GetScreenSize();

		parent->rotation += RotationAmount * RotationSpeed * deltaTime;
		
		auto movementDirection = IsMoving
			? glm::vec2(-glm::sin(glm::radians(parent->rotation)), glm::cos(glm::radians(parent->rotation)))
			: glm::vec2(0, 0);
		auto newPosition = parent->position + movementDirection * MovementBase * MovementSpeed * deltaTime;
		newPosition = glm::mod(newPosition + screenSize, screenSize); // wrap around screen

		parent->position = newPosition;
	}

	void PlayerController::KeyEvent(SDL_Event& e) {
		bool isKeyDown = e.key.type == ::SDL_KEYDOWN;
		switch(e.key.keysym.sym) {
			case SDLK_w:
				IsMoving = isKeyDown;
				break;
			case SDLK_a:
				RotationAmount = isKeyDown ? 1 : 0;
				break;
			case SDLK_d:
				RotationAmount = isKeyDown ? -1 : 0;
				break;
			case SDLK_SPACE:
				break;
			default:
				break;
		}
	}
}

