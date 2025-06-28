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

// this function is also correct but it exceeds the time limit as it takes bigO(k.n) time complexity 
// but the best time complexity is bigO(n) therefore we use another function with a single loop
node*Rotatelist(node*head,int k){
    node*temp=head;
    node*prev=NULL;
    while(k){
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        temp->next=head;
        prev->next=NULL;
        head=temp;
        k--;
    }
    return head;
}

node*rotatelist(node*head,int k){
    if(head==NULL||head->next!=NULL){
        return head;
    }
    int len=1;
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        len++;
    }
    temp->next=head;
    k%=len;
    for(int i=0;i<len-k;i++){
        temp=temp->next;
    }
    node*newH=temp->next;
    temp->next=NULL;
    return newH;
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
    insert(&head,10);
    insert(&head,20);
    insert(&head,30);
    insert(&head,40);
    insert(&head,50);
    insert(&head,60);
    display(head);
    head=rotatelist(head,2);
    display(head);
    return 0;
}