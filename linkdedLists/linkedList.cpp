#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Node()
    // {
    //     data = 0;
    //     next = nullptr;
    // }

    // Node(int x)
    // {
    //     data = x;
    //     next = nullptr;
    // }

    // Node(int x, Node *nxt)
    // {
    //     data = x;
    //     next = nxt;
    // }

    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *nxt) : data(x), next(nxt) {}
};

// CONVERT ARRAY TO LL
Node *convertArrToLL(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// PRINT LL
void printList(Node *head)
{
    Node *temp = head;
    while (temp) // sets temp to null after while loop
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// GET LENGTH OF LL
int getLength(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

// SEARCH ELEMENT IN LL
bool checkIfPresent(Node *head, int target)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == target)
            return true;
        temp = temp->next;
    }
    return false;
}

// ====================================== DELETION IN  LL ======================================

// DELETE HEAD
Node *deleteHead(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// DELETE TAIL
Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// DELETE NODE
Node *deleteNode(Node *head, int target)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    while (temp->next->next)
    {
        if (temp->next->data == target)
        {
            Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
        }
        temp = temp->next;
    }
    if (temp->next->data == target)
    {
        Node *nodeToDelete = temp->next;
        temp->next = NULL;
        free(nodeToDelete);
    }

    return head;
}

// DELETE Kth NODE
Node *deleteKthNode(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int count = 0;
    Node *prev = NULL;
    Node *temp = head;
    while (temp)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

// DELETE NODE(ALTERNATE)
Node *deleteNode1(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (head->data == k)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // int count = 0;
    Node *prev = NULL;
    Node *temp = head;
    while (temp)
    {
        // count++;
        if (temp->data == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

// ====================================== INSERTION IN LL ======================================

// INSERT HEAD
Node *insertHead(Node *head, int val)
{
    // Node* temp = new Node(val, head);
    // return temp;

    // one line solution
    return new Node(val, head);
}

// INSERT TAIL
Node *insertTail(Node *head, int val)
{
    Node *tail = new Node(val, NULL);
    if (head == NULL)
        return tail;

    Node *temp = head;
    while (temp->next) // sets temp to last element after while loop
    {
        temp = temp->next;
    }
    temp->next = tail;
    return head;
}

// INSERT AT Kth POSITION
Node *insertAtKthPosition(Node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
            return new Node(val);
        else
            return NULL;
    }

    if (k == 1)
    {
        return new Node(val, head);
    }

    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;

        if (count == k - 1)
        {
            Node *x = new Node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// INSERT BEFORE NODE WITH GIVEN VALUE
Node *insertBeforeNodeWithValK(Node *head, int val, int K)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->data == K)
    {
        return new Node(val, head);
    }

    Node *temp = head;
    // int count = 0;
    while (temp->next)
    {
        // count++;

        if (temp->next->data == K)
        {
            Node *x = new Node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// MAIN
int main(int argc, char const *argv[])
{
    /* code */
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *head = convertArrToLL(arr); // convert array to list

    printList(head); // print list
    // cout << "Length: " << getLength(head) << endl;

    // int itemToCheck = 3; // search item in LL
    // cout << "Check if " << itemToCheck << "is present in LL: " << (checkIfPresent(head, itemToCheck) ? "Yes" : "No") << endl;

    // ===== DELETION IN LL =====
    // Node *newHead1 = deleteHead(head);
    // cout << "Delete head: ";
    // printList(newHead1);

    // Node *newHead2 = deleteTail(newHead1);
    // cout << "Delete tail: ";
    // printList(newHead2);

    // int targetToDelete = 4;
    // // Node *newHead3 = deleteNode(newHead2, targetToDelete);
    // Node *newHead3 = deleteNode1(newHead2, targetToDelete);
    // cout << "Delete target(node with data): " << targetToDelete << endl;
    // printList(newHead3);

    // int k = 2;
    // Node *newHead4 = deleteKthNode(newHead3, k);
    // cout << "Delete kth node: k=" << k << endl;
    // printList(newHead4);

    // ===== INSERTION IN LINKED LIST =====
    int headValToInsert = 9;
    Node *newHead1 = insertHead(head, headValToInsert);
    cout << "Insert head: " << headValToInsert << endl;
    printList(newHead1);

    int tailValToInsert = 10;
    Node *newHead2 = insertTail(newHead1, tailValToInsert);
    cout << "Insert tail: " << tailValToInsert << endl;
    printList(newHead2);

    int kthValToInsert = 11;
    int k = 4;
    Node *newHead3 = insertAtKthPosition(newHead2, kthValToInsert, k);
    cout << "Insert at kth position: " << "k: " << k << ", val:" << kthValToInsert << endl;
    printList(newHead3);

    int valToInsert = 12;
    int insertBefore = 7;
    Node *newHead4 = insertBeforeNodeWithValK(newHead3, valToInsert, insertBefore);
    cout << "Insert before: " << insertBefore << ", val: " << valToInsert << endl;
    printList(newHead4);

    return 0;
}
