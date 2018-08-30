//
// Created by Codilis on 30/08/2018.
//
#include <iostream>
struct node{
    node * prev;
    int value;
    node * next;
};

// INSERT AT THE BEGINNING LIST
node * insert_begin(int a, node*head){
    node * temp = new node;
    if(head != NULL){
        head->prev = temp;
    }
    temp->prev = NULL;
    temp->value = a;
    temp->next = head;
    head = temp;

    return head;
}

//INSERT AT THE END OF LIST
node * insert_end(int a, node*head){
    node *temp = new node;
    if (head == NULL){
        temp->prev = NULL;
        temp->value = a;
        temp->next = NULL;
        head = temp;
        return head;
    }
    node *temp1 = new node;
    temp1 = head;
    while (head->next != NULL){
        head = head->next;
    }
    temp->value = a;
    temp->next = NULL;
    temp->prev = head;
    head->next = temp;
    return temp1;

}

//DEL A NODE FROM BEGINING
node *del_begin(node * head){
    head->next->prev = NULL;
    head = head->next;
    return head;
}

//DEL A NODE FROM END
node * del_end(node *head){
    node *temp = new node;
    temp = head;
    if(head == NULL){
        return head;
    }
    if (head->next == NULL){
        head = NULL;
        return head;
    }
    while (head->next->next != NULL){
        head = head->next;
    }
    head->next = NULL;
    return temp;

}
void print(node * head){
    while(head->next != NULL){
        std::cout<<head->value<<"\t";
        head = head->next;
    }
    std::cout<<std::endl;
}

int main(){
    node * head = new node;
    head = NULL;
    int a[] = {3,5,8,7,6,2,1};
    for (int i = 0; i < 8; ++i) {
        head = insert_end(a[i], head);
    }
    print(head);
    head = del_begin(head);
    print(head);
    head = del_end(head);
    print(head);
    return 0;
}