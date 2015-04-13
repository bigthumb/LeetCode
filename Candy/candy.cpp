/* -------------------------------------------------------------------------
//  File Name   :   candy.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-13 15:52:45
//  Description :   https://leetcode.com/problems/candy/
//
// -----------------------------------------------------------------------*/

#include <vector>
#include <limits>
#include <cassert>

//-------------------------------------------------------------------------

// �ظ�������������
// (1) �ҳ�����t�����ȷ���[t]=1�����ŴӲ���t��ǰһ������c�����1���䣬��[c]<=[c-1]����
//     ���²���[c]=[c-1]+1��
// (2) �Ӳ���t��̿�ʼ�����1���䣬ֱ����һ�����壻
// 

class Solution
{
public:
    int candy(std::vector<int>& ratings)
    {
        int count = 0;

        int c = -1;
        int t = 0;
        int cn = std::numeric_limits<int>().max();  // �����ʼ�Ĳ���������
        while(c + 1 < ratings.size())
        {
            // Ѱ�Ҳ���
            t = c + 1;
            while(t + 1 < ratings.size() && ratings[t] >= ratings[t + 1])
                ++t;

            // �Ӳ���t��ǰһ������c�������
            int tn = 1;
            int i = t;
            for(; i > c + 1; --i)
            {
                if(ratings[i] < ratings[i - 1])
                {
                    count += tn;
                    ++tn;
                }
                else if(ratings[i] == ratings[i - 1])
                {
                    count += tn;
                    tn = 1;
                }
                else
                {
                    assert(false);
                }
            }

            if(i >= 0)
                count += tn;

            if(cn <= tn)
            {
                count -= cn;
                cn = tn + 1;
                count += cn;
            }

            // �Ӳ��ȿ�ʼ����������
            cn = 2;
            c = t + 1;
            for(; c + 1 < ratings.size() && ratings[c] <= ratings[c + 1]; ++c)
            {
                if(ratings[c] < ratings[c + 1])
                {
                    count += cn;
                    ++cn;
                }
                else if(ratings[c] == ratings[c + 1])
                {
                    count += cn;
                    cn = 1;
                }
                else
                {
                    assert(false);
                }
            }

            if(c < ratings.size())
                count += cn;
        }

        return count;
    }
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
