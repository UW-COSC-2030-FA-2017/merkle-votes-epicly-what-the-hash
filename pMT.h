/*
pMT.h
Easton Tuttle
Computer Science II
Homework 5 - Merkle Votes
November 8, 2017

Interfaces of the pMT class.
*/

#pragma once

#include "stdafx.h"
#include "bTREE.h"
#include <string>
using namespace std;
class pMT
{
private:
    int selectedHash;
    bTREE myMerkle;
    
    string hash_1(string);
    string hash_2(string);
    string hash_3(string);
    
public:
    pMT(int);
    ~pMT();
    
    
    int insert(string, int);
    
    int find(string);
    int findHash(string);
    
    string locate(string);
    
    friend bool operator==(const pMT& lhs, const pMT& rhs);
    
    friend bool operator!=(const pMT& lhs, const pMT& rhs);
    
    friend pMT operator^(const pMT& lhs, const pMT& rhs);
    friend std::ostream& operator<<(std::ostream& out, const pMT& p);
    
};

