#include "Data.h"
Data::Data(int r) {
	//prendre la ligne souhaitee
	int j = 0;
	ifstream file;
	file.open("res/database.txt");
	if (!file) {
		cerr << "file couldn't initialize " << endl;
	}
	do
	{
		getline(file, line);
		j++;
	} while (j != r);
	file.close();
	//copier la ligne dans un nouveau fichier
	ofstream ofile1;
	ofile1.open("res/copy.txt");
	if (!ofile1) {
		cerr << "copy file didn't open" << endl;
	}
	ofile1 << line << endl;
	ofile1.close();
	//cout << line << endl;
}
string Data::loadData(string type) {
	verb = { 0 };
	caractereActuel = { 0 };
	past_simple = { 0 };
	past_simple2 = { 0 };
	caractereActuel2 = { 0 };
	past_participle = { 0 };
	past_participle2 = { 0 };
	caractereActuel3 = { 0 };

	//let's get our variables
	ifstream ifile;
	if (!ifile) {
		cerr << "ifile didn't initialize" << endl;
	}
	ifile.open("res/copy.txt");
	/*-------repérer le verbe--------*/
	do
	{
		verb += caractereActuel;
		ifile.get(caractereActuel);

	} while (caractereActuel != ',');
	/*****************take the past simple***********************/
	ifile.seekg(0, ios::cur);
	bool check = 0;
	do
	{
		if (caractereActuel2 == ';')
		{ // c'est le cas du 2 eme choix past simple
			check = 1;
			break;
		}
		past_simple = past_simple + caractereActuel2;
		ifile.get(caractereActuel2);

	} while (caractereActuel2 != ',');
	if (check == 1)
	{ // c'est le cas du 2 eme choix past simple
		caractereActuel2 = { 0 };
		do
		{
			past_simple2 = past_simple2 + caractereActuel2;
			ifile.get(caractereActuel2);

		} while (caractereActuel2 != ',');

	}

	/*******take the past participle*******/
	ifile.seekg(0, ios::cur);
	bool check2 = 0;
	do
	{
		if (caractereActuel3 == ';')
		{ // c'est le cas du 2 eme choix past simple
			check2 = 1;
			break;
		}
		past_participle += caractereActuel3;
		ifile.get(caractereActuel3);

	} while (caractereActuel3 != '\n');
	if (check2 == 1)
	{ // c'est le cas du 2 eme choix past simple
		caractereActuel3 = { 0 };
		do
		{
			past_participle2 += caractereActuel3;
			ifile.get(caractereActuel3);

		} while (caractereActuel3 != '\n');

	}

	ifile.close();
	verb.erase(0, 2);
	past_simple.erase(0, 2);
	past_simple2.erase(0, 2);
	past_participle.erase(0, 2);
	past_participle2.erase(0, 2);
	
	if (type == "v") {
		return verb;
	}
	if (type == "ps") {
		return past_simple;
	}
	if (type == "pp") {
		return past_participle;
	}
	if (type == "ps2") {
		return past_simple2;
	}
	if (type == "pp2") {
		return past_participle2;
	}
	return NULL;
}
