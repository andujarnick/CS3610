#include <iostream>
#include "avl_tree.h"
using namespace std;

void AVLTree::insert(const int newValue) {

  bool isTaller = false;
  AVLNode *newNode;
  newNode = new AVLNode(newValue);
  insertIntoAVL(root,newNode,isTaller);
  
}

void AVLTree::insertIntoAVL(AVLNode* &root, AVLNode *newNode, bool& isTaller){
  if (root == NULL){
    root = newNode;
    isTaller = true;
  }
  else if (root->value == newNode->value){
    cout << "Duplicate" << endl;
  }
  else if (root->value > newNode->value){

    insertIntoAVL(root->left, newNode,isTaller);

    if (isTaller){
      switch (root->bf)
	{
	case -1:
	  balanceFromLeft(root);
	  isTaller = false;
	  break;

	case 0:
	  root->bf = -1;
	  isTaller = true;
	  break;

	case 1:
	  root->bf = 0;
	  isTaller = false;
	}
    }
  }
  else{

    insertIntoAVL(root->right, newNode, isTaller);

    if(isTaller){
      switch(root->bf)
	{
	case -1:
	  root->bf = 0;
	  isTaller = false;
	  break;
	  
	case 0:
	  root->bf = 1;
	  isTaller = true;
	  break;
	  
	case 1:
	  balanceFromRight(root);
	  isTaller = false;
	}
    }
  }
}

void AVLTree::rotateToLeft(AVLNode* &root){
  AVLNode *p;
  
  if (root == NULL)
    cout << "Error in the tree" << endl;
  else if (root->right == NULL)
    cout << "Error in the tree: No right subtree to rotate." << endl;
  else{
    p = root->right;
    root->right = p->left;
    p->left = root;
    root = p; 
  }
}

void AVLTree::rotateToRight(AVLNode* &root){
  AVLNode *p;

  if (root == NULL)
    cout << "Error in the tree" << endl;
  else if (root->left == NULL)
    cout << "Error in the tree: No left subtree to rotate." << endl;
  else{
    p = root->left;
    root->left = p->right; 
    p->right = root;
    root = p; 
  }
}

void AVLTree::balanceFromLeft(AVLNode* &root){

  AVLNode *p;
  AVLNode *w;

  p = root->left;

  switch (p->bf)
    {
    case -1:
      root->bf = 0;
      p->bf = 0;
      rotateToRight(root);
      break;

    case 0:  // You need to handle this case; possible in AVL deletion
    rotateToRight(root);
      break;

    case 1:
      w = p->right;

      switch (w->bf)
	{
	case -1:
	  root->bf = 1;
	  p->bf = 0;
	  break;
	case 0:
	  root->bf = 0;
	  p->bf = 0;
	  break;
	case 1:
	  root->bf = 0;
	  p->bf = -1;
	}
      
      w->bf = 0;
      rotateToLeft(p);
      root->left = p;
      rotateToRight(root);
    }
}


void AVLTree::balanceFromRight(AVLNode* &root){
  AVLNode *p;
  AVLNode *w;

  
  p = root->right;
  switch (p->bf)
    {
    case -1:
      
      w = p->left;
      switch (w->bf)
	{
	case -1:
	  root->bf = 0;
	  p->bf = 1;
	  break;
	case 0:
	  root->bf = 0;
	  p->bf = 0;
	  break;
	case 1:
	  root->bf = -1;
	  p->bf = 0;
	}
      
      w->bf = 0;
      rotateToRight(p);
      root->right = p;
      rotateToLeft(root);
      break;

    case 0:  // You need to handle this case; possible in AVL deletion
      rotateToLeft(root);
      break;

    case 1:
      root->bf = 0;
      p->bf = 0;
      rotateToLeft(root);
    }
}

void AVLTree::print(char letter){
    if(letter == 'h'){
        findHeight(root);
        cout << endl;
    }
    else{
        outputList(root);
        cout << endl;
    }
  return; 
}


