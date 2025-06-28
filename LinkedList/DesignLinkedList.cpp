#include<iostream>
using namespace std;
class MyLinkedList{
    public :
        struct ListNode{
            int val;
            ListNode*next;
            ListNode(int x) : val(x),next(nullptr) {} // created a constructor to initialise value with x and next with nullptr
        };
        ListNode*head;
        MyLinkedList(){
            head=nullptr; // comnstructor initialises an empty linekd list
        }
        int get(int index){
            ListNode*curr=head;
            int count = 0;
            while(curr!=nullptr){
                if(count==index){
                    return curr->val;
                }
                curr=curr->next;
                count++;
            }
        }
        void addAtHead(int val){
            ListNode*newnode=new ListNode(val);
            newnode->next=head;
            head=newnode;
        }
        void addAtTail(int val){
            ListNode*newnode=new ListNode(val);
            if(head==NULL){
                head=newnode;
                return;
            }
            ListNode*curr=head;
            while(curr->next!=nullptr){
                curr=curr->next;
            }
            curr->next=newnode;
        }
        void addAtIndex(int index,int val){
            if(index<0){
                return;
            }
            if(index==0){
                addAtHead(val);
            }
            int count=0;
            ListNode*curr=head;
            while(curr!=nullptr&&count<index-1){
                curr=curr->next;
                count++;
            }
            if(curr==nullptr){
                return;
            }
            ListNode*newnode=new ListNode(val);
            newnode->next=curr->next;
            curr->next=newnode;
        }
        void deleteAtIndex(int index){
            if(index<0){
                return;
            }
            if(index==0){
                if(head!=nullptr){
                    ListNode*temp=head;
                    head=head->next;
                    delete temp;
                }
                return;
            }
            ListNode*curr=head;
            int count=0;
            while(curr!=nullptr&&count<index-1){
                curr=curr->next;
                count++;
            }
            if(curr==nullptr||curr->next==nullptr) return;
            ListNode*temp=curr->next;
            curr->next=curr->next->next;
            delete(temp);
        }
        
};
int main() {
    MyLinkedList* obj = new MyLinkedList();
    
    // Add elements
    obj->addAtHead(1);       // Linked list: 1
    obj->addAtTail(3);       // Linked list: 1 -> 3
    obj->addAtIndex(1, 2);   // Linked list: 1 -> 2 -> 3
    
    // Get element at index
    cout << obj->get(1) << endl;  // Output: 2
    
    // Delete element at index
    obj->deleteAtIndex(1);   // Linked list: 1 -> 3
    
    // Get element at index
    cout << obj->get(1) << endl;  // Output: 3
    
    // Clean up
    delete obj;
    return 0;
}
