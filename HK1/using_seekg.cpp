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
int main()
{
    int n;
    Student x;

    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");

    // Doc file input.txt
    fin >> n;
    fin.seekg(3);
    getline(fin, x.id);
    getline(fin, x.name);
    fin >> x.gpa;
    cout << n << " " << x.id << " " << x.name << " " << x.gpa;
    return 0;
}