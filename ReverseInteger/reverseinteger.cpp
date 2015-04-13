/* -------------------------------------------------------------------------
//  File Name   :   reverseinteger.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-12 23:22:22
//  Description :   https://leetcode.com/problems/reverse-integer/
//
// -----------------------------------------------------------------------*/

#include <cstdint>
#include <limits>

//-------------------------------------------------------------------------

class Solution
{
public:
    int reverse(int x)
    {
        long long res = 0L;
        for(; 0 != x; x /= 10)
        {
            res *= 10;
            res += x % 10;
        }

        if(res < std::numeric_limits<int>().min() || res > std::numeric_limits<int>().max())
            return 0;
        else
            return static_cast<int>(res);
    }
};

int main(int argc, const char* argv[])
{
    int ret1 = Solution().reverse(0);
    int ret2 = Solution().reverse(123);
    int ret3 = Solution().reverse(-123);

    int ret4 = Solution().reverse(-2147483648);
    int ret5 = Solution().reverse(2147483647);
    int ret6 = Solution().reverse(1007483004);

    int ret7 = Solution().reverse(-12040);
    int ret8 = Solution().reverse(200100);

    return 0;
}

//--------------------------------------------------------------------------
