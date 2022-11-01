#include "linked_list.h"
#include <iostream>
#include <ostream>

using namespace std;

LinkedList::LinkedList() = default;

void LinkedList::addNode(int element) {
    Node *new_node = new Node(element);
    if (head == nullptr) {
        head = new_node;
        end = head;
        return;
    }
    end->pnext = new_node;
    end = end->pnext;
}


void LinkedList::deleteElement(int element) {
    Node *pr = nullptr, *cur = head;
    while (cur != nullptr && (cur->pnext != nullptr || cur->data == element)) {
        if (cur->data == element) {

            Node *p = head;
            if (pr == nullptr) {
                head = head->pnext;
            } else {
                p = cur;
                pr->pnext = cur->pnext;
            }
            delete p;

            if (pr == nullptr)
                cur = head;
            else
                cur = pr->pnext;
            continue;
        }
        if (pr == nullptr)
            pr = head;
        else
            pr = pr->pnext;
        cur = pr->pnext;
    }
}


void LinkedList::process_file(const string &filename) {
    ifstream f(filename);
    if (!f.is_open()) {
        cerr << "File is not open" << endl;
        exit(-1);
    }
    int el_to_del;
    while (!f.eof()) {
        int element;
        f >> element;
        if (f.eof()) { el_to_del = element; }
        else { addNode(element); }
    }
    deleteElement(el_to_del);
//    cout << *this;
}

ostream &operator<<(ostream &os, const LinkedList &linkedList) {
    if (linkedList.head == nullptr) {
        os << "Linked list is empty";
        return os;
    }
    Node *p = linkedList.head;
    while (p->pnext != nullptr) {
        os << p->data << " ";
        p = p->pnext;
    }
    os << p->data;
    return os;
}
