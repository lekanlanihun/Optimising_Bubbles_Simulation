#include "../Bubble_Simulator_Optimiser/program_files/bubble_optimiser.h"
using namespace std;

int main()
{
int root_seed=674777;
srand(root_seed);
//cout<<"root seed="<<" "<<root_seed<<endl;
Bubble_Optimiser *b_optimiwser;
b_optimiwser=new Bubble_Optimiser();
clock_t begin=clock();
//b_optimiwser->calc_minimum_distance();
//b_optimiwser->calc_min_distance();


//time_t start,end;
//time (&start);
//b_optimiwser->calc_mindist();
//time (&end);
//double dif = difftime (end,start);
//printf ("Elasped time is %.2lf seconds.", dif );
clock_t end=clock();
double time_elapsed=double(end-begin)/CLOCKS_PER_SEC;
//cout<<"tme elapsed="<<" "<<time_elapsed<<endl;

return 0;

}
