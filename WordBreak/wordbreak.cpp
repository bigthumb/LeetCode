/* -------------------------------------------------------------------------
//  File Name   :   wordbreak.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-11 22:02:28
//  Description :   https://leetcode.com/problems/word-break/
//
// -----------------------------------------------------------------------*/

#include <unordered_set>
#include <string>

//-------------------------------------------------------------------------

class Solution {
public:
    bool wordBreak(std::string s, std::unordered_set<std::string>& dict)
    {
        return _break(s, 0, dict);
    }

private:
    bool _break(const std::string& s, int from, std::unordered_set<std::string>& dict)
    {
        std::string t("");
        for(int i = from; i < s.size(); ++i)
        {
            t.push_back(s[i]);
            if(dict.end() != dict.find(t))
            {
                if(i + 1 == s.size() || _break(s, i + 1, dict))
                    return true;
            }
        }

        return false;
    }
};

int main(int argc, const char* argv[])
{
    {
        std::string s = "leetcode";
        std::unordered_set<std::string> dict;
        dict.insert("leet");
        dict.insert("code");

        bool flag = Solution().wordBreak(s, dict);
    }

    {
        std::string s = "dabcmy";
        std::unordered_set<std::string> dict;
        dict.insert("d");
        dict.insert("ab");
        dict.insert("abc");
        dict.insert("my");

        bool flag = Solution().wordBreak(s, dict);
    }

    {
        std::string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
        std::unordered_set<std::string> dict;
        const char* ws[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
        for(int i = 0; i < sizeof(ws) / sizeof(const char*); ++i)
        {
            dict.insert(ws[i]);
        }

        bool flag = Solution().wordBreak(s, dict);
    }

    return 0;
}

//--------------------------------------------------------------------------
