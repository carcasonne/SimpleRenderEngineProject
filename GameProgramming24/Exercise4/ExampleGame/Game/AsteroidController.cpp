#include "AsteroidController.h"
#include "ComponentRendererSprite.h"

#include "Engine/MyEngine.h"

namespace Game {
	void AsteroidController::Init() {
		engine = MyEngine::Engine::GetInstance();
		parent = GetGameObject();
		auto screenSize = engine->GetScreenSize();

		parent->position = glm::vec2(std::rand() % ((int)screenSize.x), std::rand() % ((int)screenSize.y));
		parent->warp = true;
	}

	void AsteroidController::Update(float deltaTime) {
		auto screenSize = engine->GetScreenSize();

		parent->rotation += RotationSpeed * deltaTime;

		auto newPosition = parent->position + MovementDirection * MovementBase * MovementSpeed * deltaTime;
		newPosition = glm::mod(newPosition + screenSize, screenSize); // wrap around screen
		parent->position = newPosition;
	}

	void AsteroidController::KeyEvent(SDL_Event& e) {
		
	}
}