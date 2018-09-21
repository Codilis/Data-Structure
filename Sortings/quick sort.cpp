//
// Created by Codilis on 21/09/2018.
//

#include <iostream>

using namespace std;

void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}


int partition(int a[], int start, int end) {

    int pivot = a[end];
    int i = start - 1;

    for (int j = start; j < end; ++j) {
        if(a[j] <= pivot){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[end]);
    return (i+1);
}

void quick_sort(int a[], int start, int end) {

    if (start < end){
        int pt = partition(a, start, end);
        quick_sort(a, start, pt-1);
        quick_sort(a, pt+1, end);
    }

}

int main(){

    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int s = 0;
    int e = sizeof(a)/ sizeof(a[0]);
    quick_sort(a, s, e);
    int size = sizeof(a)/ sizeof(a[0]);
    for (int i = 0; i < size; ++i) {
        cout<<a[i]<<"\t";
    }
    return 0;
}