#include "bubble_optimiser.h"

Bubble_Optimiser::Bubble_Optimiser(){
    double x0=-2; double y0=2; double x1=2; double y1=-2;int n;
number=1144;  edge_number = 1148;v_counter=1144;  e_counter = 150000;  vertex_cols=6; edge_cols=8;
vertex_x= new double[number]; vertex_y= new double[number];
vertex_id= new int[number];
vertex_nx= new double[number];vertex_ny= new double[number]; bubble_id= new int[number];
 edge_id = new int[edge_number];
edge_vertex1_id = new int[edge_number];
    edge_vertex2_id = new int[edge_number];
    edge_vertex1_x = new double[edge_number];
    edge_vertex1_y = new double[edge_number];
    edge_vertex2_x = new double[edge_number];
    edge_vertex2_y = new double[edge_number];
    ee_x = new double[edge_number];
    ee_y = new double[edge_number];
    edge_bubble_id = new int[edge_number];
min_dist= new double[number];

/*vertex_info=new double*[number];
for(int i=0;i<number;i++){
vertex_info[i]=new double[vertex_cols];
}

edge_info=new double*[number];
for(int i=0;i<number;i++){
edge_info[i]=new double[edge_cols];
}*/

/*for(int i=0;i<number;i++){
vertex_id=0;
vertex_x[i]= 0.0;
vertex_y[i]= 0.0;
vertex_nx[i]=0.0;
vertex_ny[i]=0.0;
bubble_id[i]=0;
edge_id[i]=0;
edge_vertex1_x[i]=0.0;
edge_vertex1_y[i]=0.0;
ee_x[i]=0.0;
ee_y[i]=0.0;
edge_bubble_id[i]=0;

}*/
//bubbles_data data;
read_vertex_file();
read_edge_file();

/*double array1[number];
double array2[number];
for(int i=0;i<number;i++){
    array1[i]=vertex_x[i];
}
for(int i=0;i<number;i++){
    array2[i]=vertex_y[i];
}
double*array_x=sort(array1,number);
double x0=array_x[0]; double x1=array_x[number-1];
//cout<<"array x0="<<array1[0]<<"array x1="<<array1[number-1]<<endl;

double*array_y=sort(array2,number);
double y0=array_y[number-1]; double y1=array_y[0];*/
//cout<<"array y1="<<array2[0]<<"array y0="<<array2[number-1]<<endl;


//simple_spatial_partition(x0,  y0, x1,  y1);

overlapping_spatial_partition(x0,  y0, x1,  y1);
count_boundary_box_data();
  //cout << "b1_v_counter="<< " " << b1_v_counter<< endl;
//cout<<"get here1"<<endl;
b1_vertex_id=new double[b1_v_counter];b1_vertex_x=new double[b1_v_counter];b1_vertex_y=new double[b1_v_counter]; b1_nx=new double[b1_v_counter];b1_ny=new double[b1_v_counter];b1_vert_b_id=new double[b1_v_counter];
b1_evertex1_x=new double[b1_e_counter];b1_evertex1_y=new double[b1_e_counter]; b1_eex=new double[b1_e_counter];b1_eey=new double[b1_e_counter];b1_edge_b_id=new double[b1_e_counter];
b2_vertex_id=new double[b2_v_counter];b2_vertex_x=new double[b2_v_counter];b2_vertex_y=new double[b2_v_counter]; b2_nx=new double[b2_v_counter];b2_ny=new double[b2_v_counter]; b2_vert_b_id=new double[b2_v_counter];
    b2_evertex1_x=new double[b2_e_counter];b2_evertex1_y=new double[b2_e_counter]; b2_eex=new double[b2_e_counter];b2_eey=new double[b2_e_counter];b2_edge_b_id=new double[b2_e_counter];
b3_vertex_id=new double[b3_v_counter]; b3_vertex_x=new double[b3_v_counter];b3_vertex_y=new double[b3_v_counter]; b3_nx=new double[b3_v_counter];b3_ny=new double[b3_v_counter];b3_vert_b_id=new double[b3_v_counter];
     b3_evertex1_x=new double[b3_e_counter];b3_evertex1_y=new double[b3_e_counter]; b3_eex=new double[b3_e_counter];b3_eey=new double[b3_e_counter];b3_edge_b_id=new double[b3_e_counter];
b4_vertex_id=new double[b4_v_counter]; b4_vertex_x=new double[b4_v_counter];b4_vertex_y=new double[b4_v_counter]; b4_nx=new double[b4_v_counter];b4_ny=new double[b4_v_counter];b4_vert_b_id=new double[b4_v_counter];
     b4_evertex1_x=new double[b4_e_counter];b4_evertex1_y=new double[b4_e_counter]; b4_eex=new double[b4_e_counter];b4_eey=new double[b4_e_counter];b4_edge_b_id=new double[b4_e_counter];
out_vertex_id=new double[out_v_counter]; out_vertex_x=new double[out_v_counter];out_vertex_y=new double[out_v_counter]; out_nx=new double[out_v_counter];out_ny=new double[out_v_counter]; out_vert_b_id=new double[out_v_counter];
     out_evertex1_x=new double[out_e_counter];out_evertex1_y=new double[out_e_counter]; out_eex=new double[out_e_counter];out_eey=new double[out_e_counter];out_edge_b_id=new double[out_e_counter];
     //cout<<"get here2"<<endl;
counter=1;

assign_boundary_box_data();

for(int i=1;i<=b1_e_counter;i++){
    //cout<<"get inside loop"<<endl;
    /* cout << "b1_vertex_id[" << i <<"]="<< " " << b1_vertex_id[i] << endl;
         cout << "b1_vertex_x[" << i <<"]="<< " " << b1_vertex_x[i] << endl;
         cout << "b1_vertex_y[" << i <<"]="<< " " << b1_vertex_y[i] << endl;
         cout << "b1_nx[" << i <<"]="<< " " << b1_nx[i] << endl;
          cout << "b1_ny[" << i <<"]="<< " " << b1_ny[i] << endl;
          cout << "b1_vert_b_id[" << i <<"]="<< " " << b1_vert_b_id[i] << endl;*/
         cout << "b1_evertex1_x[" << i <<"]="<< " " << b1_evertex1_x[i] << endl;
        cout << "b1_evertex1_y[" << i <<"]"<< " " << b1_evertex1_y[i] << endl;
         cout << "b1_eex[" << i <<"]"<< " " << b1_eex[i] << endl;
         cout << "b1_eey[" << i <<"]"<< " " << b1_eey[i] << endl;
         cout << "b1_edge_b_id[" << i <<"]="<< " " << b1_edge_b_id[i] << endl;
}

for(int i=1;i<=b2_v_counter;i++){
    //cout<<"get inside loop"<<endl;
     /*cout << "b2_vertex_id[" << i <<"]="<< " " << b2_vertex_id[i] << endl;
         cout << "b2_vertex_x[" << i <<"]="<< " " << b2_vertex_x[i] << endl;
         cout << "b2_vertex_y[" << i <<"]="<< " " << b2_vertex_y[i] << endl;
         cout << "b2_nx[" << i <<"]="<< " " << b2_nx[i] << endl;
          cout << "b2_ny[" << i <<"]="<< " " << b2_ny[i] << endl;
          cout << "b2_vert_b_id[" << i <<"]="<< " " << b2_vert_b_id[i] << endl;*/
        // cout << "b1_evertex1_x[" << i <<"]="<< " " << b1_evertex1_x[i] << endl;
        // cout << "b1_evertex1_y[" << i <<"]"<< " " << b1_evertex1_y[i] << endl;
         //cout << "b1_eex[" << i <<"]"<< " " << b1_eex[i] << endl;
         //cout << "b1_eey[" << i <<"]"<< " " << b1_eey[i] << endl;

}


}


