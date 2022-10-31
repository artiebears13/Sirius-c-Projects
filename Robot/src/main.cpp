#include <iostream>
#include <fstream>
#include <sstream>
#include "robot.h"
#include "plotting.h"


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
    string file_path="..\\src\\commands.txt";
    ofstream my_file;
    my_file.open(file_path);
    my_file.clear();

    for (int i = 0; i < command.size(); ++i) {
        robot.action(command[i]);
        my_file<<robot.x<<" "<<robot.y<<endl;
    }
    string ans = "3 5 right";
    cout<<1;
    robot.print_pos();
    plot(file_path);
    return 0;


}
