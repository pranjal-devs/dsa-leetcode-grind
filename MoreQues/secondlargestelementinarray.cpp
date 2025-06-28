#include<iostream>
using namespace std;
void printarray(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("%d\t",*(arr+i));
    }
}
int findsecondlargest(int *arr,int size){
    // first sort the array
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[i]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    int largest=arr[size-1];
    int secondlargest=0;
    for(int j=size-2;j>=0;j--){
        if(arr[j]!=largest){
            secondlargest=arr[j];
            break;
        }
    }
    return secondlargest;

}
int main(){
    int arr[10]={1,2,3,4,5,5,5,5,5,5};
    printarray(arr,10);
    cout << "The second largest element of the array is : " << findsecondlargest(arr,10);
    return 0;
}