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

class Solution
{
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if ((pListHead == NULL) || k == 0)
            return NULL;
            
        ListNode* pAhead = pListHead;
        ListNode* pBehind = NULL;
        
        for (int i = 0; i < k-1; ++i)
        {
            if (pAhead->next == NULL)
                return NULL;
            else 
                pAhead = pAhead->next;
        }
        
        pBehind = pListHead;
        while (pAhead->next != NULL)
        {
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }
        
        return pBehind;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    
    return 0;
}
