//
// Created by Saijun Hu on 2019/1/17.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* head= new ListNode(0);
        //链表问题中灵活的使用伪首部，无论答案要求是有首部都可以很方便的得到
        ListNode* curr=head;
        int carry=0;
        while(p||q){
            int x= (p==NULL)? 0 : p->val;//处理不等长的情况
            int y= (q==NULL)? 0 : q->val;
            ListNode* temp =  new ListNode((x+y+carry)%10);
            carry = (x+y+carry)/10;
            curr->next=temp;
            curr=curr->next;
            if(p!=NULL) p=p->next;
            if(q!=NULL) q=q->next;
        }
        if(carry>0){
            curr->next=new ListNode(1);
        }
        return head->next;

    }
};