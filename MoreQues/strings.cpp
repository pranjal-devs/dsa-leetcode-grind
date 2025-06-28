#include<iostream>
using namespace std;
int getlength(char str[]){
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        count++;
    }
    return count;   
}
char* getreverse(char str[],int l){
    int s=0;
    int e=l-1;
    while(s<e){
        swap(str[s++],str[e--]);
    }
    return str;
}
char* getreverse2(char *s,int k){
    int st=0;
    int e=k-1;
    while(st<e){
        swap(s[st++],s[e--]);
    }
    return s;
}
int main(){
    char name[20];
    cout << "Enter your name : ";
    cin >> name;
    cout << "Your name is : " << name << endl;
    int l=getlength(name);
    // cout <<" The length of the name  is : " << l << endl;
    // char*reversed=getreverse(name,l);
    // cout <<"The reversed name is : " << reversed << endl;
    char*modifiedname=getreverse2(name,2);
    cout <<"The reversed name upto 2 words is : " << modifiedname << endl;
}