void Bubble_Optimiser::read_vertex_file(){
int v_id=0, b_id=0; double v_x=0.0, v_y=0.0, v_nx=0.0, v_ny=0.0;
ifstream read("../input_output_files/vertex_list_output.dat");
int i=1;
while (read>>v_id>>v_x>>v_y>>v_nx>>v_ny>>b_id){
 vertex_id[i]=v_id; vertex_x[i]=v_x; vertex_y[i]=v_y; vertex_nx[i]=v_nx; vertex_ny[i]=v_ny; bubble_id[i]=b_id;
   //cout<<vertex_id[i]<<" "<<vertex_x[i]<<" "<<vertex_y[i]<<" "<<vertex_nx[i]<<" "<<vertex_ny[i]<<" "<<bubble_id[i]<<endl;
i++;
}

//cout<<"counter vertex="<<" "<<i<<endl;
/*bubbles_data data;
for(int i=0;i<number_of_vertex;i++){
    data.vertex_X[number_of_vertex]=vertex_x[i];
    data.vertex_Y[number_of_vertex]=vertex_y[i];
    data.Nx[number_of_vertex]=vertex_nx[i];
    data.Ny[number_of_vertex]=vertex_ny[i];
}*/


}

void Bubble_Optimiser::read_edge_file(){
    int e_id = 0, e_v1_id = 0;
     int e_v2_id = 0;
     double e_v1_x = 0.0;
     double e_v1_y = 0.0;
     double e_v2_x = 0.0;
     double e_v2_y = 0.0;
     double eex = 0.0;
     double eey = 0.0;
     int e_bub_id = 0;

    ifstream read("../input_output_files/edge_list_output.dat");
    int i=1;
    while (read >> e_id >> e_v1_id >> e_v2_id >> e_v1_x >> e_v1_y >> e_v2_x >> e_v2_y >> eex >> eey >> e_bub_id) {
          edge_id[i] = e_id;
          edge_vertex1_id[i] = e_v1_id;
          edge_vertex2_id[i] = e_v2_id;
          edge_vertex1_x[i] = e_v1_x;
          edge_vertex1_y[i] = e_v1_y;
          edge_vertex2_x[i] = e_v2_x;
          edge_vertex2_y[i] = e_v2_y;
          ee_x[i] = eex;
          ee_y[i] = eey;
          edge_bubble_id[i] = e_bub_id;
          //cout << edge_id[i] << " " << edge_vertex1_id[i] << " " << edge_vertex2_id[i] << " " << edge_vertex1_x[i] << " " << edge_vertex1_y[i] << " " << edge_vertex2_x[i] << " " << edge_vertex2_y[i] << " " << ee_x[i] << " " << ee_y[i] << " " << edge_bubble_id[i] << endl;
          i++;
      }
/*bubbles_data data;
    for(int i=0;i<number_of_edges;i++){
        data.edge_vertex1_X[number_of_edges]=edge_vertex1_x[i];
        data.edge_vertex1_Y[number_of_edges]=edge_vertex1_y[i];
        data.ee_X[number_of_edges]=ee_x[i];
        data.ee_Y[number_of_edges]=ee_y[i];
    }*/
//cout<<"counter edge="<<" "<<i<<endl;
}

