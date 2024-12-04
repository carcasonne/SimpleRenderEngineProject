#include "AsteroidController.h"
#include "ComponentRendererSprite.h"

#include "Engine/MyEngine.h"

namespace Game {
	void AsteroidController::Init() {
		engine = MyEngine::Engine::GetInstance();
		parent = GetGameObject();

		parent->position = engine->GetScreenSize() / 2.f;
		parent->warp = true;
	}

	void AsteroidController::Update(float deltaTime) {
	
	}

	void AsteroidController::KeyEvent(SDL_Event& e) {
		
	}
}