#include <iostream>
#include <cstdlib>


class Node
{
public:
    Node* next;
    int data;
};

using namespace std;

class LinkedList
{
public:
    int length;
    Node* head;
    
    LinkedList();
    ~LinkedList();
    Node *  InsertNode(int index, double x);
    int FindNode(double x);
    int DeleteNode(double x);
    void print();
    void DisplayList();
};

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
    Node* currNode = head, *nextNode = NULL;
    while (currNode != NULL) {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
    std::cout << "LIST DELETED";
}

Node* LinkedList::InsertNode(int index, double x){
    
    if (index < 0) return NULL;
    
    int currIndex    =    1;
    Node* currNode    =    head;
    while (currNode && index > currIndex) {
        currNode    =    currNode->next;
        currIndex++;
    }
    
    if (index > 0 && currNode == NULL) return NULL;
    
    Node* newNode    =    new    Node;
    newNode->data    =    x;
    if (index == 0) {
        newNode->next    =    head;
        head        =    newNode;
        this->length++;
    }
    else {
        newNode->next    =    currNode->next;
        currNode->next    =    newNode;
        this->length++;
    }
    return newNode;
    
    
    
}

int LinkedList::FindNode(double x) {
    Node* currNode = head;
    int currIndex = 1;
    while (currNode && currNode->data != x) {
        currNode = currNode->next;
        currIndex++;
    }
    return 0;
}

int LinkedList::DeleteNode(double x) {
    Node* prevNode = NULL;
    Node* currNode = head;
    int currIndex = 1;
    while (currNode && currNode->data != x) {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode) {
        if (prevNode) {
            prevNode->next = currNode->next;
            delete currNode;
        }
        else {
            head = currNode->next;
            delete currNode;
        }
        return currIndex;
    }
    return 0;
}

void LinkedList::print(){
    Node* head = this->head;
    int i = 1;
    while(head){
        std::cout << i << ": " << head->data<<endl;
        head = head->next;
        i++;
    }
}

void LinkedList::DisplayList() {
    int num = 0;
    Node* currNode = head;
    while (currNode != NULL) {
        cout << currNode->data << endl;
        currNode = currNode->next;
        num++;
    }
    cout << "Number of nodes in the list: " << num << endl;
}

int main(int argc, char const *argv[])
{
    LinkedList* list = new LinkedList();
    list->InsertNode(0, 7.0);
    list->InsertNode(1, 5.0);
    list->InsertNode(-1, 5.0);
    list->InsertNode(0, 6.0);
    list->InsertNode(8, 4.0);
    list->DisplayList();
    if (list->FindNode(5.0) > 0) cout << "5.0 found" << endl;
    else                         cout << "5.0 not found";
    if (list->FindNode(5.0) > 0) cout << "4.5 found" << endl;
    else                         cout << "4.5 not found";
    list->DeleteNode(7.0);
    list->DisplayList();

    return 0;
}
