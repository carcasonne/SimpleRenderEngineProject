#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"

#include "Engine/MyEngine.h"

#include "Game/ComponentController.h"
#include "Game/ComponentRendererSprite.h"

void InitGame();
void ProcessEvents(SDL_Event& event);
void Update(float deltaTime);
void Render();
MyEngine::GameObject* CreateObject(std::string name, std::string spriteName, std::shared_ptr<sre::SpriteAtlas> atlas);

MyEngine::Engine engine;

glm::vec2 window_size = glm::vec2(800, 600);
sre::SDLRenderer renderer;
sre::Camera camera;
std::shared_ptr<sre::SpriteAtlas> atlas;

MyEngine::GameObject* playerObject;

int main() {
	renderer.frameRender = Render;
	renderer.frameUpdate = Update;
	renderer.keyEvent = ProcessEvents;

	renderer.setWindowSize(window_size);
	renderer.init();
	camera.setWindowCoordinates();

	atlas = sre::SpriteAtlas::create("data/spritesheet.json", "data/spritesheet.png");

	playerObject = CreateObject("player", "playerShip1_blue.png", atlas);

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

MyEngine::GameObject* CreateObject(std::string name, std::string spriteName, std::shared_ptr<sre::SpriteAtlas> atlas) {
	auto playerObject = engine.CreateGameObject(name);
	auto componentController = std::shared_ptr<ExampleGame::ComponentController>(new ExampleGame::ComponentController());
	auto componentRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	playerObject->AddComponent(componentController);
	playerObject->AddComponent(componentRenderer);
	componentRenderer->sprite = atlas->get(spriteName);
	return playerObject;
}