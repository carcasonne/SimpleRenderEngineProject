#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"

#include "Engine/MyEngine.h"

#include "Game/ComponentController.h"
#include "Game/PlayerController.h"
#include "Game/AsteroidController.h"
#include "Game/ComponentRendererSprite.h"

void InitGame();
void ProcessEvents(SDL_Event& event);
void Update(float deltaTime);
void Render();
MyEngine::GameObject* CreatePlayer(std::string name, std::string spriteName, std::shared_ptr<sre::SpriteAtlas> atlas);
MyEngine::GameObject* CreateAsteroid(std::string name, std::string spriteName, std::shared_ptr<sre::SpriteAtlas> atlas, float radius);

MyEngine::Engine engine;

glm::vec2 window_size = glm::vec2(800, 600);
sre::SDLRenderer renderer;
sre::Camera camera;
std::shared_ptr<sre::SpriteAtlas> atlas;

MyEngine::GameObject* playerObject;

struct AsteroidType {
	float radius;
	const char* spriteName;
};

static const AsteroidType ASTEROID_TYPES[] = {
	{20, "meteorGrey_small1.png"},
	{35, "meteorGrey_med2.png"},
	{60, "meteorGrey_big3.png"}
};

int main() {
	renderer.frameRender = Render;
	renderer.frameUpdate = Update;
	renderer.keyEvent = ProcessEvents;

	renderer.setWindowSize(window_size);
	renderer.init();
	camera.setWindowCoordinates();

	atlas = sre::SpriteAtlas::create("data/spritesheet.json", "data/spritesheet.png");

	playerObject = CreatePlayer("player", "playerShip1_blue.png", atlas);

	float asteroidRadi[] = { 20, 35, 60};
	std::string asteroidSprites[] = { "meteorGrey_small1.png", "meteorGrey_med2.png", "meteorGrey_big3.png" };
	for (int i = 0; i < 5; i++) {
		auto asteroidType = ASTEROID_TYPES[rand() % 3];
		auto asteroidObject = CreateAsteroid("asteroid" + std::to_string(i), ASTEROID_TYPES->spriteName, atlas, ASTEROID_TYPES->radius);
	}

	engine.Init();
	renderer.startEventLoop();
}

void ProcessEvents(SDL_Event& event) {
	engine.ProcessEvents(event);
}

void Update(float deltaTime) {
	engine.Update(deltaTime);
}

void Render() {
	engine.Render();
}

MyEngine::GameObject* CreatePlayer(std::string name, std::string spriteName, std::shared_ptr<sre::SpriteAtlas> atlas) {
	auto playerObject = engine.CreateGameObject(name);
	auto componentController = std::shared_ptr<Game::PlayerController>(new Game::PlayerController());
	auto componentRenderer = std::make_shared<Game::ComponentRendererSprite>();
	playerObject->AddComponent(componentController);
	playerObject->AddComponent(componentRenderer);
	componentRenderer->sprite = atlas->get(spriteName);
	return playerObject;
}

MyEngine::GameObject* CreateAsteroid(std::string name, std::string spriteName, std::shared_ptr<sre::SpriteAtlas> atlas, float radius) {
	auto asteroidObject = engine.CreateGameObject(name);
	auto componentController = std::shared_ptr<Game::AsteroidController>(new Game::AsteroidController(radius));
	auto componentRenderer = std::make_shared<Game::ComponentRendererSprite>();
	asteroidObject->AddComponent(componentController);
	asteroidObject->AddComponent(componentRenderer);
	componentRenderer->sprite = atlas->get(spriteName);
	return asteroidObject;
}