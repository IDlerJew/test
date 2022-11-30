#include "Queue.h"

Queue::Queue()
{
	first = nullptr;
	last = nullptr;
	size = 0;
}

Queue::Queue(int _val)
{
	Node* p = new Node(_val);
	first = p;
	last = p;
	first->next= nullptr;
	size = 1;

}

void Queue::Add(int _val)
{
	Node* p = new Node(_val);
	if (!first) {
		p->next = nullptr;
		first = p;
		last = p;
	}
	else {

		p->next = last;
		last = p;
	}
	size++;
}

void Queue::Add(Node* _val)
{
	if (!first) {
		_val->next = last;
		last = _val;
		first = _val;
		size = 1;
		first->val = _val->val;


	}
	else {
		_val->next = last;
		last = _val;
		size++;
	}
}

int Queue::Pop()
{
	if (!first) {
		exit(-1);
	}
	else {
		if (last == first) {
			int a = last->val;
			last = nullptr;
			first = nullptr;
			size--;
			return a;
			

		}
		else {
			Node* p = last;
			Node* f = last->next;
			while (f->next != nullptr) {
				f = f->next;
				p = p->next;
				
				
			}
			int a = f->val;
			p->next = nullptr;
			first = p;
			size--;
			return a;
			
		}

	}
}

void Queue::Print()
{

	while (last) {
		cout << Pop() << endl;
	}
}