void Bubble_Optimiser::calc_minimum_distance(){
//cout<<"get here1"<<endl;
double vert_x=0.0; double vert_y=0.0; double nx=0.0; double ny=0.0;  int bub_id;
//double evx=0.0; double evx=0.0; double ee_x=0.0; double ee_y=0.0; 
double denoms, ll, mm;
for(int i=1;i<=number;i++){
    min_dist[i]=4;
for(int j=1;j<=edge_number;j++){

    if (bubble_id[i] != edge_bubble_id[j] && BoundingBoxContainsData(TopLeftQuadrant, vertex_x[i], vertex_y[i], edge_vertex1_x[j], edge_vertex1_y[j]/*, edge_vertex2_x[j], edge_vertex2_y[j]*/)) {
        denoms = ee_x[j] * vertex_ny[i] - ee_y[j] * vertex_nx[i];
        if (denoms != 0) {
            ll = ((ee_y[j] * vertex_x[i] - ee_x[j] * vertex_y[i]) - (edge_vertex1_x[j] * ee_y[j] - edge_vertex1_y[j] * ee_x[j])) / denoms;
            mm = ((vertex_ny[i] * vertex_x[i] - vertex_nx[i] * vertex_y[i]) - (edge_vertex1_x[j] * vertex_ny[i] - edge_vertex1_y[j] * vertex_nx[i])) / denoms;
            if (mm >= 0 && mm <= 1) {
            if (abs(ll) < min_dist[i]) {
                    min_dist[i] = abs(ll);
                }
            }
        }
    }

   else if (bubble_id[i] != edge_bubble_id[j] && BoundingBoxContainsData(TopRightQuadrant, vertex_x[i], vertex_y[i], edge_vertex1_x[j], edge_vertex1_y[j]/*, edge_vertex2_x[j], edge_vertex2_y[j]*/)) {
        denoms = ee_x[j] * vertex_ny[i] - ee_y[j] * vertex_nx[i];
        if (denoms != 0) {
            ll = ((ee_y[j] * vertex_x[i] - ee_x[j] * vertex_y[i]) - (edge_vertex1_x[j] * ee_y[j] - edge_vertex1_y[j] * ee_x[j])) / denoms;
            mm = ((vertex_ny[i] * vertex_x[i] - vertex_nx[i] * vertex_y[i]) - (edge_vertex1_x[j] * vertex_ny[i] - edge_vertex1_y[j] * vertex_nx[i])) / denoms;
            if (mm >= 0 && mm <= 1) {
            if (abs(ll) < min_dist[i]) {
                    min_dist[i] = abs(ll);
                }
            }
        }
    }

  else if (bubble_id[i] != edge_bubble_id[j] && BoundingBoxContainsData(BottomLeftQuadrant, vertex_x[i], vertex_y[i], edge_vertex1_x[j], edge_vertex1_y[j]/*, edge_vertex2_x[j], edge_vertex2_y[j]*/)) {
        denoms = ee_x[j] * vertex_ny[i] - ee_y[j] * vertex_nx[i];
        if (denoms != 0) {
            ll = ((ee_y[j] * vertex_x[i] - ee_x[j] * vertex_y[i]) - (edge_vertex1_x[j] * ee_y[j] - edge_vertex1_y[j] * ee_x[j])) / denoms;
            mm = ((vertex_ny[i] * vertex_x[i] - vertex_nx[i] * vertex_y[i]) - (edge_vertex1_x[j] * vertex_ny[i] - edge_vertex1_y[j] * vertex_nx[i])) / denoms;
            if (mm >= 0 && mm <= 1) {
            if (abs(ll) < min_dist[i]) {
                    min_dist[i] = abs(ll);
                }
            }
        }
    }


    else if (bubble_id[i] != edge_bubble_id[j] && BoundingBoxContainsData(BottomRightQuadrant, vertex_x[i], vertex_y[i], edge_vertex1_x[j], edge_vertex1_y[j]/*, edge_vertex2_x[j], edge_vertex2_y[j]*/)) {
        denoms = ee_x[j] * vertex_ny[i] - ee_y[j] * vertex_nx[i];
        if (denoms != 0) {
            ll = ((ee_y[j] * vertex_x[i] - ee_x[j] * vertex_y[i]) - (edge_vertex1_x[j] * ee_y[j] - edge_vertex1_y[j] * ee_x[j])) / denoms;
            mm = ((vertex_ny[i] * vertex_x[i] - vertex_nx[i] * vertex_y[i]) - (edge_vertex1_x[j] * vertex_ny[i] - edge_vertex1_y[j] * vertex_nx[i])) / denoms;
            if (mm >= 0 && mm <= 1) {
            if (abs(ll) < min_dist[i]) {
                    min_dist[i] = abs(ll);
                }
            }
        }
    }
   else if (bubble_id[i] != edge_bubble_id[j] && BoundingBoxContainsData(TopMidQuadrant, vertex_x[i], vertex_y[i], edge_vertex1_x[j], edge_vertex1_y[j])) {
        denoms = ee_x[j] * vertex_ny[i] - ee_y[j] * vertex_nx[i];
        if (denoms != 0) {
            ll = ((ee_y[j] * vertex_x[i] - ee_x[j] * vertex_y[i]) - (edge_vertex1_x[j] * ee_y[j] - edge_vertex1_y[j] * ee_x[j])) / denoms;
            mm = ((vertex_ny[i] * vertex_x[i] - vertex_nx[i] * vertex_y[i]) - (edge_vertex1_x[j] * vertex_ny[i] - edge_vertex1_y[j] * vertex_nx[i])) / denoms;
            if (mm >= 0 && mm <= 1) {
            if (abs(ll) < min_dist[i]) {
                    min_dist[i] = abs(ll);
                }
            }
        }
    }

    else if (bubble_id[i] != edge_bubble_id[j] && BoundingBoxContainsData(LeftMidQuadrant, vertex_x[i], vertex_y[i], edge_vertex1_x[j], edge_vertex1_y[j])) {
        denoms = ee_x[j] * vertex_ny[i] - ee_y[j] * vertex_nx[i];
        if (denoms != 0) {
            ll = ((ee_y[j] * vertex_x[i] - ee_x[j] * vertex_y[i]) - (edge_vertex1_x[j] * ee_y[j] - edge_vertex1_y[j] * ee_x[j])) / denoms;
            mm = ((vertex_ny[i] * vertex_x[i] - vertex_nx[i] * vertex_y[i]) - (edge_vertex1_x[j] * vertex_ny[i] - edge_vertex1_y[j] * vertex_nx[i])) / denoms;
            if (mm >= 0 && mm <= 1) {
            if (abs(ll) < min_dist[i]) {
                    min_dist[i] = abs(ll);
                }
            }
        }
    }

    else if (bubble_id[i] != edge_bubble_id[j] && BoundingBoxContainsData(RightMidQuadrant, vertex_x[i], vertex_y[i], edge_vertex1_x[j], edge_vertex1_y[j])) {
        denoms = ee_x[j] * vertex_ny[i] - ee_y[j] * vertex_nx[i];
        if (denoms != 0) {
            ll = ((ee_y[j] * vertex_x[i] - ee_x[j] * vertex_y[i]) - (edge_vertex1_x[j] * ee_y[j] - edge_vertex1_y[j] * ee_x[j])) / denoms;
            mm = ((vertex_ny[i] * vertex_x[i] - vertex_nx[i] * vertex_y[i]) - (edge_vertex1_x[j] * vertex_ny[i] - edge_vertex1_y[j] * vertex_nx[i])) / denoms;
            if (mm >= 0 && mm <= 1) {
            if (abs(ll) < min_dist[i]) {
                    min_dist[i] = abs(ll);
                }
            }
        }
    }

    else if (bubble_id[i] != edge_bubble_id[j] && BoundingBoxContainsData(BottomMidQuadrant, vertex_x[i], vertex_y[i], edge_vertex1_x[j], edge_vertex1_y[j])) {
        denoms = ee_x[j] * vertex_ny[i] - ee_y[j] * vertex_nx[i];
        if (denoms != 0) {
            ll = ((ee_y[j] * vertex_x[i] - ee_x[j] * vertex_y[i]) - (edge_vertex1_x[j] * ee_y[j] - edge_vertex1_y[j] * ee_x[j])) / denoms;
            mm = ((vertex_ny[i] * vertex_x[i] - vertex_nx[i] * vertex_y[i]) - (edge_vertex1_x[j] * vertex_ny[i] - edge_vertex1_y[j] * vertex_nx[i])) / denoms;
            if (mm >= 0 && mm <= 1) {
            if (abs(ll) < min_dist[i]) {
                    min_dist[i] = abs(ll);
                }
            }
        }
    }


    else if(bubble_id[i]!=edge_bubble_id[j]){
        denoms = ee_x[j] * vertex_ny[i] - ee_y[j] * vertex_nx[i];
        if (denoms != 0) {
            ll = ((ee_y[j] * vertex_x[i] - ee_x[j] * vertex_y[i]) - (edge_vertex1_x[j] * ee_y[j] - edge_vertex1_y[j] * ee_x[j])) / denoms;
            mm = ((vertex_ny[i] * vertex_x[i] - vertex_nx[i] * vertex_y[i]) - (edge_vertex1_x[j] * vertex_ny[i] - edge_vertex1_y[j] * vertex_nx[i])) / denoms;
            if (mm >= 0 && mm <= 1) {
            if (abs(ll) < min_dist[i]) {
                    min_dist[i] = abs(ll);
                }
            }
        }
    }

}


}

print_mininum_distance();

   
}


