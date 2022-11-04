#pragma once
#include <iostream>

#ifndef LINKED_LIST_LIST_H
#define LINKED_LIST_LIST_H

using namespace std;

//struct that contains its own value and pointer to next
class Node {
public:
    int val = 0;
    Node *next;

    //constructor
    Node(int v) {
        val = v;
        next = nullptr;   //at the beginning object not linked with others
    }
//    ~Node()
//    {
//        delete next;
//    }

};

//list specifies by pointers on first and last elements
class List {
public:
    Node *first;
    Node *last;

    List() : first(nullptr), last(nullptr) {cout<<"constructor"<<endl;}; //constructor

    ~List();          //destructor

    //returns true is list is empty
    bool is_empty() {
        return first == nullptr;
    };

    //add to the end
    int push_back(int val) {
        Node *p = new Node(val);  //connecting
        if (is_empty()) {            //if list was empty => new node is the first and last
            first = p;
            last = p;
            return 0;
        };

        last->next = p;           //initialize connect out element with next (next is link to pushed)
        last = p;                 //rewrite last to pushed element
        return 0;
    };

    //removing first
    int remove_first() {
        Node *p = first;
        first = p->next;   //next element become first
        delete p;
        return 0;
    }

    //removing last
    int remove_last() {
        Node *p = first;
        while (p->next != last) {    //searching pre-last
            p = p->next;             //pointer to last
        }
        p->next = nullptr;           //clear pointer to last
        delete last;                 //delete pointer to last
        last = p;                    //pre-last become last
        return 0;
    }

    //remove element with value == n
    int remove(int n);

    string print() {
        if (is_empty()) {
            cout << "Linked list is empty" << endl;
            return "Linked list is empty";
        }
        Node *p = first;
        string arr;
        while (p) {
            cout << p->val << " "; //p->data
            if (p->next != nullptr) {
                arr += to_string(p->val) + " ";
            } else {
                arr += to_string(p->val);
            }
            p = p->next;
        }
        cout << endl;
        return arr;
    }
};

int delete_n(List l, int n);

#endif //LINKED_LIST_LIST_H
