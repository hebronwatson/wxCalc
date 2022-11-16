#include <gtest/gtest.h>
#include <wx/gdicmn.h>
#include "../src/SpaceFactory.cpp"

TEST(RUN_TEST_SUITE, CLASS_CONSTRUCTION_TEST){
    ScreenSpace* screenSpace = SpaceFactory::DisplayScreen();
    ASSERT_EQ(screenSpace, nullptr);
    delete screenSpace;
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}