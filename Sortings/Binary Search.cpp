//
// Created by Codilis on 22/09/2018.
//

#include <iostream>

using namespace std;

bool binary_search(int a[], int s, int e, int x) {

    if (x >= a[s] && x <= a[e-1]){
        int mid = (s+e)/2;

        if (a[mid] == x)
            return true;
        else if (a[mid] > x)
            return binary_search(a, s, mid, x);
        else
            return binary_search(a, mid, e, x);
    }
    else
        return false;
}

int main(){

    int a[] = {1, 5, 6, 7, 9, 12, 43, 65};
    int n = sizeof(a)/ sizeof(a[0]);
    int x;
    cin>>x;
    if (binary_search(a, 0, n, x))
        cout<<"EXISTS";
    else
        cout<<"DOES NOT EXISTS";

    return 0;
}