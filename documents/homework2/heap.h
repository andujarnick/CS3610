template <class elemType>
struct binaryTreeNode
{
  elemTyoe info;
  binaryTreeNode<elemType> *llink;
  binaryTreeNode<elemType> *rlink;
};

  //DEfinition of the class
template <class elemType>
class heap
{
public:
    heap(const heap<elemType>* otherHeap);
    heap();
    ~heap();

    
};