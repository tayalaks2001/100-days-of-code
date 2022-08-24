// Question - https://leetcode.com/problems/reorder-list/

// Approach 1 -> bad, using O(n) extra memory
void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* curr = head;
        while (curr != nullptr){
            nodes.push_back(curr);
            curr = curr->next;
        }
        
        int i = nodes.size()-1, sz = nodes.size();
        curr = head;
        while (i > sz/2){
            ListNode* nxt = curr->next;
            curr->next = nodes[i];
            nodes[i--]->next = nxt;
            curr = nxt;
        }
        if (nodes[i] == curr)
            curr->next = nullptr;
        else
            curr->next->next = nullptr;
        
    }

// Approach 2 -> better, constant size complexity
void reorderList(ListNode* head) {
        if (head->next == NULL) {
            return;
        }
        
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        
        ListNode* l1 = head;
        ListNode* l2 = reverse(slow);
        
        merge(l1, l2);
    }

ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr->next;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    void merge(ListNode* l1, ListNode* l2) {
        while (l1 != NULL) {
            ListNode* p1 = l1->next;
            ListNode* p2 = l2->next;
            
            l1->next = l2;
            if (p1 == NULL) {
                break;
            }
            l2->next = p1;
            
            l1 = p1;
            l2 = p2;
        }
    }

