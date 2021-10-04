#include "node.h"

Node::Node()
{
	this->w = 0;
	this->next = nullptr;
}

Node::Node(int w, Node *next)
{
	this->w = w;
	this->next = next;	
}

Node::~Node()
{
	delete(this->next);
	delete(this);
}