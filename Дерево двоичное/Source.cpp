
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
node* build2(int a[], node* root, int l, int r) {    //функция балансировки используя массив 
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

// Создаем узел
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Отсортированный (inorder) обход
void inorder(struct node* root) {
    if (root != NULL) {
        // Обходим лево
        inorder(root->left);

        // Обходим корень
        cout << root->key << " -> ";

        // Обходим право
        inorder(root->right);
    }
}

// Вставка узла
struct node* insert(struct node* _node, int key) {
    // Возвращаем новый узел, если дерево пустое
    if (_node == NULL) {
        node* k = new node(key);
        return k;
    }

    // Проходим в нужное место и вставляет узел
    if (key < _node->key)
        _node->left = insert(_node->left, key);
    else
        _node->right = insert(_node->right, key);
    
    return _node;
}

// Поис inorder-преемника
struct node* minValueNode(struct node* node) {
    struct node* current = node;

    // Ищем крайний левый лист — он и будет inorder-преемником
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Удаление узла
struct node* deleteNode(struct node* root, int key) {
    // Возвращаем, если дерево пустое
    if (root == NULL) return root;

    // Ищем узел, который хотим удалить
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Если у узла один дочерний элемент или их нет
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

        // Если у узла два дочерних элемента
        struct node* temp = minValueNode(root->right);

        // Помещаем inorder-преемника на место узла, который хотим удалить
        root->key = temp->key;

        // Удаляем inorder-преемника
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
// Тестим функции
int main() {
    setlocale(0, "rus");
    struct node* root = NULL;
    root = insert(root, 30); //добавление элементов
    root = insert(root, 15);
    root = insert(root, 11);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 2);
    inorder(root); // обычный вывод
    cout << endl;
    struct node* root2 = NULL;
    root2 = buildfinal(root); //балансировка дерева через массив 
    inorder(root2);
    deleteNode(root2, 4);  //удаление элементов 
    cout << endl;
    inorder(root2);
    cout << endl;
    List* p=new List;   //Поиск элементов больше заданного
    max(root2, p, 8);
    cout << maxfind(p)<<endl;
    find(root2, 28,p);
    if (!p->is_empty()){ //Поиск элемента 
        cout << "Найден" << endl;
    }
    else cout << "Не найден" << endl;

}