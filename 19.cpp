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
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//be cautious to the trivial case,4 ms, faster than 100.00% of C++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next=head;
        ListNode *pre=dummyhead,*target=head,*cur=head;
        for(int i=0;i<n-1;i++){
            if(cur) cur=cur->next;
        }
        while(cur->next!=NULL){
            cur=cur->next;
            pre=target;
            target=target->next;
        }
        pre->next=target->next;
        delete target;
        return dummyhead->next;
    }
};

int main(){
    Solution s = Solution();
    ListNode* p = new ListNode(1);
    cout<<s.removeNthFromEnd(p,1)<<endl;
    return 0;
}