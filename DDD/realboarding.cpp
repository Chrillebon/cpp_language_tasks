#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

struct PointerComparator {
  bool operator() (int *arg1, int *arg2) {
    return *arg1 > *arg2; //calls your operator
  }
};

/*class segmenttree
{
public:
  segmenttree();*/
  int *start(int[], int);
  //int constructor(int[], int, int, int*, int);
  int getmiddle(int, int);
  void insert(int*, int, int, int, int, int);
  int largest(int*, int, int, int, int, int);
/*private:
};

/*segmenttree::segmenttree()
{
  //do nothing
}*/

int segsize(int length)
{
  length = ceil(log2(length)); //Højden af træet
  length = 2*pow(2, length) - 1; //max størrelsen af træet
  return length;
}

int * /*segmenttree::*/start(int arr[], int length)
{
  int height = ceil(log2(length)); //Højden af træet
  int max = 2*pow(2, height) - 1; //max størrelsen af træet
  int *tree = new int[max]{}; //Laver arrayet
  //segmenttree::constructor(arr, 0, length-1, tree, 0); //Indsætter alle værdier
  return tree; //returnerer
}

/*int segmenttree::constructor(arr[], start, end, *tree, index)
{
  if(start == end) //den har nået enden af en node
  {
    tree[index] = arr[ss]; //Gemmer denne node
    return arr[start]; //Returnerer/går tilbage op ad træet
  }
  int middle = findmiddle(start, end); //Finder midterste værdi
  //gemmer største værdi på mellemnode
  tree[index] = max(constructor(arr[], start, middle, tree, index*2+1),
                constructor(arr[], middle+1, end, tree, index*2+2));
  return tree[index]; //returnerer
}*/

int /*segmenttree::*/getmiddle(int start, int end)
{
  return start+(end-start)/2;
}

void /*segmenttree::*/insert(int *tree, int start, int end, int target, int val, int index)
{
  //std::cout << "Insert: Start: " <<start<<", end: "<<end<<" og target: "<<target<<" samt index: "<<index<< '\n';
  if(target < start || target > end) //Så er vi uden for grænserne
  {
    return;
  }
  tree[index] = max(tree[index], val); //sammenligner den første værdi
  if(end != start)
  {
    int middle = getmiddle(start, end); //Finder den midterste værdi
    insert(tree, start, middle, target, val, 2*index+1); //opdaterer langs venstre
    insert(tree, middle+1, end, target, val, 2*index+2); //opdaterer langs højre
  }
}

int /*segmenttree::*/largest(int *tree, int start, int end, int qstart, int qend, int index)
{
  if(qstart <= start && qend >= end) //Den har findet noget inden for intervallet
  {
    return tree[index];
  }
  if(end < qstart || start > qend) //Den har findet noget uden for intervallet
  {
    return 0;
  }
  int middle = getmiddle(start, end); //Finder midten
  //returnerer største værdi af værdier under den
  return max(largest(tree, middle+1, end, qstart, qend, 2*index+2),
             largest(tree, start, middle, qstart, qend, 2*index+1));
}

int segtop(int *tree, int length)
{
  return tree[getmiddle(0, length)];
}

int main()
{
  int N, r, t;
  std::cin >> N;
  int max = segsize(N);
  int numbers[N];
  fill(&numbers[0],&numbers[N], 0);
  int *tree = /*segmenttree::*/start(numbers, N); //Laver træet
  vector<vector<int>> people(N, vector<int>(2));
  priority_queue<int*, vector<int*>, PointerComparator> move_forward;
  for(int i=0; i<N; i++)
  {
    std::cin >> r >> t;
    people[i][0] = r;
    people[i][1] = t;
    move_forward.push(&people[i][0]);
  }
  int last = 0, change_to = -1;
  for(int i=0; i<N; i++)
  {
    if(last != *move_forward.top())
    {
      change_to++;
      last = *move_forward.top();
    }
    *move_forward.top() = change_to;
    move_forward.pop();
  }
  /*//--------CMD-----------
  for(int i=0; i<N; i++)
  {
    std::cout << people[i][0] <<" og "<<people[i][1]<< '\n';
  }
  //--------CMD-----------*/
  for(int i=0; i<N; i++)
  {
    //std::cout << "couter: " <<people[i][0]<<" og "<<people[i][1]<< '\n';
    /*segmenttree::*/insert(tree, 0, N, people[i][0], people[i][1] + largest(tree, 0, N, 0, people[i][0], 0), 0);
  }
  /*
  //---------CMD---------
  for(int i=0; i<N; i++)
  {
    std::cout << people[i][0] <<" og "<<people[i][1]<< '\n';
  }
  //----------CMD---------
  //int middle = getmiddle(0, segsize(N));
  for(int i=0; i<max; i++)
  {
    std::cout << tree[i] << " ";
  }
  std::cout << '\n';*/
  std::cout << tree[0];
  return 0;
}
