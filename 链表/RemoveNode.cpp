
#include<iostream>
using namespace std;
struct Node
	{
		int val;
		Node* next;
	};
void RemoveNode(Node** head,int val){
	if(head==NULL or *head ==NULL){
		return ;
	}
	Node* ptoBeRemoved=NULL;
	if((*head)->val==val){   //待删除的节点是头结点
		ptoBeRemoved=*head;
		*head=(*head)->next;
	}
	else{
		Node* cur=*head;
		while(cur->next!=NULL && cur->next->val!=val){ //保留被删除节点的前一个节点
			cur = cur->next;
		}
		if(cur->next != NULL && cur->next->val==val){
			ptoBeRemoved=cur->next;
			cur->next=cur->next->next;
		}
		if (ptoBeRemoved){
			delete ptoBeRemoved;
			ptoBeRemoved=NULL;
		}

	}
}