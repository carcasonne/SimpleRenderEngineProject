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
		auto newPosition = parent->position + MovementDirection * MovementSpeed * deltaTime;
		// prevent overshooting screensize
		newPosition = glm::mod(newPosition + screenSize, screenSize);

		parent->position = newPosition;
	}

	void PlayerController::KeyEvent(SDL_Event& e) {
		switch (e.key.keysym.sym) {
			case SDLK_w:
				break;
			case SDLK_a:
				break;
			case SDLK_d:
				break;
			case SDLK_SPACE:
				break;
			default:
				break;
		}
	}
}