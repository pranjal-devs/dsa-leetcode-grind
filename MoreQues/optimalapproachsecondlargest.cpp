#include<iostream>
using namespace std;
void printarray(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("%d\t",*(arr+i));
    }
}
int findsecondlargest(int *arr,int size){
    int largest=arr[0];
    int secondlargest=-1;
    for(int i=0;i<size;i++){
        if(arr[i]>largest){
            secondlargest=largest;
            largest=arr[i];
        }
        else if(arr[i]>secondlargest&&arr[i]<largest){
            secondlargest=arr[i];
        }
    }
    return secondlargest;
}
int main(){
    int arr[6]={1,2,4,7,7,5};
    printarray(arr,6);
    cout << "The second largest element of the array is : " << findsecondlargest(arr,6);
    return 0;
}