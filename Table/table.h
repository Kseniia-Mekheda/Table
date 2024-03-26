#pragma once
#include <string>
#include <iostream>

class Table 
{
public:
	struct Element 
	{
		std::string data;
		std::string key;

		Element(std::string d = " ", std::string k = " ") : key(k), data(d) {}
	};

	struct Node 
	{
		Element value;
		Node* next;

		Node(const Element& val, Node* nxt = nullptr) : value(val), next(nxt) {}
	};

private:
	Node* head; 

public:
	Table() : head(nullptr) {}
	~Table() 
	{
		Node* curr = head;
		while (curr != nullptr) 
		{
			Node* next = curr->next;
			delete curr;
			curr = next;
		}
		head = nullptr;
	}

	void addToTable(const std::string& d, const std::string& k) {
		Element newElem(d, k);
		Node* newNode = new Node(newElem);
		newNode->next = head;
		head = newNode;
	}

	std::string findInTable(const std::string& key) const
	{
		int count = 0;
		Node* curr = head; 
		while (curr != nullptr) 
		{
			if (curr->value.key == key) 
			{
				return curr->value.data;
				++count;
			}
			curr = curr->next;
		}
		if (count == 0) 
		{
			return "There were 0 elements found";
		 }
	}

	std::string remove(const std::string& key) 
	{
		Node* curr = head;
		Node* prev = nullptr;
		while (curr != nullptr && curr->value.key != key) 
		{
			prev = curr;
			curr = curr->next;
		}

		if (curr != nullptr) 
		{
			if (prev == nullptr) 
			{
				head = curr->next;
			}
			else 
			{
				prev->next = curr->next;
			}
			return curr->value.data;
			delete curr;

		}
		return "No element with such key found";
	}

	void printTable() const 
	{
		Node* curr = head;
		std::cout << "|   Value   |   Key   |" << std::endl;
		std::cout << std::endl;

		while (curr != nullptr) 
		{
			std::cout << "|   " << curr->value.data << "   |   " << curr->value.key << "   |" << std::endl;
			curr = curr->next;
		}
		std::cout << std::endl;
	}
};