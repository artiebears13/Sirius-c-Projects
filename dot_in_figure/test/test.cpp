//
// Created by ArtMed on 27.10.2022.
//
#include <gtest/>
#include "../src/solver.h"
#include <string>
#include <vector>

using namespace std;

string ans_in = "dot is inside";
string ans_on = "dot is outside";
string ans_out = "dot is on the border";

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
ASSERT_EQ(solver(xv1, yv1, x1, y1), 1);
ASSERT_EQ(solver(xv2, yv2, x2, y2), 0);
ASSERT_EQ(solver(xv3, yv3, x3, y3), -1);
ASSERT_EQ(solver(xv4, yv4, x4, y4), -1);
ASSERT_EQ(solver(xv5, yv5, x5, y5), 1);
ASSERT_EQ(solver(xv6, yv6, x6, y6), 0);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}