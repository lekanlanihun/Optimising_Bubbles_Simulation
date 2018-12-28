#ifndef BUBBLE_OPTIMISER
#define BUBBLE_OPTIMISER
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <GL/glut.h>
#include <GL/glu.h>
#include <vector>
#include  "../Quad_Tree/QuadTree.h"
//#include <iomanip>
#define number_of_vertex 1145
#define number_of_edges 1145
#define vertex__file_cols 6
#define edge__file_rows 1148
#define edge__file_cols 6



using namespace std;

class Bubble_Optimiser{

public:
Bubble_Optimiser ();
void read_vertex_file();
void read_edge_file();
void calc_minimum_distance();
void calc_min_distance();
void calc_mindist();
void print_mininum_distance();
void mininum_distance(double, double, double, double, double, double, double, double,double);
void simple_spatial_partition(double, double, double, double);
void overlapping_spatial_partition(double, double, double, double);
void simple_edge_partition();
void assign_boundary_box_data();
void count_boundary_box_data();
double *sort(double*,int);

typedef struct BoundingBox{
  double x0; double y0;
    double x1; double y1;

}BoundingBox;

/*typedef struct bubbles_data{
    double* vertex_X =new double [number_of_vertex];
            double* vertex_Y=new double [number_of_vertex];
           double* Nx=new double [number_of_vertex];
            double *Ny=new double [number_of_vertex];
            double *edge_vertex1_X=new double[number_of_edges];
            double *edge_vertex1_Y=new double[number_of_edges];
            //double edge_vertex2_x[number_of_edges];
           // double edge_vertex2_y[number_of_edges];
            double* ee_X=new double [number_of_edges];
            double* ee_Y=new double[number_of_edges];

}bubbles_data;*/

BoundingBox boundingBox;


BoundingBox MakeBoundingBox(double x0, double y0, double x1, double y1){
    boundingBox.x0=x0;
    boundingBox.y0=y0;
    boundingBox.x1=x1;
    boundingBox.y1=y1;

return boundingBox;

}

BoundingBox TopLeftQuadrant;BoundingBox TopRightQuadrant;BoundingBox BottomLeftQuadrant;BoundingBox BottomRightQuadrant;
BoundingBox TopMidQuadrant;BoundingBox  LeftMidQuadrant;BoundingBox  MidMidQuadrant;BoundingBox  RightMidQuadrant; BoundingBox BottomMidQuadrant;
BoundingBox box1;BoundingBox  box2;BoundingBox box3;BoundingBox  box4; BoundingBox box5;
BoundingBox box6;BoundingBox  box7;BoundingBox box8;BoundingBox  box9; BoundingBox box10;
BoundingBox box11;BoundingBox  box12;BoundingBox box13;BoundingBox  box14; BoundingBox box15;
BoundingBox box16;BoundingBox  box17;BoundingBox box18;BoundingBox  box19; BoundingBox box20;
BoundingBox box21;BoundingBox  box22;BoundingBox box23;BoundingBox  box24; BoundingBox box25;
BoundingBox box26;BoundingBox  box27;BoundingBox box28;BoundingBox  box29; BoundingBox box30;
BoundingBox box31;BoundingBox  box32;BoundingBox box33;BoundingBox  box34; BoundingBox box35;
BoundingBox box36;BoundingBox  box37;BoundingBox box38;BoundingBox  box39; BoundingBox box40;
BoundingBox box41;BoundingBox  box42;BoundingBox box43;BoundingBox  box44; BoundingBox box45;
BoundingBox box46;BoundingBox  box47;BoundingBox box48;BoundingBox  box49; 

BoundingBox edgebox1;BoundingBox  edgebox2;BoundingBox edgebox3;BoundingBox  edgebox4;
bool BoundingBoxContainsVertices(BoundingBox boundary, double,double);
bool BoundingBoxContainsEdges(BoundingBox boundary, double,double/*, double,double*/);
bool BoundingBoxContainsData(BoundingBox boundary, double, double, double,double/*,double,double*/);


virtual ~ Bubble_Optimiser();

private:

int *vertex_id; double *vertex_x; double *vertex_y; int number; int vertex_cols; double nx; double ny; double mindists; int vert_id;
double *vertex_nx; double *vertex_ny; int *bubble_id; int *min_vertex_id;
int *edge_id; int*edge_vertex1_id;  int*edge_vertex2_id; double*edge_vertex1_x; double*edge_vertex1_y; double *ee_x; double *ee_y; int *edge_bubble_id;
 double*edge_vertex2_x;
    double*edge_vertex2_y;
double *min_dist; double *b1_min_dist;double *b2_min_dist;double *b3_min_dist; double *b4_min_dist;double *b5_min_dist;double *b6_min_dist;double *b7_min_dist; double *b8_min_dist;  double *b9_min_dist;  double *out_min_dist;  double**vertex_info; double**edge_info; int i; int edge_number;int  v_counter; int e_counter;
 double *b1_vertex_id; double *b2_vertex_id; double *b3_vertex_id; double *b4_vertex_id;  double *b5_vertex_id; double *b6_vertex_id; double *b7_vertex_id; double *b8_vertex_id; double *b9_vertex_id;double *out_vertex_id;
    double *b1_vertex_x;double* b2_vertex_x;  double *b3_vertex_x;double* b4_vertex_x; double *b5_vertex_x;double* b6_vertex_x;  double *b7_vertex_x;double* b8_vertex_x; double* b9_vertex_x;  double* out_vertex_x; 
    double *b1_vertex_y;double* b2_vertex_y;  double *b3_vertex_y;double* b4_vertex_y; double *b5_vertex_y;double* b6_vertex_y;  double *b7_vertex_y;double* b8_vertex_y; double* b9_vertex_y; double* out_vertex_y;  
    double *b1_nx;double* b2_nx;  double *b3_nx;double* b4_nx;  double *b5_nx;double* b6_nx;  double *b7_nx;double* b8_nx; double* b9_nx;double* out_nx; 
    double *b1_ny;double* b2_ny;  double *b3_ny;double* b4_ny;double *b5_ny;double* b6_ny;  double *b7_ny;double* b8_ny; double* b9_ny;  double* out_ny; 
    double *b1_vert_b_id;   double *b2_vert_b_id;double *b3_vert_b_id;double *b4_vert_b_id;double *b5_vert_b_id;   double *b6_vert_b_id;double *b7_vert_b_id;double *b8_vert_b_id;double *b9_vert_b_id; double *out_vert_b_id; 
    double *b1_evertex1_x;double* b2_evertex1_x;  double *b3_evertex1_x;double* b4_evertex1_x;  double *b5_evertex1_x;double* b6_evertex1_x;  double *b7_evertex1_x;double* b8_evertex1_x;double* b9_evertex1_x; double* out_evertex1_x; 
    double *b1_evertex1_y;double* b2_evertex1_y;  double *b3_evertex1_y;double* b4_evertex1_y;double *b5_evertex1_y;double* b6_evertex1_y;  double *b7_evertex1_y;double* b8_evertex1_y;double* b9_evertex1_y; double* out_evertex1_y; 
    double *b1_eex;double* b2_eex;  double *b3_eex;double* b4_eex; double *b5_eex;double* b6_eex;  double *b7_eex;double* b8_eex; double* b9_eex; double* out_eex; 
    double *b1_eey;double* b2_eey;  double *b3_eey;double* b4_eey;  double *b5_eey;double* b6_eey;  double *b7_eey;double* b8_eey; double* b9_eey;  double* out_eey; 
    double *b1_edge_b_id;   double *b2_edge_b_id;double *b3_edge_b_id;double *b4_edge_b_id;double *b5_edge_b_id;   double *b6_edge_b_id;double *b7_edge_b_id;double *b8_edge_b_id;double *b9_edge_b_id; double *out_edge_b_id; 

int edge_cols, counter, b1_v_counter, b1_e_counter, b2_v_counter, b2_e_counter, b3_v_counter,  b3_e_counter, b4_v_counter, b4_e_counter;
int b5_v_counter, b5_e_counter, b6_v_counter, b6_e_counter, b7_v_counter,  b7_e_counter, b8_v_counter,  b8_e_counter, b9_v_counter,b9_e_counter, out_v_counter, out_e_counter;
double minimum; double mindist;



};

#endif
