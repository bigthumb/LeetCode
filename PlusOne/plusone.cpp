/* -------------------------------------------------------------------------
//  File Name   :   plusone.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-11 16:38:23
//  Description :   https://leetcode.com/problems/plus-one/
//
// -----------------------------------------------------------------------*/

#include <vector>
#include <algorithm>

//-------------------------------------------------------------------------

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        int plus = 1;
        for(int i = digits.size() - 1; 1 == plus && i >= 0; --i)
        {
            digits[i] += plus;
            if(digits[i] >= 10)
                digits[i] = 0;
            else
                plus = 0;
        }

        std::vector<int> res;
        if(1 == plus)
        {
            res.push_back(1);
            res.insert(res.begin() + 1, digits.begin(), digits.end());
        }
        else
        {
            res.insert(res.begin(), digits.begin(), digits.end());
        }

        return res;
    }
};

int main(int argc, const char* argv[])
{
    std::vector<int> digits;
    digits.push_back(1);
    digits.push_back(1);
    digits.push_back(9);
    digits.push_back(9);

    std::vector<int> res = Solution().plusOne(digits);

    return 0;
}

//--------------------------------------------------------------------------
