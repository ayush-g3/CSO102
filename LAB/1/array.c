#include <stdio.h>
#include <stdlib.h>

void display(int *, int);
void create(int **, int);
void insert_begin(int **, int *, int);
void insert_end(int **, int *, int);
void insert_at(int **, int *, int, int);
void insert_after(int **, int *, int, int);
void delete(int **, int *, int);

void display(int *arr, int N){
    for(int i=0; i < N; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void create(int **arr, int N){
    *arr=(int *)malloc(sizeof(int)*N);
    for(int i=0; i < N; i++){
        scanf("%d", *arr+i);
    }
}

void insert_begin(int **arr, int *N, int val){
    *arr=(int *) realloc(*arr, sizeof(int)*(*N+1));
    for(int i=*N-1; i >= 0; i--){
        (*arr)[i+1]=(*arr)[i];
    }
    (*arr)[0]=val;
    (*N)++;
}

void insert_end(int **arr, int *N, int val){
    *arr=(int *)realloc(*arr, sizeof(int)*(*N+1));
    (*arr)[*N]=val;
    (*N)++;
}

void insert_at(int **arr, int* N, int pos, int val){
    *arr=(int *) realloc(*arr, sizeof(int)*(*N+1));
    for(int i=*N-1; i >= pos; i--){
        (*arr)[i+1]=(*arr)[i];
    }
    (*arr)[pos]=val;
    (*N)++;
}

void insert_after(int **arr, int *N, int el, int val){
    for(int i=0; i < *N; i++){
        if((*arr)[i] == el){
            *arr=(int *) realloc(*arr, sizeof(int)*(*N+1));
            for(int j=*N-1; j > i; j--){
                (*arr)[j+1]=(*arr)[j];
            }
            (*arr)[i+1]=val;
            (*N)++;
            break;
        }
    }
}

void delete(int **arr, int *N, int el){
    for(int i=0; i < *N; i++){
        if((*arr)[i] == el){
            for(int j=i; j < *N-1; j++){
                (*arr)[j]=(*arr)[j+1];
            }
            *arr=(int *) realloc(*arr, sizeof(int)*(*N-1));
            (*N)--;
        }
    }
}

int main(){
    int N;
    printf("Enter N: ");
    scanf("%d",&N);
    
    int *arr;
    create(&arr, N);
    
    display(arr, N);
    insert_begin(&arr, &N, 2);
    display(arr, N);
    insert_end(&arr, &N, 9);
    display(arr, N);
    insert_at(&arr, &N, 1, 7);
    display(arr, N);
    insert_after(&arr, &N, 9, 1);
    display(arr, N);
    delete(&arr, &N, 1);
    display(arr, N);
    free(arr);
    arr=NULL;
    return 0;
}