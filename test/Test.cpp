#include <gtest/gtest.h>
#include <wx/gdicmn.h>
#include "../src/ui/SpaceFactory.cpp"
#include "../src/testutils/equals.h"
#include "../src/op/Operations.h"
#include "../src/op/Calculate.h"

TEST(SpaceFactory, ItCreatesASpaceForTheScreen){
    ScreenSpace screenSpace = SpaceFactory::DisplayScreen();
    ScreenSpace SCREEN_SD = {
        wxPoint(0,0),
        wxSize(640,480)
    };

    _eq(screenSpace.location, SCREEN_SD.location);
    _eq(screenSpace.size, SCREEN_SD.size);
    ASSERT_EQ(screenSpace, SCREEN_SD);
}

TEST(SpaceFactory, ItCreatesSpacesForOneByOneGridButton){
    ScreenSpace button = SpaceFactory::Button(ButtonLayout(0,0,1,1));
    ScreenSpace expectedButton = ScreenSpace(wxPoint(8,8), wxSize(48,48));

    _eq(button.location, expectedButton.location);
    _eq(button.size, expectedButton.size);
}

TEST(SpaceFactory, ItCreatesSpacesForTwoByOneGridButton){
    ScreenSpace button = SpaceFactory::Button(ButtonLayout(0,0,2,1));
    ScreenSpace expectedButton = ScreenSpace(wxPoint(8,8), wxSize(104,48));

    _eq(button.location, expectedButton.location);
    _eq(button.size, expectedButton.size);
}

TEST(SpaceFactory, ItCreatesSpacesForOneByTwoGridButton){
    ScreenSpace button = SpaceFactory::Button(ButtonLayout(0,0,1,2));
    ScreenSpace expectedButton = ScreenSpace(wxPoint(8,8), wxSize(48,104));

    _eq(button.location, expectedButton.location);
    _eq(button.size, expectedButton.size);
}

TEST(Calculate, ItRunsIsolatedCalculations){
    vector<OperationEvent> events;
    events.push_back(OperationEvent(2));
    events.push_back(OperationEvent(OperationType::plus, 2));
    float result = Calculate::ProcessOperations(events);
    ASSERT_EQ(4, result);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}