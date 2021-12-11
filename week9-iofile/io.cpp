#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char infile[] = "input.txt";
	int N;

	ifstream fin;
	fin.open(infile);
	if (!fin)
		cout << "Unable to open file!" << endl;
	else
		fin >> N;
	fin.close();

	char outfile[] = "output.txt";
	ofstream fout;
	fout.open(outfile);
	fout << N * N;
	fout.close();

	return 0;
}