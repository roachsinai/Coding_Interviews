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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *p_reversed_head = NULL;
        ListNode *p_node = pHead;
        ListNode *p_prev = NULL;
        while (p_node != NULL) {
            ListNode *p_next = p_node->next;

            if (p_next == NULL)
            {
                p_reversed_head = p_node;
            }

            p_node->next = p_prev;

            p_prev = p_node;
            p_node = p_next;
        }
        return p_reversed_head;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
