//
// Created by ArtMed on 03.11.2022.
//

#include <iostream>
#include <regex>
#include "poly.h"
#include <string>

using namespace std;

vector<operators> get_actions(string line) {
    vector<operators> actions;
    std::map <std::string, int> mapping;
    istringstream iss(line);
    mapping["+"]  = pplus;
    mapping["-"]  = mminus;
    mapping["*"] = multiply;
    mapping["int"]  = integral;
    mapping["der"]  = derivative;
    mapping[""]=eempty;
    string sign;
    while (getline(iss,sign, ' ')) {
        if (mapping[sign]==0){
            cerr<<"unknown sign";
            exit(-1);
        }
        switch (mapping[sign]) {
            case pplus:
                actions.insert(actions.begin(),pplus);
                break;
            case mminus:
                actions.insert(actions.begin(),mminus);
                break;
            case multiply:
                actions.insert(actions.begin(),multiply);
                break;
            case integral:
                actions.insert(actions.begin(),integral);
                break;
            case derivative:
                actions.insert(actions.begin(),derivative);
                break;
            case eempty:
                break;
            default:
                cerr << "incorrect line";
                exit(-1);
                break;
        }


    }
    return actions;
}


//vector<operators> get_actions(string line) {
//    vector<operators> actions;
//    int i = line.length() - 1;
//    while (i >= 0) {
//        switch (line[i]) {
//            case ' ':
//                i--;
//                continue;
//            case '+':
//                actions.push_back(pplus);
//                i--;
//                break;
//            case '-':
//                actions.push_back(mminus);
//                i--;
//                break;
//            case '*':
//                actions.push_back(multiply);
//                i--;
//                break;
//            case 't':
//                actions.push_back(integral);
//                if (line[i-1]=='n'){
//                    if (line[i-2]=='i'){
//                        i -= 3;
//                    }
//                }
//
//                break;
//            case 'r':
//                actions.push_back(derivative);
//                i -= 3;
//                break;
//            default:
//                cerr << "incorrect line";
//                exit(-1);
//                break;
//        }
//
//        i--;
//    }
//    return actions;
//}


pair<vector<operators>, vector<Poly>> input_parsing() {

    vector<operators> actions;
    vector<Poly> polys;
//    regex regular("(\\[[0-9 ]*\\])");
    regex regular("(\\[[-?[:digit:]+ ]*\\])");
    cmatch result;
    int pos;
    string line;
    cout << "Please enter your expression:" << endl;
    getline(cin, line);

    while (regex_search(line.c_str(), result, regular)) {
//        cout << result[0] << " ";
        Poly poly(result[0]);
        pos = line.find(result[0]);
        line.erase(pos, result[0].length());

       // cout << poly;

        polys.push_back(poly);
    }
    actions = get_actions(line);
//    for (int i = 0; i < actions.size(); ++i) {
//        cout<<actions[i]<<endl;
//    }
    if (polys.size()==0){
        cerr<<"no polys entered";
        exit(0);
    }
    if (actions.size()==0){
        cerr<<"no signs entered";
        exit(0);
    }
    pair<vector<operators>, vector<Poly>> res;
    res.first = actions;
    res.second = polys;
    return res;
}

Poly calculate(pair<vector<operators>, vector<Poly>> parsed) {
    for (int i = 0; i < parsed.first.size(); ++i) {
        switch (parsed.first[i]) {
            case pplus:
                parsed.second[0] = parsed.second[0] + parsed.second[i + 1];
                break;
            case mminus:
                parsed.second[0] = parsed.second[0] - parsed.second[i + 1];
                break;
            case multiply:
                parsed.second[0] = parsed.second[0] * parsed.second[i + 1];
                break;
            case derivative:
                parsed.second[0] = parsed.second[0].derivative();
                break;
            case integral:
                parsed.second[0] = parsed.second[0].integral();
                break;
            default:
                break;
        }
    }
    return parsed.second[0];
}
