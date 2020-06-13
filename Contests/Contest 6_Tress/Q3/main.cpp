#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* node=new Node;
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

Node* insertLevelOrder(vector<string> V,Node* root,int i,int n)
{
    if(i<n && V[i]!="null")
    {
        int val=0;
        for(int j=0;j<V[i].size();j++)
            val=(val*10)+((int)(V[i][j])-48);
        //int val=stoi(V[i]);
        Node* temp=newNode(val);
        root=temp;

        root->left=insertLevelOrder(V,root->left,2*i+1,n);
        root->right=insertLevelOrder(V,root->right,2*i+2,n);
    }
    return root;
}

Node* util(Node* root,int p,int q)
{
    if(root==NULL)
        return NULL;
    if(root->data==p || root->data==q)
        return root;

    Node* l=util(root->left,p,q);
    Node* r=util(root->right,p,q);

    if(l && r)
        return root;

    return (l!=NULL)?l:r;
}

Node* LCA(Node* root,int p,int q)
{
    Node* res=util(root,p,q);
    return res;
}


int main()
{
    int N;
    cout<<"Enter number of elements\n";
    cin>>N;
    vector<string> V;
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;
        V.push_back(s);
    }
    Node* root=insertLevelOrder(V,root,0,N);
    int p,q;
    cout<<"\nEnter p\n";
    cin>>p;
    cout<<"\nEnter q\n";
    cin>>q;
    Node* ans=LCA(root,p,q);
    cout<<"\nAncestor = "<<ans->data<<endl;
    return 0;
}
