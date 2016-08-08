#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;

        ListNode *p_merge = NULL;

        if (pHead1->val < pHead2->val)
        {
            p_merge = pHead1;
            p_merge->next = Merge(pHead1->next, pHead2);
        }
        else
        {
            p_merge = pHead2;
            p_merge->next = Merge(pHead1, pHead2->next);
        }

        return p_merge;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6);
    ListNode* p1 = &l1;p1->next = &l3;l3.next = &l5;
    ListNode* p2 = &l2;p2->next = &l4;l4.next = &l6;

    ListNode* p = s.Merge(p1,p2);
    while (p!=NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
