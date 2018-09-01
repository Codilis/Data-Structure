//
// Created by Codilis on 02/09/2018.
//

#include <iostream>

struct node{
    node *left ;
    int value;
    node *right;
};

node * insert(int a, node *head) {
    if (head == NULL) {
        node *temp = new node;
        temp->value = a;
        head = temp;
        temp->right = NULL;
        temp->left = NULL;

    } else {
        if (head->value > a)
            head->left = insert(a, head->left);
        else
            head->right = insert(a, head->right);
        return head;
    }
}

void print_preorder(node *head){
    if (head != NULL) {
        std::cout << head->value << "\t";
        print_preorder(head->left);
        print_preorder(head->right);
    }
}

int main(){
    int a[] = {26, 5, 9, 6, 7, 3, 23, 78, 65, 25, 4};
    node *head = new node;
    head = NULL;
    for (int i = 0; i < 11; ++i) {
        head = insert(a[i], head);
    }
    print_preorder(head);
    return 0;
}