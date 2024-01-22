//
// Created by dmytro-nedavnii on 1/22/24.
//

#include <gtest/gtest.h>

#include "RendererWindow.h"

using namespace Game;

RendererWindow rendererWindow{"Test", 1280, 720};

TEST(RendererWindow, TestRendererIsValid) {
    ASSERT_TRUE(rendererWindow.getRenderer());
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
