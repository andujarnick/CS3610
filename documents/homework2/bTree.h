//definition of the node
template <class elemType>
struct binaryTreeNode
{
  elemTyoe info;
  binaryTreeNode<elemType> *llink;
  binaryTreeNode<elemType> *rlink;
};

  //DEfinition of the class
template <class elemType>
class binaryTreeType
{
public:
  const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&);//overload the assignment operator
  bool isEmpty();//returns whether the tree is empty
  void inorderTraversal();//does an inordertreaversal of the tree
  void preorderTraversal();//function to do a postorder traversal of the binary
  void postorderTraversal();//function that do a postorder traversal of the binary tree

  int treeHeight();
  int treeNodeCount();
  int treeLeavesCount();
  void destroytree();//deallocates the memory space ocupied by the binary tree
  
  binaryTreeType(const binaryTreeTrype<elemType>* otherTree);//copy constructor
  
  binaryTreeType();//default constructor
  
  ~binaryTreeType();//destructor
  
  protected:
    binaryTreeNode<elemType> *root;
    
  private:
    void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot, nodeType<elemType>* &otherTreeRoot);
    void destroy(nodeType<elemType> *p);
    void inorder(nodeType<elemType>* p);
    void postorder(nodeType<elemType> *p);
    int height(nodeType<elemType> * p);
    int max(int x, int y);
    int nodeCount(nodeType<elemType> *p);
    int leavesCount(nodeType<elemType> *p);
};

