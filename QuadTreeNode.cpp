#include "QuadTreeNode.h"

QuadTreeNode::QuadTreeNode(BoundingBox boundary, int capacity){

   this->TopLeftQuadrant=NULL;
    this->TopLeftQuadrant=NULL;
    this->BottomLeftQuadrant=NULL;
    this->BottomRightQuadrant=NULL;
    this->boundary=boundary;
    this->capacity=capacity;
    this->count=0;
    this->points= new QuadTreeNodeData[sizeof(QuadTreeNodeData)*capacity];
    //this->points=(QuadTreeNodeData*)mallloc(sizeof (QuadTreeNodeData)*capacity);

}

void QuadTreeNode::MakeQuadTreeNodeData(int vert_id, double vert_x, double vert_y, double Nx,double Ny,int vert_bub_id){
    QuadTreeNodeData nodedata;
    nodedata.vertex_id=vert_id;
    nodedata.vertex_x=vert_x;
    nodedata.vertex_y=vert_y;
    nodedata.nx=Nx;
    nodedata.ny=Ny;
    nodedata.vert_bubble_id=vert_bub_id;

   // nodedata.data=data;


}






void QuadTreeNode::SubDivide(){

    BoundingBox box=this-> boundingBox;

    double xmid= (box.x0 + box.x1)/2.0;
    double ymid= (box.y0 + box.y1)/2.0;

    //create the topleftquadrant bounding box
    BoundingBox TopLeftQuadrant=MakeBoundingBox(box.x0,box.y0, xmid, ymid);
    this->TopLeftQuadrant=new QuadTreeNode(TopLeftQuadrant, this->capacity);
    BoundingBox TopRightQuadrant=MakeBoundingBox(xmid,box.y0, box.x1, ymid);
    this->TopRightQuadrant=new QuadTreeNode(TopRightQuadrant, this->capacity);

    BoundingBox BottomLeftQuadrant=MakeBoundingBox(box.x0,ymid, xmid, box.y1);
    this->BottomLeftQuadrant=new QuadTreeNode(BottomLeftQuadrant, this->capacity);

    BoundingBox BottomRightQuadrant=MakeBoundingBox(xmid,ymid, box.x1, box.y1);
    this->BottomRightQuadrant=new QuadTreeNode(BottomRightQuadrant, this->capacity);



}


bool QuadTreeNode::BoundingBoxContainsData(BoundingBox boundary, QuadTreeNodeData data){

bool Contains_Vertex_X=boundary.x0<=data.vertex_x && data.vertex_x<=boundary.x1;
bool Contains_Vertex_Y=boundary.y0<=data.vertex_y && data.vertex_y<=boundary.y1;

return Contains_Vertex_X && Contains_Vertex_Y;

}


/*bool QuadTreeNode::BoundingBoxIntersectsBoundingBox(BoundaryBox boundary, BoundaryBox test){

return (boundary.x0<=test.x1 && boundary.x1>=test.x0 && boundary.y0<=test.y1 && boundary.y1>=test.y0  );

}*/


/*QuadTreeNode*QuadTreeNodeMake(BoundaryBox boundary, int capacity){

QuadTreeNode *node=new QuadTreeNode(boundary, capacity);
return node;

}*/

/*void QuadTreeNode::GatherAllDataWithinBoundary(BoundaryBox boundary, QuadTreeNodeDataBlock block){
    if(!BoundingBoxIntersectsBoundingBox(this->boundary,boundary)){
        return;
    }

    for(int i=0; i<this->count;i++){
        if(BoundingBoxContainsData(boundary, this->points[i])){
            block(this->points[i]);

        }
    }

    if(this->TopLeftQuadrant==NULL){
        return;
    }

this->TopLeftQuadrant->GatherAllDataWithinBoundary(boundary,block);
this->TopRightQuadrant->GatherAllDataWithinBoundary(boundary,block);
this->BottomLeftQuadrant->GatherAllDataWithinBoundary(boundary,block);
this->BottomRightQuadrant->GatherAllDataWithinBoundary(boundary,block);

}*/

// this traverse the block of code that calculate minimum distance, i.e. for calc_mindist() method, recursively over the nodes.
/*void QuadTreeNode::Tranverse(QuadTreeNodeTranverseBlock block){
    block(this);
    if(this->TopLeftQuadrant==NULL){
        return;
    }

    this->TopLeftQuadrant->Tranverse(block);
    this->TopRightQuadrant->Tranverse(block);
    this->BottomLeftQuadrant->Tranverse(block);
    this->BottomRightQuadrant->Tranverse(block);
}*/

bool QuadTreeNode::Insert_Data(QuadTreeNodeData data){

    if(!BoundingBoxContainsData(this->boundary,data)){
        return false;
    }

    if(this->count<this->capacity){
        this->points[this->count++]=data;
        return true;
    }

    //check if the current is a leaf, and if it is split.
    if(this->TopLeftQuadrant==NULL){
        this->SubDivide();
    }

    //tranverse the tree and insert data
    if(this->TopLeftQuadrant->Insert_Data(data))
      return true;
    if(this->TopRightQuadrant->Insert_Data(data))
      return true;
    if(this->BottomLeftQuadrant->Insert_Data(data))
      return true;
    if(this->BottomRightQuadrant->Insert_Data(data))
      return true;

    //default: it was able to add the node
    return false;

}





/*BoundingBox QuadTreeNode::getBoundary() const{
    return this->boundary;
}*/

int QuadTreeNode::getCapacity() const{
    return this->capacity;
}

QuadTreeNode::~QuadTreeNode(){

if(this->TopLeftQuadrant!=NULL)
    delete this->TopLeftQuadrant;

if(this->TopRightQuadrant!=NULL)
    delete this->TopRightQuadrant;

if(this->BottomLeftQuadrant!=NULL)
    delete this->BottomLeftQuadrant;

if(this->TopLeftQuadrant!=NULL)
    delete this->BottomRightQuadrant;

for(int i=0;i<this->count;i++){

    free(this->points[i].data);
}

/*for(int i=0;i<count;i++){
    delete [] this->points[i].data;
}*/
delete [] this->points;
/*delete this->points;*/

}