AVLNode* AVLTree::getPred(AVLNode* node){//used to return the predecessor of the node sent to it
    AVLNode* current;//pointer used to traverse the tree
    AVLNode* trailCurrent;//pointer used to follow current
    bool found = false;
    
    if(root == NULL){
        cout << "No predecessor, list empty" << endl;
    }
    else{
        current = root;
        trailCurrent = root;
        
        while((current != NULL) && (!found)){//loops until it finds the target node
            if(current -> value == node -> value){//checks to see if the target node was found
                found = true;
            }
            else{//advances down the list
                trailCurrent = current;
                if(current -> value > node -> value){
                    current = current -> left;
                }
                else{
                    current = current -> right;
                }
            }
        }
        if(current == NULL){//if no node is found
            cout << "Item is not in the tree" << endl;
        }
        else if(found){
            return trailCurrent;
        }
    }
    return trailCurrent;
}

void AVLTree::remove(int badValue){
  bool isShorter = false;
  remove(root,badValue, isShorter);
}

void AVLTree::remove(AVLNode* &root, int badValue, bool& isShorter){//used to remove a node from the tree
    AVLNode* deleteNode;//used to mark a node for deletion
    
    if(root == NULL){
        cout << "Nothing in the tree" << endl; return;
    }
    
    if(root -> value == badValue){//deletion node found
        if(root -> left == NULL && root -> right == NULL){//first case, no children
            deleteNode = root;//reassigns the node to be deleted
            delete deleteNode;//deletes the node
            root = NULL;//reassigns the original node to NULL;
            return;
        }
        if(root -> left != NULL && root -> right == NULL){//second case, left child but no right
            deleteNode = root -> left;
            *root = *deleteNode;
            delete root;
            if(isShorter == true){
                root -> bf--;
                balanceFromLeft(root);
            }
            return;
        }
        if(root -> left == NULL && root -> right != NULL){//third case, right child but no left
            deleteNode = root -> right;
            *root = *deleteNode;
            delete root;
            if(isShorter == true){
                root -> bf++;
                balanceFromRight(root);
            }
            return;
        }
        if(root -> left != NULL && root -> right != NULL){//fourth case, two children
            deleteNode = getPred(root);
            *root = *deleteNode;
            cout << deleteNode << "    " << root << endl;
            delete root;
            if(isShorter){
                root -> bf++;
                balanceFromLeft(root);
            }
            return;
        }
    }
    else{//sends the cursors down the list to find the badvalue
        if(badValue > root -> value){//sends it down the right side of the list
            isShorter = true;
            remove(root -> right, badValue, isShorter);
        }
        else{//sends it down the left side of the list
            isShorter = true;
            remove(root -> left, badValue, isShorter);
        }
    }

    
    if(root == NULL){//if the list is empty
        return;
    }
    
    
  return; 

}

//****************Added Functions********************
int AVLTree::max(int num1, int num2){//used to compare 2 numbers
    if(num1 > num2){return num1;}
    else{return num2;}
}


int AVLTree::goToEnd(AVLNode* &node){//advances a node to the bottom of a tree; helper function for findHeight
    if(node == NULL){return 0;}
    else{
        return 1 + max(goToEnd(node->left), goToEnd(node->right));//recursively calls the function
    }
}

void AVLTree::findHeight(AVLNode* &root){//finds how far a node is from the bottom of the list
    if(goToEnd(root) != 0){
        cout << goToEnd(root) << " ";
    }
    AVLNode* cursor;
    cursor = root;
    
    if(cursor == NULL){return;}
    else{
        findHeight(cursor->right);//recursively calls the function, advances down the list
        findHeight(cursor->left);//recursively calls the function, advances down the list
    }
}

void AVLTree::outputList(AVLNode* &root){//outputs the list of data in the tree
    if(root != NULL){
        outputList(root->left);
        cout << root->value << " ";
        outputList(root->right);
    }
}

//void AVLTree::getPredTester(){
//    AVLNode* cursor = root;
//    AVLNode* placeholder;
////    cursor = cursor -> left;
//    placeholder = getPred(cursor -> left);
//    cout << "placeholder -> value: " << placeholder -> value << endl;
//}
