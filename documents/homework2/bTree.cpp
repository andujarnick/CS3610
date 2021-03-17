#include <iostream>
#include "bTree.h"
using namespace std;

template<class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
  root = NULL;
}
template<class elemType>
bool binaryTreeType<elemType>::isEmpty()
{
  return (root == NULL);
}
template<class elemType>
void binaryTreeType<elemType>::inorderTraversal()
{
  inorder(root);
}
template<class elemType>
void binaryTreeType<elemType>::preorderTraversal()
{
  preorder(root);
}
template<class elemType>
void binaryTreeType<elemType>::postorderTraversal()
{
  postorder(root);
}
template<class elemType>
int binaryTreeType<elemType>::treeHeight()
{
  return height(root);
}
template<class elemType>
int binaryTreeType<elemType>::treeNodeCount()
{
  return nodeCount(root);
}
template<class elemType>
int binaryTreeType<elemType>::treeLeavesCount()
{
  return leavesCount(root);
}

template<class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType> *p){
    //returns nothing if the node is at the end of the tree
    if(node == NULL)
        {return 0;}

    else{
        //returns 1 if the node is at a leaf
        if((p -> rlink == NULL) && (p -> llink == NULL)){
            return 1;
        }
        //continues down the list if it is not at a leaf or the end
        else{
            return leavesCount(p -> rlink) + leavesCount(p -> llink);
        }
    }
}