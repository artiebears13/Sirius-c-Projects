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
    int i = line.length() - 1;
    while (i >= 0) {
        switch (line[i]) {
            case ' ':
                i--;
                continue;
            case '+':
                actions.push_back(pplus);
                i--;
                break;
            case '-':
                actions.push_back(mminus);
                i--;
                break;
            case '*':
                actions.push_back(multiply);
                i--;
                break;
            case 't':
                actions.push_back(integral);
                i -= 3;
                break;
            case 'r':
                actions.push_back(derivative);
                i -= 3;
                break;
            default:
                cerr << "incorrect line";
                exit(-1);
                break;
        }

        i--;
    }
    return actions;
}


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

        cout << poly;

        polys.push_back(poly);
    }
    actions = get_actions(line);
//    for (int i = 0; i < actions.size(); ++i) {
//        cout<<actions[i]<<endl;
//    }
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
