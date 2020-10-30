#include <stdio.h>
#ifndef _OPENMP
#include <omp.h>
#endif

void worlding()
{
  int t_id = 0;
  #pragma omp parallel private(t_id)
  {
    #ifdef _OPENMP
    t_id = omp_get_thread_num();
    #endif
    printf("Hello world from %d\n", t_id);
  }   /* end parallel */
  return;
}

int main()
{
  int maxthread = omp_get_max_threads();
  for(int o=1;o<=maxthread;o++)
  {
    omp_set_num_threads(o);
    printf("Testing %d threads!\n", o);
    worlding();
    printf("End of test\n\n");
  }
}
