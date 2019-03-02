//
// Created by Saijun Hu on 2019/1/27.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//TODO code problem, use tail recursive from others idea;0 ms, faster than 100.00%
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* tmp = head->next;
        head->next = swapPairs(tmp->next);
        tmp->next=head;
        return tmp;
    }
};
//the iterative version, 0 ms, faster than 100.00% of C++
class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next=head;
        ListNode* cur = dummyhead;
        while (cur->next!=NULL && cur->next->next!=NULL){
            ListNode* first = cur->next;
            ListNode* second = cur->next->next;
            first->next = second->next;
            cur->next = second;
            second->next = first;
            cur=cur->next->next;
        }
        return dummyhead->next;
    }
};