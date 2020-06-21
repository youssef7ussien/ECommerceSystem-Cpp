#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template<class type>
class Queue
{
    struct Node
    {
        type item;
        Node *next;
    };
    int length;
    Node *front;
    Node *rear;

public:
    Queue()
    {
        length=0;
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
        return front->item;
	}

	type getRear() const
	{
        return rear->item;
	}

    void enqueue(const type &item)
    {
        Node *ptr=new Node;
        ptr->item=item;
        ptr->next=nullptr;
        if(isEmpty())
            front=rear=ptr;
        else
        {
            rear->next=ptr;
            rear=ptr;
        }
        length++;
    }

    type dequeue()
    {
        Node *tempNode=nullptr;
        if(!isEmpty())
        {
            tempNode=front;
            front=front->next;
            tempNode->next=NULL;
            type item=tempNode->item;
            delete tempNode;
            if(length==1)
                rear=NULL;
            length--;
            return item;
        }
        return tempNode->item;
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
    Queue<type> copy() const
    {
        Node*cur=front;
        Queue<type> q;
        while (cur!=NULL)
        {
            q.enqueue(cur->item);
            cur=cur->next;
        }
        return q;
    }

//    void operator=(const Queue &queue)
//    {
//        Node* tmp = queue.front;
//        while(tmp->next != NULL) {
//            front->item = tmp->item;
//            front->next = new Node;
//            front = front->next;
//            tmp = tmp->next;
//        }
//    }


};

#endif // QUEUE_H_INCLUDED
