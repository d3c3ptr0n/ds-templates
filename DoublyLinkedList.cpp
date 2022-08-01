#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	Node* prev;
	int data;
	Node* next;

	Node(int data) {
		this -> prev = NULL;
		this -> data = data;
		this -> next = NULL;
	}

	~Node() {
		int value = this -> data;
		if (next != NULL) {
			delete next;
			next = NULL;
		}
	}
};

void insertAtHead(Node* &head, int data) {
	Node* temp = new Node(data);
	if (head == NULL) {
		head = temp;
		return;
	}
	temp -> next = head;
	head -> prev = temp;
	head = temp;
}

void insertAtTail(Node* head, int data) {
	Node* temp = new Node(data);

	while (head -> next != NULL) {
		head = head -> next;
	}

	head -> next = temp;
	temp -> prev = head;
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

	if (temp -> next == NULL) {
		temp -> next = newNode;
		newNode -> prev = temp;
		return;
	}

	temp->next->prev = newNode;
	newNode -> prev = temp;
	newNode -> next = temp -> next;
	temp -> next = newNode;
}

void deleteAtNthPosition(Node* &head, int n) {
	if (n == 1) {
		Node* temp = head;
		temp -> next -> prev = NULL;
		head = temp -> next;
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

		if (curr -> next == NULL) {
			curr -> prev = NULL;
			prev -> next = NULL;
			curr -> next = NULL;
			delete curr;
			return;
		}
		curr -> prev = NULL;
		prev -> next = curr -> next;
		curr -> next -> prev = prev;
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

	Node* head = NULL;
	print(head);
	return 0;
}
