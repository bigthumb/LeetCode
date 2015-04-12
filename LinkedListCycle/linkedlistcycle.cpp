/* -------------------------------------------------------------------------
//  File Name   :   linkedlistcycle.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-12 16:50:42
//  Description :  
//
// -----------------------------------------------------------------------*/

#include <cstdio>

//-------------------------------------------------------------------------

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        ListNode* low = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            low = low->next;
            fast = fast->next->next;

            if(low == fast)
                return true;
        }

        return false;
    }
};

int main(int argc, const char* argv[])
{
    // 无环
    {
        // 空链表
        bool ret = Solution().hasCycle(NULL);
    }

    {
        // 1个节点
        ListNode* head = new ListNode(1);
        bool ret = Solution().hasCycle(head);
    }

    {
        // 2个节点
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        bool ret = Solution().hasCycle(head);
    }

    {
        // 5个节点
        ListNode* head = new ListNode(1);
        ListNode* tail = head;

        tail->next = new ListNode(2); tail = tail->next;
        tail->next = new ListNode(3); tail = tail->next;
        tail->next = new ListNode(4); tail = tail->next;
        tail->next = new ListNode(5); tail = tail->next;

        bool ret = Solution().hasCycle(head);
    }


    // 有环
    {
        // 空链表
        bool ret = Solution().hasCycle(NULL);
    }

    {
        // 1个节点
        ListNode* head = new ListNode(1);
        ListNode* tail = head;

        tail->next = head;

        bool ret = Solution().hasCycle(head);
    }

    {
        // 2个节点
        ListNode* head = new ListNode(1);
        ListNode* tail = head;

        head->next = new ListNode(2); tail = tail->next;
        tail->next = head;

        bool ret = Solution().hasCycle(head);
    }

    {
        // 5个节点
        ListNode* head = new ListNode(1);
        ListNode* tail = head;

        tail->next = new ListNode(2); tail = tail->next;
        tail->next = new ListNode(3); tail = tail->next;
        ListNode* node3 = tail;
        tail->next = new ListNode(4); tail = tail->next;
        tail->next = new ListNode(5); tail = tail->next;
        tail->next = node3;

        bool ret = Solution().hasCycle(head);
    }

    return 0;
}

//--------------------------------------------------------------------------
