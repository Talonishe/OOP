#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
	T data;
	Node* next;

	Node(T d)
	{
		data = d;
		next = NULL;
	}
};

template<class T>
class CircleList
{
private:
	Node<T>* head;

public:
	CircleList()
	{
		head = NULL;
	}

	void add(T value)
	{
		Node<T>* temp = new Node<T>(value);

		if (!head)
		{
			head = temp;
			head->next = head;
			return;
		}

		Node<T>* p = head;

		while (p->next != head)
			p = p->next;

		p->next = temp;
		temp->next = head;
	}

	void show()
	{
		if (!head) return;

		Node<T>* p = head;

		do
		{
			cout << p->data << " ";
			p = p->next;
		} while (p != head);
	}
};

int main()
{
	CircleList<int> list;

	list.add(10);
	list.add(20);
	list.add(30);

	list.show();

	return 0;
}