//NOTICE: Please use 
//g++ -std=c++11 pw_gen pw_gen_linux.cpp
//to compile
#include "set"
#include "iostream"
#include "ctime"
//#include "windows.h"

#define white_on_black  
#define red_on_black  
#define start is_digit=is_lower=is_upper=1; \
		is_punc=0; \
		idigit=16;
#define restart start
using namespace std;
bool is_digit,is_lower,is_upper,is_punc;
int idigit;
bool is_exist(string x,string y)
{
	if(x.find(y)!=string::npos)return 1;
	return 0;
}
set<char> digit {'0','1','2','3','4','5','6','7','8','9'};
set<char> lower {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
set<char> upper {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
set<char> punc {'!','@','#','$','%','^','&','*','(',')','-',':','<','>','\'','\"','|','/','\\','?','~','`'};
int charand()
{
	int t=0;
	set<char> legal;
	if(is_digit)
		for(auto i=digit.begin(); i!=digit.end();
		        i++)legal.insert(*i);
	if(is_lower)
		for(auto i=lower.begin(); i!=lower.end();
		        i++)legal.insert(*i);
	if(is_upper)
		for(auto i=upper.begin(); i!=upper.end();
		        i++)legal.insert(*i);
	if(is_punc)
		for(auto i=punc.begin(); i!=punc.end();
		        i++)legal.insert(*i);
	while(legal.find((char)t)==legal.end())
	{
		t=rand()%128;
	}
	return t;
}
string gen()
{
	string ret;
	if(!ret.empty())ret="";
	for(int i=0; i<idigit; i++)ret+=charand();
	return ret;
}
int main()
{
	start
	srand(time(0));
	white_on_black
	cout<<"Welcome to passwordGenerator. \nUse h for help. "<<endl;
	red_on_black
	cout<<gen();
	white_on_black
	cout<<" is a 16-digit password generated for you."<<endl;
	string command;
	while(getline(cin,command))
	{
		restart
		if(is_exist(command,"h"))
		{
			cout<<"This is the help page"<<endl;
			cout<<"use option d to disable digit"<<endl;
			cout<<"use option l to disable lowercase"<<endl;
			cout<<"use option u to disable uppercase"<<endl;
			cout<<"use option p to enable punctuation"<<endl;
			cout<<"use s (number) to suggest length"<<endl;
			cout<<"use exit to exit generator"<<endl;
			continue;
		}
		if(is_exist(command,"d"))
		{
			is_digit=0;
		}
		if(is_exist(command,"l"))
		{
			is_lower=0;
		}
		if(is_exist(command,"u"))
		{
			is_upper=0;
		}
		if(is_exist(command,"p"))
		{
			is_punc=1;
		}
		if(is_exist(command,"s"))
		{
			auto Abegin=command.find("s")+1;
			auto Aend=command.length()-Abegin;
			string a(command,Abegin,Aend);
			idigit=atoi(a.c_str());
		}
		if(is_exist(command,"exit"))
		{
			return 0;
		}
		white_on_black
		cout<<"Your generated password is ";
		red_on_black
		cout<<gen()<<endl;
		white_on_black
	}
	return 0;
}
