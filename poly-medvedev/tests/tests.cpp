//include the google test dependencies
#include <gtest/gtest.h>
#include "../src/poly.h"

string ans_in = "In poly";
string ans_on = "On the board";
string ans_out = "Outside poly";

vector<float> xv1 = {0, 0, 1, 2, 2};
vector<float> yv1 = {0, 2, 1, 2, 0};
float x1= 1.4;
float y1 = 1.5;

vector<float> xv2 = {0, 0, 1, 2, 2};
vector<float> yv2 = {0, 2, 1, 2, 0};
float x2= 4;
float y2 = 5;

vector<float> xv3 = {0, 0, 1, 2, 2};
vector<float> yv3 = {0, 2, 1, 2, 0};
float x3= 1;
float y3 = 1;

vector<float> xv4 = {0, 0, 2, 2};
vector<float> yv4 = {0, 2, 0, 2};
float x4= 1;
float y4 = 1;

vector<float> xv5 = {0, 0, 2, 2};
vector<float> yv5 = {0, 2, 0, 2};
float x5= 0.9;
float y5 = 0.7;

vector<float> xv6 = {0, 0, 2, 2};
vector<float> yv6 = {0, 2, 0, 2};
float x6= 1;
float y6 = 0;

TEST(in_out_data, is_inside_poly)
{
    ASSERT_EQ(is_inside_poly(xv1, yv1, x1, y1, ans_in), 0);
    ASSERT_EQ(is_inside_poly(xv2, yv2, x2, y2, ans_out), 0);
    ASSERT_EQ(is_inside_poly(xv3, yv3, x3, y3, ans_on), 0);
    ASSERT_EQ(is_inside_poly(xv4, yv4, x4, y4, ans_on), 0);
    ASSERT_EQ(is_inside_poly(xv5, yv5, x5, y5, ans_in), 0);
    ASSERT_EQ(is_inside_poly(xv6, yv6, x6, y6, ans_out), 0);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
