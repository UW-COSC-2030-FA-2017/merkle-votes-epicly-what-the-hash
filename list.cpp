/*
list.cpp
Sam Blair, Oyedola Ajao, and Easton Tuttle
Computer Science II
Homework 5 - Merkle Votes
November 27, 2017

The implementations of the list class.
*/

#include "stdafx.h"
#include "list.h"

List::List()
{
	head = new treeNode();
	current = head;
	tail = head;
}


List::~List()
{

}


void List::printList()
{
	current = head->nextNode;
	if (current == NULL)
	{
		cout << "The list currently contains: \n";
	}
	else
	{
		cout << "The list currently contains: ";
		while (current->nextNode != NULL)
		{
			cout << current->data << ", ";
			current = current->nextNode;
		}
		cout << current->data << "\n";
	}
}

void List::makeEmpty()
{
	head->nextNode = NULL;
}

bool List::isEmpty()
{
	if (head->nextNode == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void List::insert(string newData)
{
	treeNode *newCell = new treeNode(newData);
	tail->nextNode = newCell;
	newCell->prevNode = tail;
	tail = newCell;
}

void List::remove(string comparison)
{
	if (head != NULL)
	{
		current = head;
		while (current->nextNode != NULL)
		{
			if (current->data == comparison)
			{
				if (current->prevNode == NULL)
				{
					head = current->nextNode;
				}
				else
				{
					treeNode *temp;
					temp = current->nextNode;
					current = current->prevNode;
					current->nextNode = temp;
					temp->prevNode = current;
				}
			}
			current = current->nextNode;
		}
		if (tail->data == comparison)
		{
			tail = tail->prevNode;
			tail->nextNode = NULL;
		}
	}
	else
	{
		return;
	}
}

treeNode List::removeFirst()
{
	treeNode *tempCell;
	tempCell = head;
	head = head->nextNode;
	head->prevNode = NULL;
	return *tempCell;
}

treeNode List::removeLast()
{
	treeNode *tempCell;
	tempCell = tail;
	tail = tail->prevNode;
	tail->nextNode = NULL;
	return *tempCell;
}