#include <stdio.h>
#define N 5

int update(int arr[], int i) {

    //Base Case
    if (i == 0){
        return arr[0];
    }

    arr[i] = arr[i] + update(arr, i-1);
}

int main() {
    int arr[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int i = N-1;
    update(arr, i);

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}