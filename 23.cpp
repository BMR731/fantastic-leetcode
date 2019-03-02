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
#include <queue>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//use the heap directly,time nlogn, space n, 16 ms, faster than 99.52%
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* p1, ListNode* p2){ return p1->val > p2->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(ListNode* list : lists){
            while(list){
                pq.push(list);
                list=list->next;
            }
        }
        ListNode* dummyhead = new ListNode(0);//pointer must be init!
        ListNode* pre = dummyhead;
        while(!pq.empty()){
            ListNode* cur = pq.top();
            pre ->next=cur;
            pre = cur;
            pq.pop();
        }
        pre->next= NULL;
        return dummyhead->next;
    }
};
//use the heap n times, constrcut a heap which size is k,time o(nlogk),space o(k);
//16 ms, faster than 99.52% of C++
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* p1, ListNode* p2){ return p1->val > p2->val;};
        //notice here comparator is '>', the result will ascend
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(ListNode* list : lists){
            if(list){
                pq.push(list);
                list=list->next;
            }
        }
        ListNode* dummyhead = new ListNode(0);//pointer must be init!
        ListNode* pre = dummyhead;
        while(!pq.empty()){
            ListNode* cur = pq.top();
            pre ->next=cur;
            pre = cur;
            if(cur->next) pq.push(cur->next);
        }
        pre->next= NULL;
        return dummyhead->next;
    }
};