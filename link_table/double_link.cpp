// 双向链表插入节点

#include <iostream>
#include <fstream>
#include <typeinfo>
#include <cstring>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int x) : val(x),left(NULL),right(NULL){}
};

void display(Node* head)
{
    while (head)
    {
        cout << head->val << ' ';
        head = head->right;
    }
    cout << endl;
}

// 头插法
void CreateDoubleLinkHead(Node*& head)
{
    ifstream inn("input.txt");
    if (!inn)
    {
        cout << "can't read file 'input.txt'." << endl;
        return ;
    }

    int node_num;
    inn >> node_num;
    while (node_num != -1)
    {
        int x;
        Node* pre = NULL;
        while (node_num --)
        {
            inn >> x;

            head = new Node(x);
            if (pre == NULL)
            {
                pre = head;
            }
            else
            {
                head->right = pre;
                pre->left = head;
                pre = head;
            }

        }
    }

}

// 节点降序排列，找到合适的位置插入
void linkInsert(Node*& head)
{
    cout << "Please input a number: " << endl;
    int x;
    cin >> x;

    Node* to_insert = new Node(x);

    if (head == NULL)
    {
        head = to_insert;
        return ;
    }

    Node* p = head;
    while (p->right != NULL)
    {
        if (p->val >= x)
            p = p->right;
        else
        {
            p->left->right = to_insert;
            to_insert->right = p;
            to_insert->left = p->left;
            p->left = to_insert;

            return ;
        }
    }

    // 节点p为最后一个节点
    // 讨论待插入节点，插入到p的前面，还是后面
    if (p->val >= x)
    {
        p->right = to_insert;
        to_insert->left = p;
    }
    else
    {
        p->left->right = to_insert;
        to_insert->right = p;
        to_insert->left = p->left;
        p->left = to_insert;
    }
}

int main()
{
    Node* head = NULL;
    CreateDoubleLinkHead(head);
    display(head);

    linkInsert(head);
    display(head);

    return 0;
}
