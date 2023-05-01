#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0;
        int high = n1;

        while (low <= high)
        {
            int c1 = (low + high) / 2;
            int c2 = (n1 + n2 + 1) / 2 - c1;

            int l1 = c1 > 0 ? nums1[c1 - 1] : INT_MIN;
            int l2 = c2 > 0 ? nums2[c2 - 1] : INT_MIN;

            int r1 = c1 < n1 ? nums1[c1] : INT_MAX;
            int r2 = c2 < n2 ? nums2[c2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            }
            else if (l1 > r2)
                high = c1 - 1;
            else
                low = c1 + 1;
        }
        return 0.0;
    }
};
int main()
{
    Solution s = Solution();
    vector<int> v1 = {2, 3, 5, 8};
    vector<int> v2 = {10, 12, 14, 16, 18, 20};
    double ans = s.findMedianSortedArrays(v1, v2);
    return 0;
}