#include <iostream>
#include "robot.h"


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

vector<char> get_commands(string filename){

}