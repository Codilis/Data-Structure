//
// Created by Codilis on 14/09/2018.
//

#include <iostream>
using namespace std;


struct node {
    char bracket;
    node * next;
};

node *insert(node *head, char value){
    node * temp = new node;
    temp->next = head;
    head = temp;
    temp->bracket = value;
    return head;

}


bool correct_brackets(char brackets[100], int n) {
    node *head = new node;
    head = NULL;
    bool ans = false;
    for (int i = 0; i < n; ++i) {
        if (brackets[i] == '{' || brackets[i] == '[' || brackets[i] == '(')
            head = insert(head, brackets[i]);
        else {
            if (head == NULL) {
                ans = false;
                break;
            }
            char x = head->bracket;
            head = head->next;
            if(brackets[i] == '}' && x == '{')
                ans = true;
            else if (brackets[i]==')' && x == '(')
            ans = true;
            else if (brackets[i]==']' && x == '[')
                ans = true;
            else {
                ans = false;
                break;
            }
        }
    }
    if (head != NULL)
        ans = false;
    return ans;
}

int main(){
    char brackets[100];
    int n;

    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>brackets[i];
    }
    if (correct_brackets(brackets, n))
        cout<<"CORRECT";
    else
        cout<<"INCORRECT";


}