void Bubble_Optimiser::mininum_distance(double vertex_x, double vertex_y, double  nx, double ny, double evx, double evy, double ee_x, double ee_y, double min){
     mindist=min;
    double denoms=ee_x*ny-ee_y*nx;
    if(denoms!=0){
   double  ll = ((ee_y*vertex_x-ee_x*vertex_y) - (evx*ee_y-evy*ee_x) ) / denoms;
   double  mm = ((ny*vertex_x-nx*vertex_y) - (evx*ny-evy*nx) ) / denoms;
    if(mm>=0 && mm<=1){
        if(abs(ll)<mindist){
            mindist=abs(ll);
            minimum=mindist;
        }
    }

    }
}

void Bubble_Optimiser::calc_mindist(){

double ll, mm, denoms;
    for(int i=1;i<=number;i++){
         min_dist[i]=4.0;
        for(int j=1;j<=edge_number;j++){
            if(bubble_id[i]!=edge_bubble_id[j]){
                denoms=ee_x[j]*vertex_ny[i]-ee_y[j]*vertex_nx[i];
            if(denoms!=0){
                 ll = ((ee_y[j]*vertex_x[i]-ee_x[j]*vertex_y[i]) - (edge_vertex1_x[j]*ee_y[j]-edge_vertex1_y[j]*ee_x[j]) ) / denoms;
                 mm = ((vertex_ny[i]*vertex_x[i]-vertex_nx[i]*vertex_y[i]) - (edge_vertex1_x[j]*vertex_ny[i]-edge_vertex1_y[j]*vertex_nx[i]) ) / denoms;
                if(mm>=0 && mm<=1){
                    if(abs(ll)<min_dist[i]){
                        min_dist[i]=abs(ll);
                    }

                }

                }
            }

        }
//cout<<vertex_x[i]<<" "<<vertex_y[i]<<" "<<min_dist[i]<<endl;
    }

print_mininum_distance();

}


