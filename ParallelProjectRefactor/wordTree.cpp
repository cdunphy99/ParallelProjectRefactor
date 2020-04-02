#include "wordTree.h"

wordTreeNode* wordTreeNode::getParent()
{
	return this->parent;
}

wordTreeNode* wordTreeNode::setParent(wordTreeNode* toSet)
{
	this->parent = toSet;
	return this;
}

wordTreeNode* wordTreeNode::getLeft()
{
	return this->left;
}

wordTreeNode* wordTreeNode::getRight()
{
	return this->right;
}

wordTreeNode* wordTreeNode::setLeft(wordTreeNode* toSet)
{
	this->left = toSet;
	return this->left;
}

wordTreeNode* wordTreeNode::setRight(wordTreeNode* toSet)
{
	this->right = toSet;
	return this->left;
}

wordTreeNode* wordTreeNode::setNodeValue(std::string value)
{
	this->nodeValue = value;
	return this;
}

wordTreeNode* wordTree::setRoot(wordTreeNode* newRoot)
{
	this->root = newRoot;
	return this->root;
}

// TODO: write insert functions
wordTreeNode* wordTree::insertNode(std::string newNodeValue, wordTreeNode* parent)
{
	return nullptr;
}

wordTreeNode* wordTree::insertNode(std::string newNodeValue, wordTreeNode* parent, wordTreeNode* leftChild, wordTreeNode* rightChild)
{
	return nullptr;
}
