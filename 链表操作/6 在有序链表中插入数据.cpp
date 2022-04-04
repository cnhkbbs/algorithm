// 给定一批严格递增排列的整型数据，给定一个x，若x不存在，则插入x，要求插入后保持有序。存在则无需任何操作。

// 输入格式:
// 输入有两行：
// 第一个数是n值，表示链表中有n个数据。后面有n个数，分别代表n个数据。
// 第二行是要插入的数。

// 输出格式:
// 输出插入后的链表数据，以空格分开。行末不能有多余的空格。

// 输入样例1:
// 在这里给出一组输入。例如：

// 5 1 3 6 9 11
// 4
// 输出样例1:
// 在这里给出相应的输出。例如：

// 1 3 4 6 9 11
// 输入样例2:
// 在这里给出一组输入。例如：

// 5 1 3 6 9 11
// 3
// 输出样例2:
// 在这里给出相应的输出。例如：

// 1 3 6 9 11

#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode, * LinkList;


void CreateList(LinkList& L, int n)
{
    L = new LNode;
    L->next = NULL;
    LNode* p = L;
    int m;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        p->next = new LNode;
        p = p->next;
        p->data = m;
        p->next = NULL;
    }
}

void OutputList(LinkList L)
{
    LNode* p = L->next;
    while (p != NULL) {
        cout << p->data;
        if (p->next != NULL)
            cout << " ";
        p = p->next;
    }
}
void InsertList(LinkList& L, int n, int x)
{
    LNode* p = L;
    if (p->next == NULL)
    {
        LNode* q = new LNode;
        q->data = x;
        q->next = NULL;
        p->next = q;
        p = q;
        return;
    }
    while (p->next != NULL)
    {
        LNode* temp = p;
        p = p->next;
        if (p->data == x) return;
        if (p->data > x)
        {
            LNode* q = new LNode;
            q->data = x;
            q->next = p;
            temp->next = q;
            return;
        }
    }

    LNode* q = new LNode;
    q->data = x;
    q->next = NULL;
    p->next = q;
    p = q;
    return;

}
int main()
{
    int n, x;
    cin >> n;
    LinkList L;
    CreateList(L, n);

    cin >> x;
    InsertList(L, n, x);
    OutputList(L);
}