void Bubble_Optimiser::simple_spatial_partition(double x0, double y0, double x1, double y1){

   // BoundingBox box=this-> boundingBox;

    double xmid= (x0 + x1)/2.0;
    double ymid= (y0 + y1)/2.0;

    TopLeftQuadrant=MakeBoundingBox(x0, y0, xmid, ymid);
    TopRightQuadrant=MakeBoundingBox(xmid, y0, x1, ymid);
    BottomLeftQuadrant=MakeBoundingBox(x0,ymid, xmid, y1);
    BottomRightQuadrant=MakeBoundingBox(xmid, ymid, x1, y1);

}


void Bubble_Optimiser::overlapping_spatial_partition(double x0, double y0, double x1, double y1){

    double xmid = (x0 + x1) / 2.0;
        double xquart1 = (x0 + xmid) / 2.0;
        double xquart1b = (x0 + xquart1) / 2.0;
        double xquart1c= (xquart1+xmid) / 2.0;
        double xquart2 = (xmid + x1) / 2.0;
        double xquart2b = (xmid + xquart2) / 2.0;
        double xquart2c = (xquart2 + x1) / 2.0;
        double ymid = (y0 + y1) / 2.0;
        double yquart1 = (y0 + ymid) / 2.0; // first quarter along y axis
        double yquart1b = (y0 + yquart1) / 2.0; // first quarter along y axis
        double yquart1c = (yquart1+ymid) / 2.0; // first quarter along y axis
        double yquart2 = (ymid + y1) / 2.0; // second quarter along y axis
        double yquart2b = (yquart2 + ymid) / 2.0;
        double yquart2c = (yquart2 + y1) / 2.0;

        //creating 9 overlapping bounding boxescdcd
       TopLeftQuadrant = MakeBoundingBox(x0, y0, xmid, ymid); // left top quadrant bounding box
        TopMidQuadrant = MakeBoundingBox(xquart1, y0, xquart2, ymid); //middle top quadrant bounding box
        TopRightQuadrant = MakeBoundingBox(xmid, y0, x1, ymid); //right top quadrant bounding box
        LeftMidQuadrant = MakeBoundingBox(x0, yquart1, xmid, yquart2); //left middle quadrant bounding box
        MidMidQuadrant = MakeBoundingBox(xquart1, yquart1, xquart2, yquart2); //Central middle quadrant bounding box
        RightMidQuadrant = MakeBoundingBox(xmid, yquart1, x1, yquart2); //Right middle quadrant bounding box
        BottomLeftQuadrant = MakeBoundingBox(x0, ymid, xmid, y1);
        BottomMidQuadrant = MakeBoundingBox(xquart1, ymid, xquart2, y1);
        BottomRightQuadrant = MakeBoundingBox(xmid, ymid, x1, y1);

        box1 = MakeBoundingBox(x0, y0, xquart1, yquart1); // left top quadrant bounding box
        box2= MakeBoundingBox(xquart1b, y0, xquart1c, yquart1); //middle top quadrant bounding box
        box3= MakeBoundingBox(xquart1, y0, xmid, yquart1); //right top quadrant bounding box
        box4= MakeBoundingBox(xquart1c, y0, xquart2b, yquart1); //left middle quadrant bounding box
        box5= MakeBoundingBox(xmid, y0, xquart2, yquart1); //Central middle quadrant bounding box
        box6= MakeBoundingBox(xquart2b, y0, xquart2c, yquart1); //Right middle quadrant bounding box
        box7 = MakeBoundingBox(xquart2, y0, x1, yquart1);
        box8 = MakeBoundingBox(x0, yquart1b, xquart1, yquart1c);
        box9= MakeBoundingBox(xquart1b, yquart1b, xquart1c, yquart1c);
        box10= MakeBoundingBox(xquart1, yquart1b, xmid, yquart1c);
        box11 = MakeBoundingBox(xquart1c, yquart1b, xquart2b, yquart1c); // left top quadrant bounding box
        box12= MakeBoundingBox(xmid, yquart1b, xquart1, yquart1c); //middle top quadrant bounding box
        box13= MakeBoundingBox(xquart2b, yquart1b, xquart2c, yquart1c); //right top quadrant bounding box
        box14= MakeBoundingBox(xquart2, yquart1b, x1, yquart1c); //left middle quadrant bounding box
        box15= MakeBoundingBox(x0, yquart1, xquart1, ymid); //Central middle quadrant bounding box
        box16= MakeBoundingBox(xquart1b, yquart1, xquart1c, ymid); //Right middle quadrant bounding box
        box17 = MakeBoundingBox(xquart1, yquart1, xmid, ymid);
        box18 = MakeBoundingBox(xquart1c, yquart1, xquart2b, ymid);
        box19= MakeBoundingBox(xmid, yquart1, xquart2, ymid);
        box20= MakeBoundingBox(xquart2b, yquart1, xquart2c, ymid);
        box21 = MakeBoundingBox(xquart2, yquart1, x1, ymid); // left top quadrant bounding box
        box22= MakeBoundingBox(x0, yquart1c, xquart1, yquart2b); //middle top quadrant bounding box
        box23= MakeBoundingBox(xquart1b, yquart1c, xquart1c, yquart2b); //right top quadrant bounding box
        box24= MakeBoundingBox(xquart1, yquart1c, xmid, yquart2b); //left middle quadrant bounding box
        box25= MakeBoundingBox(xquart1c, yquart1c, xquart2b, yquart2b); //Central middle quadrant bounding box
        box26= MakeBoundingBox(xmid, yquart1c, xquart2, yquart2b); //Right middle quadrant bounding box
        box27 = MakeBoundingBox(xquart2b, yquart1c, xquart2c, yquart2b);
        box28 = MakeBoundingBox(xquart2, yquart1c, x1, yquart2b);
        box29= MakeBoundingBox(x0, ymid, xquart1, yquart2);
        box30= MakeBoundingBox(xquart1b, ymid, xquart1c, yquart2);
        box31 = MakeBoundingBox(xquart1, ymid, xmid, yquart2); // left top quadrant bounding box
        box32= MakeBoundingBox(xquart1c, ymid, xquart2b, yquart2); //middle top quadrant bounding box
        box33= MakeBoundingBox(xmid, ymid, xquart2, yquart2); //right top quadrant bounding box
        box34= MakeBoundingBox(xquart2b, ymid, xquart2c, yquart2); //left middle quadrant bounding box
        box35= MakeBoundingBox(xquart2, ymid, x1, yquart2); //Central middle quadrant bounding box
        box36= MakeBoundingBox(x0, yquart2b, xquart1, yquart2c); //Right middle quadrant bounding box
        box37 = MakeBoundingBox(xquart1b, yquart2b, xquart1c, yquart2c);
        box38 = MakeBoundingBox(xquart1, yquart2b, xmid, yquart2c);
        box39= MakeBoundingBox(xquart1c, yquart2b, xquart2b, yquart2c);
        box40= MakeBoundingBox(xmid, yquart2b, xquart2, yquart2c);
        box41 = MakeBoundingBox(xquart2b, yquart2b, xquart2c, yquart2c); // left top quadrant bounding box
        box42= MakeBoundingBox(xquart2, yquart2b, x1, yquart2c); //middle top quadrant bounding box
        box43= MakeBoundingBox(x0, yquart2, xquart1, y1); //right top quadrant bounding box
        box44= MakeBoundingBox(xquart1b, yquart2, xquart1c, y1); //left middle quadrant bounding box
        box45= MakeBoundingBox(xquart1, yquart2, xmid, y1); //Central middle quadrant bounding box
        box46= MakeBoundingBox(xquart1c, yquart2, xquart2b, y1); //Right middle quadrant bounding box
        box47 = MakeBoundingBox(xmid, yquart2, xquart2, y1);
        box48 = MakeBoundingBox(xquart2b, yquart2, xquart2c, y1);
        box49= MakeBoundingBox(xquart2, yquart2, x1, y1);




}

