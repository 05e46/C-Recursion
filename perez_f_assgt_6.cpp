#include<iostream>
using namespace std;
//creat the node class
class Node
{
public:
	Node(int = 0);
	int info;
	Node * next;
};
//constructor for the node
Node::Node(int data)
{
	info = data;
	next = 0;
}
/*Functions*/
void recurse_insert(Node* &head, int number);
void recurse_print(Node* head);
void recurse_delete(Node* &head);
void print_reverse(Node* head);
void recurse_front_delete(Node* &head);
//main function
int main()
{
	//variable declaration
	char choice;
	int number;
	Node* head;
	head = NULL;
	do
	{
		cout << "Select one of the following options!" << endl;
		cout << "I: to insert to the list." << endl;
		cout << "D: to delete from the end of the list." << endl;
		cout << "P: to print the list contents." << endl;
		cout << "F: to delete from start of list." << endl;
		cout << "B: to print the list backwards." << endl;
		cout << "Q: to quit this program." << endl;
		cout << endl;
		cin >> choice;
		cout << endl;
		choice = static_cast<char>(toupper(choice));
		switch (choice)
		{
		case 'I':
			cout << "Enter a number to add to the list: " << endl;
			cin >> number;
			cout << endl;
			recurse_insert(head, number);
			break;
		case 'D':
			cout << "Deleting at the end of the list: " << endl;
			recurse_delete(head);
			cout << endl;
			break;
		case 'F':
			recurse_front_delete(head);
			cout << endl;
		case 'P':
			recurse_print(head);
			cout << endl;
			break;
		case'B':
			print_reverse(head);			
			break;
		}
	}
	while (choice != 'Q');
	return 0;
}
//Function Definitions
void recurse_insert(Node* &head, int number){
	if (head == NULL){
		/*head is empty, and not pointing to anything
		make a new node and add it to the end of the list, starting from head */
		head = new Node;
		head->info = number;
		head->next = NULL;
	}
	else {
		/*Otherwise, simply go to the next node*/
		recurse_insert(head->next, number);
	}
}
void recurse_print(Node* head){
	/*If the head is empty, exit*/
	if (head == NULL){
		return;
	}
	else{
		/*If the head is not empty, print the current head's info and call 
		recursive function on the current heads next pointer - that points to the next node*/
		cout << head->info << endl;
		(recurse_print(head->next));
		return;
	}

}
void print_reverse(Node* head){
	if (head != NULL){
		(print_reverse(head->next));
		cout << head->info << endl;
		return;
	}
}
void recurse_delete(Node* &head){
	if (head == NULL){
		cout << "Empty list!" << endl;
	}
	else if (head->next == NULL){
		delete head;
		head = NULL;
	}
	else{
		(recurse_delete(head->next));
		return;
	}
}
void recurse_front_delete(Node* &head){
	if (head == NULL){
		cout << "Empty list.\n";
	}
	else if (head->next != NULL){
		Node* temp;
		temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	else{
		recurse_front_delete(head->next);
	}
}