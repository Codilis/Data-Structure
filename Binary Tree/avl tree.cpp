//
// Created by Codilis on 07/09/2018.
//
#include <iostream>

struct node{
    node *left;
    int value;
    node *right;
    int height;
};

int calculate_balance_factor(node *head){
    int factor;
    if (head == NULL)
        return 0;
    else
        factor = head->left->height - head->right->height;
    return factor;
}

node *right_rotate(node *head) {

    node *temp1 = head->left;
    node *temp2 = temp1->right;

    temp1->right = head;
    head->left = temp2;

    head->height = __max(head->left->height, head->right->height);
    temp1->height = __max(temp1->left->height, temp1->right->height);

    return temp1;
}

node *left_rotate(node *head) {
    return head;
}

node *insert(node *head, int a) {
    if (head == NULL){
        node *temp = new node;
        temp->value = a;
        temp->right = NULL;
        temp->left = NULL;
        head = temp;
        temp->height = 1;
    } else {
        if (a > head->value) {
            head->right = insert(head->right, a);
        } else if (a < head->value) {
            head->left = insert(head->left, a);
        } else
            return head;
    }
    head->height = 1 + __max(head->left->height, head->right->height);

    int balance_factor = calculate_balance_factor(head);

    // Left Left Case
    if(balance_factor > 1 && a < head->left->value)
        return right_rotate(head);
    // Right Right Case
    if(balance_factor < -1 && a > head->right->value)
        return left_rotate(head);
    // Left Right Case
    if(balance_factor > 1 && a > head->left->value) {
        head->left = left_rotate(head->left);
        return right_rotate(head);
    }
    // Right Left Case
    if (balance_factor < -1 && a < head->right->value){
        head->right = right_rotate(head->right);
        return left_rotate(head);
    }
    return head;
}

void print(node * head){
    if (head != NULL) {
        std::cout << head->value << "\t";
        print(head->left);
        print(head->right);
    }
}

int main(){
    int a[] = {6, 7, 9, 4, 1, 3, 15, 17, 5, 2};
    node *head = new node;
    head = NULL;
    for (int i = 0; i < 10; ++i) {
        head = insert(head, a[i]);
    }
    print(head);

}
