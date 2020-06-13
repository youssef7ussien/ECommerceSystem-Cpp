#ifndef E_COMMERCE_SYSTEM_STACK_H
#define E_COMMERCE_SYSTEM_STACK_H

template <class type>
class Stack
{
    struct Node
    {
        type item;
        Node *next;
    };
    Node *top;

public:

    Stack()
    {
        top=nullptr;
    }

    bool isEmpty()
    {
        return top==nullptr;
    }

    void push(type item)
    {
        Node *newNode=new Node;
        if(newNode!=NULL)
        {
            newNode->item=item;
            newNode->next=top;
            top=newNode;
        }
    }

    type pop()
    {
        if(!isEmpty())
        {
            Node *tempNode=top;
            top=top->next;
            tempNode=NULL;
            delete tempNode;
        }
    }

    type getTop()
    {
        if(!isEmpty())
            return top->item;
    }

};

#endif //E_COMMERCE_SYSTEM_STACK_H
