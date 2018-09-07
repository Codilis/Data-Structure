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
    }
    return head;
}

node * minValueNode(node *head){
    node* current = head;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

node *del(int a, node *head){
    if(head == NULL){
        return head;
    }
    if(a < head->value){
        head->left = del(a, head->left);
    } else if(a > head->value){
        head->right = del(a, head->right);
    } else{
        if(head->left == NULL){
            node *temp = head->right;
            free(head);
            return  temp;
        } else if(head->right == NULL){
            node * temp = head->left;
            free(head);
            return temp;
        }
        node *temp = minValueNode(head->right);

        head->value = temp->value;
        head->right = del(a, head->right);
    }
    return head;

}

void  print_nth_row(node *head, int n){
    if (n == 1){
        std::cout<<head->value<<"\t";
    }
    else {
        if (head->left != NULL)
            print_nth_row(head->left, n - 1);
        if (head->right != NULL)
            print_nth_row(head->right, n - 1);
    }
}

void print_preorder(node *head){
    if (head != NULL) {
        std::cout << head->value << "\t";
        print_preorder(head->left);
        print_preorder(head->right);
    }
}

void print_postorder(node *head){
    if(head != NULL) {
        print_postorder(head->left);
        print_postorder(head->right);
        std::cout << head->value<<"\t";
    }
}

void print_inorder(node *head){
    if (head != NULL) {
        print_preorder(head->left);
        std::cout << head->value << "\t";
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
    std::cout<<std::endl;
    print_nth_row(head, 1);
    std::cout<<std::endl;
    print_postorder(head);
    std::cout<<std::endl;
    print_inorder(head);

    del(3, head);
    std::cout<<std::endl;
    print_inorder(head);
    return 0;
}