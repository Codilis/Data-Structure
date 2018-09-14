//
// Created by Codilis on 14/09/2018.
//

#include <iostream>

struct node {
    char bracket;
    node * next;
};
using namespace std;
int main(){
    char brackets[100];
    int n;
    node *head = new node;
    head = NULL;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>brackets[i];
    }

    for (int i = 0; i < n; ++i) {
        if (brackets[i] == '{')

    }

}