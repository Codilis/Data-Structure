//
// Created by Codilis on 30/08/2018.
//
#include <iostream>
struct node{
    node * prev;
    int value;
    node * next;
};
struct pointers{
    node *first;
    node *second;
};

// PRINTS FROM STARTING OF LIST
void print_from_begin(node * head){
    while(head->next != NULL){
        std::cout<<head->value<<"\t";
        head = head->next;
    }
    std::cout<<std::endl;
}

//PRINTS IN REVERSE ORDER
void print_from_end(node * tail){
    while (tail->prev != NULL){
        std::cout<<tail->value<<"\t";
        tail = tail->prev;
    }
    std::cout<<std::endl;
}

// INSERT AT THE BEGINNING LIST
pointers insert_begin(int a, node*head, node *tail){
    node * temp = new node;
    pointers pointers1;
    if (tail == NULL){
        tail = temp;
    }
    if(head != NULL){
        head->prev = temp;
    }
    temp->prev = NULL;
    temp->value = a;
    temp->next = head;
    head = temp;
    pointers1.first = head;
    pointers1.second = tail;
    return pointers1;
}

//INSERT AT THE END OF LIST
pointers insert_end(int a, node*head, node *tail){
    node *temp = new node;
    pointers pointers1;
    if (head == NULL){
        head = temp;
    }
    if (tail != NULL) {
       tail->next = temp;
    }
    temp->prev = tail;
    temp->value = a;
    temp->next = NULL;
    tail = temp;
    pointers1.first = head;
    pointers1.second = tail;
    return  pointers1;


}

//DEL A NODE FROM BEGINING
pointers del_begin(node * head, node *tail){
    pointers pointers1;
    if(head == NULL){
        tail = NULL;
        pointers1.first = head;
        pointers1.second = tail;
        return  pointers1;
    }
    if (head->next == NULL){
        head = tail = NULL;
        pointers1.first = head;
        pointers1.second = tail;
        return  pointers1;
    }
    head->next->prev = NULL;
    head = head->next;
    pointers1.first = head;
    pointers1.second = tail;
    return  pointers1;
}

//DEL A NODE FROM END
pointers del_end(node *head, node *tail){
    pointers pointers1;
    if(tail == NULL){
        head = NULL;
        pointers1.first = head;
        pointers1.second = tail;
        return  pointers1;
    }
    if (tail->prev == NULL) {
        head = tail = NULL;
        pointers1.first = head;
        pointers1.second = tail;
        return  pointers1;
    }
    tail->prev->next = NULL;
    tail = tail->prev;
    pointers1.first = head;
    pointers1.second = tail;
    return  pointers1;
}

//SORTING DOUBLY LINKED LIST
node *sort(node * head){
    int tmp;
    for (node *i = head;  i->next != NULL ; i = i->next) {
        for (node *j = i->next; j->next != NULL ; j = j->next) {
            if(i->value > j->value){
                tmp = i->value;
                i->value = j->value;
                j->value = tmp;
            }
        }
    }
    return head;
}


int main(){
    node * head = new node;
    node * tail = new node;
    pointers pointers1;
    head = NULL;
    tail = NULL;
    int a[] = {3,5,8,7,6,2,1};
    for (int i = 0; i < 8; ++i) {
        pointers1 = insert_end(a[i], head, tail);
        head = pointers1.first;
        tail = pointers1.second;
    }
    print_from_begin(head);
//    head = sort(head);
    print_from_begin(head);
    pointers1 = del_begin(head, tail);
    head = pointers1.first;
    tail = pointers1.second;
    print_from_begin(head);
    pointers1 = del_end(head, tail);
    head = pointers1.first;
    tail = pointers1.second;
    print_from_end(tail);
    return 0;
}
