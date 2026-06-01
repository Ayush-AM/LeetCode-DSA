class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has only one node, it's already sorted
        if (!head || !head->next) {
            return head;
        }
        
        // Step 1: Split the list into two halves using slow and fast pointers
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Break the link between the first half and the second half
        prev->next = nullptr;
        
        // Step 2: Recursively sort each half
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        // Step 3: Merge the two sorted halves
        return merge(l1, l2);
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        // Attach the remaining nodes of l1 or l2
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        
        return dummy.next;
    }
};