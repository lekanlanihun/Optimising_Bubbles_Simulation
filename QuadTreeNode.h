#ifndef QUAD_TREE_NODE
#define QUAD_TREE_NODE
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <GL/glut.h>
#include <GL/glu.h>
#include <vector>
#include<malloc.h> 

using namespace std;




//QuadTreeNodeData*MakeQuadTreeNodeData(int,double, double,double,void *data);

class QuadTreeNode{

public:


void MakeQuadTreeNodeData(int,double, double,double,double,int);

//void MakeBoundingBox(double x0,double y0,double x1,double y1);
void SubDivide();
int getCapacity() const;

/*bool BoundingBoxIntersectsBoundingBox(BoundaryBox boundary, BoundaryBox test);
static QuadTreeNode *QuadTreeNodeMake(BoundaryBox boundary, int capacity);
void GatherAllDataWithinBoundary(BoundaryBox boundary, QuadTreeNodeDataBlock block);
void Tranverse(QuadTreeNodeTranverseBlock block);*/

typedef struct BoundingBox{
double x0; double y0;
double x1; double y1;

}BoundingBox;

QuadTreeNode(BoundingBox boundary, int capacity);

BoundingBox MakeBoundingBox(double x0, double y0, double x1, double y1){
   // BoundingBox boundingBox;
    boundingBox.x0=x0;
    boundingBox.y0=y0;
    boundingBox.x1=x1;
    boundingBox.y1=y1;

return boundingBox;

}


typedef struct QuadTreeNodeData{
int vertex_id;
double vertex_x;
double vertex_y;
double nx;
double ny;
int vert_bubble_id;
void *data;
}QuadTreeNodeData;

bool Insert_Data(QuadTreeNodeData data);

QuadTreeNodeData*getPoints() const{
 return this->points;
}


BoundingBox getBoundary() const{
    return this->boundary;
}

//bool BoundingBoxIntersectsBoundingBox(BoundaryBox boundary, BoundaryBox test);
//static QuadTreeNode *QuadTreeNodeMake(BoundaryBox boundary, int capacity);
//void GatherAllDataWithinBoundary(BoundaryBox boundary, QuadTreeNodeDataBlock block);
bool BoundingBoxContainsData(BoundingBox boundary, QuadTreeNodeData data);





virtual ~ QuadTreeNode();

private:
 BoundingBox boundingBox;
BoundingBox boundary;
QuadTreeNode *TopLeftQuadrant;
QuadTreeNode *TopRightQuadrant;
QuadTreeNode *BottomLeftQuadrant;
QuadTreeNode *BottomRightQuadrant;
int capacity; int count;

protected:
//BoundaryBox boundary;

QuadTreeNodeData*points;
/*BoundaryBox boundary;
int capacity; int count;*/
};

#endif
