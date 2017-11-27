/*
bTREE.h
Sam Blair, Oyedola Ajao, and Easton Tuttle
Computer Science II
Homework 5 - Merkle Votes
November 8, 2017

The interfaces for the binary tree.
*/

#pragma once

#include "stdafx.h"
#include "list.h"
#include <string>
using namespace std;

class bTREE
{
private:
	// Linked list used to hold the treeNodes together.
	List tree;

	// Any helper variables that may be needed.
    
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