#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

int main()
{
  int N;
  std::string M;

  scanf("%d", &N);

  for(int i = 0; i < N; i++)
  {
    scanf (" %[^\n]%*c", M);
    std::cout << "dette er svaret: " << M << '\n';
    if (M.substr(0, 10) == "Simon says");
    {
      std::string rest = M - M.substr(0, 10)
      std::cout << rest << '\n';
      for (unsigned int i = 0; i < strlen(chars); ++i)
      {
        M.erase (std::remove(str.begin(), str.end(), chars[i]), str.end());
      }
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
