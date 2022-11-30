#pragma once
class Node {
private:
public:
	int val;
	Node* next;
	Node* left;
	Node* right;
	Node(int _val) : val(_val), next(nullptr), left (nullptr),  right(nullptr) {};
	Node() : next(nullptr), left(nullptr), right(nullptr) {};
};