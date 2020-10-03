#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* next;
	node(int x)
	{
		data=x;
		next=NULL;
	}
};
node* head=NULL;
node* insertfirst(node* head,int x)
{
	node* temp=new node(x);
	temp->next=head;
	return temp;
}
node* insertend(node* head,int x)
{
	node* temp=new node(x);
	node* curr=head;
	if(curr==NULL)
	return temp;
	while(curr->next!=NULL)
	curr=curr->next;
	curr->next=temp;
	temp->next=NULL;
	return head;
}
node* deltop(node* head)
{
	if(head==NULL)
	return 0;
	node* curr=head->next;
	delete head;
	return curr;
}
node* dellast(node* head)
{
	if(head==NULL)
	return 0;
	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}
	node* c=head;
	while(c->next->next!=NULL)
	c=c->next;
	delete c->next;
	c->next=NULL;
	return head;
}

void printlist(node* head)
{
	node* c=head;
	while(c!=NULL){
		cout<<c->data<<" ";
		c=c->next;
	}
}
int main()
{

 int ch, data;
 while (1) {
 printf("1.Insertion at top\n");
 printf("2.Insertion at last\n");
 printf("3.Deletion at top\n");
 printf("4.Deletion at last\n");
 printf("5. Traverse\n6. Exit");
 printf("\nEnter your choice:");
 scanf("%d", &ch);
 switch (ch) {
 case 1:
 printf("Enter the element to insert:");
 scanf("%d", &data);
 head=insertfirst(head,data);
 break;
 case 2:
 printf("Enter the element to insert:");
 scanf("%d", &data);
 head=insertend(head,data);
 break;
 case 3:
 head=deltop(head);
 break;
 case 4:
 head=dellast(head);
 break;
 case 5:
 printlist(head);
 printf("\n");
 break;
 case 6:
 exit(0);
 default:
 printf("Not available\n");
 break;
 }
 printf("\n");
  }
	return 0;
}

	
