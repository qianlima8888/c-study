#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int gtk(wstring skey)
{
	int hash=5381,i;
	for(i=0;i<skey.length();i++)
		hash+=(hash<<5)+skey[i];
	return hash&2147483647;
}

int main()
{
	int p;
	wstring skey=L"u0irNL0DCV3o9g2jI76ABsWmEOXuT5d1Mcc-z3WTM78_";//p_skey=u0irNL0DCV3o9g2jI76ABsWmEOXuT5d1Mcc-z3WTM78_   skey=@jiV7k3Fq6
	p=gtk(skey);
	cout<<p;//1233432172
}