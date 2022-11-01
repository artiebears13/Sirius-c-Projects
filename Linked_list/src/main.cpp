#include <iostream>
#include "linked_list.h"

using namespace std;

int main(int argc, char **argv) {
    string filename;

    try {
        filename = argv[1];
    }
    catch (invalid_argument) {
        cerr << "Incorrect arguments format\n";
        cerr << "Yours: \"" << argv[1] << "\"\n";
        cerr << "Correct: \"<string>\"\n";
        exit(-1);
    }

    LinkedList list = LinkedList();
    list.process_file(filename);
    cout << list;
    return 0;
}
