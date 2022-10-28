//
// Created by ArtMed on 27.10.2022.
//
#include <gtest/gtest.h>
#include "../src/solver.h"
#include <string>
#include <vector>

using namespace std;


TEST(in_out_data, is_inside_poly)
{
    string ans_in = "In poly";
    string ans_on = "On the board";
    string ans_out = "Outside poly";

    vector<double> xv1 = {0, 0, 1, 2, 2};
    vector<double> yv1 = {0, 2, 1, 2, 0};
    double x1= 1.4;
    double y1 = 1.5;

    vector<double> xv2 = {0, 0, 1, 2, 2};
    vector<double> yv2 = {0, 2, 1, 2, 0};
    double x2= 4;
    double y2 = 5;

    vector<double> xv3 = {0, 0, 1, 2, 2};
    vector<double> yv3 = {0, 2, 1, 2, 0};
    double x3= 1;
    double y3 = 1;

    vector<double> xv4 = {0, 0, 2, 2};
    vector<double> yv4 = {0, 2, 0, 2};
    double x4= 1;
    double y4 = 1;

    vector<double> xv5 = {0, 0, 2, 2};
    vector<double> yv5 = {0, 2, 0, 2};
    double x5= 0.9;
    double y5 = 0.7;

    vector<double> xv6 = {0, 0, 2, 2};
    vector<double> yv6 = {0, 2, 0, 2};
    double x6= 1;
    double y6 = 0;

//    ASSERT_EQ(is_inside_poly(xv1, yv1, x1, y1, ans_in), 0);
//    ASSERT_EQ(is_inside_poly(xv2, yv2, x2, y2, ans_out), 0);
//    ASSERT_EQ(is_inside_poly(xv3, yv3, x3, y3, ans_on), 0);
//    ASSERT_EQ(is_inside_poly(xv4, yv4, x4, y4, ans_on), 0);
//    ASSERT_EQ(is_inside_poly(xv5, yv5, x5, y5, ans_in), 0);
//    ASSERT_EQ(is_inside_poly(xv6, yv6, x6, y6, ans_out), 0);


    ASSERT_EQ(is_inside_poly(xv1, yv1, x1, y1), 1);
    ASSERT_EQ(is_inside_poly(xv2, yv2, x2, y2), 1);
    ASSERT_EQ(is_inside_poly(xv3, yv3, x3, y3), -1);
    ASSERT_EQ(is_inside_poly(xv4, yv4, x4, y4), -1);
    ASSERT_EQ(is_inside_poly(xv5, yv5, x5, y5), 1);
    ASSERT_EQ(is_inside_poly(xv6, yv6, x6, y6), 1);
    cout<<"=============Test completed==========="<<endl;

}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}