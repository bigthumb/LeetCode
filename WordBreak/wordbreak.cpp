/* -------------------------------------------------------------------------
//  File Name   :   wordbreak.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-11 22:02:28
//  Description :   https://leetcode.com/problems/word-break/
//                  unordered_set具有迷惑性，实际使用双链树作为键树的存储结构处理最为合适
//                  
//
// -----------------------------------------------------------------------*/

#include <unordered_set>
#include <string>
#include <cstring>
#include <assert.h>

//-------------------------------------------------------------------------

class Solution 
{
public:
    bool wordBreak(std::string s, std::unordered_set<std::string>& dict)
    {
        _init(dict);

        return (_break(s, 0, dict) > 0);
    }
private:
    inline int M(char ch) const
    {
        if('\0' == ch)
            return 0;
        else if('a' <= ch && ch <= 'z')
            return (ch - 'a' + 1);
        else if('A' <= ch && ch <= 'Z')
            return (ch - 'A' + 27);
        else 
        {
            assert(false);
            return 0;
        }
    }

    void _init(std::unordered_set<std::string>& dict)
    {
        ::memset(m_existed, false, 52);
        ::memset(m_adj, false, 54 * 54);

        // 遍历字典所有词的字符，记录存在哪些字符，字符间是否有邻接关系
        for(auto it = dict.begin(); dict.end() != it; ++it)
        {
            std::string str = *it;

            char pre = '\0';
            for(int i = 0; i < str.size(); ++i)
            {
                char cur = str[i];
                m_existed[M(cur)] = true;
                m_adj[M(pre)][M(cur)] = true;
                pre = cur;
            }

            m_adj[M(pre)][M('\0')] = true;
        }

        // 字典中的词能否被字典中其他词分词，若是，则先删除
        for(auto it = dict.begin(); dict.end() != it; )
        {
            std::string str = *it;
            int c = _break(str, 0, dict);
            if(1 == c)
                ++it;
            else
                it = dict.erase(it);
        }
    }

    int _break(const std::string& s, int from, std::unordered_set<std::string>& dict)
    {
        char pre = '\0';
        std::string t("");
        for(int i = from; i < s.size(); ++i)
        {
            char cur = s[i];
            if(!m_existed[M(cur)])
                return -1;
            else if(!m_adj[M(pre)][M(cur)])
                return 0;
            else
            {
                t.push_back(cur);
                pre = cur;

                if(m_adj[M(cur)][M('\0')] && dict.end() != dict.find(t))
                {
                    if(i + 1 == s.size())
                        return 1;
                    else
                    {
                        int ret = _break(s, i + 1, dict);
                        if(-1 == ret)
                            return -1;
                        else if(ret > 0)
                        {
                            return (1 + ret);
                        }
                        else
                            ;
                    }
                }
            }
        }

        return 0;
    }
private:
    bool m_existed[52];     // 表示字典中存在的字符
    bool m_adj[54][54];     // 表示字典中存在的字符相邻关系
};

//int main(int argc, const char* argv[])
//{
//    {
//        std::string s = "leetcode";
//        std::unordered_set<std::string> dict;
//        dict.insert("leet");
//        dict.insert("code");
//
//        bool flag = Solution().wordBreak(s, dict);
//    }
//
//    {
//        std::string s = "dabcmy";
//        std::unordered_set<std::string> dict;
//        dict.insert("d");
//        dict.insert("ab");
//        dict.insert("abc");
//        dict.insert("my");
//
//        bool flag = Solution().wordBreak(s, dict);
//    }
//
//    {
//        std::string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
//        std::unordered_set<std::string> dict;
//        const char* ws[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
//        for(int i = 0; i < sizeof(ws) / sizeof(const char*); ++i)
//        {
//            dict.insert(ws[i]);
//        }
//
//        bool flag = Solution().wordBreak(s, dict);
//    }
//
//    return 0;
//}

//--------------------------------------------------------------------------
