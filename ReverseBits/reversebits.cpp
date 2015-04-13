/* -------------------------------------------------------------------------
//  File Name   :   reversebits.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-12 23:07:08
//  Description :   https://leetcode.com/problems/reverse-bits/
//
// -----------------------------------------------------------------------*/

#include <cstdint>

//-------------------------------------------------------------------------

class Solution
{
public:
    inline uint32_t reverseBits(uint32_t n) const
    {
        uint32_t m = 0;
        for(int i = 0; i < 32; ++i)
        {
            m <<= 1;
            if(0 != (n & 1))
                m |= 1;
            n >>= 1;
        }

        return m;
    }
};

int main(int argc, const char* argv[])
{
    uint32_t ret1 = Solution().reverseBits(9);
    uint32_t ret2 = Solution().reverseBits(43261596);

    return 0;
}

//--------------------------------------------------------------------------