bool Bubble_Optimiser::BoundingBoxContainsVertices(BoundingBox boundary,double vertex_x, double vertex_y){

    bool contains_vertex_x = boundary.x0 <= vertex_x && vertex_x <=boundary.x1;
    bool contains_vertex_y = boundary.y0 >= vertex_y && vertex_y >= boundary.y1;

    return contains_vertex_x && contains_vertex_y;
}

bool Bubble_Optimiser::BoundingBoxContainsEdges(BoundingBox boundary, double e_vertex1_x, double e_vertex1_y/*,double e_vertex2_x,double e_vertex2_y*/){

       bool contains_e_vertex1_x = boundary.x0 <= e_vertex1_x && e_vertex1_x <= boundary.x1;
       bool contains_e_vertex1_y = boundary.y0 >=e_vertex1_y && e_vertex1_y >= boundary.y1;
       //bool contains_e_vertex2_x = boundary.x0 <= e_vertex2_x && e_vertex2_x <= boundary.x1;
      //bool contains_e_vertex2_y = boundary.y0 >= e_vertex2_y && e_vertex2_y >= boundary.y1;


       return contains_e_vertex1_x && contains_e_vertex1_y; /* && contains_e_vertex2_x && contains_e_vertex2_y;*/


}
bool Bubble_Optimiser::BoundingBoxContainsData(BoundingBox boundary,double vertex_x, double vertex_y, double e_vertex1_x, double e_vertex1_y/*,double e_vertex2_x,double e_vertex2_y*/){

   
    bool contains_vertex_x = boundary.x0 <= vertex_x && vertex_x <=boundary.x1;
       bool contains_vertex_y = boundary.y0 >= vertex_y && vertex_y >= boundary.y1;
       bool contains_e_vertex1_x = boundary.x0 <= e_vertex1_x && e_vertex1_x <= boundary.x1;
       bool contains_e_vertex1_y = boundary.y0 >=e_vertex1_y && e_vertex1_y >= boundary.y1;
       //bool contains_e_vertex2_x = boundary.x0 <= e_vertex2_x && e_vertex2_x <= boundary.x1;
      //bool contains_e_vertex2_y = boundary.y0 >= e_vertex2_y && e_vertex2_y >= boundary.y1;


       return contains_vertex_x && contains_vertex_y && contains_e_vertex1_x && contains_e_vertex1_y; /* && contains_e_vertex2_x && contains_e_vertex2_y;*/


}


