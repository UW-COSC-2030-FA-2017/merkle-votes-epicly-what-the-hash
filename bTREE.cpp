/*
bTREE.cpp
Sam Blair, Oyedola Ajao, Sam Goering, and Easton Tuttle
Computer Science II
Homework 5 - Merkle Votes
November 8, 2017
Implementations of the bTREE class.
*/

#include <iostream>

#include "stdafx.h"
#include "bTREE.h"

using namespace std;

// Binary tree constructor - creates a new tree with a default tree node.
bTREE::bTREE()
{
	tree = new treeNode();
}

// Binary tree destructor.
bTREE::~bTREE()

{

}

// Compare whether two trees are equal to each other. Returns true if equal, false if not equal.
bool bTREE::compare(bTREE comparison)
{
	equal = true;
	compareH(comparison.getNode(), tree);
	return equal;
}

// The compare helper function.
void bTREE::compareH(treeNode* comparisontree, treeNode * subtree)
{
	if (comparisontree->data != subtree->data)
	{
		equal = false;
		return;
	}
	if (subtree->left != NULL && comparisontree->left != NULL)
	{
		compareH(comparisontree->left, subtree->left);
	}
	if (subtree->left != NULL && comparisontree->left == NULL)
	{
		equal = false;
		return;
	}
	if (subtree->left == NULL && comparisontree->left != NULL)
	{
		equal = false;
		return;
	}
	if (subtree->right != NULL && comparisontree->right != NULL)
	{
		compareH(comparisontree->right, subtree->right);
	}
	if (subtree->right != NULL && comparisontree->right == NULL)
	{
		equal = false;
		return;
	}
	if (subtree->right == NULL && comparisontree->right != NULL)
	{
		equal = false;
		return;
	}
}

// Counts the amount of data inserted into the tree by returning the amount of leaves.
int bTREE::dataInserted()
{
	return dataInsertedH(tree);
}

// dataInserted helper function.
int bTREE::dataInsertedH(treeNode* subtree)
{
	int rightLeaves = 0;
	int leftLeaves = 0;

	if (subtree->left == NULL && subtree->right == NULL)
	{
		return 1;
	}
	else
	{
		leftLeaves = dataInsertedH(subtree->left);
		rightLeaves = dataInsertedH(subtree->right);
		return leftLeaves + rightLeaves;
	}
}

// Returns the number of nodes within a tree.
int bTREE::numberOfNodes()
{
	return numberOfNodesH(tree);
}

// numberOfNodes helper function.
int bTREE::numberOfNodesH(treeNode * subtree)
{
	if (subtree->left == NULL && subtree->right == NULL)
	{
		return 1;
	}
	else
	{
		return numberOfNodesH(subtree->right) + numberOfNodesH(subtree->left) + 1;
	}
}

// Inserts a new treeNode into the bTREE.
bool bTREE::insert(string newData, int newTime)
{
	if (root == 0)
	{
		count++;
		tree->set_data(newData, newTime, true);
		root++;
	}
	else
	{
		insertH(tree, newData, newTime);
	}

	return true;
}

// insert helper function.
int bTREE::insertH(treeNode* subtree, string data, int time)
{
	if (subtree->isLeaf == false) {
		count++;//Move down the tree until we get a leaf node
		if (subtree->right == NULL) {
			return -1;
		}

		else {
			count++;
			insertH(subtree->left, data, time);
		}
	}
	else {
		count++;
		subtree->isLeaf = false;
		subtree->left = new treeNode;
		subtree->left->set_data(data, time, true); //Sets the new left to the inputed data

		subtree->right = new treeNode;
		subtree->right->set_data(subtree->data, subtree->time, true); //Sets the new right to the imputed data.
		subtree->data = "Insert hash here:_____";
	}
}

// Returns true if the input is found in a tree and false if not found.
bool bTREE::find(string input)
{
	found = false;
	findH(tree, input);
	return found;
}

// find helper function.
void bTREE::findH(treeNode* subtree, string data)
{
	// If only one node is in the tree, check if the node data matches the parameter data.
	if (subtree->data == data)
	{
		found = true;
		count++;
	}
	// If there is a left subtree, recursively perform find on the left subtree.
	if (subtree->left != NULL)
	{
		findH(subtree->left, data);
		count++;
	}
	// If there is a righ subtree, recursively perform find on the right subtree.
	if (subtree->right != NULL)
	{
		findH(subtree->right, data);
		count++;
	}

}

// Returns the path taken to locate the input in the bTREE.
string bTREE::locate(string input)
{
	// Check if the input is "found" in the tree - if input is found, locate the input. Otherwise, print that the input
	// has not been located.
	path = "- ";
	if (find(input))
	{
		locateH(tree, input, path);
		return path;
	}
	else
	{
		return "Input not located.";
	}
}

// locate helper function.
void bTREE::locateH(treeNode* subtree, string data, string  pathway)
{
	// Check if the data is located in the root node.
	if (subtree->data == data)
	{
		path = pathway;
		return;
	}
	// Recursively check if the data is in the root of the left subtree.
	if (subtree->left != NULL)
	{
		locateH(subtree->left, data, pathway + "L ");
	}
	// Recursively check if the data is in the root of the right subtree.
	if (subtree->right != NULL)
	{
		locateH(subtree->right, data, pathway + "R ");
	}

}

// Prints the binary tree.
void bTREE::display(std::ostream& outfile)
{
	std::string prefix;
	if (tree == NULL)
	{
		outfile << "-" << std::endl;
	}
	else
	{
		displayLeft(outfile, tree->left, "    ");
		outfile << "---" << tree->data << std::endl;
		displayRight(outfile, tree->right, "    ");
	}
}

// Prints the left side of the binary tree (used for recursion.)
void  bTREE::displayLeft(std::ostream & outfile, treeNode* subtree, std::string prefix)
{
	if (subtree == NULL)
	{
		outfile << prefix + "/" << std::endl;
	}
	else
	{
		displayLeft(outfile, subtree->left, prefix + "     ");
		outfile << prefix + "/---" << subtree->data << std::endl;
		displayRight(outfile, subtree->right, prefix + "|    ");
	}
}

// Prints the right side of the binary tree (used for recursion.)
void  bTREE::displayRight(std::ostream & outfile, treeNode* subtree, std::string prefix)
{
	if (subtree == NULL)
	{
		outfile << prefix + "\\" << std::endl;
	}
	else
	{
		displayLeft(outfile, subtree->left, prefix + "|    ");
		outfile << prefix + "\\---" << subtree->data << std::endl;
		displayRight(outfile, subtree->right, prefix + "     ");
	}
}
