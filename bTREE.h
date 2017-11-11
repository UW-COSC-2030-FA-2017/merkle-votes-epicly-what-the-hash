/*
bTREE.h
Easton Tuttle
Computer Science II
Homework 5 - Merkle Votes
November 8, 2017

The interfaces for the binary tree.
*/

#pragma once

#include "stdafx.h"
#include <string>
using namespace std;

class bTREE
{
	// Nodes of the tree which hold a pseudo-time stamp (integer, non-unique,)
	// a 128-bit data component (string of 32 characters,)
	// have 2 pointers to type node, and be differentiable
	// if a leaf or not.
    struct treeNode
	{
		int time;
        string data;
		treeNode *firstPointer;
		treeNode *secondPointer;
		bool isLeaf = false;
    };
    
private:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
    
public:
    bTREE();
    ~bTREE();
    
    int dataInserted();
    int numberOfNodes();
    
    int insert(string, int);
    
    int find(string);
    
    string locate(string);
    
    
    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);

	friend bool operator ==(const bTREE& lhs, const bTREE& rhs)
	{
	}

	friend bool operator !=(const bTREE& lhs, const bTREE& rhs)
	{
	}

	friend std::ostream& operator <<(std::ostream& out, const bTREE& p)
	{
	}
    
};