/*
bTREE.h
Sam Blair, Oyedola Ajao, Sam Goering, and Easton Tuttle
Computer Science II
Homework 5 - Merkle Votes
November 8, 2017
Interfaces of the bTREE class.
*/

#pragma once
#include <string>
#include "treeNode.h"

using namespace std;

class bTREE
{
private:
	treeNode* tree;
	int count = 0;
	int root = 0;
	bool found = false;
	bool equal = true;
	string path;

	int insertH(treeNode* subtree, string data, int time);
	void findH(treeNode* subtree, string data);
	void locateH(treeNode* subtree, string data, string path);
	void compareH(treeNode* comparisontree, treeNode* subtree);
	int dataInsertedH(treeNode* subtree);
	int numberOfNodesH(treeNode * subtree);

public:
	bTREE();
	~bTREE();
	int gotCount() { return count; }
	void resetCount() { count = 0; }
	int dataInserted();
	int numberOfNodes();
	bool compare(bTREE comparison);
	bool insert(string data, int time);
	bool find(string data);
	string locate(string data);
	treeNode* getNode() { return tree; }
	void display(std::ostream& outfile);
	void displayLeft(std::ostream & outfile, treeNode* subtree, std::string prefix);
	void displayRight(std::ostream & outfile, treeNode* subtree, std::string prefix);
};