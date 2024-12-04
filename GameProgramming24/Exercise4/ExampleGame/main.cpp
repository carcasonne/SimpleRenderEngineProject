#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"

#include "Engine/MyEngine.h"

#include "Game/ComponentController.h"
#include "Game/PlayerController.h"
#include "Game/AsteroidController.h"
#include "Game/ComponentRendererSprite.h"

#include <iostream>
#include <random>

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
	{35, "meteorGrey_med1.png"},
	{60, "meteorGrey_big1.png"}
};

std::random_device rd;
std::mt19937 generator(rd());

int main() {
	renderer.frameRender = Render;
	renderer.frameUpdate = Update;
	renderer.keyEvent = ProcessEvents;

	renderer.setWindowSize(window_size);
	renderer.init();
	camera.setWindowCoordinates();

	atlas = sre::SpriteAtlas::create("data/spritesheet.json", "data/spritesheet.png");
	engine.atlas = atlas;

	playerObject = CreatePlayer("player", "playerShip1_blue.png", atlas);

	float asteroidRadi[] = { 20, 35, 60};
	std::uniform_int_distribution<> distr(0, 2);
	for (int i = 0; i < 5; i++) {
		auto asteroidType = ASTEROID_TYPES[distr(generator)];
		auto asteroidObject = CreateAsteroid("asteroid" + std::to_string(i), asteroidType.spriteName, atlas, asteroidType.radius);
		std::cout << "asteroid " << i << " | sprite: " << asteroidType.spriteName << " | radius: " << asteroidType.radius << "\n";
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
	asteroidObject->radius = radius;
	auto componentController = std::shared_ptr<Game::AsteroidController>(new Game::AsteroidController());
	auto componentRenderer = std::make_shared<Game::ComponentRendererSprite>();
	asteroidObject->AddComponent(componentController);
	asteroidObject->AddComponent(componentRenderer);
	componentRenderer->sprite = atlas->get(spriteName);
	return asteroidObject;
}