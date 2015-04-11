/* -------------------------------------------------------------------------
//  File Name   :   preorder.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-11 16:03:00
//  Description :   https://leetcode.com/problems/binary-tree-preorder-traversal/
//
// -----------------------------------------------------------------------*/

#include <vector>
#include <stack>
#include <cstdio>

//-------------------------------------------------------------------------

// Definition for binary tree
//struct TreeNode 
//{
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

class Solution 
{
public:
    std::vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> res;

        std::stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty())
        {
            if(p)
            {
                res.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.top()->right;
                s.pop();
            }
        }

        return res;
    }

    //void preOrderCreate(TreeNode*& root)
    //{
    //    int val = 0;
    //    ::scanf("%d", &val);
    //    if(-1 == val)
    //        root = NULL;
    //    else
    //    {
    //        root = new TreeNode(val);
    //        preOrderCreate(root->left);
    //        preOrderCreate(root->right);
    //    }
    //}
};

//int main(int argc, const char* argv[])
//{
//    TreeNode* root = NULL;
//    Solution s;
//    s.preOrderCreate(root);
//    std::vector<int> res = s.preorderTraversal(root);
//
//    return 0;
//}

//--------------------------------------------------------------------------
