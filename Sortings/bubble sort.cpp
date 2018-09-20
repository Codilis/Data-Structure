//
// Created by Codilis on 20/09/2018.
//

#include <iostream>

using  namespace std;

void bubble_sort(int a[], int length) {

    for (int i = 0; i < length; ++i) {
        for (int j = i+1; j < length; ++j) {
            if (a[i] > a[j]){
                a[i] += a[j];
                a[j] = a[i]-a[j];
                a[i] = a[i]-a[j];
            }
        }
    }
    for (int k = 0; k < length; ++k) {
        cout<<a[k]<<"\t";
    }

}

int main(){
    int a[] = {2,5,1,4,6,7,2,7,3,6,7,2,6};
    bubble_sort(a,sizeof(a)/ sizeof(a[0]) );
    return 0;
}