#include<fakedb/fakedb.h>
#include <fstream>

using namespace std;

int SetNetList(int n) {
    ofstream outfile;
    outfile.open("db.dat");
    outfile << n << endl;
    outfile.close();
    return n;
}
int GetNetList() {
    ifstream infile; 
    infile.open("db.dat");
    int data;
    infile >> data; 
    infile.close();
    return data;
}