#include <iostream>
#include "src/poly.h"
#include "src/parsing.h"
#include <vector>

using namespace std;

int main() {
    std::string p1 = "* + [1 0 1] [1 2 3]";
//    std::string p2 = "1 1";
//    Poly poly1(p1);
//    Poly poly2(p2);
//
//    Poly answer;
//    Poly answer2;
//    answer = poly1.derivative();
//    answer2=poly2.integral();
//    cout << answer;

//    parsing(p1);
pair<vector<operators>, vector<Poly>> parsed;
parsed=input_parsing();
  cout<<calculate(parsed);




    return 0;

}
