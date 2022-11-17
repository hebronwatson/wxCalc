#include <gtest/gtest.h>
#include <wx/gdicmn.h>
#include "../src/SpaceFactory.cpp"

TEST(RUN_TEST_SUITE, CLASS_CONSTRUCTION_TEST){
    ScreenSpace screenSpace = SpaceFactory::DisplayScreen();
    ScreenSpace SCREEN_SD = {
        wxPoint(0,0),
        wxSize(640,480)
    };

    ASSERT_EQ(screenSpace.location, SCREEN_SD.location);
    ASSERT_EQ(screenSpace.size, SCREEN_SD.size);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}