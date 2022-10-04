#include "llrec.h"
using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	if(head == nullptr){
		smaller = nullptr;
		larger = nullptr;
		return;
	}
	int val = head->val;
	if(val<pivot){
		smaller = head;
		head = head->next;
		llpivot(head, smaller->next, larger, pivot);
	
	}
	else{
		larger = head;
		head = head->next;
		llpivot(head, smaller, larger->next, pivot);
	}
}

