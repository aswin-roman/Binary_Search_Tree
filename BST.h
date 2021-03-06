#pragma once
class Node
{
public:
	int Data;
	Node* Left;
	Node* Right;
	Node(int* data, Node& left, Node& right)
	{
		this->Data = *data;
		this->Left = &left;
		this->Right = &right;
	}
};
