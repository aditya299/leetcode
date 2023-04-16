#include <iostream>

using namespace std;

class Solution
{
public:
    int charToIntRoman(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
        }
        return 0;
    }

    int romanToInt(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size();)
        {
            if (i + 1 < s.size() && s[i] == 'I')
            {
                if (s[i + 1] == 'V')
                {
                    ans += 4;
                    i += 2;
                    continue;
                }

                else if (s[i + 1] == 'X')
                {
                    ans += 9;
                    i += 2;
                    continue;
                }
            }

            if (i + 1 < s.size() && s[i] == 'X')
            {

                if (s[i + 1] == 'L')
                {
                    ans += 40;
                    i += 2;
                    continue;
                }
                else if (s[i + 1] == 'C')
                {
                    ans += 90;
                    i += 2;
                    continue;
                }
            }
            if (i + 1 < s.size() && s[i] == 'C')
            {

                if (s[i + 1] == 'D')
                {
                    ans += 400;
                    i += 2;
                    continue;
                }
                else if (s[i + 1] == 'M')
                {
                    ans += 900;
                    i += 2;
                    continue;
                }
            }

            ans += charToIntRoman(s[i]);
            i++;
        }
        return ans;
    }
};