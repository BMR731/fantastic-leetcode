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
// use the recursive idea;but TODO i failed to code it, then copy from others,
//especially the reverse func code!
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* end = head;
        for (int i = 0; i < k; ++i) {
            if(end){end=end->next;}
            else{ return head;}
        }
        auto new_head = reverse(head,end);
        head->next = reverseKGroup(end,k);
        return new_head;
    }
    //it's worthy to learn that separate func from complicate procedure
    //reverse range [first,last);
    ListNode* reverse(ListNode* first, ListNode* last)
    {
        ListNode* prev = last;
        //why prev initialized last? cause last doesn't belong this range!
        //there is open bracket!
        while ( first != last )
        {
            auto tmp = first->next;
            first->next = prev;
            prev = first;
            first = tmp;
        }
        return prev;
    }
};

int main(){
    Solution s = Solution();
    ListNode* dummyhead = new ListNode(-1);
    ListNode* pre = dummyhead;
    for(int i : {1,2,3,4,5}){
        ListNode* tmp = new ListNode(i);
        pre->next = tmp;
        pre = pre->next;
    }
    ListNode* result = s.reverseKGroup(dummyhead->next,2);
    while(result){
        cout<<result->val<<" ";
        result=result->next;
    }
    return 0;
}