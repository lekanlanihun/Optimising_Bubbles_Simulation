#include "QuadTree.h"

QuadTree::QuadTree(QuadTreeNodeData *data, BoundingBox boundary, int capacity):QuadTreeNode(boundary, capacity){
for(int i=0; i< sizeof(data)/sizeof(QuadTreeNodeData);i++){
this->Insert_Data(data[i]);
}

}

/*QuadTree::QuadTreeNode* MakeQuadTree(QuadTreeNodeData*data, BoundingBox boundary, int capacity){
    QuadTree *tree=new QuadTree(data, boundary, capacity);
    return tree;

}*/

QuadTree::~QuadTree(){

}
