#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}node;
void insert(node**head,int data){
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    node*temp;
    if(*head==NULL){
        *head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}

int gcd(int x,int y){
    if(x==0&&y==0){
        return -1;
    }
    int gcd;
    for(int i=1;i<=x&&i<=y;i++){
        if(x%i==0&&y%i==0){
            gcd=i;
        }
    }
    return gcd;
}

node*insertGreatestCommonDivisors(node*head){
    node*temp=head;
    while(temp!=NULL&&temp->next!=NULL){
        node*newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        if(newnode==NULL){
            return head;
        }
        newnode->data=gcd(temp->data,temp->next->data);
        newnode->next=temp->next;
        temp->next=newnode;
        temp=newnode->next;
    }
    return head;
}

void display(node*head){
    while(head!=NULL){
        printf("%d\t",head->data);
        head=head->next;
    }
    printf("\n");
}
int main(){
    node*head=NULL;
    insert(&head,18);
    insert(&head,6);
    insert(&head,10);
    insert(&head,3);
    display(head);
    head=insertGreatestCommonDivisors(head);
    display(head);
    return 0;
}