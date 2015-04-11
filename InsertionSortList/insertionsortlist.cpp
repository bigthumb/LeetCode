/* -------------------------------------------------------------------------
//  File Name   :   insertionsortlist.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-11 17:51:20
//  Description :   https://leetcode.com/problems/insertion-sort-list/
//
// -----------------------------------------------------------------------*/

#include <cstdio>

//-------------------------------------------------------------------------

// Definition for singly-linked list.
//struct ListNode 
//{
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

class Solution
{
public:
    inline bool comp(int l, int r) { return l < r; }

    ListNode* insertionSortList(ListNode* head)
    {
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        ListNode* p = NULL;
        while(head)
        {
            p = head;
            head = head->next;

            if(!newHead)
            {
                p->next = NULL;
                newHead = p;
                newTail = p;
            }
            else if(comp(p->val, newHead->val))
            {
                p->next = newHead;
                newHead = p;
            }
            else if(!comp(p->val, newTail->val))
            {
                p->next = newTail->next;
                newTail->next = p;
                newTail = p;
            }
            else
            {
                ListNode** q = &newHead;
                while(*q && comp((*q)->val, p->val)) 
                    q = &(*q)->next;

                p->next = *q;
                *q = p;
            }
        }

        return newHead;
    }

    void addNode(ListNode*& head, int val)
    {
        ListNode* p = new ListNode(val);
        p->next = head;
        head = p;
    }
};

//int main(int argc, const char* argv[])
//{
//    ListNode* head = NULL;
//    Solution s;
//    s.addNode(head, 1);
//    s.addNode(head, 4);
//    s.addNode(head, 2);
//    s.addNode(head, 5);
//    s.addNode(head, 3);
//    s.addNode(head, 3);
//    s.addNode(head, 6);
//    s.addNode(head, 6);
//
//    ListNode* newHead = s.insertionSortList(head);
//
//    return 0;
//}

//--------------------------------------------------------------------------
