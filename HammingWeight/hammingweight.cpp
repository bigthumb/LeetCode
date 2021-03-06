/* -------------------------------------------------------------------------
//  File Name   :   hammingweight.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-12 17:38:43
//  Description :   https://leetcode.com/problems/number-of-1-bits/
//
// -----------------------------------------------------------------------*/

#include <cstdint>

//-------------------------------------------------------------------------

class Solution 
{
public:
    int hammingWeight(uint32_t n)
    {
        // 归并，对于一个32位的整数，先分成16组，统计每组（2位）中1的个数，
        // 再将统计的结果两两合并，得到8组，在此基础上又合并得到4组，2组，1组，进而得到最终结果
        // 比如对于一个8位的整数122，用二进制表达0111 1010（abcd efgh），
        // 第1行代码的功能是x=0b0d 0f0h+0a0c 0e0g，两位一组，
        // 分别计算四组（a,b; c,d; e,f; g,h; ）中1的个数，
        // 本例中x=0101 0000+0001 0101=0110 0101（更新的abcd efgh），
        // 在此基础上，再分组，就是第二行的功能x=00cd 00gh+00ab 00ef，
        // 四位一组（abcd； efgh），分别计算这两组包含1的个数，
        // 本例中x=0010 0001+0001 0001=0011 0010（更新abcd efgh），
        // 再8位一组，如第三行所示，x=0000 efgh+0000abcd=0000 0010+0000 0011=0000 0101=5，
        // 所以该整数122共包含5个1

        n = (n & 0x55555555UL) + ((n>>1) & 0x55555555UL);
        n = (n & 0x33333333UL) + ((n>>2) & 0x33333333UL);
        n = (n & 0x0f0f0f0fUL) + ((n>>4) & 0x0f0f0f0fUL);
        n = (n & 0x00ff00ffUL) + ((n>>8) & 0x00ff00ffUL);
        n = (n & 0x0000ffffUL) + ((n>>16) & 0x0000ffffUL);

        return n;
    }
};

int main(int argc, const char* argv[])
{
    int n1 = Solution().hammingWeight(7);
    int n2 = Solution().hammingWeight(122);
    int n13 = Solution().hammingWeight((1 << 30) - 1);

    return 0;
}

//--------------------------------------------------------------------------
