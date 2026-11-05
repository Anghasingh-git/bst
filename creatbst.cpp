#include<iostream>
struct node{
  int data;
  node*left;
  node*right;
  node(int val){
    data=val;
    left=nullptr;
    right=nullptr;
  }
};
node*printtree(node*root,int k){
    if(root==NULL){
        return new node(k);
    }
   if(k<root->data){
   root->left = printtree(root->left,k);
   }
   else{
    root->right=printtree(root->right,k);
   }
   return root;
}
void inorder(node*root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    std::cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    node* root = nullptr;
    root = printtree(root, 50);
    root = printtree(root, 30);
    root = printtree(root, 20);
    root = printtree(root, 40);
    root = printtree(root, 70);
    root = printtree(root, 60);
    std::cout << "Inorder traversal: ";
    inorder(root);
    std::cout<<" ";
    return 0;
}