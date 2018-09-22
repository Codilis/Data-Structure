//
// Created by Codilis on 22/09/2018.
//

//Question: Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

#include <iostream>

using namespace std;

bool subset_sum(int a[], int n, int k){
    if (k == 0){
        return true;
    }
    if(n == 0 && k != 0)
        return false;
    if (a[n-1] > k)
        return subset_sum(a, n-1, k);
    return subset_sum(a, n-1, k) || subset_sum(a, n-1, k-a[n-1]);
}

int main(){

    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int k;
    cin>>k;
    int n = sizeof(a)/ sizeof(a[0]);
    if (subset_sum(a, n, k))
        cout<<"SUBSET EXISTS";
    else
        cout<<"SUBSET DOES NOT EXSITS";

    return 0;
}