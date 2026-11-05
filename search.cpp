#include<iostream>
using namespace std;
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
 int search(node*root,int a){
    if (root==NULL){
        return 0;
    }
    if (a < root->data) {
    return search(root->left, a);  
} else if (a > root->data) {
    return search(root->right, a); 
} else {
    return 1; 
}
 }
 int main() {
    node* root = nullptr;
    root = printtree(root, 50);
    root = printtree(root, 30);
    root = printtree(root, 20);
    root = printtree(root, 40);
    root = printtree(root, 70);
    root = printtree(root, 60);

    int target = 30; 
    if (search(root, target)) {
        cout << target << " is present in the BST!" << endl;
    } else {
        cout << target << " is NOT present in the BST!" << endl;
    }

    return 0;
}