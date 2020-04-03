#pragma once
#include <string>

using namespace std;

class TreeNode
{
public:
	TreeNode(string);
	TreeNode(TreeNode*, string newChar);
	string getPermutation();


	~TreeNode() = default;

private:

	string permutation;
	int level;

};

TreeNode::TreeNode(string startingString)
{
	this->level = 1;
	this->permutation = startingString;
}

TreeNode::TreeNode(TreeNode* oldNode, string newChar)
{
	this->level = oldNode->level + 1;
	this->permutation = oldNode->permutation + newChar;
}

string TreeNode::getPermutation() {
	return this->permutation;
}



class TreeRow
{
public:
	TreeRow(char, string*, int*);
	TreeRow(TreeRow*);
	bool testPermutation(string);
	~TreeRow();

private:
	TreeNode** RowTree;
	int Treelevel;
	int rowLen;
	string* possibleValues;
	int* numOfPossibleValue;
};

TreeRow::TreeRow(char startingChar, string* possibleValues, int* numOfPossibleValues)
{
	this->rowLen = *numOfPossibleValue;
	this->RowTree = new TreeNode * [rowLen];
	for (int i = 0; i < *numOfPossibleValue; i++)
	{
		this->RowTree[i] = &TreeNode(startingChar + possibleValues[i]);
	}
	this->Treelevel = 2;
	this->possibleValues;
	this->numOfPossibleValue;
}


TreeRow::TreeRow(TreeRow* oldRow)
{
	//creates next row
	this->rowLen = oldRow->rowLen * (*oldRow->numOfPossibleValue);
	this->Treelevel = oldRow->Treelevel + 1;
	this->possibleValues = oldRow->possibleValues;
	this->numOfPossibleValue = oldRow->numOfPossibleValue;


	this->RowTree = new TreeNode * [rowLen];
	for (int i = 0; i < oldRow->rowLen; i++)
	{
		for (int j = 0; i < *oldRow->numOfPossibleValue; j++)
		{
			this->RowTree[i * j] = &TreeNode(oldRow->RowTree[i]->getPermutation() + this->possibleValues[j]);
		}
	}
	delete (oldRow);
}


bool TreeRow::testPermutation(string word) {
	for (int i = 0; i < this->rowLen; i++)
	{
		if (this->RowTree[i]->getPermutation() == word)
		{
			return true;
		}
	}
	return false;
}

TreeRow::~TreeRow()
{
	delete (RowTree);
}