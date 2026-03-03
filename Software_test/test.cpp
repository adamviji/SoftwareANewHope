#include "pch.h"
#include "../Software_lib/Cat.h"

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

class CatTests_fixture : public testing::Test {
protected:
	Cat myCat;

	void SetUp() override {}
	void TearDown() override {}

public:
	CatTests_fixture() {}
	~CatTests_fixture() {}

};

TEST_F(CatTests_fixture, def_constr_test) {
	ASSERT_EQ(myCat.getAge(), 42);
}