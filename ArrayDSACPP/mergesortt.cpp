//merge sorting for 2 sorted arrays
#include<iostream>
void merge(int a[],int b[],int c[],int m,int n){ // function definition with 3 arrays and 2 variables 
// array a for first sorted array and b for second. array c for third array which stores the finally sorted array
// variable m is the size of array a and variable b is the size of array b
    int i,j,k;
    i=j=k=0; // initialising the i,j,k with 0
    while(i<m&&j<n){   //first loop to check both the arrays simultaneously
        if(a[i]<b[j]){   // if the element of array a is lesser than that of array b
            c[k]=a[i];  // then push the value of array a in array c 
            i++; // increment i to point to the next index
            k++;  // increment k to point to the next empty index
        }
        else{   // else if the element of array a is greater than that of array b
            c[k]=b[j]; // then push the value of array b in array c
            j++;  // incremenet j to point to the next index
            k++;  // increment k to point to the next empty index
        }
    }
    while(i<m){  // this loop will put all the remaining values of array a in the array c after the array b size ends
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<n){  // this loop will put all the remaining values of array b in the array c after the array a size ends
        c[k]=b[j];
        k++;
        j++;
    }
}
int main(){
    int a[3]={3,6,9};
    int b[4]={2,4,5,8};
    int c[7];
    merge(a,b,c,3,4);
    printf("The sorted array is as follows : \n");
    for(int i=0;i<7;i++){
        printf("%d\t",c[i]);
    }
}