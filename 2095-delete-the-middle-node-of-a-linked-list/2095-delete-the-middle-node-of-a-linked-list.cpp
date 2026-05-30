class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge Case: If the list has only 1 node, deleting it leaves an empty list.
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next->next; // Start fast 2 nodes ahead
        
        // Move fast by 2 steps and slow by 1 step
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // slow is now pointing to the node BEFORE the middle node
        ListNode* middle = slow->next;
        slow->next = slow->next->next; // Bypass the middle node
        
        delete middle; // Free the memory of the deleted node
        
        return head;
    }
};