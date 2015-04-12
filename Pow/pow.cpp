/* -------------------------------------------------------------------------
//  File Name   :   pow.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-12 12:57:40
//  Description :   https://leetcode.com/problems/powx-n/
//
// -----------------------------------------------------------------------*/

#include <cassert>

//-------------------------------------------------------------------------

class Solution
{
public:
    inline double pow(double x, int n) const
    {
        if(1.0 == x)
            return 1.0;
        if(-1.0 == x)
            return (0 == (n & 1) ? 1.0 : -1.0);

        // ����C��׼���pow������ԭ���ظ�����2�����裬ֱ��ָ��Ϊ0
        // 1. ��n=2k,(k=0,1,2,...)����x^n=x^2k=(x^2)^(2k/2)=(x^2)^k
        // 2. ��n=2k+1,(k=0,1,2,...)����x^n=x^(2k+1)=x^(2k)*x��x^(2k)���㲽��1

        int pn = (n > 0 ? n : -n);
        for(double r = 1.0; ; x *= x)
        {
            if(0 != (pn & 1))
                r *= x;
            if(0 == (pn >>= 1))  // pn = pn / 2
                return (n > 0 ? r : 1.0 / r);
        }

        assert(false);
        return 0.0;
    }
};

int main(int argc, const char* argv[])
{
    double r1 = Solution().pow(2.0, 3);
    double r2 = Solution().pow(2.0, -3);

    double r3 = Solution().pow(-1.0, -3);
    double r4 = Solution().pow(-1.0, -4);

    return 0;
}

//--------------------------------------------------------------------------
