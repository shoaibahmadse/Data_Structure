// #include<iostream>
// using namespace std ;

// Simple Binary Tree

// struct binaryTree
// {
//     int data;
//     binaryTree *left,*right;
//     binaryTree(int data):data{data},left{nullptr},right{nullptr}{};
// };

// void print_dfs(binaryTree *root){
//     if (root == nullptr){
//         return;
//     }
//     cout << root->data << " ";
//     print_dfs(root->left);
//     print_dfs(root->right);
// }


// int main(){
//     // Nodes construction
//     binaryTree *root = new binaryTree(1);
//     binaryTree *left = new binaryTree(2);
//     binaryTree *right = new binaryTree(3);
//     binaryTree *left_left = new binaryTree(4);
//     binaryTree *left_right = new binaryTree(5);
//     binaryTree *right_left = new binaryTree(6);
//     binaryTree *right_right = new binaryTree(7);

//     // connecting nodes
//     root->left = left;
//     root->right = right;
//     left->left = left_left;
//     left->right = left_right;
//     right->left = right_left;
//     right->right = right_right;

//     // printing binary tree
//     print_dfs(root);

//     // Deleting nodes
//     delete root;
//     delete left;
//     delete right;
//     delete left_left;
//     delete left_right;
//     delete right_left;
//     delete right_right;

//     return 0 ;
// }

// Binary Search Tree

#include<iostream>
#include<queue>
using namespace std ;

struct bstNode{
    int data;
    bstNode *left;
    bstNode *right;
} *root=NULL;

// add node in empty tree
bstNode* addToEmpty(int data){
    bstNode * temp = new bstNode;
    temp->right = NULL;    
    temp->data = data;
    temp->left = NULL;
    return temp;
}

// insert data in asscending order in bst
bstNode* insert(bstNode* root,int data){
    if(root == NULL){
        root = addToEmpty(data);
        return root;
    }else if(data <= root->data){
        root->left = insert(root->left,data);
    }else {
        root->right = insert(root->right,data);
    }
    return root;
}

// search data in bst
bool search(bstNode* root,int data){
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return search(root->left,data);
    else return search(root->right,data);
}

// display data by breath-first
void levelOrder(bstNode* root){
    if(root == NULL) return;
    queue<bstNode*> q;
    q.push(root);
    while(!q.empty()){  //time o(n); and space o(n);
        bstNode * current = q.front();
        cout << current->data << " ";
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
        q.pop();
    }
}

// display data by Depth-first: method by pre-order
void preOrder(bstNode *root){
    if (root == NULL) return;  //worst case: Time O(n), space(n)
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
// display data by Depth-first: method by in-order
void inOrder(bstNode *root){
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
// display data by Depth-first: method by post-order
void postOrder(bstNode *root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
bool isSubTreeLesser(bstNode *root, int data);
bool isSubTreeGreater(bstNode *root, int data){
    if(root == NULL) return true;
    if(
        root->data > data 
        && isSubTreeGreater(root->left,data) 
        && isSubTreeGreater(root->right,data)
    )return true;
    else return false;
};
bool isBinarySearchTree(bstNode *root){
    if (root == NULL) return;
    
    if(
        isSubTreeLesser(root->left,root->data) 
     && isSubTreeGreater(root->right,root->data)
     && isBinarySearchTree(root->left)
     && isBinarySearchTree(root->right)
    )return true;
    else return false;
}

int main(){
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,8); 
    root = insert(root,12);
    
    // int number;
    // cout << "Enter number be searched\n";
    // cin >> number;
    // if(search(root,number) == true) cout << "Found\n";
    // else cout << "Not Found\n";

    // levelOrder(root);
    preOrder(root);

    return 0 ;
}