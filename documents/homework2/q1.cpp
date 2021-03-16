template<class elemType>
int binaryTreeType::leafCount(nodeType <elemType> *node){
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
            return leafCount(p -> rlink) + leafCount(p -> llink);
        }
    }
}

template<class elemType>
int binaryTreeType::leafCount(nodeType <elemType> *node){
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
            return leafCount(p -> rlink) + leafCount(p -> llink);
        }
    }
}