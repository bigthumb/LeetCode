/* -------------------------------------------------------------------------
//  File Name   :   search.cpp
//  Author      :   bigthumb
//  Create Time :   2015-4-13 11:38:27
//  Description :   https://leetcode.com/problems/search-in-rotated-sorted-array/
//
// -----------------------------------------------------------------------*/

#include <cassert>

//-------------------------------------------------------------------------

// ����������ݲ�ȷ�������ᷴת��Ҫ��������������ʹ�ö��ֲ��ң��������ҳ��ؼ��㣬�ؼ�����������ߵ�
// Ԫ�ض����С�����ö��ֲ��ҵı����ҹؼ��㡣
// �������������У�ǰ��<=��̣�����ת������� 4,5,6,7,0,1,2,3���ؼ�����Ȼ��7��
// ���λ4���м�λ7�����λ3�����ȽϵĽ��
// 4 < 7    (1)
// 7 > 3    (2)
// 4 > 3    (3)
// �۲�(1)��(2)�Ĵ�С��ͬ��˵�����λ�����λ֮������в���ȫ������ġ�
// (2)��(3)����>��˵�����λ���м�λ֮�������������ġ�������7��3֮����������ҹؼ��㣬
// �����λΪ7���м�λΪ1�����λ��Ϊ3�����������ȽϵĽ��
// 7 > 1
// 1 < 3
// 7 > 3
// ��Ȼ�����λ�����λ֮��������Բ���ȫ������ģ������м�λ�����λ֮�������������
// ͬ���ķ�������ֱ�����λ���м�λ��Ԫ����ȣ���
// 7 = 7
// 7 > 0
// 7 > 0
// ��˹ؼ�����7�������������У�ǰ��>=��̣�Ҳ�������Ĺ����ҵ��ؼ���֮�󣬶Ա����ؼ����
// �������ֲ��ҡ���δ�ҵ�Ŀ�꣬����ֲ��ҹؼ�����Ҳ�������δ�ҵ����򷵻�-1��

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
        // A�в����ڴ�С��ȵ�Ԫ��

        int low = 0;
        int high = n - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            int lm = _comp(A[low], A[mid]);
            int mh = _comp(A[mid], A[high]);
            int lh = _comp(A[low], A[high]);

            if(0 == lm || lm == mh)    // ���λ���м�λ��Ԫ����Ȼ�ȫ���������
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
