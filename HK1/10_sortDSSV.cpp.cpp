#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct student
{
	string id = "";
	string name = "";
	float gpa = 0;
};

int main()
{
	int n;
	ifstream input;
	student students[100];
	int i = 0;
	input.open("input.txt");
	input >> n;

	//Doc file input.txt
	for(int i = 0; i < n; i++)
	{
		//input.ignore();
		getline(input, students[i].id, '\n');
		getline(input, students[i].name, '\n');
		input >> students[i].gpa;
	}

	//Sap xep giam dan
	for (int k = 0; k < n - 1; k++)
	{
		for (int j = k + 1; j < n; j++)
		{
			if (students[k].gpa < students[j].gpa)
			{
				swap(students[k], students[j]);
			}
		}
	}
	input.close();

	//Xuat file output.txt
	ofstream output;
	output.open("output.txt");

	for (int k = 0; k < n; k++)
	{
		output << "ID: " << students[k].id << " ,Name: " << students[k].name << " ,GPA: " << students[k].gpa << endl;
	}

	output.close();
}