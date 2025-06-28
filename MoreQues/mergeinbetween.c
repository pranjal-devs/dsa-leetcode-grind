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

node* mergeinbetween(node*list1,int a,int b,node*list2){
    node*temp1=list1;
    node*temp2=list1;
    node*prev1=NULL;
    int i=0;
    int j=0;
    while(i<a){
        prev1=temp1;
        temp1=temp1->next;
        i++;
    }
    while(j<b){
        temp2=temp2->next;
        j++;
    }
    temp2=temp2->next;
    prev1->next=list2;
    node*temp3=list2;
    while(temp3->next!=NULL){
        temp3=temp3->next;
    }
    temp3->next=temp2;
    return list1;
}

void display(node*head){
    while(head!=NULL){
        printf("%d\t",head->data);
        head=head->next;
    }
    printf("\n");
}
int main(){
    node*head1=NULL;
    insert(&head1,10);
    insert(&head1,1);
    insert(&head1,13);
    insert(&head1,6);
    insert(&head1,9);
    insert(&head1,5);
    display(head1);
    node*head2=NULL;
    insert(&head2,10);
    insert(&head2,11);
    insert(&head2,12);
    display(head2);
    head1=mergeinbetween(head1,3,4,head2);
    display(head1);
    return 0;
}