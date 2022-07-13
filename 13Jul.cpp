// Question - https://leetcode.com/problems/copy-list-with-random-pointer/

#include<bits/stdc++.h>
using namespace std;

Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mapping;
        Node *newHead = NULL, *newTail = NULL;
        
        Node* temp = head;
        while (temp != NULL){
            Node* newTemp;
            if (mapping.find(temp) != mapping.end())
                newTemp = mapping[temp];
            else{
                newTemp = new Node (temp->val);
                mapping[temp] = newTemp;
            }
            
            if (temp->random != NULL){
                Node* newRand;
                if (mapping.find(temp->random) != mapping.end())
                    newRand = mapping[temp->random];
                else{
                    newRand = new Node (temp->random->val);
                    mapping[temp->random] = newRand;
                }
                newTemp->random = newRand;
            }
            
            if (newHead == NULL){
                newHead = newTemp;
                newTail = newHead;
            }
            else{
                newTail->next = newTemp;
                newTail = newTail->next;
            }
            
            temp = temp->next;
        }
        
        return newHead;
    }
