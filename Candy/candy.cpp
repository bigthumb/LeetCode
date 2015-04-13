/* -------------------------------------------------------------------------
//  File Name   :   candy.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-13 15:52:45
//  Description :   https://leetcode.com/problems/candy/
//
// -----------------------------------------------------------------------*/

#include <vector>

//-------------------------------------------------------------------------

// 抽象来看，序列有这样的特性，上升段、水平段和下降段作为一个最小单元，而且一个最小单元中，
// 这三段至少出现1段，至多3段都出现，例如序列1，2，2，1，上升段、水平段和下降段都出现，又例如
// 序列3，2，1，只出现下降段。故思路是先求出一个最小单元的计数，然后求出所有最小单元的计数总和。
// 

class Solution
{
public:
    int candy(std::vector<int>& ratings)
    {
        int count = 0;
        int sz = ratings.size();
        for(int i = 0; i + 1 < sz; )
        {
            // 上升段
            int asc = 1;
            for(; i + 1 < sz && ratings[i] < ratings[i + 1]; ++i) count += asc++;

            // 水平段
            int hor = 1;
            for(; i + 1 < sz && ratings[i] == ratings[i + 1]; ++i) hor++;

            // 下降段
            int des = 1;
            for(; i + 1 < sz && ratings[i] > ratings[i + 1]; ++i) count += des++;

            // 根据是否出现水平段做处理
            if(hor == 1)
                count += max(asc, des);
            else
            {
                count += asc;
                count += hor - 2;     // 水平段个数超过2才真正计数
                count += des;
            }

            // 出现下降段则计数减1
            if(des > 0) count -= 1;
        }

        // 补上最后的计数
        if(sz > 0) count += 1;

        return count;
    }
private:
    inline int max(int l, int r) const { return (l > r ? l : r); }
};

int main(int argc, const char* argv[])
{
    {
        // 空
        std::vector<int> ratings;
        int count = Solution().candy(ratings);
    }

    {
        int a[] = { 1 };
        int n = sizeof(a) / sizeof(int);
        std::vector<int> ratings(a, a + n);
        int count = Solution().candy(ratings);
    }

    {
        int a[] = { 2, 1 };
        int n = sizeof(a) / sizeof(int);
        std::vector<int> ratings(a, a + n);
        int count = Solution().candy(ratings);
    }

    {
        int a[] = { 3, 5 };
        int n = sizeof(a) / sizeof(int);
        std::vector<int> ratings(a, a + n);
        int count = Solution().candy(ratings);
    }

    {
        int a[] = { 3, 7, 5, 2, 6, 1 };
        int n = sizeof(a) / sizeof(int);
        std::vector<int> ratings(a, a + n);
        int count = Solution().candy(ratings);      // expected 10
    }

    {
        int a[] = { 2, 2, 1 };
        int n = sizeof(a) / sizeof(int);
        std::vector<int> ratings(a, a + n);
        int count = Solution().candy(ratings);      // expected 4
    }

    {
        int a[] = { 1, 3, 3, 3 };
        int n = sizeof(a) / sizeof(int);
        std::vector<int> ratings(a, a + n);
        int count = Solution().candy(ratings);      // expected 5
    }

    {
        int a[] =
        { 
            58, 21, 72, 77, 48, 9, 38, 71, 68, 77, 82, 47, 25, 94, 89, 54, 26, 54, 54, 
            99, 64, 71, 76, 63, 81, 82, 60, 64, 29, 51, 87, 87, 72, 12, 16, 20, 21, 54, 
            43, 41, 83, 77, 41, 61, 72, 82, 15, 50, 36, 69, 49, 53, 92, 77, 16, 
            73, 12, 28, 37, 41, 79, 25, 80, 3, 37, 48, 23, 10, 55, 19, 51, 38, 96, 92, 99, 
            68, 75, 14, 18, 63, 35, 19, 68, 28, 49, 36, 53, 61, 64, 91, 2, 43, 68, 34, 46, 
            57, 82, 22, 67, 89 
        };
        int n = sizeof(a) / sizeof(int);
        std::vector<int> ratings(a, a + n);
        int count = Solution().candy(ratings);      // expected 208
    }

    return 0;
}

//--------------------------------------------------------------------------
