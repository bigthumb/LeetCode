/* -------------------------------------------------------------------------
//  File Name   :   search.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-13 11:38:27
//  Description :   https://leetcode.com/problems/search-in-rotated-sorted-array/
//
// -----------------------------------------------------------------------*/

#include <cassert>

//-------------------------------------------------------------------------

// 有序数组根据不确定的枢轴反转，要在这样的序列中使用二分查找，必须先找出关键点，关键点比左右两边的
// 元素都大或都小，利用二分查找的变种找关键点。
// 例如有正序序列（前继<=后继），反转后的数组 4,5,6,7,0,1,2,3，关键点显然是7。
// 最低位4、中间位7和最高位3两两比较的结果
// 4 < 7    (1)
// 7 > 3    (2)
// 4 > 3    (3)
// 观察(1)和(2)的大小序不同，说明最低位和最高位之间的序列不是全部有序的。
// (2)和(3)都是>，说明最低位和中间位之间的序列是有序的。接着在7到3之间的序列中找关键点，
// 即最低位为7，中间位为1，最高位仍为3，三者两两比较的结果
// 7 > 1
// 1 < 3
// 7 > 3
// 显然，最低位和最高位之间的序列仍不是全部有序的，而且中间位和最高位之间的序列是有序。
// 同样的方法查找直到最低位和中间位的元素相等，即
// 7 = 7
// 7 > 0
// 7 > 0
// 因此关键点是7。对于逆序序列（前继>=后继）也有这样的规则。找到关键点之后，对保护关键点的
// 左部做二分查找。若未找到目标，则二分查找关键点的右部。若仍未找到，则返回-1。

class Solution
{
public:
    int search(int A[], int n, int target)
    {
        int k = _keyIndex(A, n);

        // n==0 or n > 0
        bool positive = (A[0] <= A[k]);
        int u = _binarySearch(A, 0, k, positive, target);
        if(-1 == u)
            u = _binarySearch(A, k + 1, n - 1, positive, target);

        return u;
    }
private:
    int _keyIndex(int A[], int n)
    {
        // A中不存在大小相等的元素

        int low = 0;
        int high = n - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            int lm = _comp(A[low], A[mid]);
            int mh = _comp(A[mid], A[high]);
            int lh = _comp(A[low], A[high]);

            if(0 == lm || lm == mh)    // 最低位和中间位的元素相等或全部是有序的
                break;
            else if(lm == lh)
                high = mid;
            else if(mh == lh)
                low = mid;
            else
                assert(false);
        }

        return low;
    }

    int _binarySearch(int A[], int low, int high, bool positive, int target)
    {
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(target == A[mid])
                return mid;
            else if(target > A[mid])
            {
                if(positive)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else // target < A[mid]
            {
                if(positive)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return -1;
    }

    inline int _comp(int l, int r) const
    {
        return (l > r ? 1 : l < r ? -1 : 0);
    }
};

//int main(int argc, const char* argv[])
//{
//    {
//        int A[] = { 0 };
//        int n = 0;
//        int i = Solution().search(A, n, 2);
//    }
//
//    {
//        int A[] = { 4, 5};
//        int n = sizeof(A) / sizeof(int);
//        int i = Solution().search(A, n, 9);
//    }
//
//    {
//        int A[] = { 4, 5, 6, 7, 0, 1, 2, 3 };
//        int n = sizeof(A) / sizeof(int);
//        int i = Solution().search(A, n, 6);
//    }
//
//    {
//        int A[] = { 2, 1, 0, 5, 4, 3 };
//        int n = sizeof(A) / sizeof(int);
//        int i = Solution().search(A, n, 5);
//    }
//
//    return 0;
//}

//--------------------------------------------------------------------------
