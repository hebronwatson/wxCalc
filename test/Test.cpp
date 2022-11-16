#include <gtest/gtest.h>
#include <wx/gdicmn.h>
#include "../Calc.cpp"

TEST(RUN_TEST_SUITE, SIMPLE_TEST){

    Examples::Frame frame{};
    wxPoint point{frame.buttonPosition({0,0})};
    wxPoint point2{0,0};
    ASSERT_EQ(point, point2);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}