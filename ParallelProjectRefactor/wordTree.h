#pragma once
#include <string>
/* This contains the tree code for our string tree.
All functions return a pointer to the appropriate node of the tree. It is optional to use these return values, but they're there if you want to use them.
*/
class wordTreeNode
{
private:
	wordTreeNode* parent;
	wordTreeNode* left;
	wordTreeNode* right;
	std::string nodeValue;
public:
	wordTreeNode* getParent();
	wordTreeNode* setParent(wordTreeNode* toSet);
	wordTreeNode* getLeft();
	wordTreeNode* getRight();
	wordTreeNode* setLeft(wordTreeNode* toSet);
	wordTreeNode* setRight(wordTreeNode* toSet);
	wordTreeNode* setNodeValue(std::string value);
};
class wordTree
{
public:
	wordTreeNode* root;
	
	wordTreeNode* setRoot(wordTreeNode* newRoot);
	wordTreeNode* insertNode(std::string newNodeValue, wordTreeNode* parent);
	wordTreeNode* insertNode(std::string newNodeValue, wordTreeNode* parent, wordTreeNode* leftChild, wordTreeNode* rightChild);
};

