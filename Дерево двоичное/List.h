#pragma once
#include "Node.h"

class List
{
private:Node* first;
	   Node* last;


public:
	List();
	Node* Getlast();
	Node* Getfirst() const;
	bool is_empty();
	void push_back(int  _val);
	void push_back(int _val, int _degree);
	void push_start(int _val);
	void push_start(int _val, int _degree);
	void delete_first();
	void print();
	int size();
	void reverse();
	void create(int _maxdegree);
	void sort();
	void clear();

};


;

