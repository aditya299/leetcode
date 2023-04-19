#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        int n = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }

        int mid = n / 2;
        int i = 0;
        temp = head;
        while (i < mid)
        {
            temp = temp->next;
            i++;
        }

        // if(n % 2 == 0)
        //     temp = temp-> next;

        // std::cout << n << " "<< mid << " " << i;

        return temp;
    }
};