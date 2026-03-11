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
	std::cout << "SelectObjectNegative (dragon): " << nåttkul << std::endl;
	ASSERT_EQ(nåttkul, "");
}

TEST_F(gameobjectTest, selectInteractionPositive) {
	myGame.selectObject("guitar");
	bool success = myGame.selectInteraction("taste");

	ASSERT_EQ(success, true);
}

TEST_F(gameobjectTest, selectedInteractionNegative) {
	myGame.selectObject("dragon");
	bool success = myGame.selectInteraction("");

	ASSERT_FALSE(success);
}


TEST_F(gameobjectTest, startInteractionPositive) {
	myGame.selectObject("guitar");
	myGame.selectInteraction("taste");
	std::string interactionStr = myGame.startInteraction();

	ASSERT_EQ(interactionStr, "You taste guitar\n");
}

TEST_F(gameobjectTest, startInteractionmNegative) {
	myGame.selectObject("dragon");
	std::string result = myGame.startInteraction();
	ASSERT_EQ(result, "No object selected.");
}