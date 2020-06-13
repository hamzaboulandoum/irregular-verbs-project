#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;
class Data
{
public:
	Data(int r);
	string loadData(string type);
	string line;
private:
	
	string verb{ 0 };
	char caractereActuel = { 0 };
	string past_simple{ 0 };
	string past_simple2;
	char caractereActuel2 = { 0 };
	string past_participle{ 0 };
	string past_participle2{ 0 };
	char caractereActuel3 = { 0 };

};

