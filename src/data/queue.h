#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


template<class type>
class Queue
{
    struct Node
    {
        type element;
        Node *next;
    };
    int length;
    Node *front;
    Node *rear;
//    double total;

public:
    Queue()
    {
        length=0;
//        total=0;
        front=rear=nullptr;
    }

    bool isEmpty() const
    {
        return length==0;
    }

    int getLength() const
    {
        return length;
    }

    type getFront() const
	{
        return front->element;
	}

	type getRear() const
	{
		if(!isEmpty())
            return rear->item;
	}

    void enqueue(type item)
    {
        Node *ptr=new Node;
        ptr->element=item;
        ptr->next=nullptr;
        if(isEmpty())
        {
            front=rear=ptr;
        }
        else
        {
            rear->next=ptr;
            rear=ptr;
        }
        length++;
        //total+=prod.getPrice();
    }

    type dequeue()
    {
        if(!isEmpty())
        {
            Node *tempNode=front;
            front=front->next;
            tempNode->next=NULL;
            type element=tempNode->element;
            delete tempNode;
            if(length==1)
                rear=NULL;
            length--;
            return element;
        }
    }

    void clear()
    {
        Node*cur;
        while(front!=nullptr)
        {
            cur=front;
            front=front->next;
            delete cur;
        }
        rear=nullptr;
        length=0;
    }
};

#endif // QUEUE_H_INCLUDED
