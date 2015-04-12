/* -------------------------------------------------------------------------
//  File Name   :   swapnodeinpairs.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-11 20:36:22
//  Description :   https://leetcode.com/problems/swap-nodes-in-pairs/
//
// -----------------------------------------------------------------------*/

#include <cstdio>

//-------------------------------------------------------------------------

// Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if(!head) 
            return NULL;

        ListNode** p = &head;
        ListNode** q = &head->next;
        while(*p && *q)
        {
            ListNode* s = (*q);

            *q = s->next;
            s->next = *p;
            *p = s;

            p = q;
            q = &(*p)->next;
        }

        return head;
    }

    void addNode(ListNode*& head, int val)
    {
        ListNode* p = new ListNode(val);
        p->next = head;
        head = p;
    }
};

int main(int argc, const char* argv[])
{
    ListNode* head = NULL;
    Solution s;
    s.addNode(head, 0);
    s.addNode(head, 1);
    s.addNode(head, 4);
    s.addNode(head, 2);
    s.addNode(head, 5);
    s.addNode(head, 3);
    s.addNode(head, 6);

    ListNode* newHead = s.swapPairs(head);

    return 0;
}

//--------------------------------------------------------------------------
