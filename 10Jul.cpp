// Question - rearrange elements of linked list in-place such that all even numbers are placed after odd numbers

#include<bits/stdc++.h>
using namespace std;

class node {
	public:
		int data;
		node *next;

		node(int d){
			data = d;
			next = NULL;
		}
};

void evenAfterOdd(node* &head){

	node* oddPrev = NULL;
	node* oddHead = head;

	if ((head->data)%2 == 1){
		oddHead = head->next;
		oddPrev = head;
	}

	node* curr = head->next;
	node* prev = head;
	node* nxt;

	while (curr != NULL){
		nxt = curr->next;
		if ((curr->data)%2 == 1){
			if (oddHead == head){
				curr->next = head;
				prev->next = nxt;
				head = curr;
				curr = nxt;
				oddHead = head->next;
				oddPrev = head;
			}
			else{
				curr->next = oddHead;
				oddPrev->next = curr;
				oddPrev = curr;
				prev->next = nxt;
				curr = nxt;
			}
		}
		else{
			prev = curr;
			curr = nxt;
		}
	}
}

int main() {
	int n;
	cin>>n;
	node *head = NULL, *tail = NULL;
	for (int i=0; i<n; i++){
		int d;
		cin>>d;
		if (head == NULL){
			head = new node(d);
			tail = head;
		}
		else{
			tail->next = new node(d);
			tail = tail->next;
		}
	}
	node* t = head;
	// while (t != NULL){
	// 	cout<<t->data<<" ";
	// 	t = t->next;
	// }
	// cout<<endl;
	evenAfterOdd(head);
	t = head;
	while (t != NULL){
		cout<<t->data<<" ";
		t = t->next;
	}
	return 0;
}
