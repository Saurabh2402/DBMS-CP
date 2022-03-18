#include <bits/stdc++.h>
using namespace std;

void HelpCommand(vector<string>& Tokens)
{
    
}

void HelpTables()
{
    fstream SchemaFile;
    SchemaFile.open("SchemaFile.txt",ios::in);

    if(!SchemaFile)
    {cout<<"No Tables Found"<<endl;return;}
    
    cout<<"Tables in the database are : "<<endl;
    string line;
    while(!SchemaFile.eof())
    {
        getline(SchemaFile,line);
        if(line.front()=='*' && line.back()=='*')// *Teacher*
            cout << line.substr(1,line.size()-2) << endl;
         
    }

}