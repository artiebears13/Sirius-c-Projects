#include <iostream>
#include <fstream>
#include <sstream>
#include "robot.h"

using namespace std;

int main(int argc, char *argv[]) {
    string path = argv[1];
    int x =atoi(argv[2]);
    int y = atoi(argv[3]);
    string start_orient_str = argv[4];
    cout<<1;
    direction start_orient = convert_orient(start_orient_str);

    if (start_orient == undef_orient) {
        cout << "undefined start orientation";
        return 0;
    }

    Robot robot(x,y,start_orient);
    vector<Command> command;
    command= get_commands(path);

    for (int i = 0; i < command.size(); ++i) {
        robot.action(command[i]);
    }
    string ans = "3 5 right";
    cout<<1;
    robot.print_pos();
    return 0;


}
