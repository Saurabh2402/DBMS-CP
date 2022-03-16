#include <bits/stdc++.h>
using namespace std;



int main()
{
    //Reading
    system("cls");
    fstream file;
    file.open("dipak.txt");

    string line;

    while(!file.eof())
    {
        getline(file,line);
        cout<<"* : "<<line<<endl;
    }

    //Writing
    //append endl explicityly before adding anything new to file
    /*
    fstream file;
    file.open("tp.csv",ios::app);

    string line = "Hello World3";
    file<<endl;
    file << line;
    file.close();
    */

}