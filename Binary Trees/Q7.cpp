//Coding Challenge: Determine whether a binary tree is Skewed BST or not
//Note: Here Skewed BST means it has neither left skewed properties or right skewed properties but it can have atmost 1 child node only means either nullptr or 1 child node.
//This question doesn't convey real meaning of skewed BST. The tree is question is called degenerated tree which takes O(n) time complexity.
#include<iostream>
using namespace std;

bool isSkewedBST(int preorder[], int n){
    if(n <= 2) return true;
    int minimum_so_far = min(preorder[n-1],preorder[n-2]);
    int maximum_so_far = max(preorder[n-1],preorder[n-2]);
    for(int i = n - 3; i >= 0; i--){
        if(preorder[i] < minimum_so_far) minimum_so_far = preorder[i];
        else if(preorder[i] > maximum_so_far) maximum_so_far = preorder[i];
        else return false;
    }
    return true;
}

int main(){
    int preorder[] = {15, 20, 18, 22};
    int n = sizeof(preorder) / sizeof(preorder[0]);
    bool ans = isSkewedBST(preorder, n);
    if(ans){
        cout<<"BST is Skewed "<<endl;
        return 0;
    }
    cout<<"BST is not skewed "<<endl;
}

//Example of skewed: 15 30 25 18 20
//Example of not skewed: 15 30 25 35 20
//Example when n <= 2: 15 10