 /*                                  deepyadav442 --> :     c++14     <--                                */
#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
/*                                           input                    */
#define si(i) scanf("%d",&i)
#define sii(i,j) scanf("%d%d",&i,&j)
#define siii(i) scanf("%lld",&i)
#define sss(s) scanf("%s",s)
/*                                           output                   */
#define pi(i) printf("%d",i)
#define pii(i,j) printf("%d%d",i,j)
#define piii(i) printf("%lld",i)
#define space printf(" ")
#define newline printf("\n")
/*                                          loops &stls                      */
#define loop(i,s,n) for(i=s;i<n;i++)
#define looprev(i,s,n) for(i=s;i>=n;i--)
#define itervec vector<int>::iterator itv
#define iterrev vector<int>::reverse_iterator it
#define itermap map<string,int>::iterator itm
#define pb(S) push_back(S)
#define mp(i,j) make_pair(i,j)
#define f first
#define s second
#define MAX(a,b) 	(a>b) ? (a) : (b)
#define MIN(a,b) 	(a<b) ? (a) : (b)
using namespace std;
int cnt=-1;
typedef struct node{
	int data;
	struct node *left,*right;
}node;
class BT{
	public:
	node* insert(node*,int);
	node* create_node(int);
	//node* preorder(node*);
	void inorder(node*);
	//node* postorder(node*);
};
node* BT::create_node(int value)
{
	cout<<"2"<<endl;
	node *n = new node();
	n->data=value;
	n->left=n->right=NULL;
	return n;
	
}
node* BT::insert(node *root,int num)
{
	if(root==NULL)	{
		return create_node(num);
	}
	else if(root->data >num)
		insert(root->left,num);
	else
		insert(root->right,num);
	return root;
}
void BT::inorder(node *root)
{
	cout<<"5"<<endl;
	while(root!=NULL){
		cout<<"6"<<endl;
		inorder(root->left);
		printf("Data for node is :");
		pi(root->data);
		newline;
		inorder(root->right);				
	}

}
int main()
{
	int value,i;
	node *root;
	BT b;
	cout<<"1"<<endl;
	root=b.insert(root,2); 
	root=b.insert(root,4);
	root=b.insert(root,6);
	root=b.insert(root,3);
	root=b.insert(root,6);	
	root=b.insert(root,7);
	cout<<"4"<<endl;
	b.inorder(root);	
	return 0;
}
	
