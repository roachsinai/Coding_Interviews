#include <iostream>
#include <vector>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        ConnectCloneNodes(pHead);
        return CutLinks(pHead);
    }

    // 复制每个结点，并连接在当前结点后面
    void CloneNodes(RandomListNode* pHead)
    {
        RandomListNode* p_node = pHead;
        RandomListNode* p_clone_node = pHead;

        while (p_node != NULL)
        {
            p_clone_node = new RandomListNode(p_node->label); // 构造函数中，指针列表初始化为NULL
            p_clone_node->next = p_node->next;

            p_node->next = p_clone_node;
            p_node = p_clone_node->next;
        }
    }

    // 根据原始链表，clone_node random 指向对应的 CloneNodes
    void ConnectCloneNodes(RandomListNode* pHead)
    {
        RandomListNode* p_node = pHead;
        while (p_node != NULL)
        {
            // 判断 p_node 的 random 指针是否为空
            if (p_node->random != NULL)
                p_node->next->random = p_node->random->next;

            p_node = p_node->next->next;
        }
    }

    // 将复制好的两份链表拆开
    RandomListNode* CutLinks(RandomListNode* pHead)
    {
        RandomListNode* p_node = pHead;
        RandomListNode* p_clone_head = NULL;
        RandomListNode* p_clone_node = NULL;

        // p_node 要先走一步
        if (p_node != NULL)
        {
            p_clone_head = p_clone_node = p_node->next;
            p_node->next = p_clone_node->next;
            p_node = p_node->next;
        }

        while (p_node != NULL)
        {
            p_clone_node->next = p_node->next;
            p_clone_node = p_clone_node->next;

            p_node->next = p_clone_node->next;
            p_node = p_node->next;
        }

        return p_clone_head;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
