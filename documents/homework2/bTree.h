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
  bool isEmpty() const;//returns whether the tree is empty
  void inorderTraversal() const;//does an inordertreaversal of the tree
  void preorderTraversal() const;//function to do a postorder traversal of the binary
  
  int treeHeight() const;
  int treeNodeCount() const;
  int treeLeavesCount() const;
  void destroytree();//deallocates the memory space ocupied by the binary tree
  
  binaryTreeType(const binaryTreeTrype<elemType>* otherTree);//copy constructor
  
  binaryTreeType();//default constructor
  
  ~binaryTreeType();//destructor
  
  protected:
    binaryTreeNode<elemType> *root;
    
  private:
    void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,
