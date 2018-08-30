#include <iostream>

struct node{
    int value;
    node *address;
};
//INSERT NODE AT THE BEGINING OF LIST
node * insert_begin(int a, node *head){
    node *temp = new node;
    temp->value = a;
    temp->address = head;
    head = temp;
    return head;
}

//INSERT NODE AT THE END OF NODE
node * insert_end(int a, node *head){
    node *temp = new node;
    node *temp1 = new node;
    if(head == NULL){
        temp->address = NULL;
        temp->value = a;
        head = temp;
        return head;
    }
    temp1 = head;
    while(temp1->address != NULL){
        temp1 = temp1->address;
    }
    temp1->address = temp;
    temp->value = a;
    temp->address = NULL;
    return head;
}
void print(node *head){
    node *temp = new node;
    temp = head;
    while(temp != NULL){
        std::cout<<temp->value<<"\t";
        temp = temp->address;
    }
    std::cout<<std::endl;
}
//DELETE FROM BEGINING
node *del_begin(node *head){
    if(head == NULL){
        return head;
    }
    head = head->address;
    return head;
}
//DELETE FROM END
node *del_end (node *head){
    node *temp = new node;
    if(head == NULL){
        return head;
    }
    if(head->address == NULL){
        head = NULL;
        return head;
    }
    temp = head;
    while(temp->address->address != NULL){
        temp = temp->address;
    }
    temp->address = NULL;
    return head;
}
int main(){
    node *head = new node;
    head = NULL;
    int a[] = {3,5,8,7,4,2};
    for (int i = 0; i < 6; ++i) {
        head = insert_begin(a[i], head);
    }
    print(head);
    head = del_begin(head);
    print(head);
    head = del_end(head);
    print(head);

}
