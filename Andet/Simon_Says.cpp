#include <iostream>
#include <stdio.h>
#include <string>


int main()
{
  int N;
  char M[100];
  scanf("%d \n", &N);

  for(int i = 0; i < N; i++)
  {
    fgets(M, 100, stdin);
    std::string M1(M);
    if (M1.substr(0, 10) == "Simon says")
    {
      std::string M2 = M1.erase(0, 11); //sletter alt på nær "simon says"
      std::cout << M2 << '\n';
    }
  }
  return 0;
}


/*
#include <string>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string input = "1 1
Four score and seven years ago
	2 2 1
	our fathers brough forth on this continent a new nation,
	5 1 3 2 5 4
	conceived in liberty and dedicated to the proposition
	10 5 10 8 1 3 6 4 7 2 9
	that all men are created equal.
	0"
	vector<string> messages;
	vector<string> keys;
	string line;
	int count = 0;
	while (getline(cin, line))
	{
		if(count > 4)
	    {
	    	return 0;
	    }
		if(count%2)
		{
			messages.push_back(line);
		}
		else
		{
			keys.push_back(line);
		}
   		count++;
	}


	//vector< vector<char> > multi = { { 'a', 'b' }, { 'c', 'd' } };

	cout << messages[0];
	cout << keys[0];
}
*/
