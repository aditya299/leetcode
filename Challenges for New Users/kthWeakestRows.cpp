
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;



void test(){
    // To use priority queue as min heap:
    priority_queue<int, greater<int>> pq_min;

    // To use priority queue as max heap:
    priority_queue<int> pq_max;

    // To use priority queue with custom data structure, use operatior within a class/struct:

    // struct comp{
    //     bool operator()(const pair<int, int> &p1, const pair<int, int> &p2){
    //         // If cond is true, then no swap required, else swap required.
    //         if(cond){
    //             return true;
    //         }
    //         return false
    //     }
    // };

    struct comp{
        bool operator()(const pair<int, int> &p1, const pair<int, int> &p2){
            // If cond is true, then no swap required, else swap required.
            if(p1.second > p2.second){
                return true;
            }
            return false;
        }
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq_custom;

    // Use normal pq.push() / pq.pop() operations.





    // To use make_heap(), push_heap(), pop_heap():

    struct comp{
        bool operator()(int a, int b){
            // If cond is true, then no swap required, else swap required.
            if(a > b){
                return true;
            }
            return false;
        }
    };

    vector<int> v = {1, 2, 3, 4, 5};

    make_heap(v.begin(), v.end(), comp());

    v.push_back(15);
    push_heap(v.begin(), v.end(), comp());

    int test = v.front();

    pop_heap(v.begin(), v.end(), comp());

}


class Solution
{
public:
    static bool comparator(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        if (p1.second < p2.second)
            return true;
        else if (p1.second == p2.second)
            return p1.first < p2.first;
        return false;
    }

    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int r = mat.size();
        int c = mat[0].size();
        vector<int> ans;

        vector<pair<int, int>> v;

        for (int i = 0; i < r; i++)
        {
            int soldiers = 0;
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == 1)
                    soldiers++;
                else
                    break;
            }
            // arr[i] = soldiers;

            v.push_back(make_pair(i, soldiers));
        }

        sort(v.begin(), v.end(), comparator);

        for (int i = 0; i < k; i++)
        {

            ans.push_back(v[i].first);
        }

        return ans;
    }
};

class Solution2
{
public:
    struct lowers
    {
        bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
        {
            if (p1.second == p2.second)
                return p1.first > p2.first;
            return p1.second > p2.second;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int r = mat.size();
        int c = mat[0].size();
        vector<int> ans;

        vector<pair<int, int>> v;

        make_heap(v.begin(), v.end(), lowers());

        for (int i = 0; i < r; i++)
        {
            int soldiers = 0;
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == 1)
                    soldiers++;
                else
                    break;
            }
            // arr[i] = soldiers;

            v.push_back(make_pair(i, soldiers));
            push_heap(v.begin(), v.end(), lowers());
        }

        for (int i = 0; i < k; i++)
        {
            pair<int, int> p = v.front();
            pop_heap(v.begin(), v.end(), lowers());
            ans.push_back(p.first);
        }

        return ans;
    }
};

class Solution3
{
public:
    struct lowers
    {
        bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
        {
            if(p1.second > p2.second)
                return true;
            else if(p1.second == p2.second && p1.first > p2.first)
                return true;
            return false;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int r = mat.size();
        int c = mat[0].size();
        vector<int> ans;

        // vector<pair<int, int>> v;
        priority_queue<pair<int, int>, vector<pair<int, int>>, lowers> pq;

        // make_heap(v.begin(), v.end(), lowers());

        for (int i = 0; i < r; i++)
        {
            int soldiers = 0;
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == 1)
                    soldiers++;
                else
                    break;
            }
            // arr[i] = soldiers;

            pq.push(make_pair(i, soldiers));
        }

        for (int i = 0; i < k; i++)
        {
            pair<int, int> p = pq.top();
            pq.pop();
            ans.push_back(p.first);
        }

        return ans;
    }
};

int main()
{
    Solution3 s = Solution3();
    vector<vector<int>> mat = { { 1, 1, 0, 0, 0 },
                                { 1, 1, 1, 1, 0 },
                                { 1, 0, 0, 0, 0 },
                                { 1, 1, 0, 0, 0 },
                                { 1, 1, 1, 1, 1 } };

    vector<int> ans = s.kWeakestRows(mat, 3);
    return 0;
}