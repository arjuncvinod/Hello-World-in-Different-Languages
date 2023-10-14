#include <iostream>
#include <map>
using namespace std;

class Node{
    public:
    int d;
    Node* next;

    Node(int d){
        this -> d = d;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, Node* &tail, int d, map<Node*,bool> &visited){
    if (head == NULL) {
        Node* newNode = new Node(d);
        visited[newNode] = false;
        head = newNode;
        tail = newNode;
        return;
    } 
    Node* newNode = new Node(d);
    visited[newNode] = false;
    newNode -> next = head;
    head = newNode;
}

void printLL(Node* head) {
    while (head != NULL){
        cout << head -> d << " ";
        head = head -> next;
    } cout << endl;
}

bool detectLoop(Node* head, map<Node*, bool> visited){
    // O(N) for TC and SC
    while (head != NULL) {
        if (visited[head])
            return 1;
        
        visited[head] = true;
        head = head -> next;
    }

    return 0;
}

Node* findStartingNodeOfLoop(Node* head){

    if (head == NULL){
        return head;
    }
    
    Node* slow = head;
    Node* fast = findStartingNodeOfLoop(head);

    while (slow != fast){
        slow = slow -> next;
        fast = fast -> next;
    }

    return slow;

}

Node* detectLoopUsingFloydCycle(Node* head){
    if (head == NULL)
        return NULL;

    Node * slow = head;
    Node * fast = head;

    while (slow != NULL && fast != NULL) {
        slow = slow -> next;
        fast = fast -> next;
        
        if (fast != NULL){
            fast = fast -> next;
        }

        if (slow == fast){
            return slow;
        }
        
    }

    return NULL;

}


void removeLoopFromLL(Node* slow){
    Node *temp = slow;

    while (temp -> next != slow) {
        temp = temp -> next;
    }

    temp -> next = NULL;
}


int main() {

    map <Node*, bool> visited;
    Node* head = NULL;
    Node* tail = NULL;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i++){
        insertAtHead(head, tail, arr[i], visited);
    }

    printLL(head);

    tail -> next = head -> next;

    cout << detectLoop(head, visited) << endl;
    
    cout << detectLoopUsingFloydCycle(head) -> d << endl;

    Node* startingNodeOfLoop = findStartingNodeOfLoop(head);

    cout << "Loop starts from " << startingNodeOfLoop -> d << endl;

    removeLoopFromLL(startingNodeOfLoop);

    cout << detectLoopUsingFloydCycle(head) << endl;

    return 0;
}
