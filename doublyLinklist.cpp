#include <iostream>
using namespace std;



template <class D>
class Doublylist {
	
	struct Node {
		D data;
		Node* next;
		Node* prev;
		Node()
		{
			next = prev = nullptr;
		}
		Node(D data)
		{
			this->data = data;
			next = prev = nullptr;
		}
	};

	Node* head;
	
	bool searchHelper(Node* temp, D data)
	{
		if (!temp)
			return false;
		if (temp->data == data)
			return true;
		searchHelper(temp->next, data);
	}

	int lenghtHelper(Node* temp)
	{
		if (!temp)
			return 0;
		
		return 1 + lenghtHelper(temp->next);
	}

public:
	Doublylist()
	{
		head = nullptr;
	}
	
	Doublylist(D data)
	{
		head = new Node(data);
	}

	void insertAtEnd(D data)
	{
		Node* n = new Node(data);
		if (!head)
		{
			head = n;
		}
		else {
			Node* temp = head;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = n;
			n->prev = temp;
		}
	}
	
	void insertAtStart(D data)
	{
		Node* n = new Node(data);
		if (!head)
		{
			head = n;
		}
		else {
			Node* temp = head;
			head = n;
			temp->prev = n;
			n->next = temp;
			n->prev = nullptr;
		}
	}

	bool deleteElement(D data)
	{
		if (!head)
			return false;

		Node* temp = head;
		bool found = false;
		while (temp && !found)
		{
			if (temp->data == data)
			{
				if (temp->next)
				{
					temp->next->prev = temp->prev;
				}
				if (temp->prev)
				{
					temp->prev->next = temp->next;
				}
				temp->next = temp->prev = nullptr;
				delete temp;
				temp = nullptr;
				found = true;
			}
			if (!found)
				temp = temp->next;
		}
		return found;
	}

	bool searchIterative(D data)
	{
		Node* temp = head;
		bool found = false;
		while (temp)
		{
			if (temp->data == data)
				found = true;
			temp = temp->next;
		}

		return found;

	}
	
	bool searchRecersive(D data)
	{
		return searchHelper(head, data);
	}

	int getLengthIterative() //return length of list
	{
		int i = 0;
		Node* temp = head;
		while (temp)
		{
			i++;
			temp = temp->next;
		}
		return i;
	}

	int getLengthRecersive() //return length of list
	{
		return lenghtHelper(head);
	}

	void Print()
	{
		Node* temp = head;
		while (temp)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}

	D findKthNode(int k)
	{
		if (!head)
			return 0;
		int i = 1;
		Node* temp = head;

		while (temp && i <= k)
		{
			if (i == k)
				return temp->data;

			temp = temp->next;
			i++;
		}
		return 0;
	}

	void reverseList()
	{
		Node* temp = head;
		while (temp)
		{
			Node* n = temp->next;
			temp->next = temp->prev;
			temp->prev = n;
			head = temp;
			temp = temp->prev;
		}
	}
};


int main()
{
	Doublylist<int> list;
	list.insertAtEnd(1);
	list.insertAtEnd(2);
	list.insertAtEnd(3);
	list.insertAtEnd(4);
	list.insertAtEnd(5);

	list.Print();

	list.insertAtStart(0);

	list.Print();

	cout << "is 5 present in list(searching iteratively) : " << list.searchIterative(5);
	cout << "\nis 12 present in list(searching recersivly) : " << list.searchRecersive(12);

	cout << "\nLength of list(iteratively): " << list.getLengthIterative();
	cout << "\nLength of list(Recersively): " << list.getLengthRecersive() << endl;


	list.deleteElement(3);
	list.Print();

	list.reverseList();
	list.Print();

	cout << "2nd element in list is " << list.findKthNode(2);
}