/* datasize1.c */

extern double arr[];

int datasize1(long int elem)
{
  for(long int i=0; i<elem; i++)
  {
    arr[i] *= 3;
  }
  return elem;
}
