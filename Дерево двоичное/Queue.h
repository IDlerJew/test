#pragma once
#include "Node.h"
#include <iostream>
using namespace std;
class Queue
{
public:
	int size;
	Node* first;
	Node* last;
	Queue();
	Queue(int _val);
	void Add(int _val);
	void Add(Node* _val);
	int  Pop();
	void Print();
};

