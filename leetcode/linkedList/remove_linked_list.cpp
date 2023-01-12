
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // Create temporary node
        ListNode *temporary_node = new ListNode(0);

        // Set the next node of temporary node to head
        temporary_node->next = head;

        // create a pointer
        ListNode *prevNode = temporary_node;

        // check if head is not null
        while (head != nullptr)
        {
            if (head->val == val)
            {
                prevNode->next = head->next;
            }
            else
            {
                prevNode = head;
            }
            head = head->next;
        }
        return temporary_node->next;
    }
};