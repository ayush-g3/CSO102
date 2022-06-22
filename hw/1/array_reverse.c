#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    
    int arr[N];
    for(int i=0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    
    for(int i=0; i < N/2; i++){
        int temp = arr[i];
        arr[i]=arr[N-1-i];
        arr[N-1-i]=temp;
    }
    
    for(int i=0; i < N; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}