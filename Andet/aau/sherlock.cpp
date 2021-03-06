#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

int T, n, tmp;

vector<string> res;

class tree
{
public:
  vector<int> t;
  int members, total;

  void print(int i)
  {
    std::cout << t[i+1] << '\n';
  }

  void init(int size)
  {
    t.clear();
    members = size;
    int height = ceil(log2(size)); //Højden af træet
    total = 2*pow(2, height) - 1; //max størrelsen af træet
    t.resize(total);
  }


  void update(int i, int pos, int val, int left, int right) //back end    input er (1, pos, val, 0, size-1)
  {
    if(pos == left && pos == right)
    {
      t[i] = val;
      return;
    }
    else if(pos > right || pos < left)
    {
      return;
    }
    else
    {
      update((i<<1), pos, val, left, (left+right)/2); //go left, index double
      update((i<<1)+1, pos, val, (left+right)/2+1, right); //go right, index double+1
      t[i] = t[(i<<1)] + t[(i<<1)+1];
    }
  }

  void insert(int pos, int val) //front end
  {
    return update(1, pos, val, 0, members-1);
  }

  int resl(int i, int start, int end, int left, int right)
  {
    if(left >= start && right <= end) // Jeg har svaret der hvor jeg står
    {
      return t[i];
    }
    else if(left > end || right < start) //stop denne gren med det samme!
    {
      return 0;
    }
    else //Prøv begge veje
    {
      int val1,val2;
      //resultatet af begge grene
      val1 = resl((i<<1), start, end, left, (left+right)/2);
      val2 = resl((i<<1)+1, start, end, (left+right)/2+1, right);
      return (val1+val2);
    }
  }

  int result(int start, int end)
  {
    return resl(1, start, end, 0, members-1);
  }
};

int main()
{
  tree l;
  std::cin >> T;
  for(int tc=0;tc<T;tc++)
  {
    std::cin >> n;
    if(n==1) //That is the only number, so yes...
    {
      for(int i=0;i<n;i++) //Still need to take the input...
      {
        std::cin >> tmp;
      }
      res.push_back("YES");
    }

    else
    {
      l.init(n); //n-many integers
      for(int i=0;i<n;i++) //Inserting all the elements
      {
        std::cin >> tmp;
        l.insert(i, tmp);
      }
      if(l.result(1,n-1) == 0 || l.result(0,n-2) == 0) //all but ends are 0
      {
        res.push_back("YES");
      }
      else if(n == 2)
      {
        res.push_back("NO");
      }
      else
      {
        for(int i=1;i<n-1;i++) //testing if a place exist
        {
          //std::cout << "Prøver plads " <<i<< '\n';
          if(l.result(0,i-1) == l.result(i+1, n-1))
          {
            res.push_back("YES");
            break;
          }
          if(i>=n-2)
          {
            res.push_back("NO");
            break;
          }
        }

      }
      //End of this test case
    }
  }
  for(int i=0;i<res.size();i++)
  {
    std::cout << res[i] << '\n';
  }
  return 0;
}


