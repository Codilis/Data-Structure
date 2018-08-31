//
// Created by Codilis on 31/08/2018.
//

#include <iostream>
struct node{
    node *prev;
    int value;
    node *next;
}*head = NULL, *tail = NULL;

//INSERT NODE AT THE BEGINING OF THE LIST
void insert_begining(int a){
    node *temp = new node;
    if (head == NULL){
        tail = temp;
    }
    if (head != NULL){
        head->prev = temp;
    }
    temp->value = a;
    temp->next = head;
    temp->prev = tail;
    tail->next = temp;
    head = temp;
}

//INSERT NODE AT THE END OF THE LIST
void insert_end(int a){
    node *temp = new node;
    if (tail == NULL){
        head = temp;
    }
    if (tail != NULL){
        tail->next = temp;
    }
    temp->next = head;
    temp->value = a;
    temp->prev = tail;
    head->prev = temp;
    tail = temp;
}

//PRINTS FROM STARTING
void print_from_begin(){
    node *temp = head;
    do{
        std::cout<<temp->value<<"\t";
        temp = temp->next;
    }while(temp != head);
    std::cout<<std::endl;
}

//PRINTS FORM END
void print_from_end(){
    node *temp = tail;
    do{
        std::cout<<temp->value<<"\t";
        temp = temp->prev;
    }while(temp != tail) ;
    std::cout<<std::endl;
}

int main(){
    int a[] = {4, 5, 9, 8, 2 ,3, 6};
    for (int i = 0; i < 7; ++i) {
        insert_end(a[i]);
    }
    print_from_begin();
    print_from_end();

}