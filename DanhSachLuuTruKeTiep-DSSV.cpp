#include <iostream>
using namespace std;

struct SinhVien
{
    string name;
    double gpa;
    SinhVien() {}
    SinhVien(string ten, double diem)
    {
        name = ten;
        gpa = diem;
    }
};

struct node
{
    SinhVien data;
    node *next;
};

node *makeNode(SinhVien x)
{
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void duyet(node *head)
{
    while (head != NULL)
    {
        cout << head->data.name << " " << head->data.gpa << endl;
        head = head->next;
    }
}

int size(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

void pushFront(node **head, SinhVien x)
{
    node *newNode = makeNode(x);
    newNode->next = *head;
    *head = newNode;
}

void pushBack(node **head, SinhVien x)
{
    node *newNode = makeNode(x);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insert(node **head, SinhVien x, int k)
{
    int n = size(*head);
    if (k < 1 || k > n + 1)
    {
        return;
    }
    if (k == 1)
    {
        pushFront(head, x);
        return;
    }
    node *temp = *head;
    for (int i = 1; i < k - 1; i++)
    {
        temp = temp->next;
    }
    node *newNode = makeNode(x);
    newNode->next = temp->next;
    temp->next = newNode;
}

void popFront(node **head)
{
    if (*head == NULL)
    {
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    delete temp;
}

void popBack(node **head)
{
    if (*head == NULL)
    {
        return;
    }
    node *temp = *head;
    if (temp->next == NULL)
    {
        *head = NULL;
        delete temp;
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void erase(node **head, int k)
{
    int n = size(*head);
    if (k < 1 || k > n)
    {
        return;
    }
    if (k == 1)
    {
        popFront(head);
        return;
    }
    node *temp = *head;
    for (int i = 1; i < k - 1; i++)
    {
        temp = temp->next;
    }
    node *kth = temp->next; // vi tri k
    temp->next = kth->next; // k-1 -> k+1
    delete kth;
}

void sapxep(node **head)
{

    for (node *i = *head; i != NULL; i = i->next)
    {

        node *maxNode = i;

        for (node *j = i->next; j != NULL; j = j->next)
        {
            if (maxNode->data.gpa > j->data.gpa)
            {
                maxNode = j;
            }
        }

        SinhVien temp = i->data;
        i->data = maxNode->data;
        maxNode->data = temp;
    }
}

int main()
{
    node *head = NULL;
    while (1)
    {
        cout << "...................\n";
        cout << "1 Them vao dau danh sach\n";
        cout << "2 Them vao cuoi danh sach\n";
        cout << "3 Them vao giua danh sach\n";
        cout << "4 xoa dau danh sach\n";
        cout << "5 xoa cuoi danh sach\n";
        cout << "6 xoa giua danh sach\n";
        cout << "7 Sap xep Danh sach theo chieu tang dan cua gpa\n";
        cout << "8 duyet \n";
        cout << "Lua Chon Cua Ban ";
        int lc;
        cin >> lc;
        if (lc == 1)
        {
            string ten;
            double diem;
            cout << "Nhap ten: ";
            cin >> ten;
            cout << "Nhap diem: ";
            cin >> diem;
            pushFront(&head, SinhVien(ten, diem));
        }
        else if (lc == 2)
        {
            string ten;
            double diem;
            cout << "Nhap ten: ";
            cin >> ten;
            cout << "Nhap diem: ";
            cin >> diem;
            pushBack(&head, SinhVien(ten, diem));
        }
        else if (lc == 3)
        {
            string ten;
            double diem;
            cout << "Nhap ten: ";
            cin >> ten;
            cout << "Nhap diem: ";
            cin >> diem;
            int k;
            cout << "Nhap vi tri k: ";
            cin >> k;
            insert(&head, SinhVien(ten, diem), k);
        }
        else if (lc == 4)
        {
            popFront(&head);
        }
        else if (lc == 5)
        {
            popBack(&head);
        }
        else if (lc == 6)
        {
            int k;
            cout << "Nhap vi tri k: ";
            cin >> k;
            erase(&head, k);
        }
        else if (lc == 7)
        {

            sapxep(&head);
            cout << "danh Sach Sinh Vien Sau Khi Sap Xep" << endl;
            duyet(head);
        }
        else if (lc == 8)
        {
            duyet(head);
        }
        else
        {
            break;
        }
    }
    return 0;
}
