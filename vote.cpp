/*
list.cpp
Sam Blair, Oyedola Ajao, Sam Goering, and Easton Tuttle
Computer Science II
Homework 5 - Merkle Votes
November 27, 2017

The testing program for the Merkle voting tree.
*/

#include "stdafx.h"
#include "pMT.h"
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	// Test of pMT functions.
	pMT merkleOne = pMT(2);
	pMT loli =  pMT(1);

	loli.insert("Test One", 3);
	loli.insert("Test Two", 4);
	loli.insert("Test Three", 1);
	loli.insert("Test Four", 3);
	loli.insert("Test Five", 11);
	loli.accessbTREE().display(cout);
	loli.hash(loli.accessbTREE().getNode());
	loli.accessbTREE().display(cout);

	if (loli.findHash("170564485") > 0)
	{
		cout << "it was found" << endl;
	}
	else
	{
		cout << "It was not found"<<endl;
	}
	
	if (loli.findHash("12900930") > 0)
	{
		cout << "it was found" << endl;
	}
	else
	{
		cout << "It was not found" << endl;
	}
	if (loli.findHash("t") > 0)
	{
		cout << "it was found" << endl;
	}
	else
	{
		cout << "It was not found" << endl;
	}

	cout << "\n Number of operations to insert into a tree of five nodes: " << loli.insert("Operations", 100);
	cout << "\n Number of operations to insert to an empty: " << merkleOne.insert("Operations", 56);

	merkleOne.accessbTREE().display(cout);

	// Beginning of vote.cpp tests.
	ifstream voteFile;
	string fileName;
	string hashChoice;
	string vote;
	string time;
	
	// Get file name from the user.
	cout << "Please enter the name of the voting file: ";
	getline(cin, fileName);
	voteFile.open(fileName);

	// If the file name is invalid, loop until valid.
	while (voteFile.fail())
	{
		cout << "The file could not be opened. Please check the spelling of the file name and ensure the file exists.\n\n";
		cout << "Please enter the name of the voting file: ";
		getline(cin, fileName);
		voteFile.open(fileName);
	}

	// Ask the user to select a hash function.
	cout << "Please select a hash function to use:\n";
	cout << "1. Sam Blair's hash\n";
	cout << "2. Sam Goering's hash\n";
	cout << "3. Oyedola Ajao's hash\n";
	cout << "4. Easton Tuttle's hash\n";

	// Get the user's input, convert it to a integer, and pass it into the merkle tree constructor.
	getline(cin, hashChoice);
	int intHashChoice = std::stoi(hashChoice);
	pMT merkleTree = pMT(intHashChoice);

	// While not at the end of the file, add each vote from the file (in the TIME:VOTE 
	/*while (!voteFile.eof())
	{
		getline(voteFile, time);
		int timeInt = std::stoi(time);
		getline(voteFile, vote);
		merkleTree.insert(vote, timeInt);
		voteFile.close();
	}*/

	
	return 0;
}