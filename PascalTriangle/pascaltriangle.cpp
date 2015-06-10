/* -------------------------------------------------------------------------
//  File Name   :   pascaltriangle.cpp
//  Author      :   bigthumb
//  Create Time :   2015-6-10 16:02:25
//  Description :   https://leetcode.com/problems/pascals-triangle/
//
// -----------------------------------------------------------------------*/

#include <vector>
#include <cassert>

//-------------------------------------------------------------------------

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
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

        return res;
    }
};

//int main(int argc, const char* argv[])
//{
//    {
//        std::vector<std::vector<int>> res = Solution().generate(1);
//    }
//
//    {
//        std::vector<std::vector<int>> res = Solution().generate(2);
//    }
//
//    {
//        std::vector<std::vector<int>> res = Solution().generate(5);
//    }
//
//    {
//        std::vector<std::vector<int>> res = Solution().generate(100);
//    }
//
//    return 0;
//}

//--------------------------------------------------------------------------
