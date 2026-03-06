#include "pch.h"
#include "../Software_lib/Game.h"


class gameobjectTest : public testing::Test
{
protected:
	Game myGame;

	void SetUp() override {
		auto scene = std::make_unique<Scene>("testScene");
		scene->addGameObject(std::make_unique<GameObject>("guitar"));
		myGame.setCurrentScene(std::move(scene));
	};

	void TearDown() override {}
};

TEST_F(gameobjectTest, SelectObjectPositeve) {
	std::string nåttkul = myGame.selectObject("guitar");
	std::cout << "SelectObjectPositev (guitar): " << nåttkul << std::endl;
	ASSERT_EQ(nåttkul, "guitar");
}

TEST_F(gameobjectTest, SelectObjectNegative) {
	std::string nåttkul = myGame.selectObject("dragon");
	std::cout << "SelectObjectPositev (Adam sandler): " << nåttkul << std::endl;
	ASSERT_EQ(nåttkul, "dragon");
}
