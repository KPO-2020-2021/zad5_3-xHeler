#include "gtest/gtest.h"
#include "Obstacle.h"

TEST(Collision, circleInBox) {
    Obstacle<true> sphere({0, 0, 0, 50});
    Obstacle<false> box({0, 50, 0, 50, 0, -50});
    EXPECT_TRUE(isCollisonSphereBox(box, sphere));
}

TEST(Collision, osulation) {
    Obstacle<true> sphere({0, 0, 0, 50});
    Obstacle<false> box({50, 100, 0, 50, 0, -50});
    EXPECT_FALSE(isCollisonSphereBox(box, sphere));
}

TEST(Collision, noCollision) {
    Obstacle<true> sphere({0, 0, 0, 50});
    Obstacle<false> box({55, 105, 0, 50, 0, -50});
    EXPECT_FALSE(isCollisonSphereBox(box, sphere));
}


