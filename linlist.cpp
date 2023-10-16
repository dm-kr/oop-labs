#include <iostream>

using namespace std;


struct Node {
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class LinkedList
{
    int size = 1;
    Node *head = new Node(0);
    Node *tail = head;

public:
    LinkedList() {}
    LinkedList(int value)
    {
        head = new Node(value);
        tail = head;
    }
    LinkedList(int value, Node *next)
    {
        head = new Node(value);
        tail = next;
    }

    int getsize()
    {
        return size;
    }

    int getvalue(int index) {
        if(index >= size)
            return -1;
        Node* temp = head;
        for(int i=0; i<index; ++i)
            temp = temp->next;
        
        return temp->val;
    }
    
    void push(int val) {
        Node* newnode = new Node(val);
        newnode->next = head;
        head = newnode;
        if(size == 0)
            tail = newnode;
        size++;
    }
    
    void pushback(int val) {
        if(size  == 0) {
            push(val);
            return;
        }
        Node *newnode = new Node(val);
        tail->next = newnode;
        tail = newnode;
        size++;
    }
    
    void insert(int index, int val) {
        if(index>size)
            return;
        if(index == size)
        {
            pushback(val);
            return;
        }
        if(index == 0)
        {
            push(val);
            return;
        }
        Node *temp =head;
        Node *newnode = new Node(val);
        for(int i=0; i<index-1; ++i) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        size++;
    }
    
    void delIndex(int index) {
        if(index>=size)
            return;
        if(index == size-1) {
           
            if(index == 0){
                head = nullptr;
                tail = nullptr;
                return;
            }
            
            Node *temp = head;
            while(temp->next != tail) {
                temp = temp->next;
            }
            tail = temp;
            temp->next = nullptr;
            return;
        }
        if(index == 0) {
            head = head->next;
            return;
        }
        
        Node *temp = head;
        for(int i=0; i<index-1; ++i) {
            temp = temp->next;
        }
        Node *t = temp->next;
        temp->next = temp->next->next;
        t->next = nullptr;
            
        size--;
    }

    void printList()
    {
        Node *curr = head;
        while (curr != tail)
        {
            std::cout << curr->val << ", ";
            curr = curr->next;
        }
        std::cout << tail->val << endl;
    }

    void pop()
    {
        Node *curr = head;
        while (curr->next != tail)
        {
            curr = curr->next;
        }
        tail = curr;
        size--;
    }
};

int main()
{
    LinkedList a(1);
    a.pushback(4);
    a.pushback(6);
    a.pushback(7);
    a.push(13);
    a.insert(3, 5);
    std::cout << a.getvalue(1) << std::endl;
    a.printList();
    std::cout << a.getsize() << std::endl;
    a.delIndex(2);
    a.printList();
    a.pop();
    a.printList();
    std::cout << a.getsize() << std::endl;
}