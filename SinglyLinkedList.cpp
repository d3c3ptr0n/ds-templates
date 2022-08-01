#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this -> data = data;
		this -> next = NULL;
	}

	~Node() {
		int value = this -> data;
		if (this -> next != NULL) {
			delete next;
			this -> next = NULL;
		}
	}
};

void insertAtHead(Node* &head, int data) {
	Node* temp = new Node(data);
	temp -> next = head;
	head = temp;
}

void insertAtTail(Node* head, int data) {
	Node* temp = new Node(data);
	while (head -> next != NULL) {
		head = head -> next;
	}
	head -> next = temp;
}

void insertAtNthPosition(Node* &head, int n, int data) {

	if (n == 1) {
		insertAtHead(head, data);
		return;
	}

	Node* temp = head;
	int count = 1;

	while (count < n - 1) {
		temp = temp -> next;
		count++;
	}

	Node* newNode = new Node(data);
	newNode -> next = temp -> next;
	temp -> next = newNode;
}

void deleteAtNthPosition(Node* &head, int n) {


	if (n == 1) {
		Node* temp = head;
		head = head -> next;
		temp -> next = NULL;
		delete temp;
	} else {
		Node* curr = head;
		Node* prev = NULL;

		int count = 1;
		while (count < n) {
			prev = curr;
			curr = curr -> next;
			count++;
		}

		prev -> next = curr -> next;
		curr -> next = NULL;
		delete curr;
	}
}
void print(Node* head) {
	while (head != NULL) {
		cout << head -> data << " -> ";
		head = head -> next;
	}
	cout << "NULL" << endl;
}
signed main()
{

	Node* head = new Node(10);
	print(head);

	return 0;
}
