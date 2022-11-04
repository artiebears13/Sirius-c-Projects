#pragma once
#include <iostream>
#include "list.h"

using namespace std;

int List::delete_n( int n) {
    int counter = 0;
    while (remove(n) != 1) {
        counter++;
    };
    if (counter == 0) {
        cout << "Element " << n << " does not in list" << endl;
    };

    string my_ans = print();
    return 0;
}

List::~List() {
    cout<<"destructor"<<endl;
    while (!is_empty()){
        if (last!=first){
            remove_first();
        } else{
            first =nullptr;
            last =nullptr;

        }
    }

}


int List::remove(int n) {
    if (is_empty()) {
        // cout << "Linked list is empty" << endl;
        return 1;
    }

    if (first->val == n) {        //if value of first element is equals to n then we should remove first
        remove_first();
        return 0;
    } else if (last->val == n) {   //if value of last element is equals to n then we should remove last

        remove_last();
        return 0;
    }


    //if deleting not first or last
    Node *prev = first;
    Node *curr = prev->next;
    while (curr && curr->val != n) {     //while not last element and not equals to n goes to next
        prev = prev->next;
        curr = curr->next;
    }
    if (!curr) {                                     //we got the end of list
        // cout << "Element does not exist" << endl;
        return 1;
    }
    //we reach this code if found element equal to n
    prev->next = curr->next;    //removing
    delete curr;
    return 0;
}
