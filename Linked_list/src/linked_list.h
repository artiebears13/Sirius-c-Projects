#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data{};
    Node* pnext{};
    Node()= default;
    explicit Node(int el){data=el;};
};

class LinkedList{
private:
    Node* head = nullptr;
    Node* end = nullptr;
public:
    LinkedList();
    void addNode(int element);
    void deleteElement(int element);
    void process_file(const string &filename);
    friend ostream& operator<<(ostream&, const LinkedList&);
};
