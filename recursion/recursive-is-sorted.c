#include <stdio.h>

int isSorted(int* array, int max, int n);

int main(){
    int a[] = {3,6,7,9,12};
    int b[] = {3,4,9,8};
    printf("%d\n", isSorted(a, 12, 5));
    printf("%d\n", isSorted(b, 20, 4));
}

int isSorted(int* array, int max, int n){
    if (n == 1){
        return 1;
    }
    if (array[n-1] < array[n-2] || array[n-1] > max){
        return 0;
    }
    return isSorted(array, max, n-1);
}