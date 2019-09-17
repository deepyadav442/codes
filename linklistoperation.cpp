#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	int data;
	struct node *next;
}node;
node* create(int num)
{
	node *head=NULL,*p=NULL,*n=NULL,*q=NULL;
	for(int i=0;i<num;i++){
		n=(node*)malloc(sizeof(node));
		printf("Enter value for the node");		
		scanf("%d",&(n->data));
		n->next=NULL;
		if(i==0){
			p=n;
			head=n;
		}
		else{
			p->next=n;
			p=n;

		}	
	}
	return head;

}
int list_length(node *head)
{
	int length=0;
       	while(head!=NULL){
	       length++;
	       head=head->next;
       }
	return length;
}
node* insert(node *head,int place)
{
	node *n,*p;
	int length=list_length(head);
	if(place<1||place >length+1){
		printf("Wrong place to insert the node here");
		return head;
	}
	n=(node*)malloc(sizeof(node));
	printf("Enter the value for node : ");
	scanf("%d",&(n->data));
	n->next=NULL;
	if(place==1){
		n->next=head;
		return n;	
	}
	else{
		node *p=head,*q=NULL;
		for(int i=1;i<place;i++)	
		{
			q=p;
			p=p->next;
		}
		n->next=p;
		q->next=n;
	}
	return head;

}

void print_nodes(node *head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}
node* deletion(node *head,int place)
{
	int length=list_length(head);
	if(place<0 ||place>length){
		printf("Not a suitable place to delete");
		return head;
	}
	if(place==1)
		return (head->next);
	else if(place==length){
		node *p=head;
		while((p->next->next)!=NULL)
		{
			p=p->next;
		}
		p->next=NULL;
	
	}
	else{
		node *p=head,*q=NULL;
		for(int i=1;i<place;i++){
			q=p;
			p=p->next;
		}
		q->next=p->next;
	}
	return head;

}
int main()
{
	int n;
	printf("Number of nodes are :\n");
	scanf("%d",&n);
	node *head=create(n);
	print_nodes(head);
	printf("List of link list is : %d\n",list_length(head));
	//head=insert(head,1);
	//print_nodes(head);
	//head=insert(head,3);
	//print_nodes(head);
	//head=insert(head,list_length(head)+1);
	//print_nodes(head);
	//head=deletion(head,1);
	//print_nodes(head);
	//head=deletion(head,3);
	//print_nodes(head);
	//head=deletion(head,5);
	//print_nodes(head);
	printf("\n%d\n",list_length(head));
	return 0;
}
