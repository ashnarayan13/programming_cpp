#include "bits/stdc++.h"

class Node {
    public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

bool foundSum(Node* node, int sum){
    /* return true if we run out of tree and sum==0 */
	if (node == NULL) 
	{ 
		return (sum == 0); 
	} 
	
	else
	{ 
		bool ans = 0; 
	
		/* otherwise check both subtrees */
		int subSum = sum - node->data; 
	
		/* If we reach a leaf node and sum becomes 0 then return true*/
		if ( subSum == 0 && node->left == NULL && node->right == NULL ) 
		return 1; 
	
		if(node->left) 
			ans = ans || foundSum(node->left, subSum); 
		if(node->right) 
			ans = ans || foundSum(node->right, subSum); 
	
		return ans; 
	} 
}

int main(){
    int sum = 18;
    Node* root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(13);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->right->right = newNode(19);

    if(foundSum(root, sum)){
        std::cout<<"Found a match!\n";
    }
    else{
        std::cout<<"Failed to find match!\n";
    }
    return 0;
}