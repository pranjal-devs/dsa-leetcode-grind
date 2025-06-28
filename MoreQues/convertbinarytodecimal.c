#include<stdio.h>
int converttodecimal(int binary){
    int decimal=0,base=1,remainder;
    while(binary>0){
        remainder=binary%10;
        decimal+=remainder*base;
        base*=2;
        binary/=10;
    }
    return decimal;
}
int main(){
    int d=converttodecimal(10);
    printf("%d",d);
}