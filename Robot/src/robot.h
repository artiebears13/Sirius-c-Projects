//
// Created by ArtMed on 29.10.2022.
//

#include <vector>
#include <string>
using namespace std;




enum direction {
    up, // 0
    down, // 1
    rright, // 2
    lleft, // 3
    undef_orient
};

enum Command {
    f, // 0
    b, // 1
    l, // 2
    r, // 3
    undef_command
};

class Robot{
public:
    int x;
    int y;
    direction dir;

    Robot(int x1, int y1, direction dir1);
    void action(Command command);
    void print_pos();
};
Command convert_command(string s);

vector<Command> get_commands(string filename);
direction convert_orient(string s);

