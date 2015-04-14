/* -------------------------------------------------------------------------
//  File Name   :   twosum.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-14 8:51:45
//  Description :   https://leetcode.com/problems/two-sum/
//
// -----------------------------------------------------------------------*/

#include <unordered_map>
#include <vector>
#include <cstdint>

//-------------------------------------------------------------------------

class Solution 
{
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        std::vector<int> res;

        std::unordered_map<int, int> m;
        for(uint32_t i = 0; i < numbers.size(); ++i)
        {
            std::unordered_map<int, int>::iterator it = m.find(target - numbers[i]);
            if(m.end() != it)
            {
                res.push_back(it->second + 1);
                res.push_back(i + 1);
                break;
            }

            m[numbers[i]] = i;
        }

        return res;
    }
};

int main(int argc, const char* argv[])
{
    {
        int a[] = { 2, 7, 11, 15 };
        int n = sizeof(a) / sizeof(int);
        std::vector<int> numbers(a, a + n);
        int target = 17;
        std::vector<int> res = Solution().twoSum(numbers, target);
    }

    return 0;
}

//--------------------------------------------------------------------------
