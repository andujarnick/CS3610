template <class elemType>
struct arrayListNode
{
  elemType info;
  arrayListNode<elemType> *llink;
  arrayListNode<elemType> *rlink;
};



  //DEfinition of the class
template <class elemType>
class arrayListType
{
public:
    // heap(const arrayListType<elemType>* otherHeap);
    arrayListType();
    // ~heap();

    void heapify(int low, int hight);
    void buildHeap();
    void outputArray();

protected:
    arrayListNode<elemType> *root;
    int list[] = {47, 78, 81, 52, 50, 82, 58, 42, 65, 80, 92, 53, 63, 87, 95, 59, 34, 37, 7, 20};
    int length = 20;
};