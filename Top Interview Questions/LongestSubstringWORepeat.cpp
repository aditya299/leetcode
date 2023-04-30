#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> set;

        int i = 0;
        int j = 0;
        int ans = 0;
        if (s == " ")
            return 1;
        if (s.size() == 1)
            return 1;
        while (j < s.size())
        {
            if (set.find(s[j]) == set.end())
            {
                set.insert(s[j]);
                j++;
            }
            else
            {
                set.erase(s[i]);
                ans = max(ans, j - i);
                i++;
            }
        }

        ans = max(ans, j - i);

        return ans;
    }
};