void Bubble_Optimiser::count_boundary_box_data(){
      b1_v_counter=0;  b2_v_counter=0; b3_v_counter=0; b4_v_counter=0;
      b1_e_counter=0;  b2_e_counter=0; b3_e_counter=0; b4_e_counter=0;
for(int i=1;i<=number;i++){
      if(BoundingBoxContainsVertices(TopLeftQuadrant, vertex_x[i], vertex_y[i])){
         b1_v_counter++;
      }
      else if(BoundingBoxContainsVertices(TopRightQuadrant, vertex_x[i], vertex_y[i])){
          b2_v_counter++;
      }else if(BoundingBoxContainsVertices(BottomLeftQuadrant, vertex_x[i], vertex_y[i])){
          b3_v_counter++;
      }else if(BoundingBoxContainsVertices(BottomRightQuadrant, vertex_x[i], vertex_y[i])){
          b4_v_counter++;
      }
}

for(int i=1;i<=edge_number;i++){
      if(BoundingBoxContainsEdges(TopLeftQuadrant, edge_vertex1_x[i], edge_vertex1_y[i])){
         b1_e_counter++;
      }
      else if(BoundingBoxContainsEdges(TopRightQuadrant, edge_vertex1_x[i], edge_vertex1_y[i])){
          b2_e_counter++;
      }else if(BoundingBoxContainsEdges(BottomLeftQuadrant, edge_vertex1_x[i], edge_vertex1_y[i])){
          b3_e_counter++;
      }else if(BoundingBoxContainsEdges(BottomRightQuadrant, edge_vertex1_x[i], edge_vertex1_y[i])){
          b4_e_counter++;
      }
}

}

void Bubble_Optimiser::assign_boundary_box_data(){
b1_v_counter=0;b2_v_counter=0;b3_v_counter=0;b4_v_counter=0;
b1_e_counter=0;b2_e_counter=0;b3_e_counter=0;b4_e_counter=0;

//cout<<"get here1"<<endl;
    for(int i=1;i<=number;i++){
          if(BoundingBoxContainsVertices(TopLeftQuadrant, vertex_x[i], vertex_y[i])){
             b1_v_counter++;
            b1_vertex_id[b1_v_counter]=vertex_id[i];
            b1_vertex_x[b1_v_counter]=vertex_x[i];
            b1_vertex_y[b1_v_counter]=vertex_y[i];
            b1_nx[b1_v_counter]=vertex_nx[i];
            b1_ny[b1_v_counter]=vertex_ny[i];
            b1_vert_b_id[b1_v_counter]=bubble_id[i];
                     //cout << "vertex_x[" << b1_v_counter <<"]="<< " " << b1_vertex_x[b1_v_counter] << endl;
          }
          else if(BoundingBoxContainsVertices(TopRightQuadrant, vertex_x[i], vertex_y[i])){
               b2_v_counter++;
              b2_vertex_id[b2_v_counter]=vertex_id[i];
              b2_vertex_x[b2_v_counter]=vertex_x[i];
              b2_vertex_y[b2_v_counter]=vertex_y[i];
              b2_nx[b2_v_counter]=vertex_nx[i];
              b2_ny[b2_v_counter]=vertex_ny[i];
              b2_vert_b_id[b2_v_counter]=bubble_id[i];

          }else if(BoundingBoxContainsVertices(BottomLeftQuadrant, vertex_x[i], vertex_y[i])){
              b3_v_counter++;
             b3_vertex_id[b3_v_counter]=vertex_id[i];
             b3_vertex_x[b3_v_counter]=vertex_x[i];
             b3_vertex_y[b3_v_counter]=vertex_y[i];
             b3_nx[b3_v_counter]=vertex_nx[i];
             b3_ny[b3_v_counter]=vertex_ny[i];
             b3_vert_b_id[b3_v_counter]=bubble_id[i];

          }else if(BoundingBoxContainsVertices(BottomRightQuadrant, vertex_x[i], vertex_y[i])){
              b4_v_counter++;
             b4_vertex_id[b4_v_counter]=vertex_id[i];
             b4_vertex_x[b4_v_counter]=vertex_x[i];
             b4_vertex_y[b4_v_counter]=vertex_y[i];
             b4_nx[b4_v_counter]=vertex_nx[i];
             b4_ny[b4_v_counter]=vertex_ny[i];
             b4_vert_b_id[b4_v_counter]=bubble_id[i];

          }
    }

    for(int i=1;i<=edge_number;i++){
          if(BoundingBoxContainsEdges(TopLeftQuadrant, edge_vertex1_x[i], edge_vertex1_y[i])){
             b1_e_counter++;
            b1_evertex1_x[b1_e_counter]=edge_vertex1_x[i];
            b1_evertex1_y[b1_e_counter]=edge_vertex1_y[i];
            b1_eex[b1_e_counter]=ee_x[i];
            b1_eey[b1_e_counter]=ee_y[i];
            b1_edge_b_id[b1_e_counter]=edge_bubble_id[i];
                     //cout << "vertex_x[" << b1_v_counter <<"]="<< " " << b1_vertex_x[b1_v_counter] << endl;
          }
          else if(BoundingBoxContainsEdges(TopRightQuadrant, edge_vertex1_x[i], edge_vertex1_y[i])){
               b2_e_counter++;
               b2_evertex1_x[b2_e_counter]=edge_vertex1_x[i];
               b2_evertex1_y[b2_e_counter]=edge_vertex1_y[i];
               b2_eex[b2_e_counter]=ee_x[i];
               b2_eey[b2_e_counter]=ee_y[i];
               b2_edge_b_id[b2_e_counter]=edge_bubble_id[i];

          }else if(BoundingBoxContainsEdges(BottomLeftQuadrant, edge_vertex1_x[i], edge_vertex1_y[i])){
              b3_e_counter++;
              b3_evertex1_x[b3_e_counter]=edge_vertex1_x[i];
              b3_evertex1_y[b3_e_counter]=edge_vertex1_y[i];
              b3_eex[b3_e_counter]=ee_x[i];
              b3_eey[b3_e_counter]=ee_y[i];
              b3_edge_b_id[b3_e_counter]=edge_bubble_id[i];

          }else if(BoundingBoxContainsEdges(BottomRightQuadrant, edge_vertex1_x[i], edge_vertex1_y[i])){
              b4_e_counter++;
              b4_evertex1_x[b4_e_counter]=edge_vertex1_x[i];
              b4_evertex1_y[b4_e_counter]=edge_vertex1_y[i];
              b4_eex[b4_e_counter]=ee_x[i];
              b4_eey[b4_e_counter]=ee_y[i];
              b4_edge_b_id[b4_e_counter]=edge_bubble_id[i];

          }
    }
//cout<<"get here2"<<endl;
}



