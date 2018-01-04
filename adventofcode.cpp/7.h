//7.h

void explode(const string& s, char* t[20], const char& c)
{
	string buff{""};
	//char v[8][20]{};
  int words=0;

	for(auto n:s)
	{
		if(n != c || n != ',' || n != '-' || n != '>')
		{
			buff+=n;
			int nn = n;
			int cc = c;
			int nc = n == c && buff != "";
			std::cout << "buff: " <<buff<<" og n: "<<nn<<" og c: "<<cc<<" og if-statement: "<<nc<< '\n';
		}
		if(n == c && buff != "")
		{
			std::cout << "test" << '\n';
			t[words] = strdup(buff.c_str());
			buff = "";
			words++;
		}
	}
	if(buff != "")
	{
		t[words] = strdup(buff.c_str());
		//std::cout << "Den slutter med: " <<buff<< '\n';
	}
	//return v;
}

class Towers
{
public:
  Towers();
  string name();
  int relations();
  string relation(int);
  int weight();
private:
  char Name [20];
  int Weight = 17;
  char* names[20]{};
};

Towers::Towers()
{
  std::cout << "Så langt så godt: "<<Name<< '\n';
  char mem1[100];
  //char mem[8][20]{};
  scanf("%s (%u) -> %[a-z ,]", Name, &Weight, &mem1);
  //scanf("%s (%u) -> %s %s %s %s %s %s %s", Name, &Weight, &mem[0], &mem[1], &mem[2], &mem[3], &mem[4], &mem[5], &mem[6]);
	explode(mem1, names, ' ');
  //sørg for at bugteste...
  /*for(int i=0;i<7;i++)
  {
    if(mem[i][0] == '\0')
    {
      break;
    }
    else
    {
      for(int o=0;o<20;o++)
      {
        names[i][o] = mem[i][o];
      }
    }
  }*/

  //scanf("%s", Name);
  //std::cin >> Name >> Weight >> names[0] >> names[1] >> names[2] >> names[3] >> names[4] >> names[5] >> names[6];
  //std::cout << "Name: " <<names[0]<< '\n';
}

string Towers::name()
{
  //std::cout << "den kører denne: " << Name << '\n';
  return Name;
}

int Towers::relations()
{
  for(int i=0;i<8;i++)
  {
    if(names[i][0] == '\0')
    {
      return i;
    }
  }
  //std::cout << "int relations error!!!!!!!!!!!" << '\n';
  return 11;
}

string Towers::relation(int n)
{
  return names[n];
}

int Towers::weight()
{
  return Weight;
}
