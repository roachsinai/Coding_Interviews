// 逆置单链表

// iteration 方法：A -> B -> C -> D -> NULL
//                NULL <- A <- B <- C <- D  即原地调转指针方向

// Recursion 方法将 A->DCB 变成 DCB->A 即后三个已经完美解决

#include <iostream>
#include <fstream>
#include <typeinfo>
#include <cstring>

using namespace std;

struct Node
{
    int val;
    Node* next;

    Node(int x) : val(x),next(NULL){}
};

void iteration(Node* &head)
{
    if (head == NULL || head->next == NULL)
        return ;

    Node* p = head->next;
    head->next = NULL;

    Node* q;
    while (p)
    {
        q = p->next;
        p->next = head;
        head = p;
        p = q;
    }
}

Node* recursion(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node* newhead = recursion(head->next);
    // a->b->c<-d
    head->next->next = head; // 即 c->next = b; b->next = NULL;

    head->next = NULL;
    return newhead;
}

void display(Node* head)
{
    while (head)
    {
        cout << head->val << ' ';
        head = head->next;
    }

    cout << endl;
}

// 头插法
void CreateLinkHead(Node*& head)
{
    ifstream inn("input.txt");
    if (!inn)
    {
        cout << "can't open file 'input.txt'." << endl;
        return ;
    }

    // 节点 个数
    int n;
    inn >> n;

    while (n != -1)
    {
        int x;
        head = NULL;
        Node* pre = NULL;
        while (n --)
        {
            inn >> x;
            head = new Node(x);
            head->next = pre;
            pre = head;
        }
        display(head);
    }

    inn.close();
}

// 尾插法
void CreateLinkEnd(Node*& head)
{
    ifstream inn("input.txt");
    if (!inn)
    {
        cout << "can't open file 'input.txt'." << endl;
        return ;
    }

    // 节点 个数
    int n;
    inn >> n;
    while (n != -1)
    {
        int x;
        head = NULL;
        Node* pre = NULL;
        Node* temp;
        while (n --)
        {
            inn >> x;
            temp = new Node(x);
            if (head == NULL)
            {
                head = temp;
                // pre = tmp;
            }
            else
                pre->next = temp;

            pre = temp;
        }
        display(head);
    }

    inn.close();
}

int main(int argc, char const *argv[]) {
    //CreateLinkHead();
    Node* head = NULL;
    CreateLinkEnd(head);

    iteration(head);
    display(head);

    head = recursion(head);
    display(head);

    return 0;
}
