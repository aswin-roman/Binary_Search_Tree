#include<iostream>

class Node
{
public:
	int Data;
	Node* Left;
	Node* Right;
	Node(int* data, Node* left, Node* right)
	{
		this->Data = *data;
		this->Left = left;
		this->Right = right;
	}
};

class BST
{
public:
	Node* Root;
	int size;
	BST()
	{
		Root = NULL;
		size = 0;
	}

	Node* InsertData(int* data)
	{
		if (Root == NULL)
		{
			Root = new Node(data, NULL, NULL);;
			return Root;
		}
		AddData(data, Root);
		return Root;
	}

	void Print()
	{
		if (this->Root == NULL)
		{
			std::cout << "Empty"  ;
		}
		else
		{
			PrintPrivate(Root);
		}
		std::cout << std::endl;
	}

	void Delete(int* data)
	{
		if (this->Root == NULL)
		{
			std::cout << "Empty" << std::endl;
		}
		else
		{
			SearchDestroy(data, NULL,Root);
		}
	}

private:
	void AddData(int* data, Node* i)
	{
		if (*data < i->Data)
		{
			if (i->Left != NULL)
			{
				AddData(data,i->Left);
			}
			else
			{
				i->Left = new Node(data, NULL, NULL);
			}
		}
		else if (*data > i->Data)
		{
			if (i->Right != NULL)
			{
				AddData(data, i->Right);
			}
			else
			{
				i->Right = new Node(data, NULL, NULL);
			}
		}
		else
		{
			std::cout << "Data Exists" << std::endl;
		}
	}

	void PrintPrivate(Node* i)
	{
		if (i->Left != NULL)
		{
			PrintPrivate(i->Left);
		}
		std::cout << i->Data << ", ";
		if (i->Right != NULL)
		{
			PrintPrivate(i->Right);
		}
	}

	void SearchDestroy(int* data,Node* Parent, Node* i)
	{
		if (i == NULL)
		{
			std::cout << "Element Not Found" << std::endl;
			return;
		}
		else if (i->Data < *data)
		{
			SearchDestroy(data, i,i->Right);
		}
		else if (i->Data > *data)
		{
			SearchDestroy(data, i,i->Left);
		}
		else if (i->Data == *data)
		{
			if (i->Left == NULL && i->Right == NULL)
			{
				DeleteNode(Parent, i, NULL);
			}
			else if (i->Left == NULL && i->Right != NULL)
			{
				DeleteNode(Parent, i, i->Right);
			}
			else if (i->Left != NULL && i->Right == NULL)
			{
				DeleteNode(Parent, i, i->Left);
			}
			else if (i->Left != NULL && i->Right != NULL)
			{
				Node* RightSmallest = FindSmallest(i->Right);
				int data_temp = RightSmallest->Data;
				SearchDestroy(&(data_temp), NULL, Root);
				i->Data = data_temp;
			}
		}
	}

	Node* FindSmallest(Node* i)
	{
		if (i == NULL)
			return i;
		else if (i->Left == NULL)
			return i;
		else
			return FindSmallest(i->Left);
	}

	void DeleteNode(Node* Parent,Node* i, Node* j)
	{
		if (i == Root)
		{
			delete i;
			Root = j;
			return;
		}
		else if (Parent->Right == i)
			Parent->Right = j;
		else if (Parent->Left == i)
			Parent->Left = j;
		delete i;
	}

};