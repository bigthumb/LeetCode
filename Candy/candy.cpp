/* -------------------------------------------------------------------------
//  File Name   :   candy.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-13 15:52:45
//  Description :   https://leetcode.com/problems/candy/
//
// -----------------------------------------------------------------------*/

#include <vector>

//-------------------------------------------------------------------------

// �������������������������ԣ������Ρ�ˮƽ�κ��½�����Ϊһ����С��Ԫ������һ����С��Ԫ�У�
// ���������ٳ���1�Σ�����3�ζ����֣���������1��2��2��1�������Ρ�ˮƽ�κ��½��ζ����֣�������
// ����3��2��1��ֻ�����½��Ρ���˼·�������һ����С��Ԫ�ļ�����Ȼ�����������С��Ԫ�ļ����ܺ͡�
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
            // ������
            int asc = 1;
            for(; i + 1 < sz && ratings[i] < ratings[i + 1]; ++i) count += asc++;

            // ˮƽ��
            int hor = 1;
            for(; i + 1 < sz && ratings[i] == ratings[i + 1]; ++i) hor++;

            // �½���
            int des = 1;
            for(; i + 1 < sz && ratings[i] > ratings[i + 1]; ++i) count += des++;

            // �����Ƿ����ˮƽ��������
            if(hor == 1)
                count += max(asc, des);
            else
            {
                count += asc;
                count += hor - 2;     // ˮƽ�θ�������2����������
                count += des;
            }

            // �����½����������1
            if(des > 0) count -= 1;
        }

        // �������ļ���
        if(sz > 0) count += 1;

        return count;
    }
private:
    inline int max(int l, int r) const { return (l > r ? l : r); }
};

int main(int argc, const char* argv[])
{
    {
        // ��
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
