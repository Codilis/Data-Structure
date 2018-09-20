//
// Created by Codilis on 20/09/2018.
//

#include <iostream>

using namespace std;

void merge(int a[], int l, int m, int r) {


    int s1 = m-l+1;
    int s2 = r-m;

    int L[s1], R[s2];

    for (int n = 0; n < s1; ++n) {
        L[n] = a[l+n];
    }
    for (int n = 0; n < s2; ++n) {
        R[n] = a[m+1+n];
    }

    int i=0, k=l,j=0;
    while (i<s1 && j<s2){
        if(L[i] < R[j]){
            a[k] = L[i];
            i += 1;
        }
        else{
            a[k] = R[j];
            j += 1;
        }
        k++;
    }

    while (i < s1){
        a[k] = L[i];
        i += 1;
        k += 1;
    }

    while (j<s2){
        a[k] = R[j];
        k += 1;
        j += 1;
    }

}

void merge_sort(int a[], int start, int end) {

    if(start < end) {
        int mid = start +(end-start) / 2;
        merge_sort(a, start, mid);
        merge_sort(a, mid+1, end);
        merge(a, start, mid, end);
    }



}

int main(){

    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int end = sizeof(a)/ sizeof(a[0]);
    int start = 0;
    merge_sort(a, start, end-1);
    for (int i = 0; i < end; ++i) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    return 0;
}