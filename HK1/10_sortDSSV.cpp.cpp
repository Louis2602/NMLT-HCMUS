#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Student
{
	string id;
	string name;
	float gpa;
};
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int n;
	Student students[100];

	ifstream fin;
	fin.open("input.txt");
	ofstream fout;
	fout.open("output.txt");

	// Doc file input.txt
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin.ignore(); // bo qua dong dau tien
		getline(fin, students[i].id, '\n');
		getline(fin, students[i].name, '\n');
		fin >> students[i].gpa;
	}
	// Sap xep tang dan
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - 1 - i; ++j)
			if (students[j].gpa > students[j + 1].gpa)
				swap(students[j].gpa, students[j + 1].gpa);

	for (int i = 0; i < n; ++i)
	{
		fout << "ID: " << students[i].id << " ,Name: " << students[i].name << " ,GPA: " << students[i].gpa << endl;
	}

	fin.close();
	fout.close();
}