#ifndef QUAD_TREE
#define QUAD_TREE
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <GL/glut.h>
#include <GL/glu.h>
#include <vector>
#include "QuadTreeNode.h"

using namespace std;

class QuadTree:public QuadTreeNode{

public:
QuadTree(QuadTreeNodeData *data, BoundingBox boundary, int capacity);
//static QuadTree*MakeQuadTree(QuadTreeNodeData *data, BoundingBox boundary, int capacity);

static QuadTreeNode* MakeQuadTree(QuadTreeNodeData*data, BoundingBox boundary, int capacity){
    QuadTree *tree=new QuadTree(data, boundary, capacity);
    return tree;

}
virtual ~ QuadTree();

private:


};

#endif
