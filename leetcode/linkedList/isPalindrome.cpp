#include <stack>
#include <queue>
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
    bool isPalindrome(ListNode *head)
    {
        std::stack<int> s;
        std::queue<int> q;

        ListNode *temp = head;

        while (temp)
        {
            s.push(temp->val);
            q.push(temp->val);
            temp = temp->next;
        }
        while (!s.empty() or !q.empty())
        {
            if (s.top() != q.front())
            {
                return false;
            }
            s.pop();
            q.pop();
        }
        return true;
    }
};