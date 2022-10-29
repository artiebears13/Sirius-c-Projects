#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <typeinfo>

#include "poly.h"

using namespace std;

int main(int argc, char *argv[]) {
//    cout << "argv0  " << argv[0] << endl;
//    cout << "argv1  " << argv[1] << endl;
//    cout << "argv2  " << argv[2] << endl;
//    cout << "argv3  " << argv[3] << endl;
    string path = argv[1];
    float x =atof(argv[2]);
    float y = atof(argv[3]);

//    string path = "../example.txt";
//    float x = 1;
//    float y = 1;

    // read file
    vector<float> x_arr;
    vector<float> y_arr;

    ifstream infile;
    infile.open(path);
    if (!infile) {
        cout << "Unable to open file";
    }

    string brain_file;
    while(getline(infile, brain_file)) {
        istringstream iss(brain_file);
        string x_str, y_str;
        float x, y;
        iss >> x_str >> y_str;
        try {
            x = stof(x_str);
            y = stof(y_str);
        }
        catch (const exception& e) {
            cout << e.what();
            return -1;
        }
        x_arr.push_back(x);
        y_arr.push_back(y);
    }

//    for (int i = 0; i < x_arr.size(); i++) {
//        cout << x_arr[i] << " " << y_arr[i] << endl;
//    }

    string ans = "";
    is_inside_poly(x_arr, y_arr, x, y, ans);
    return 0;
}