#include <iostream>
using namespace std;
class Node
{

	int data;
	Node* next;
	friend class linked_list;
public:
	Node()
	{
		next = NULL;
	}
	Node(int d)
	{
		data = d;
	}
};

class linked_list
{
	Node* head;
	Node* tail;
public:
	linked_list()
	{
		head = NULL;
		tail = NULL;
	}
	~linked_list()
	{
		delete head;
		delete tail;
	}

	Node* insertathead(Node*& head, int agee)
	{
		Node* temp = new Node(agee);
		temp->next = head;
		head = temp;
		return temp;
	}
	Node* insertattail(Node*& head, int agee)
	{
		Node* temp = new Node(agee);// node to insert
		Node* ptr = head;//node for traversal
		while (ptr->next != NULL)
		{
			ptr = ptr->next;// to find the tail
		}
		ptr->next = temp;//insert value at tail
		tail = temp;//update tail
		tail->next = NULL;// conventionally point it to null
		return ptr;
	}
	void print(Node*& head)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " , ";
			temp = temp->next;

		}
	}
	bool is_palindrome(Node*& head)
	{
		int n = 5;
		int array[5];
		Node* temp = head;
		int i = 0;
		while (temp != NULL)
		{
			array[i] = temp->data;
			i++;

			temp = temp->next;
		}

		bool flag = 0;
		for (int i = 0; i < n / 2; i++)
		{
			if (array[i] == array[n - i - 1])
			{
				flag = 1;
			}
		}
		return flag;
	}
	Node* reverse(Node*& head)
	{
		if (head == NULL || head->next == NULL)
		{
			cout << head;
		}

		Node* prev = NULL;
		Node* curr = head;
		Node* forward = NULL;
		while (curr != NULL)
		{
			forward = curr->next;
			curr->next = prev;
			prev = curr;
			curr = forward;

		}

		head = prev;
		return prev;

	}

	Node* Link_alternate(Node*& head, int key)
	{
		Node* curr1 = head;
		Node* curr2 = head;
		Node* prev1 = NULL;
		Node* prev2 = curr2->next;
		Node* temp;
		int size = 1;
		if (key == 1) {
			while (curr1->next!=NULL) {
				prev1 = curr1;
				curr1 = curr1->next;
			}
			
			curr1->next = prev2;
			prev1->next = curr2;
			curr2->next = NULL;
			head = curr1;
			
		}
		else {
			while (curr1->next != NULL)
			{
				size++;
				curr1 = curr1->next;
			}
			//cout << size;
			curr1 = head;

			for (int i = 1; i < key; i++)
			{
				prev1 = curr1;
				curr1 = curr1->next;
			}
			for (int i = 1; i <= size - key; i++)
			{
				prev2 = curr2;
				curr2 = curr2->next;
			}

			/*cout << "prev1 : " << prev1->data<<endl;
			cout << "curr1 : " << curr1->data << endl;
			cout << "prev2 : " << prev2->data << endl;
			cout << "curr2 : " << curr2->data << endl;
			cout << "temp : " << temp->data << endl;
			*/

			temp = curr2->next;
			prev1->next = curr2;
			curr2->next = curr1->next;
			prev2->next = curr1;
			curr1->next = temp;


		}



		

		return head;
	}
	Node* Swap(Node* &head)
	{
		int count = 1 ;
		Node *curr1 = head;
		Node *next1 = curr1->next;
		Node *curr2  = head;
		Node *next2 = NULL;
		Node *temp = NULL;
		while (curr2->next != NULL)
		{

			curr2 = curr2->next;
			count++;
		}
		curr2 = head;
		for (int i = 0; i < (count / 2)&& curr2->next != NULL; i++)
		{
			for(int j=1;j<count;j++)
			{
				curr2 = curr2->next;
				
			}

			curr2->next = curr1->next;

			curr1->next = curr2;
			curr1 = next1;
			next1 = next1->next;
			curr2 = head;

		}
		curr1->next = NULL;
	


		return head;
	}


};

int main()
{
	Node* n = new Node(2);
	Node* head = n;
	linked_list obj;
	obj.insertathead(head, 1);
	obj.insertattail(head, 3);
	obj.insertattail(head, 4);
	obj.insertattail(head, 5);
	obj.insertattail(head, 6);

	obj.insertattail(head, 7);
	cout << "values inserted " << endl;
	obj.print(head);
	cout << endl;
	/*cout << endl << "Reversed linked list " << endl;
	obj.reverse(head);
	obj.print(head);
	cout << " PAlINDROME " << endl;
	if (obj.is_palindrome(head))
	{
		cout << endl << " palindrome " << endl;
	}
	else
	{
		cout << " not palindrome baby" << endl;
	}
	obj.Link_alternate(head, 3);
	*/
	obj.Swap(head);
	obj.print(head);   // obj.Swap(head,2);
	// obj.print(head);*/
	system("PAUSE");
}