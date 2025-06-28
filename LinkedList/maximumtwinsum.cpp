#include <iostream>
using namespace std;

// ListNode class representing each node in the linked list
class ListNode {
public:
    int val;      // Data value to store
    ListNode* next; // Pointer to the next node

    // Constructor to initialize node
    ListNode(int value) {
        val = value;
        next = nullptr;
    }
};

// Solution class to handle the linked list operations
class Solution {
public:
    // Function to add a new node at the end of the linked list
    void append(ListNode*& head, int value) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to display all elements in the linked list
    void display(ListNode* head) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int pairSum(ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*curr=slow;
        ListNode*prev=NULL;
        ListNode*next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode*revhead=prev;

        int maxsum=0;
        while(revhead!=nullptr){
            maxsum=max(maxsum,head->val+revhead->val);
            revhead=revhead->next;
            head=head->next;
        }
        return maxsum;
    }
};

int main() {
    Solution solution;
    ListNode* head = nullptr;
    solution.append(head, 4);
    solution.append(head, 2);
    solution.append(head, 2);
    solution.append(head, 3);
    solution.display(head);
    int ans=solution.pairSum(head);
    cout << ans;

    return 0;
}
