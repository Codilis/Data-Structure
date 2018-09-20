//
// Created by Codilis on 20/09/2018.
//

#include <iostream>

using namespace std;

void insertion_sort(int a[], int length) {
    int j, temp;
    for (int i = 1; i < length; i++) {
        j = i-1;
        temp = a[i];
        while (j > -1 && a[j] > temp){
            a[j + 1] = a[j];
            j -= 1;
        }
        a[j+1] = temp;
    }

    for (int j = 0; j < length; ++j) {
        cout<<a[j]<<"\t";
    }

}

int main(){

    int a[] = {64, 34, 25, 12, 22, 11, 90};
    insertion_sort(a, sizeof(a)/ sizeof(a[0]));

    return 0;
}
