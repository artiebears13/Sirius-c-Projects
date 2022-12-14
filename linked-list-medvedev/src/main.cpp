#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "list.h"

using namespace std;

int main(int argc, char *argv[]) {

    string path = argv[1];
    ifstream infile;
    infile.open(path);
    if (!infile) {
        cerr << "Unable to open file";
        exit(-1);
    }

    string file;
    List l;
    int last;
    while (getline(infile, file)) {
        istringstream iss(file);
        string n_str;
        int n;
        iss >> n_str;
        try {
            n = stoi(n_str);
            l.push_back(n);
            last = n;
        }
        catch (const exception& e) {
            cerr << e.what();
            exit(-1);
        }
    }

//    l.print();
//    cout << endl;
//    cout << last<< endl;

cout<<"before remove last"<<endl;
    l.remove_last();
    cout<<"after remove last"<<endl;
    l.delete_n(last);
    cout<<"after delete_n"<<endl;



    return 0;

}
