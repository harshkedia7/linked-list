//to implement circular singly linked list
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
void display(node* head)
{
	node* p=head;
	do
	{
		cout<<p->data<<" ";
		p=p->next;
	}while(p!=head);
}
node* insertbegin(node* head,int x)
{
	node* t=new node(x);
	if(head==NULL)
	{
		t->next=t;
		return t;
	}
	else
	{
		t->next=head->next;
		head->next=t;
		int p=head->data;
		head->data=t->data;
		t->data=p;
		return head;
	}
}
node* insertend(node* head,int x)
{
	node* t=new node(x);
	if(head==NULL)
	{
		t->next=t;
		return t;
	}
	else
	{
		t->next=head->next;
		head->next=t;
		int p=head->data;
		head->data=t->data;
		t->data=p;
		return t;
	}
}
node* delbegin(node* head)
{
	if(head==NULL)
	return NULL;
	if(head->next==head)
	return NULL;
	head->data=head->next->data;
	node* p=head->next;
	head->next=head->next->next;
	delete p;
	return head;
	
}
node* delend(node* head)
{
	if(head==NULL)
	return NULL;
	node* p=head;
	if(head->next==head)
	return NULL;
	while(p->next->next!=head)
	p=p->next;
	node* t=p->next;
	p->next=head;
	delete t;
	return head;
	
}
int main()
{

 int ch, data;
 while (1) {
 printf("1.Insertion at first\n");
 printf("2.Insertion at last\n");
 printf("3.Deletion at first node\n");
 printf("4.Deletion at last node\n");
 printf("5.Traverse\n6.Exit");
 printf("\nEnter your choice:");
 scanf("%d", &ch);
 switch (ch) {
 case 1:
 printf("Enter the element to insert at begin:");
 scanf("%d", &data);
 head=insertbegin(head,data);
 break;
 case 2:
 printf("Enter the element to insert at end:");
 scanf("%d", &data);
 head=insertend(head,data);
 break;
 case 3:
 head=delbegin(head);
 cout<<"deleted"<<endl;
  break;
 case 4:
 head=delend(head);
  cout<<"deleted"<<endl;
 break;
 case 5:
 display(head);
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

