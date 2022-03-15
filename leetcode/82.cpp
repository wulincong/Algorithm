#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode h;
        ListNode *p, *last;
        h.next = head;
        last = &h;
        p = head;
        bool isDuplicate = false;
        while(p->next != nullptr) {
            if(p->val == p->next->val){
                p->next = p->next->next;
                isDuplicate = true;
            }else{
                if(isDuplicate){
                    last->next = p->next;
                    p = last->next;
                    isDuplicate = false;
                }else{
                    last = p;
                    p = p->next;
                }
            }
        }
        if(isDuplicate){
            last->next = p->next;
        }
        return &h;
    }
};