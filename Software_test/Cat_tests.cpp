#include "pch.h"
#include "../Software_lib/Cat.h"

TEST(CatTests, Construction_Test) {
	Cat bob;

	ASSERT_EQ(bob.getAge(), 42);

}

TEST(CatTests, Construction_int_Test) {
	Cat bob(12);

	ASSERT_EQ(bob.getAge(), 12);

	ASSERT_NE(bob.getAge(), 42);
}