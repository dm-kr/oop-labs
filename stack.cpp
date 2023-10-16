#include <iostream>
#include <optional>

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

public:
    LinkedList() {}
    LinkedList(int value)
    {
        head = new Node(value);
    }
    LinkedList(int value, Node *next)
    {
        head = new Node(value);
    }

    Node gethead()
    {
        return *head;
    }

    int getsize()
    {
        return size;
    }
    
    void push(int val) {
        Node *newnode = new Node(val);
        Node *curr = head;
        while(curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newnode;
        size++;
    }

    Node pop()
    {   
        if (head == nullptr)
        {   
            Node *empty = new Node(0);
            std::cout << "Stack is empty" << std::endl;
            return *empty;
        }
        Node *curr = head;
        while(curr->next->next != nullptr)
        {
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next = nullptr;
        size--;
        return *temp;
    }

    void printList()
    {
        Node *curr = head;
        while (curr->next != nullptr)
        {
            std::cout << curr->val << ", ";
            curr = curr->next;
        }
        std::cout << curr->val << endl;
    }
};

std::ostream &operator<<(std::ostream &stream, LinkedList &obj)
{
    Node curr = obj.gethead();
    while(curr.next != nullptr)
    {
        stream << curr.val << ", ";
        curr = *curr.next;
    }
    stream << curr.val;
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const Node &obj)
{
    stream << obj.val;
    return stream;
}

int main()
{
    LinkedList a(1);
    a.push(4);
    a.push(6);
    a.push(7);
    std::cout << "stack: " << a << std::endl;
    std::cout << "size = " << a.getsize() << std::endl;
    std::cout << "stack: " << a << std::endl;
    std::cout << "popped value: " << a.pop() << std::endl;
    std::cout << "stack: " << a << std::endl;
    std::cout << "size = " << a.getsize() << std::endl;
    a.pop();
    std::cout << "stack: " << a << std::endl;
    a.pop();
    std::cout << "stack: " << a << std::endl;
    a.pop();
    std::cout << "stack: " << a << std::endl;
}