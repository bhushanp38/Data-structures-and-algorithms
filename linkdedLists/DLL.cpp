#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node() : data(0), next(nullptr), back(nullptr) {}
    Node(int x) : data(x), next(nullptr), back(nullptr) {}
    Node(int x, Node *nextptr, Node *backptr) : data(x), next(nextptr), back(backptr) {}
};

Node *convertArrToDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head; // initially

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp; // prev = prev->next;
    }

    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void printReverseList(Node *head)
{
    Node *temp = head;
    while (temp->next)
        temp = temp->next;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->back;
    }

    cout << endl;
}
// ====================================== DELETION IN DLL ======================================
// DELETE HEAD
Node *deleteHead(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == nullptr)
    {
        delete head;
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    head->back = nullptr;
    delete temp;
    return head;
}

// DELETE TAIL
Node *deleteTail(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == nullptr)
    {
        delete head;
        return NULL;
    }
    Node *temp = head;
    while (temp->next) // sets temp to last element after while loop
        temp = temp->next;

    temp->back->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

// DELETE Kth ELEMENT
Node *deleteKthElement(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    if (k == 1)
    {
        Node *newHead = head->next;
        if (head->next != NULL)
        {
            head->back = nullptr;
        }
        head->next = nullptr;
        delete head;
        return newHead;
    }
    int count = 0;
    // Node *prev = NULL;
    Node *temp = head;
    while (temp)
    {
        count++;
        if (count == k)
        {
            temp->back->next = temp->next;
            if (temp->next != NULL)
                temp->next->back = temp->back;
            temp->back = nullptr;
            temp->next = nullptr;
            delete temp;
            break;
        }
        // prev = temp;
        temp = temp->next;
    }

    return head;
}

// DELETE NODE WITH GIVEN DATA
Node *deleteNodeWithVal(Node *head, int nodeVal)
{
    if (head == NULL)
        return NULL;
    if (head->data == nodeVal)
    {
        Node *newHead = head->next;
        if (newHead)
            newHead->back = nullptr;
        head->next = nullptr;
        delete head;
        return NULL;
    }
    // Node *prev = nullptr;
    Node *temp = head;
    while (temp)
    {
        if (temp->data == nodeVal)
        {
            temp->back->next = temp->next;
            if (temp->next)
                temp->next->back = temp->back;
            temp->back = nullptr;
            temp->next = nullptr;
            delete temp;
            break;
        }
        // prev = temp;
        temp = temp->next;
    }

    return head;
}

// DELETE NODE BEFORE GIVEN DATA
Node *deleteNodeBeforeVal(Node *head, int nextNodeVal)
{
    if (head == NULL)
        return NULL;

    if (head->data == nextNodeVal)
    {
        return head;
    }
    // Node *prev = nullptr;
    Node *temp = head;
    while (temp->next)
    {
        if (temp->next->data == nextNodeVal)
        {
            temp->back->next = temp->next;
            if (temp->next)
                temp->next->back = temp->back;
            temp->back = nullptr;
            temp->next = nullptr;
            delete temp;
            break;
        }
        // prev = temp;
        temp = temp->next;
    }

    return head;
}

// ====================================== INSERTION IN DLL : INSERT BEFORE ======================================
// INSERT BEFORE HEAD
Node *insertHead(Node *head, int val)
{
    Node *newHead = new Node(val, head, nullptr);
    if (head == NULL)
        return newHead;
    head->back = newHead;
    return newHead;
}

// INSERT BEFORE TAIL
Node *insertBeforeTail(Node *head, int val)
{

    if (head == NULL)
        return new Node(val);

    if (head->next == NULL)
    {
        insertHead(head, val);
    }

    Node *temp = head;
    while (temp->next)
    {

        temp = temp->next;
    }

    Node *newNode = new Node(val, temp, temp->back);
    temp->back->next = newNode;
    temp->back = newNode;

    return head;
}

