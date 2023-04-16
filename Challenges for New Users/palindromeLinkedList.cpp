/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include<iostream>
#include<stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// O(N) Time and O(N) Space complexity
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
            return true;
        if (head->next == NULL)
            return true;

        stack<int> s;
        int n = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }

        temp = head;
        int i = 0;
        while (temp != NULL)
        {

            if (i < n / 2)
            {
                s.push(temp->val);
                i++;
            }

            else
            {
                if (n % 2 != 0 && i == n / 2)
                {
                    i++;
                    temp = temp->next;
                    continue;
                }

                if (s.top() != temp->val)
                    return false;

                s.pop();
                i++;
            }
            temp = temp->next;
        }

        return true;
    }
};

// O(N) Time and O(1) Space complexity if recursion stack is ignored
class Solution2 {
public:

    bool util(ListNode **left, ListNode* right){
        if(right == NULL)
            return true;

        if(!util(left, right->next))
            return false;

        if((*left)->val != right->val)
            return false;
        
        *left = (*left)->next;

        return true;
    }
    bool isPalindrome(ListNode* head) {
        return util(&head, head);
    }
};

// O(N) Time and O(1) Space complexity
class Solution3 {
public:

    ListNode* reverseLL(ListNode * head){
        if(head == NULL)
            return NULL;

        if(head->next == NULL)
            return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(next != NULL){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }   

        curr->next = prev; 

        return curr;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        int n = 0;

        while(temp != NULL){
            temp = temp->next;
            n++;
        }

        temp = head;
        int i = 0;
        while(i < n/2){
            temp = temp->next;
            i++;
        }

        if(n % 2 != 0)
            temp = temp->next;

        temp = reverseLL(temp);

        while(temp != NULL){
            if(head->val != temp->val)
                return false; 

            temp = temp->next;
            head = head->next;           
        }

        return true;
    }
};

int main(){


    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(1);

    ListNode* head = node1;
    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    Solution3 sol = Solution3();
    cout << sol.isPalindrome(head) << endl;



    return 0;

    
}