#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

const vector<string> explode(const string& s, const char& c)
{
	string buff{""};
	vector<string> v;

	for(auto n:s)
	{
		if(n != c) { buff+=n; } else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "")
	{
		v.push_back(buff);
		//std::cout << "Den slutter med: " <<buff<< '\n';
	}

	return v;
}

int anagram(char a[],char b[])
{
	string ab = a;
	string ba = b;
	//std::cout << "Testord er: " <<ab<< " og "<<ba<< '\n';
	int l = ab.size();
	for(int i=0;i<l;i++)
	{
		for (int o=0;o<l;o++)
		{
			//std::cout << "if: " <<a[i]<<" == "<<b[o]<< '\n';
			if(a[i]==b[o])
			{
				a[i] = '_';
				b[o] = '_';
				o+=l;
			}
			//std::cout << "Så har vi tilbage: " <<a<<" og "<<b<< '\n';
		}
	}
	for(int i=0;i<l;i++)
	{
		if(a[i] != '_') return 0;
	}
	a = &ab[0u];
	b = &ba[0u];
	std::cout << "Anagram was: " <<ab<< " og "<<ba<<"---------------------------------------------------------------"<< '\n';
	return 1;
}


int main()
{
  int sum = 0,minus=0;

  //std::vector<std::string> list(15);
  int length=0;

  while(1)
  {
    char mem[5001]{};
    //scanf("%100[a-z ]", &mem);
		cin.getline(mem,sizeof(mem));
		vector<string> list{explode(mem, ' ')};
    //std::cout << "Første: " <<list[0]<< " og anden: "<<list[1]<< '\n';
    for(int i=0;i<list.size();i++)
    {
      for(int o=i+1;o<=list.size();o++)
      {
        //std::cout << "Første: " <<list[0]<< " og anden: "<<list[1]<< '\n';
        if(list[i]==list[o])
        {
          //std::cout << "Det virker!" << '\n';
          minus++;
          i+=16;
          o+=16;
        }
				else if( list[i].size() == list[o].size() )
				{
					char* f = strdup(list[i].c_str());
					char* g = strdup(list[o].c_str());
					if(anagram( f, g ))
					{
						minus++;
	          i+=16;
	          o+=16;
					}
				}
      }
    }
    sum++;
    std::cout << "SUM! " <<sum-minus<< '\n';
  }
	std::cout << "SUM! " <<sum-minus<< '\n';
  return 0;
}
