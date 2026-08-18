/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , Solution> minHeap;
        
        for(auto list : lists){
            if(list) minHeap.push(list);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(!minHeap.empty()){
            ListNode* node = minHeap.top();
            minHeap.pop();
            tail -> next = node;
            tail = tail -> next;

            if(node -> next){
                minHeap.push(node->next);
            }
        }
        return dummy->next;
    }
};