#include<iostream>
using namespace std;
void printarray(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("%d\t",*(arr+i));
    }
}
int removeduplicates(int *nums,int numsize){
    int i=0;
    for(int j=1;j<numsize;j++){
        if(nums[i]!=nums[j]){
            nums[i+1]=nums[j];
            i++;
        }
    }
    return i+1;
}
int main(){
    int arr[6]={1,2,4,7,7,5};
    printarray(arr,6);
    cout << "The remove duplicate size is : " << removeduplicates(arr,6);

    return 0;
}