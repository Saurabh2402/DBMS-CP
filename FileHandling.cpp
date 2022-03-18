#include <bits/stdc++.h>
using namespace std;

void Delete(fstream &file,string name)
{
    fstream temp;
    temp.open("temp.txt",ios::out);

    string line;
    bool hasFound = false;
    while(!file.eof())
    {
       getline(file,line);
       if(line==name)
       {
           hasFound = true;
           continue;
       }
       temp << line << endl;
    }
    if(hasFound)
        cout<<"Name found"<<endl;
    else
        cout<<"Name not found"<<endl;

    temp.close();
    file.close();
    remove("names.txt");
    rename("temp.txt","names.txt");
}

void Write()
{
    
    
}

void remove_endl()
{
    fstream names;
    names.open("names.txt",ios::in);

    fstream temp;

}
int main()
{
    
    system("cls");
    
    

    //Delete Yash
    //Delete(names,"Harsh");

    remove_endl();

}