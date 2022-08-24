// Question - https://leetcode.com/problems/remove-nth-node-from-end-of-list/

ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr)
            return nullptr;
        
        ListNode* behind = head;
        ListNode* ahead = head;
        while (n--){
            ahead = ahead->next;
        }
        
        if (ahead == nullptr){
            return head->next;
        }
        
        while (ahead->next != nullptr){
            ahead = ahead->next;
            behind = behind->next;
        }
        
        if (behind->next != nullptr){
            behind->next = behind->next->next;
        }
        
        return head;
    }
