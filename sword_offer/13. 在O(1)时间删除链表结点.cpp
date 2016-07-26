#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

class Solution
{
public:
    void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
    {
        if (!pListHead || pToBeDeleted)
            return;

        // 要删除的结点不是尾结点
        if (pToBeDeleted->m_pNext != NULL)
        {
            ListNode* pNext = pToBeDeleted->m_pNext;
            pToBeDeleted->m_nValue = pNext->m_nValue;
            pToBeDeleted->m_pNext = pNext->m_pNext;

            delete pNext;
            pNext = NULL;
        }
        // 链表只有一个结点，删除头结点（也是尾结点）
        else if (*pListHead == pToBeDeleted)
        {
            delete pToBeDeleted;
            pToBeDeleted = NULL;
            *pListHead = NULL;
        }
        // 链表中有多个结点，删除尾结点
        else
        {
            ListNode* pNode = *pListHead;
            while (pNode->m_pNext != pToBeDeleted)
            {
                pNode = pNode->m_pNext;
            }

            delete pToBeDeleted;
            pToBeDeleted = NULL;

            pNode->m_pNext = NULL;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
