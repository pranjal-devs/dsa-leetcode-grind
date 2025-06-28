#include<stdio.h>
#include<stdlib.h>
void printarray(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("%d\t",*(arr+i));
    }
}

int findmissing(int *arr,int n){
    for(int i=0;i<=n;i++){
        if(arr[i]!=i){
            return i;
            
        }
    }
    return n;
}

int main(){
    int arr[4]={0,3,1,4};
    printarray(arr,4);
    printf("The missing element is : %d",findmissing(arr,4));
    return 0;
}