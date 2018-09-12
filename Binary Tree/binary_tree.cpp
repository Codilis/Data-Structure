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
int height(node * head){
    if (head == NULL){
        return -1;
    }
    return 1 + __max(height(head->left), height(head->right));
}
node * minValueNode(node *head){
    node* current = head;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

node * lowest_common_ancestor(node *head, int v1, int v2){
    v1 = __max(v1, v2);
    v2 = __min(v1, v2);
    if (head->value < v1 && head->value > v2)
        return head;
    if (head->value > v1)
        return lowest_common_ancestor(head->left, v1, v2);
    if (head->value < v2)
        return  lowest_common_ancestor(head->right, v1, v2);
    if (head->value == v1 || head->value == v2)
        return head;
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
    std::cout<<"HEIGHT OF TREE IS "<<height(head)<<std::endl<<"TREE IN PRE-ORDER: ";
    print_preorder(head);
    std::cout<<std::endl<<"3rd ROW OF TREE IS: ";
    print_nth_row(head, 3);
    std::cout<<std::endl<<"TREE IN POST-ORDER: ";
    print_postorder(head);
    std::cout<<std::endl<<"TREE IN IN-ORDER: ";
    print_inorder(head);
    std::cout<<std::endl<<"LOWEST COMMON ANCESTOR IS "<<lowest_common_ancestor(head, 78, 9)->value;
    del(3, head);
    std::cout<<std::endl<<"TREE AFTER DELETING VALUE 3 IN IN-ORDER: ";
    print_inorder(head);
    return 0;
}