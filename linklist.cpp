#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    struct node *next;
    int data;
}node;
int number=0;
node* create()
{
    int i,z;
    node *n,*p,*h;
    h=NULL;
    cout<<"Number of nodes"<<endl;
    scanf("%d",&z);
    for(i=0;i<z;i++)
    {
        n=(node*)malloc(sizeof(node));
        cin>>n->data;
        n->next=NULL;
        if(h==NULL)
        {
            h=n;
            p=n;
        }
        else
        {
            p->next=n;
            p=n;
        }
    }
    return h;
}
void print(node *h)
{
    node *p;
    p=h;
    while(p!=NULL)
    {
        cout<<"  "<<p->data;
        p=p->next;
    }
}
void length(node *h)
{
    node *p;
    p=h;
    while(p!=NULL){
        number++;
        p=p->next;
    }
    cout<<number<<endl;
}
node* insert(node *h)
{
    int data,pos,i;
    node *p,*n,*q;
    p=h;
    cout<<"enter the position where you want to enter data"<<endl;
    cin>>pos;
    if(pos<1||pos>number+1){
        cout<<"cannot insert into this"<<endl;
        return h;
    }
    n=(node*)malloc(sizeof(node));
    n->next=NULL;
    cin>>n->data;
    if(pos==1)
    {
        n->next=h;
        h=n;
        return h;
    }
    else
    {
        for(i=1;i<pos;i++)
        {
           q=p;
           p=p->next;
        }
        n->next=p;
        q->next=n;
        return h;
    }
}
node* delete1(node *h)
{
    int data,pos,i;
    node *p,*n,*q;
    p=h;
    cout<<"enter the position where you want to delete data"<<endl;
    cin>>pos;
    if(pos<1||pos>number+1){
        cout<<"cannot delete into this"<<endl;
        return h;
    }
    if(pos==1)
    {
        h=h->next;
        return h;
    }
    else
    {
        for(i=1;i<pos;i++)
        {
           q=p;
           p=p->next;
        }
        q->next=p->next;
        return h;
    }
}
node* reversenode(node *head)
{
    node *p,*r=NULL;
    while(head)
    {
        p=head->next;
        head->next=r;
        r=head;
        head=p;
    }
    return r;
}
int main()
{
    node *h=create();
    print(h);
    //length(h);
    //h=insert(h);
    //print(h);
    //length(h);
    //h=delete1(h);
    //print(h);
    h=reversenode(h);
    print(h);
    return 0;
}

