#include "ComponentRendererSprite.h"
#include "Engine/MyEngine.h"

namespace ExampleGame {
	static const std::array<glm::vec2, 5> WRAP_OFFSETS = { {
		{0, 0},      // og position 
		{0, -1},     // below
		{0, 1},      // above
		{1, 0},      // right
		{-1, 0}      // left
	} };

	void ComponentRendererSprite::Render(sre::SpriteBatch::SpriteBatchBuilder& builder) {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();

		sprite.setPosition(parent->position);
		sprite.setRotation(parent->rotation);
		builder.addSprite(sprite);

		glm::vec2 screensize = engine->GetScreenSize();

		if (!parent->warp)
		{
			return;
		}

		auto& pos = GetGameObject()->position;
		for (auto& offset : WRAP_OFFSETS) {
			sprite.setPosition(pos + offset * screensize);
			builder.addSprite(sprite);
		}
	}
}