/*
10
100
75 26 45 72 81 47 29 97 2 75 25 82 84 17 56 32 2 28 37 57 39 18 11 79 6 40 68 68 16 40 63 93 49 91 10 55 68 31 80 57 18 34 28 76 55 21 80 22 45 11 67 67 74 91 4 35 34 65 80 21 95 1 52 25 31 2 53 96 22 89 99 7 66 32 2 68 33 75 92 84 10 94 28 54 12 9 80 43 21 51 92 20 97 7 25 67 17 38 100 86
100
83 20 6 81 58 59 53 2 54 62 25 35 79 64 27 49 32 95 100 20 58 39 92 30 67 89 58 81 100 66 73 29 75 81 70 55 18 28 7 35 98 52 30 11 69 48 84 54 13 14 15 86 34 82 92 26 8 53 62 57 50 31 61 85 88 5 80 64 90 52 47 43 40 93 69 70 16 43 7 25 99 12 63 99 71 76 55 17 90 43 27 20 42 84 39 96 75 1 58 49
100
185 170 208 216 236 155 88 206 211 209 84 99 130 245 232 125 127 232 187 140 92 213 221 231 129 197 221 168 95 186 136 180 94 125 150 244 249 248 140 207 125 84 123 85 100 175 67 116 107 143 158 75 165 172 115 134 175 123 115 123 159 181 63 176 158 109 67 154 126 141 111 95 138 161 71 118 151 189 126 109 194 176 159 151 189 71 95 133 154 157 109 78 101 174 169 152 94 193 176 137
100
9 79 79 61 14 23 44 100 94 47 20 52 63 74 29 84 30 22 65 46 85 91 53 5 10 53 56 43 94 54 97 75 31 74 20 37 95 45 54 73 6 65 24 52 31 29 53 31 92 27 13 81 38 63 58 58 66 1 95 74 7 51 68 78 9 4 7 8 92 99 50 6 99 22 98 15 81 67 82 37 19 11 26 44 88 26 44 2 88 44 55 21 89 46 31 16 45 54 34 22
100
83 42 26 41 86 1 61 32 61 68 3 76 58 72 66 59 24 36 41 54 18 25 95 49 25 56 50 78 11 83 84 90 59 45 45 68 22 1 55 72 85 75 12 65 21 20 96 16 57 49 48 7 35 91 84 82 68 98 74 41 39 93 17 3 34 68 71 65 21 83 3 66 49 32 76 88 38 64 36 73 70 22 74 32 60 55 48 80 61 89 54 20 34 33 45 90 40 12 17 35
100
31 59 49 55 48 46 47 33 47 25 49 34 52 35 46 55 44 53 56 34 38 36 41 49 55 38 42 20 22 33 43 51 28 44 45 25 19 19 18 32 27 33 15 13 29 29 30 18 27 12 15 19 14 28 18 22 26 18 28 21 27 23 24 17 32 21 30 34 27 15 30 31 31 14 19 26 18 15 29 23 16 12 31 23 30 17 31 20 32 28 23 29 18 27 31 16 12 15 28 28
100
31 27 35 21 33 15 13 17 27 29 23 31 31 30 25 26 30 34 19 25 28 22 33 19 28 22 20 12 22 26 27 16 22 34 25 13 14 24 34 18 15 21 16 27 13 13 20 14 33 27 34 14 30 33 21 25 18 14 16 29 29 13 20 26 16 23 23 28 16 32 29 23 33 15 15 26 34 31 14 31 12 17 35 113 149 134 84 100 139 107 97 98 73 74 83 104 143 141 130 151
100
243 146 249 194 131 284 229 161 287 134 321 135 287 215 336 218 155 131 142 153 226 307 322 317 328 142 256 136 163 195 132 245 313 233 249 193 243 27 80 71 197 173 144 86 111 100 115 79 142 73 126 111 198 181 72 112 198 151 112 85 184 150 78 108 157 167 107 141 140 70 101 137 178 126 185 131 190 159 175 141 110 99 149 197 82 72 139 114 113 179 161 184 71 107 87 99 172 157 141 176
100
95 98 55 67 98 90 78 95 8 16 100 33 50 12 82 53 97 81 20 27 25 55 40 70 50 78 33 39 19 33 88 99 58 20 22 61 66 22 56 1 77 44 82 66 46 4 9 49 96 27 85 55 13 59 63 39 91 70 60 34 11 74 76 45 77 14 45 43 9 79 37 40 82 53 31 95 17 94 71 65 90 86 93 4 72 93 54 21 32 60 23 82 81 64 36 65 71 94 58 75
100
10 54 29 74 95 16 26 83 64 52 15 40 35 80 62 74 45 12 45 7 54 21 20 11 7 3 13 52 63 51 91 25 74 42 43 81 42 19 30 29 53 57 3 1 40 43 38 71 73 6 89 78 31 78 19 52 56 49 47 61 34 51 18 30 91 93 23 3 63 46 72 6 54 61 31 89 51 28 63 12 99 78 19 36 72 71 95 49 54 67 15 89 25 19 41 83 69 19 15 81

*/
