#include <gtest/gtest.h>
#include <wx/gdicmn.h>
#include "../src/ui/SpaceFactory.cpp"
#include <equals.h>

TEST(SpaceFactory, ItCreatesASpaceForTheScreen){
    ScreenSpace screenSpace = SpaceFactory::DisplayScreen();
    ScreenSpace SCREEN_SD = {
        wxPoint(0,2),
        wxSize(640,490)
    };

    _eq(screenSpace.location, SCREEN_SD.location);
    ASSERT_EQ(screenSpace, SCREEN_SD);
}

TEST(SpaceFactory, ItCreatesSpacesForOneByOneGridButton){
    ScreenSpace button = SpaceFactory::Button(ButtonLayout(0,0,1,1));
    ScreenSpace expectedButton = ScreenSpace(wxPoint(8,8), wxSize(48,48));

    ASSERT_EQ(button.location, expectedButton.location);
    ASSERT_EQ(button.size, expectedButton.size);
}

TEST(SpaceFactory, ItCreatesSpacesForTwoByOneGridButton){
    ScreenSpace button = SpaceFactory::Button(ButtonLayout(0,0,2,1));
    ScreenSpace expectedButton = ScreenSpace(wxPoint(8,8), wxSize(104,48));

    ASSERT_EQ(button.location, expectedButton.location);
    ASSERT_EQ(button.size, expectedButton.size);
}

TEST(SpaceFactory, ItCreatesSpacesForOneByTwoGridButton){
    ScreenSpace button = SpaceFactory::Button(ButtonLayout(0,0,1,2));
    ScreenSpace expectedButton = ScreenSpace(wxPoint(8,8), wxSize(48,108));

    ASSERT_EQ(button.location, expectedButton.location);
    ASSERT_EQ(button.size, expectedButton.size);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}