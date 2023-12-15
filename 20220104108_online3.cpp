#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    //node *prev;
};
node *root=NULL;
void printing ()
{
    node *curr_node=root;
    while(curr_node!=NULL)
    {
        cout<<curr_node->data<<" ";
        curr_node=curr_node->next;
    }
}
void ins_first(int v)
{
    node *temp;
    temp=new node();
    temp->data=v;
    temp->next=root;
    root=temp;

}
void ins_last(int v)
{
    node *curr_node=root,*temp;
    temp=new node();
    temp->data=v;
    temp->next=NULL;
    if(curr_node==NULL)
    root=temp;
    else
    {
        while(curr_node->next!=NULL)
        {
            curr_node=curr_node->next;
        }
        curr_node->next=temp;
    }


}
void ins_anyByVal(int o,int n)
{
    node *curr_node=root,*temp,*prev=root;
    temp=new node();
    temp->data=n;
    while(curr_node!=NULL)
    {

        if(curr_node->data==o)
        break;
        else
        {
            prev=curr_node;
        curr_node=curr_node->next;
        }
    }
    if(prev==root)
    {

        root=temp;
        temp->next=curr_node;
    }
    else
    {
    temp->next=prev->next;
    prev->next=temp;
    }
}
void ins_anyByPos(int p,int v)
{
    node *curr=root,*temp,*prev=root;
    temp=new node();
    temp->data=v;
    int count=1;
    while (curr!=NULL)

    {
        if(count==p)
        break;
        else
        {
            count++;
            prev=curr;
            curr=curr->next;
        }

    }
    if(count==1)
    {
        temp->next=root;
        root=temp;
    }
    else{
    temp->next=prev->next;
    prev->next=temp;
    }


}
void del_f()
{
    node *curr=root;
    if(curr!=NULL)
    root=curr->next;



}
void del_l()
{
    node *curr=root;
    while(curr->next->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=NULL;
}
void delByVal(int o)
{
    cout<<"fds";
    node *curr=root,*prev=root;
    while(curr!=NULL)
    {
        if(curr->data==o)
        break;
        else
        {
        prev=curr;
        curr=curr->next;
    }}
    if(curr==root)
    {
        //cout<<"fs";
        root=curr->next;

    }
    else if(curr->next==NULL)
    {
        //cout<<"fs";


        prev->next=NULL;
    }

    else

    prev->next=curr->next;
}
void delByPos(int p)
{
    node *curr=root,*prev;
    int count=1;
    while (curr!=NULL)
    {
        if(count==p)
        {
            break;

        }
        else
        {
            count++;
            prev=curr;
            curr=curr->next;
        }
    }
    if(count==1)
    {
        del_f();
    }
    else
    {
        prev->next=curr->next;

    }



}
void search(int v)
{
    node *curr=root;
    while(curr!=NULL)
    {
        if(curr->data==v)
        {
            cout<<v<<" found"<<endl;
            break;
        }

        curr=curr->next;
    }
    if(curr==NULL)
    cout<<"NOT FOUND!"<<endl;
}
int size()
{
    node *curr=root;
    int count=0;
    while(curr!=NULL)
    {
        curr=curr->next;
        count++;
    }
    return count;
   // cout<<"size is: "<<count<<endl;
}
void p_last()
{
    node *curr=root;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    cout<<"last val: "<<curr->data<<endl;
}
void prev_last()
{
    node *curr=root;
    while(curr->next->next!=NULL)
    {
        curr=curr->next;
    }
    cout<<"prev last val: "<<curr->data<<endl;
}
void check(int x,int n)
{
    node *curr=root;
    int c=0;

    while(curr!=NULL)
    {
        c++;
        if(c-1==n)
            break;




        if((curr->data)<x){

                int d=curr->data;


            delByVal(curr->data);

ins_first(d);





        }
        if(curr->data>x)
        {

            int d=curr->data;

            delByVal(curr->data);
            ins_last(d);






        }

        curr=curr->next;




    }



}

int main()
{
    int n;
    cin>>n;
   for(int i =0;i<n;i++)
   {
       int m;
       cin>>m;

       ins_last(m);
   }

   int x;
   cin>>x;
   check(x,n);
   printing();
//   delByVal(4);
//
//   printing();
//   node *p,*q,*r,*s;
//   p=new node();
//   q=new node();
//   r=new node();
//   s=new node();
//   p->data=10;
//   q->data=15;
//   r->data=20;
//   s->data=25;
//   p->next=q;
//   q->next=r;
//   r->next=s;
//   s->next=NULL;
//   printing();






}
