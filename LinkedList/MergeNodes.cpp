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
    ListNode* mergeNodes(ListNode*head){
        ListNode*dummy=new ListNode(-1);
        ListNode*current=dummy;
        ListNode*temp=head->next;
        int sum=0;
        while(temp!=nullptr){
            while(temp->val!=0){
                sum+=temp->val;
                temp=temp->next;
            }
            ListNode*newnode=new ListNode(sum);
            current->next=newnode;
            current=current->next;
            sum=0;
            temp=temp->next;
        }
        return dummy->next;
    }
};

int main() {
    Solution solution;
    ListNode* head = nullptr;
    solution.append(head, 0);
    solution.append(head, 3);
    solution.append(head, 1);
    solution.append(head, 0);
    solution.append(head, 4);
    solution.append(head, 5);
    solution.append(head, 2);
    solution.append(head, 0);
    solution.display(head);
    head=solution.mergeNodes(head);
    solution.display(head);
    return 0;
}
