#include "BinaryTree.h"

/**
 * Implement balanceFactors() correctly
 */

void getHeight(BinaryTree::Node* node, unordered_map<BinaryTree::Node*,int>& height){
    
    if(node == nullptr){
        height.insert({node,0});
        return;
    }
   
    getHeight(node->leftChild, height);
    getHeight(node->rightChild, height);
    
    if(height[node->leftChild] > height[node->rightChild]){
        height.insert({node,height[node->leftChild]+1});
    }
    else {
        height.insert({node,height[node->rightChild]+1});
    }
   
}

void getBalanceFactor(BinaryTree::Node* node, unordered_map<BinaryTree::Node*,int>& height, unordered_map<int, int>& balanceFactor){
   
    if(node == nullptr){
        return;
    }
    
    getBalanceFactor(node->leftChild, height, balanceFactor);
    getBalanceFactor(node->rightChild, height, balanceFactor);
    balanceFactor.insert({node->label,height[node->rightChild]-height[node->leftChild]});       
   
}
unordered_map<int,int> BinaryTree::balanceFactors() {
    unordered_map<BinaryTree::Node*,int> height;
    getHeight(root, height);
    
    unordered_map<int, int>balanceFactor;
    getBalanceFactor(root, height, balanceFactor);
    return balanceFactor;
}
