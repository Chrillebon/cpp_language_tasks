//7.h

void explode(const string& s, char* t[20], const char& c)
{
	string buff{""};
  int words=0;

	for(auto n:s)
	{
		//std::cout << "Den forsøger med: " <<n<<" så det giver: "<<buff<< '\n';
		if(n != c && n != ',' && n != '-' && n != '>')
		{
			buff+=n;
			int nn = n;
			int cc = c;
			int nc = n == c && buff != "";
		}
		else if(n == c && buff != "")
		{
			t[words] = strdup(buff.c_str());
			buff = "";
			words++;
		}
	}
	if(buff != "")
	{
		t[words] = strdup(buff.c_str());
		t[words+1] = "_";
	}
	else
	{
		t[words] = "_";
	}
}

class Towers
{
public:
  Towers();
	void set(const char *);
  string name();
  int relations();
  string relation(int);
  int weight();
	int cont();
	void cpy(Towers);
	void stop();
private:
  char Name [20];
  int Weight;
  char* names[20];
	int Cont = 1;
};

Towers::Towers()
{
  /*char mem1[100];
  if(scanf("%s (%u)%[a-z ,->]", Name, &Weight, &mem1) == EOF)
	{
		Cont = 0;
	}
  //scanf("%s (%u) -> %s %s %s %s %s %s %s", Name, &Weight, &mem[0], &mem[1], &mem[2], &mem[3], &mem[4], &mem[5], &mem[6]);
	explode(mem1, names, ' ');*/
}

void Towers::set(const char * s)
{
	char mem1[100]{'_'};
	if(sscanf(s, "%s (%d)%[a-z ,->]", Name, &Weight, &mem1) == EOF)
	{
		Cont = 0;
	}
	if(mem1[0] == '_')
	{
		names[0]= "_";
	}
	else
	{
		explode(mem1, names, ' ');
	}
  //scanf("%s (%u) -> %s %s %s %s %s %s %s", Name, &Weight, &mem[0], &mem[1], &mem[2], &mem[3], &mem[4], &mem[5], &mem[6]);
}

string Towers::name()
{
  return Name;
}

int Towers::relations()
{
  for(int i=0;i<8;i++)
  {
    if(names[i][0]=='_')
    {
      return i;
    }
  }
  std::cout << "int relations error!!!!!!!!!!!" << '\n';
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

int Towers::cont()
{
	return Cont;
}

void Towers::stop()
{
	Cont = 0;
}