// INSERT BEFORE Kth NODE
Node *insertBeforeKthNode(Node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
            return new Node(val);

        return NULL;
    }
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        if (count == k)
        {
            Node *newNode = new Node(val, temp, temp->back);
            temp->back->next = newNode;
            temp->back = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// INSERT BEFORE NODE WITH VAL K
Node *insertBeforeNodeWithValK(Node *head, int val, int K)
{
    if (head == NULL)
        return NULL;

    Node *temp = head;
    while (temp)
    {
        if (temp->data == K)
        {
            Node *newNode = new Node(val, temp, temp->back);
            temp->back->next = newNode;
            temp->back = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// ====================================== INSERTION IN DLL : INSERT AFTER ======================================
// INSERT AFTER HEAD
Node *insertAfterHead(Node *head, int val)
{
    if (head == NULL)
        return new Node(val);
    if (head->next == NULL)
    {
        Node *newNode = new Node(val, nullptr, head);
        head->next = newNode;
        return head;
    }
    Node *newNode = new Node(val, head->next, head);
    head->next->back = newNode;
    head->next = newNode;
    return head;
}

// INSERT AFTER TAIL
Node *insertTail(Node *head, int val)
{
    if (head == NULL)
        return new Node(val);
    if (head->next == NULL)
    {
        Node *newNode = new Node(val, nullptr, head);
        head->next = newNode;
        return head;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;

    Node *newNode = new Node(val, nullptr, temp);
    temp->next = newNode;

    return head;
}

// INSERT AFTER Kth POSITION
Node *insertAfterKthNode(Node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
            return new Node(val);

        return NULL;
    }
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        if (count == k)
        {
            Node *newNode = new Node(val, nullptr, temp);
            if (temp->next)
            {
                newNode->next = temp->next;
                temp->next->back = newNode;
            }
            temp->next = newNode;
        }
        temp = temp->next;
    }
    return head;
}

// INSERT AFTER NODE WITH GIVEN VALUE
Node *insertAfterNodeWithValK(Node *head, int val, int K)
{
    if (head == NULL)
        return NULL;

    Node *temp = head;
    while (temp)
    {
        if (temp->data == K)
        {
            Node *newNode = new Node(val, nullptr, temp);
            if (temp->next)
            {
                newNode->next = temp->next;
                temp->next->back = newNode;
            }
            temp->next = newNode;
        }
        temp = temp->next;
    }
    return head;
}

// ====================================== DLL OPERATIONS ======================================
Node *reverseDLL(Node *head)
{
    // Approach 1: using stack
    stack<int> st;
    Node *temp = head;
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *head = convertArrToDLL(arr); // convert array to list

    cout << "Linked list: " << endl;
    printList(head); // print list

    // // ===== DELETION IN DLL =====
    // Node *newHead1 = deleteHead(head);
    // cout << "Delete head: " << endl;
    // printList(newHead1);

    // Node *newHead2 = deleteTail(newHead1);
    // cout << "Delete tail: " << endl;
    // printList(newHead2);

    // int k = 6;
    // Node *newHead3 = deleteKthElement(newHead2, k);
    // cout << "Delete kth element: k=" << k << endl;
    // printList(newHead3);

    // int elementToDelete = 6;
    // Node *newHead4 = deleteNodeWithVal(newHead3, elementToDelete);
    // cout << "Delete node: val=" << elementToDelete << endl;
    // printList(newHead4);

    // int nextElement = 5;
    // Node *newHead5 = deleteNodeBeforeVal(newHead4, nextElement);
    // cout << "Delete node before: val=" << nextElement << endl;
    // printList(newHead5);

    // ===== INSERTION IN DLL =====
    // ===== INSERT BEFORE
    // int elementToInsert1 = 9;
    // Node *newHead1 = insertHead(head, elementToInsert1);
    // cout << "Insert head: " << elementToInsert1 << endl;
    // printList(newHead1);

    // int elementToInsert2 = 10;
    // Node *newHead2 = insertBeforeTail(newHead1, elementToInsert2);
    // cout << "Insert before tail: " << elementToInsert2 << endl;
    // printList(newHead2);

    // int elementToInsert3 = 11;
    // int k = 4;
    // Node *newHead3 = insertBeforeKthNode(newHead2, elementToInsert3, k);
    // cout << "Insert before kth element: " << elementToInsert3 << ", k=" << k << endl;
    // printList(newHead3);

    // int elementToInsert4 = 12;
    // int nextNodeVal = 8;
    // Node *newHead4 = insertBeforeNodeWithValK(newHead3, elementToInsert4, nextNodeVal);
    // cout << "Insert before node: " << elementToInsert4 << ", K=" << nextNodeVal << endl;
    // printList(newHead4);

    // ===== INSERT AFTER
    // int elementToInsert1 = 9;
    // Node *newHead1 = insertAfterHead(head, elementToInsert1);
    // cout << "Insert after head: " << elementToInsert1 << endl;
    // printList(newHead1);
    // printReverseList(newHead1); // to check linking

    // int elementToInsert2 = 10;
    // Node *newHead2 = insertTail(newHead1, elementToInsert2);
    // cout << "Insert after tail: " << elementToInsert2 << endl;
    // printList(newHead2);
    // printReverseList(newHead2); // to check linking

    // int elementToInsert3 = 11;
    // int k = 4;
    // Node *newHead3 = insertAfterKthNode(newHead2, elementToInsert3, k);
    // cout << "Insert after kth element: " << elementToInsert3 << ", k=" << k << endl;
    // printList(newHead3);
    // printReverseList(newHead3); // to check linking

    // int elementToInsert4 = 12;
    // int nextNodeVal = 8;
    // Node *newHead4 = insertAfterNodeWithValK(newHead3, elementToInsert4, nextNodeVal);
    // cout << "Insert after node: " << elementToInsert4 << ", K=" << nextNodeVal << endl;
    // printList(newHead4);
    // printReverseList(newHead4); // to check linking

    cout << "Reversed DLL: " << endl;
    printList(reverseDLL(head));

    return 0;
}
