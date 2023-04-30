
#include <iostream>

// Definition for singly-linked list.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL;
        ListNode *curr = NULL;
        int carry = 0;
        bool isCarry = false;

        while (l1 != NULL && l2 != NULL)
        {
            int sum = carry + l1->val + l2->val;
            if (sum >= 10)
            {
                carry = sum / 10;
                sum = sum % 10;
                isCarry = true;
            }
            else
                carry = 0;
            ListNode *temp = new ListNode(sum);
            if (!head)
            {
                head = temp;
                curr = head;
            }

            else
            {
                curr->next = temp;
                curr = curr->next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 == NULL && l2 != NULL)
        {
            while (l2 != NULL)
            {
                int sum = l2->val + carry;
                carry = sum / 10;
                sum = sum % 10;
                ListNode *temp = new ListNode(sum);
                curr->next = temp;
                curr = curr->next;
                l2 = l2->next;
            }
        }

        if (l2 == NULL && l1 != NULL)
        {
            while (l1 != NULL)
            {
                int sum = l1->val + carry;
                carry = sum / 10;
                sum = sum % 10;
                ListNode *temp = new ListNode(sum);
                curr->next = temp;
                curr = curr->next;
                l1 = l1->next;
            }
        }
        if (carry > 0)
            curr->next = new ListNode(carry);

        return head;
    }
};