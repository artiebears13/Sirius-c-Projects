#include <iostream>
#include <fstream>
#include <sstream>
#include "robot.h"

using namespace std;

Robot::Robot(int x1, int y1, direction dir1) {
    x = x1;
    y = y1;
    dir = dir1;
}

void Robot::action(Command command) {
    switch (command) {
        case f:
// ------------moving forward
            switch (dir) {
                case up:
                    y += 1;
                    break;
                case down:
                    y -= 1;
                    break;
                case lleft:
                    x -= 1;
                    break;
                case rright:
                    x += 1;
                    break;
                default:
                    cout << "undefined orientation";
                    break;
            }
            break;
        case b:
//------------------moving backward-------------------
            switch (dir) {
                case up:
                    y -= 1;
                    break;
                case down:
                    y += 1;
                    break;
                case lleft:
                    x += 1;
                    break;
                case rright:
                    x -= 1;
                    break;
                default:
                    cout << "undefined orientation";
                    break;
            }
            break;
        case r:
//-----------------turning right-------------
            switch (dir) {
                case up:
                    dir = rright;
                    break;
                case down:
                    dir = lleft;
                    break;
                case lleft:
                    dir = up;
                    break;
                case rright:
                    dir = down;
                    break;
                default:
                    cout << "undefined orientation";
                    break;
            }
            break;
        case l:
//-----------------turning left-------------
            switch (dir) {
                case up:
                    dir = lleft;
                    break;
                case down:
                    dir = rright;
                    break;
                case lleft:
                    dir = down;
                    break;
                case rright:
                    dir = up;
                    break;
                default:
                    cout << "undefined orientation";
                    break;
            }
            break;
        default:
            cout << "unknown command";
            break;


    }
}

void Robot::print_pos() {
    cout << "x:" << x << ", y:" << y << ", direction:" << dir << endl;
}

Command convert_command(string s) {
    if (s == "f") return f;
    else if (s == "b") return b;
    else if (s == "l") return l;
    else if (s == "r") return r;
    else return undef_command;
}

direction convert_orient(string s) {
    if (s == "up") return up;
    else if (s == "down") return down;
    else if (s == "right") return rright;
    else if (s == "left") return lleft;
    else return undef_orient;
}

vector<Command> get_commands(string filename){
    vector<Command> command;
    ifstream infile;
    infile.open(filename);
    if (!infile) {
        cout << "Unable to open file";
        exit(-1);
    }

    string brain_file;
    while(getline(infile, brain_file)) {
        istringstream iss(brain_file);
        string c;
        iss >> c;
        Command ci = convert_command(c);
        if (ci == undef_command) {
            cout << "Unable command in input file";
            exit(-1);
        }
        command.push_back(ci);
    }
    return command;
}