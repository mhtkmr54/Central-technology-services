/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
    If a loop exists, then the fast pointer will eventually end up behind the slow pointer. The fast pointer will then catch up to the slow pointer, detecting the loop. This will always happen, no matter the size of the loop.
*/

bool has_cycle(Node* head) {
   if (head == NULL) return false;
    
    Node* slow = head;
    Node* fast = head->next;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) return false;
        
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return true;
        
    
}
