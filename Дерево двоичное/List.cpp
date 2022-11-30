#include "List.h"

#include <iostream>
#include <math.h>

using namespace std;

List::List() : first(nullptr), last(nullptr) {}

Node* List::Getlast() {
    return last;
}

Node* List::Getfirst() const {
    return first;
}

bool List::is_empty() {
    if (first) {

        return  false;
    }
    else return true;
}

void List::push_back(int _val) {
    Node* p = new Node(_val);
    if (is_empty()) {
        first = p;
        last = p;
        return;

    }
    else {

        last->next = p;
        last = p;
    }
}

void List::push_back(int _val, int _degree)
{
    Node* p = new Node(_val);
    if (is_empty()) {
        first = p;
        last = p;
        return;

    }
    else {

        last->next = p;
        last = p;
    }
}

void List::push_start(int _val)
{
    Node* p = new Node;
    p->val = _val;
    p->next = first;
    first = p;
}

void List::push_start(int _val, int _degree)
{
    Node* p = new Node;
    p->val = _val;
    p->next = first;
 
    first = p;
}

void List::delete_first()
{
    Node* p = first;

    p = p->next;
    delete first;
    first = p;

}

void List::print() {
    if (is_empty()) return;
    Node* p = first;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int List::size() {
    int i = 0;
    Node* p = first;
    while (p) {
        p = p->next;
        i++;

    }
    return i;
}
void List::create(int _maxdegree) {
    int b = _maxdegree;
    for (int i = -1; i < _maxdegree; i++) {
        push_back(0, b);
        b--;
    }
}
void List::sort()
{
    Node* p = new Node;
    Node* f = new Node;
    p = first;
    f = first->next;
    int i = 0;
    int j = 0;
    while (true) {
        p = first;
        f = first->next;
        while (f) {
            if (p->val > f->val) {
                j = p->val;
                p->val = f->val;
                f->val = j;
                i++;
            }
            f = f->next;
            p = p->next;
        }
        if (i == 0)break;
        i = 0;
    }
}
void List::clear()
{
    Node* p = new Node;
    Node* j = new Node;
    p = first;
    j = first->next;
    while (j) {
        delete p;
        p = j;
        j = j->next;
    }
    delete p;
}
void List::reverse() {
    double save1 = 0;
    for (int i = 0; i < (size() / 2); i++) {

        Node* p = first;
        Node* f = first;
        for (int j = 0; j < i; j++) {
            p = p->next;
        }
        save1 = p->val;
        for (int k = 1; k < size() - i; k++) {
            f = f->next;
        }
        p->val = f->val;
        f->val = save1;
    }
    return;
}



