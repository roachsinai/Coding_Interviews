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
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        unsigned int length1 = GetListLength(pHead1);
        unsigned int length2 = GetListLength(pHead2);

        int lengthDif = length1 - length2;

        ListNode* pListLong = pHead1;
        ListNode* pListShort = pHead2;

        if (lengthDif < 0)
        {
            pListLong = pHead2;
            pListShort = pHead1;
            lengthDif = length2 - length1;
        }

        // 长链后移几步
        for (int i = 0; i < lengthDif; ++ i)
            pListLong = pListLong->next;

        while (pListLong != NULL && pListShort != NULL && pListLong != pListShort)
        {
            pListLong = pListLong->next;
            pListShort = pListShort->next;
        }

        // 如果两个链表没有相交的节点，则此时两个指针都指向 NULL
        return pListShort;
    }

    unsigned int GetListLength(ListNode *pHead)
    {
        unsigned int length = 0;
        ListNode* pNode = pHead;
        while (pNode != NULL)
        {
            ++ length;
            pNode = pNode->next;
        }

        return length;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