void Bubble_Optimiser::print_mininum_distance() {
    for (int i = 1; i <= number; i++) {
        cout << "vertex[" << i << "].mindistio:=" << " " << min_dist[i] << endl;
    }

    //ofstream outfile;
    //outfile.open("../input_output_files/mininum_distance.dat");
    //outfile<<"mindistio:=\n";
    //for(int i=1;i<=number;i++){
    //outfile<<"vertex["<<i<<"].mindistio:="<<" "<<min_dist[i];
    //}
    //outfile.close();
}

double* Bubble_Optimiser::sort(double*array,int size){
    double temp_value=0.0;

    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(array[j]>array[j+1]){
                temp_value=array[j];
                array[j]=array[j+1];
                array[j+1]=temp_value;
            }
        }
    }

    //bounding_values[0]=array[1];
    //bounding_values[1]=array[size];

    return array;


}




Bubble_Optimiser::~Bubble_Optimiser(){

delete [] vertex_id; delete [] vertex_x;delete [] vertex_y; delete [] bubble_id;
delete [] vertex_nx; delete [] vertex_ny; delete [] vertex_id;
    delete [] edge_id;
        delete [] edge_vertex1_id;
        delete [] edge_vertex2_id;
        delete [] edge_vertex1_x;
        delete [] edge_vertex1_y;
        delete [] edge_vertex2_x;
        delete [] edge_vertex2_y;
        delete [] ee_x;
        delete [] ee_y;
        delete [] edge_bubble_id;
    delete [] min_dist;
    delete[] b1_vertex_id; delete [] b2_vertex_id;  delete [] b3_vertex_id;delete [] b4_vertex_id; delete [] out_vertex_id;
   delete[] b1_vertex_x; delete [] b2_vertex_x;  delete [] b3_vertex_x;delete [] b4_vertex_x; delete [] out_vertex_x;
       delete [] b1_vertex_y;delete [] b2_vertex_y;  delete []b3_vertex_y;delete [] b4_vertex_y; delete [] out_vertex_y;
       delete[] b1_nx;delete [] b2_nx;  delete [] b3_nx;delete [] b4_nx; delete [] out_nx;
       delete [] b1_ny;delete [] b2_ny;  delete []b3_ny;delete [] b4_ny; delete [] out_ny;
       delete[] b1_evertex1_x;delete [] b2_evertex1_x;  delete [] b3_evertex1_x;delete [] b4_evertex1_x; delete [] out_evertex1_x;
       delete [] b1_evertex1_y;delete [] b2_evertex1_y;  delete []b3_evertex1_y;delete [] b4_evertex1_y; delete [] out_evertex1_y;
      delete[] b1_eex;delete [] b2_eex;  delete [] b3_eex;delete [] b4_eex; delete [] out_eex;
      delete[] b1_eey;delete [] b2_eey;  delete [] b3_eey;delete [] b4_eey; delete [] out_eey;

/*for(int i=0;i<number;i++){
delete [] vertex_info[i];
}
delete [] vertex_info;

for(int i=0;i<number;i++){
delete [] edge_info[i];
}
delete [] edge_info;*/


}


