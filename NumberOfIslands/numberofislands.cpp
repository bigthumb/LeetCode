/* -------------------------------------------------------------------------
//  File Name   :   numberofislands.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-13 9:49:49
//  Description :   https://leetcode.com/problems/number-of-islands/
//
// -----------------------------------------------------------------------*/

#include <vector>
#include <cstdint>
#include <cassert>

//-------------------------------------------------------------------------

class Solution
{
public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        int count = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[i].size(); ++j)
            {
                if('1' == grid[i][j])
                {
                    ++count;
                    _expand(i, j, grid);
                }
            }
        }

        return count;
    }
private:
    void _expand(int i, int j, std::vector<std::vector<char>>& g)
    {
        g[i][j] = '0';

        // вС
        if(j - 1 >= 0 && '1' == g[i][j - 1])
            _expand(i, j - 1, g);

        // ио
        if(i - 1 >= 0 && '1' == g[i - 1][j])
            _expand(i - 1, j, g);

        // ср
        if(j + 1 < g[i].size() && '1' == g[i][j + 1])
            _expand(i, j + 1, g);

        // об
        if(i + 1 < g.size() && '1' == g[i + 1][j])
            _expand(i + 1, j, g);
    }
};

int main(int argc, const char* argv[])
{
    {
        const char* s[4] = {
            "11110", 
            "11010", 
            "11000", 
            "00000"
        };

        std::vector<std::vector<char>> g;
        for(int i = 0; i < 4; ++i)
        {
            std::vector<char> oneRow;
            for(int j = 0; j < 5; ++j)
            {
                oneRow.push_back(s[i][j]);
            }

            g.push_back(oneRow);
        }

        int count = Solution().numIslands(g);
    }

    return 0;
}

//--------------------------------------------------------------------------
