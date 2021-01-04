#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {

    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);
    bool filled = false;
    while(head != NULL)
    {
        if(data<head->data)
        {
            DoublyLinkedListNode* tempNewNode = head;
            newNode->next = head;
            newNode->prev = head->prev;
            if(head->prev != NULL)
            {
                head->prev->next = newNode;
            }
            head->prev = newNode;
            filled = true;
            break;
        }
        else
        {
            if(head->next == NULL)
            {
                break;
            }
            head = head->next;
        }
    }
    if(!filled)
    {
        // Add at the end
        // We should be at the last element
        head->next = newNode;
        newNode->prev = head;
    }
    // Now need to back iterate till we reach start
    while(head->prev != NULL)
    {
        head = head->prev;
    }
    return head;
    /*
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);
    if(head == NULL)
    {
        return newNode;
    }
    else if(data<head->data)
    {
        cout<<"Here \n";
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    else {
        cout<<"No here\n";
        DoublyLinkedListNode* tempNode = sortedInsert(head->next, data);
        cout<<tempNode->data<<endl;
        head->next = tempNode;
        tempNode->prev = head;
        return head;
    }*/
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        int data;
        cin >> data;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

        print_doubly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_doubly_linked_list(llist1);
    }

    fout.close();

    return 0;
}
