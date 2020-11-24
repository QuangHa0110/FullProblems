#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int value;
    Node *next;
} Node;

Node *makeNode(int data)
{
    Node *p = new Node();
    p->value = data;
    p->next = NULL;
    return p;
}

void printResult(Node *h)
{
    if (h == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        Node *p = h;
        while (p != NULL)
        {
            printf("%d ", p->value);
            p = p->next;
        }
    }
}
Node *addFirst(Node *h, int data)
{
    Node *p = makeNode(data);
    if (h == NULL)
    {
        h = p;
    }
    else
    {
        p->next = h;
        h = p;
    }
    return h;
}
Node *addLast(Node *h, int data)
{
    Node *p = makeNode(data);
    if (h == NULL)
    {
        h = p;
    }
    else
    {
        Node *t = h;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = p;
    }
    return h;
}
Node *addAt(Node *h, int data, int position)
{
    Node *p = makeNode(data);
    if (h == NULL)
    {
        h = p;
    }
    else
    {
        int k = 0;
        Node *t = h;
        while (t->next != NULL)
        {
            if (k + 1 == position)
                break;
            else
            {
                k++;
                t = t->next;
            }
        }
        p->next = t->next;
        t->next = p;
    }

    return h;
}
Node *deleteFirst(Node *h) // xóa node ở đầu danh sách
{
    if (h == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        Node *p = h->next;
        free(h);
        h = p;
    }
    return h;
}
Node *deleteLast(Node *h) // xóa node ở cuối danh sách
{
    if (h == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        Node *t = h;
        while (t->next->next != NULL)
        {
            t = t->next;
        }
        free(t->next->next);
        t->next = NULL;
    }
    return h;
}
Node *deleteAt(Node *h, int position) // xóa 1 node ở vị trí bất kì trong danh sách
{
    if (h == NULL)
    {
        printf("Linked list is empty");
    }
    else if (position == 0)
    {
        h = deleteFirst(h);
    }
    else
    {
        Node *t = h;
        int k = 1;
        while (t->next->next != NULL && k != position)
        {
            k++;
            t = t->next;
        }
        if (k != position) // nếu không tìm thấy vị trí cần xóa trong danh sách thì xóa ở vị trí cuối cùng
        {
            deleteLast(h);
        }
        else
        {
            Node *p = t->next->next; // gán node sau node cần xóa vào một node mới
            free(t->next);           // giải phóng cho node xóa
            t->next = p;             // gán node đó bằng node tiếp theo
            free(p);                 // giải phóng node mới
        }
    }
    return h;
}
Node *removeAt(Node *h, int data) // giải phóng node có value bằng data
{
    if (h == NULL)
    {
        free(h);
        printf("Danh sách rỗng");
    }
    else
    {
        Node *t = h;
        while (t->next->value != data) // duyệt danh sách
        {
            t = t->next;
        }
        Node *p = t->next->next; // gán node sau node cần xóa vào một node mới
        free(t->next);           // giải phóng cho node xóa
        t->next = p;             // gán node đó bằng node tiếp theo
        free(p);                 // giải phóng node mới
    }
    return h;
}
Node *removeAll(Node *h)
{

    while (h != NULL)
    {
        Node *p = h->next;
        free(h);
        h = p;
    }
    return h;
}

int main()
{
    Node *head = NULL;
    for (int i = 0; i < 10; i++)
    {
        head = addLast(head, i);
    }

    head = deleteAt(head, 7);
    printResult(head);
    return 0;
}
