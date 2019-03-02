//
// Created by Saijun Hu on 2019/1/24.
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
//4 ms, faster than 100.00%
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead1 =  new ListNode(0);
        ListNode* dummyhead2 =  new ListNode(0);
        dummyhead1->next = l1;
        dummyhead2->next = l2;
        ListNode* work1=l1,*pre1=dummyhead1,*pre2=dummyhead2,*work2=l2;
        while(work1 && work2) {
            if (work1->val <= work2->val) {
                pre1=work1;work1=work1->next;
            } else {
                pre2->next=work2->next;
                work2->next = work1;
                pre1->next = work2;
                pre1=pre1->next;
                work2=pre2->next;
            }
        }
        while(work2) pre1->next=work2;
        return dummyhead1->next;
    }
};
