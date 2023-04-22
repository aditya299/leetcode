#include <vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = 0;

        int m = accounts.size();
        int n = accounts[0].size();

        for(int i = 0; i < m; i++){
            int wealth = 0;

            for(int j = 0; j < n; j++)
                wealth += accounts[i][j];

            max_wealth = max(max_wealth, wealth);
        }

        return max_wealth;

    }
};