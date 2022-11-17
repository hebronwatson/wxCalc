
#include <wx/gdicmn.h>
#include <gtest/gtest.h>

/**
 * 
 * Asserts that wxPoints are equal
*/

bool _eq(const wxPoint& a, const wxPoint& b){
    ASSERT_EQ(a.x, b.x << "X values don't match");
    ASSERT_EQ(a.y, b.y << "Y values don't match");
}
