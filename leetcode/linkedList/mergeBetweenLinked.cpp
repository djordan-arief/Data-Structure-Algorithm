
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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        // a and b are not data points, but they are like indexes. starting from 0.
        ListNode *a1 = nullptr;  // will store the node of previous to the size a. i.e where size+1==a
        ListNode *a2 = nullptr;  // will store the node where the size of the node will be equal to b.
        ListNode *b1 = nullptr;  // used to store the first node of list2.
        ListNode *b2 = nullptr;  // used to store the last node of list2.
        ListNode *l1 = list1; // rederence to the list1 orignal head.
        int size = 0;         // size stores what is the current size of the linked list.
        while (list1->next != nullptr)
        {
            // store previous and check if next->next!=NULL although this condition will always
            // meet because of questions input is length-1.
            if (list1->next->next != nullptr && size + 1 == a)
            {
                a1 = list1; // store the node in a1
            }
            else if (size == b)
            { // store next
                a2 = list1->next;
            }
            list1 = list1->next; // move ahead into list
            size++;              // increase the size
        }

        b1 = list2; // store the first of list2
        while (list2->next != nullptr)
        {
            list2 = list2->next;
        }
        b2 = list2; // store the last of list2.

        // if at any case we found that a1==NULL, we will directly store b1.
        // Will not store in its next.
        // Current link is as follows....
        // LIST1->A1->
        if (a1 != nullptr)
        {
            a1->next = b1; // pointing to the b1
        }
        // UPDATED LINKS WILL BE: LIST1->A1->B1->B2->
        else
        {
            a1 = b1;
        }
        b2->next = a2; // point the b2 to a2.
        // UPDATED LINK: LIST1->A1->B1->B2->A2 //final result
        return l1;
    }
};