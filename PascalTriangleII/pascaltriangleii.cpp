/* -------------------------------------------------------------------------
//  File Name   :   pascaltriangleii.cpp
//  Author      :   bigthumb
//  Create Time :   2015-6-10 16:48:34
//  Description :   https://leetcode.com/problems/pascals-triangle-ii/
//
// -----------------------------------------------------------------------*/

#include <vector>
#include <cassert>

//-------------------------------------------------------------------------

class Solution
{
public:
    std::vector<int> getRow(int rowIndex)
    {
        int numRows = rowIndex + 1;
        std::vector<std::vector<int>> res(numRows);

        if(numRows > 0)
        {
            res[0].push_back(1);
        }

        for(int i = 1; i < numRows; ++i)
        {
            for(int j = 0; j <= i; ++j)
            {
                int a = (0 == j ? 0 : res[i - 1][j - 1]);
                int b = (i == j ? 0 : res[i - 1][j]);
                res[i].push_back(a + b);
            }
        }

        return res[numRows - 1];
    }
};

//int main(int argc, const char* argv[])
//{
//    {
//        std::vector<int> res = Solution().getRow(0);
//    }
//
//    {
//        std::vector<int> res = Solution().getRow(1);
//    }
//
//    {
//        std::vector<int> res = Solution().getRow(2);
//    }
//
//    {
//        std::vector<int> res = Solution().getRow(5);
//    }
//
//    {
//        std::vector<int> res = Solution().getRow(10);
//    }
//
//    {
//        std::vector<int> res = Solution().getRow(100);
//    }
//
//    return 0;
//}

//--------------------------------------------------------------------------
