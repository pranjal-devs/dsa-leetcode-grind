#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}node;
void insert(node**head,int value){
    node*temp;
    node*newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=NULL;
    if(*head==NULL){
        *head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}
void display(node*head){
    while(head!=NULL){
        printf("%d\t",head->data);
        head=head->next;
    }
    printf("\n");
}
node*getintersection(node*head1,node*head2){
    node*temp1=head1;
    node*temp2=head2;
    while(temp1!=NULL){
        while(temp2!=NULL){
            if(temp1->data==temp2->data){
                return temp1;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return NULL;
}
int main(){
    node*head1=NULL;
    insert(&head1,1);
    insert(&head1,2);
    insert(&head1,3);
    insert(&head1,4);
    insert(&head1,5);
    insert(&head1,6);
    node*head2=NULL;
    insert(&head2,7);
    insert(&head2,4);
    insert(&head2,8);
    insert(&head2,4);
    insert(&head2,0);
    insert(&head2,8);
    display(head1);
    display(head2);
    node*intersection=getintersection(head1,head2);
    printf("The intersection of list 1 and list 2 is : %d",intersection->data);
}