
#include <iostream>
#include "List.h"
using namespace std;

struct node {
    int height;
    int key;
    struct node* left, * right;
    node(int k) { key = k; left = right = 0; height = 1; }
};

int maxfind(List* j) {
    Node* p = new Node();
    int i = 0;
    p = j->Getfirst();
    while (p) {
        i++;
        p = p->next;
    }
    while (j->Getfirst()) {
        j->delete_first();
    }
    return i;
}
node* build2(int a[], node* root, int l, int r) {    //������� ������������ ��������� ������ 
    if (l > r) {
        return nullptr;
    }
    int mid = (l + r) / 2;
    node* p = new node(a[mid]);
    root = p;
    root->left=build2(a, root->left, l, mid - 1);
    root->right=build2(a, root->right, mid + 1, r);
    return p;
}

void addlist(node* j,List *k) {
    if (!j)return;
    k->push_back(j->key);
    addlist(j->left, k);
    addlist(j->right, k);
}

void  max(node* p,List* j,int k ) {
    if (p == nullptr) {
        return;
    }
    if (k < p->key) {
        j->push_start(1);
    }
    max(p->left,  j,  k);
    max(p->right, j, k);
}

// ������� ����
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// ��������������� (inorder) �����
void inorder(struct node* root) {
    if (root != NULL) {
        // ������� ����
        inorder(root->left);

        // ������� ������
        cout << root->key << " -> ";

        // ������� �����
        inorder(root->right);
    }
}

// ������� ����
struct node* insert(struct node* _node, int key) {
    // ���������� ����� ����, ���� ������ ������
    if (_node == NULL) {
        node* k = new node(key);
        return k;
    }

    // �������� � ������ ����� � ��������� ����
    if (key < _node->key)
        _node->left = insert(_node->left, key);
    else
        _node->right = insert(_node->right, key);
    
    return _node;
}

// ���� inorder-���������
struct node* minValueNode(struct node* node) {
    struct node* current = node;

    // ���� ������� ����� ���� � �� � ����� inorder-����������
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// �������� ����
struct node* deleteNode(struct node* root, int key) {
    // ����������, ���� ������ ������
    if (root == NULL) return root;

    // ���� ����, ������� ����� �������
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // ���� � ���� ���� �������� ������� ��� �� ���
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // ���� � ���� ��� �������� ��������
        struct node* temp = minValueNode(root->right);

        // �������� inorder-��������� �� ����� ����, ������� ����� �������
        root->key = temp->key;

        // ������� inorder-���������
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
node* buildfinal(node * root) {
    if (!root)return nullptr;
    List* y = new List();
    
    addlist(root, y);
    y->sort();
    y->print();
    Node* h = new Node();
    h = y->Getfirst();
    int t = 0;
    while (h) {
        t++;
        h = h->next;
    }
    h = y->Getfirst();
    int *a=new int[t];
    for (int i = 0; i < t; i++) {
        a[i] = h->val;
        h = h->next;
    }
    struct node* root2 = NULL;
    root2= build2(a, root2, 0, t-1);
    return root2;
}
void find(node* root, int k,List* j) {
    if (!root) return;
    if (root->key == k) {
        j->push_back(0);
        return;
    }
     find(root->left, k,j);
     find(root->right, k,j);
}
// ������ �������
int main() {
    setlocale(0, "rus");
    struct node* root = NULL;
    root = insert(root, 30); //���������� ���������
    root = insert(root, 15);
    root = insert(root, 11);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 2);
    inorder(root); // ������� �����
    cout << endl;
    struct node* root2 = NULL;
    root2 = buildfinal(root); //������������ ������ ����� ������ 
    inorder(root2);
    deleteNode(root2, 4);  //�������� ��������� 
    cout << endl;
    inorder(root2);
    cout << endl;
    List* p=new List;   //����� ��������� ������ ���������
    max(root2, p, 8);
    cout << maxfind(p)<<endl;
    find(root2, 28,p);
    if (!p->is_empty()){ //����� �������� 
        cout << "������" << endl;
    }
    else cout << "�� ������" << endl;

}