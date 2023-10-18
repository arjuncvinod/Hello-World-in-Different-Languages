#include <stdio.h>
#include <stdlib.h>

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  
};

struct Node* createNode(int data)
{
    // use malloc to create memory
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    
    // assign data
    newNode->data = data;
    
    //assign left and right to be NULL
    newNode->left = NULL;
    newNode->right = NULL;
    
    return(newNode);
}

int calcSize(Node *root){
    
    if(root==NULL)
        return 0;
    else
        return (1+ calcSize(root->left) + calcSize(root->right));
}

int main() {
	
	struct Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->right->left = createNode (4);
	root->right->right = createNode(5);
	
    printf("The size of Tree is : %d",calcSize(root));

}
Code in C++:
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  Node(int val){
      data=val;
      left=right=NULL;
  }
};

int calcSize(Node *root){
    
    if(root == NULL)
        return 0;
    else
        return(1 + calcSize(root->left) + calcSize(root->right));
}

int main() {
	
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->right->left=new Node(4);
	root->right->right=new Node(5);
	
    cout << "The size of Tree is : " << calcSize(root);
}
Code in C++ (STL Version):
#include<bits/stdc++.h>
using namespace std;
 
void connect(int a,int b,int c,vector<vector<int>> &adj)
{
    adj[a-1][c]=b; //c is indicating left or right
    adj[b-1][0]=a; //attatching parents
}
 
int calcSize(int a,vector<vector<int>> adj)
{
    if(a==INT_MIN) return 0;
    return 1+ calcSize(adj[a-1][1],adj) + calcSize(adj[a-1][2],adj);
}
 
int main()
{
    int number_of_nodes=5,root=1;
    vector<vector<int>> adj(number_of_nodes,vector<int>(3,INT_MIN));
    //root=1, and root->left=2, root->right=3
    //So we connect 1 with 2 and 3.
    //Here 0 is for parent,1 is for left, 2 is for right
    connect(1,2,1,adj);
    connect(1,3,2,adj);
    connect(3,4,1,adj);
    connect(3,5,2,adj);
    cout << "The size of Tree is : " << calcSize(root,adj);
}
