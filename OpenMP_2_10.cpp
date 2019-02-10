//*****************************************
//	ECE5720
//	off class practise with OpenMP
//	2/10/2019
//	Hongliang Si (hs983@cornell.edu)
//*****************************************

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

static long num_steps = 100000;
double step;
int main()
{
  int num_threads = 1;
  double t_exc, pi, sum[num_threads]={};
  //Start timing:
  t_exc = omp_get_wtime();
  //set step sizes:
  step = 1/(double)num_steps;

  #pragma omp parallel num_threads(num_threads)
  {
    int ID = omp_get_thread_num();
    int i; double x;
    int chunk_size = num_steps/num_threads;
    //Need to update to case when
    //num_steps/num_threads is not integer
    for(i=(chunk_size*ID); i<(num_steps-chunk_size*(num_threads-1-ID));i++)
    { //Dynamic range for each thread depending on chunk_size
      x = (i+0.5)*step;
      sum[ID] = sum[ID] + 4.0/(1.0 + x*x);
    }
    //For debuging use. Commended to improve excute speed.
    //printf("for ID %d, i starts at %d, ends at %d, sum is %f \n", ID,chunk_size*ID,(num_steps-chunk_size*(num_threads-1-ID))-1,sum[ID]);

  }
  for(int i = 0; i < num_threads; i++)
  { //Summing everything togather in Pi.
    pi = pi + sum[i]*step;
  }
  //Stop timing the computation
  t_exc = (omp_get_wtime()-t_exc)*1000;

  printf("pi  is %f\n", pi);
  printf("time used %f ms\n", t_exc);
  printf("Finished\n");
}

//double pooh(int ID, num_threads,double step,sum){
//  int i; double x;
//  chunk_size = num_steps/num_threads;
//  //Need to update to case when
//  //num_steps/num_threads is not integer
//  for(i=0; i<num_steps;i++){
//    x = (i+0.5)*step;
//    sum = sum + 4.0/(1.0 + x*x);
//}

//Unrelevent practise.
//#pragma omp parallel num_threads(4)
//{
//  int ID = omp_get_thread_num();
//  pooh(ID,a)
  //printf("hello(%d)", ID);
  //printf(" world(%d)\n", ID);
//}
