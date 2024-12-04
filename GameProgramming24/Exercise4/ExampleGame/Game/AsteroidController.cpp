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
		parent->rotation += RotationSpeed * deltaTime;
		parent->position = parent->position + MovementSpeed * MovementDirection * MovementBase * deltaTime;
	}

	void AsteroidController::KeyEvent(SDL_Event& e) {
		
	}
}