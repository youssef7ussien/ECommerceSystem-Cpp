#pragma once

#include<iostream>
using namespace std;

template<class type>
class List {
	struct Node {
		type item;
		Node *next;
	};
	int length;
	Node *head, *tail;
public:

	List()
	{
		tail=head=NULL;
		length=0;
	}

	bool isEmpty() const
	{
		return (length==0);
	}

	int getLength() const
	{
		return length;
	}

	void clear()
	{
		Node *cur;
		while (head!=NULL)
        {
			cur=head;
			head=head->next;
			delete cur;
		}
        tail=NULL;
        length=0;
	}

	void insertLast(type element)
	{

		Node *newNode=new Node;
		newNode->item=element;

		if (length==0) {
			tail=head=newNode;
			newNode->next=NULL;
		}
		else {
			tail->next=newNode;
			newNode->next=NULL;
			tail=newNode;
		}
		length++;
	}

	bool removeFirst()
	{
		if (length==0)
			return false;
		else if (length==1)
        {
			delete head;
			head=tail=NULL;
			length--;
            return true;
		}
		else
            {
			Node *cur=head;
			head=head->next;
			delete cur;
			length--;
            return true;
		}
		return false;
	}

	bool removeLast()
	{
		if (length == 0)
			return false;
		else if (length == 1)
        {
			delete tail;
			tail = head = NULL;
			length--;
            return true;
		}
		else {
			Node *cur, *prev;
			cur = head->next;
			prev = head;
			while (cur->next != NULL) {
				prev = cur;
				cur = cur->next;
			}
			prev->next = NULL;
			tail = prev;
			delete cur;
			length--;
			return true;
		}
	}

	bool removeAt(int index)
	{
        if(index==0)
            return removeFirst();
        else if(index==length-1)
            return removeLast();
		else if(index>0 && index<length)
        {
			Node *cur, *prev;
			cur = head->next;
			prev = head;
			for (int i = 1; i<index; i++)
			{
				prev = cur;
				cur = cur->next;
			}
            prev->next = cur->next;
            cur->next = NULL;
            delete cur;
            length--;
            return true;
		}
		return false;
	}

    template<typename secondType>
	bool remove(secondType element)
	{
		if (head->item == element)
            return removeFirst();
		else if (tail->item == element)
            return removeLast();
		else
        {
			Node *cur, *prev;
			cur = head->next;
			prev = head;
			while (cur != NULL && cur->item != element) {
				prev = cur;
				cur = cur->next;
			}
			if (cur == NULL)
				return false;
			else
			{
				prev->next = cur->next;
				cur->next = NULL;
				delete cur;
				length--;
                return true;
			}
		}
		return false;
	}

	type& getHead() const
	{
		return head->item;
	}

	template<typename secondType>
	type* getItem(secondType element)
	{
		Node *cur = head;
		while (cur != NULL) {
			if (cur->item == element)
                return &cur->item;
			cur = cur->next;
		}
        return &cur->item;
	}

	type* operator [](string name)
	{
		return getItem<string>(name);
	}

	type* getItemAt(int index)
	{
        Node *cur = head;
        while(index--)
            cur = cur->next;
        return &cur->item;
	}

	type* operator [](int index)
	{
        return getItemAt(index);
	}

	type getCopyItem(int element) const
	{
		Node *cur = head;
		while (cur != NULL) {
			if (cur->item == element)
                return cur->item;
			cur = cur->next;
		}
        return cur->item;
	}

	type getCopyItemAt(int index) const
	{
        Node *cur = head;
        while(index--)
            cur = cur->next;
        return cur->item;
	}

	template<typename secondType>
	type search(secondType element) const
	{
		Node *cur=head;
		while(cur!=NULL)
		{
			if(cur->item==element)
			    return cur->item;
			cur=cur->next;
		}
		return cur->item;
	}

	template<typename secondType>
	bool contain(secondType element) const
	{
		Node *cur = head;
		while (cur != NULL) {
			if (cur->item == element)
			    return true;
			cur = cur->next;
		}
		return false;
	}

	template<typename secondType>
	bool contain(secondType element,type &item) const
	{
		Node *cur = head;
		while (cur != NULL) {
			if (cur->item == element)
			    {
			    	item=cur->item;
			    	return true;
				}
			cur = cur->next;
		}
		return false;
	}
};
