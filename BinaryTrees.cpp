#include<stdio.h>

// using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int val = 0,node* lft = NULL, node* rt = NULL ){
        data = val;
        left = lft;
        right = rt;
    }
    friend class BinaryTree;

};
class BinaryTree{
    node* root;
    public:
    BinaryTree(){
        root = NULL;
    }
    void preorder(node* root);
    void inorder(node* root);
    void postorder(node* root);
    int search(int inorder[],int start, int end, int curr);
    node* BuildTree(int preorder[], int inorder[],int start, int end);
    void InorderPrint(node* root);
    node* BuildTree2(int postorder[],int inorder[], int start, int end);
};
//preorder traversal in a binary tree
void preorder(node* root){
    if(root==NULL){
       return; 
    }
    printf("%d",root->data);
    printf(" ");
    preorder(root->left);
    preorder(root->right);
    return;
}
//inorder traversal in a binary tree
void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    return;
}
//postorder traversal in binary trees
void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
    return;
}
//defining the search function for BuildTree
int search(int inorder[],int start, int end, int curr){
    for(int i=start;i<=end; i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}
//making a binary tree using preorder and inorder arrays
node* BuildTree(int preorder[], int inorder[],int start, int end){
    static int idx = 0;
    if(start>end){
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    node* Node = new node(curr);
    if(start == end){
        return Node;
    }
    int pos = search(inorder, start, end, curr);
    Node->left = BuildTree(preorder, inorder, start, pos-1);
    Node->right = BuildTree(preorder, inorder, pos+1, end);
    return Node;
}
void InorderPrint(node* root){
    if(root == NULL){
        return;
    }
    InorderPrint(root->left);
    printf("%d ", root->data);
    InorderPrint(root->right);
    return;

}
node* BuildTree2(int postorder[],int inorder[], int start, int end){
    static int idx = 4;
    if(start>end){
        return NULL;
    }
    int curr = postorder[idx];
    idx--;
    node* Node = new node(curr);
    if(start==end){
        return Node;
    }
    int pos = search(inorder, start, end, curr);
    Node->right = BuildTree2(postorder, inorder, pos+1, end);
    Node->left = BuildTree2(postorder,inorder,start, pos-1);
    return Node;

}
