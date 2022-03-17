#include <bits/stdc++.h>

using namespace std;
void CreateTable(vector<string>&Tokens)
{
    //Check whether table with specified name exists in Schema file or not
    {
        fstream SchemaFile;
        SchemaFile.open("SchemaFile.txt",ios::in);
        if(SchemaFile)
        {
            string TableNameInQuery = Tokens[2];
            string line;

            while(!SchemaFile.eof())
            {
                getline(SchemaFile,line);
                if(line[0]=='*')
                {
                    string name = line.substr(1,line.size()-2);
                    if(name==TableNameInQuery)
                    {
                        cout<<"Table <"<<TableNameInQuery<<"> already exists"<<endl;
                        SchemaFile.close();
                        return;
                    }
                }
            }
        }
    }
        

    //If control comes here means, table with specified name doesn't exists
    //So, Append the name of table and its attribute to schema file
    {
        fstream SchemaFile;
        SchemaFile.open("SchemaFile.txt",ios::app);

        SchemaFile << "*" << Tokens[2] << "*" << endl << "<<" << endl;
        SchemaFile << "pk: " << Tokens.back() << endl;

        int i = 3;
        while(i<Tokens.size()-3)
        {
            SchemaFile << Tokens[i] << " ";

            if(Tokens[i+1]=="varchar")
                {SchemaFile << Tokens[i+1] << " " << Tokens[i+2];  i+=3;}

            else if(Tokens[i+1]=="decimal")
                {SchemaFile << Tokens[i+1] << " " << Tokens[i+2] <<  " " << Tokens[i+3]; i+=4;}

            else
            {
                SchemaFile << Tokens[i+1];
                i+=2;
            }
            if(Tokens[i]=="check")
            {
                SchemaFile <<" " << Tokens[i] << " " ;
                SchemaFile << Tokens[i+1] << " " << Tokens[i+2] << " " << Tokens[i+3] ;
                i+=4;
                while(Tokens[i]=="AND" || Tokens[i]=="OR")
                {
                    SchemaFile <<" " << Tokens[i] << " " ;
                    SchemaFile << Tokens[i+1] << " " << Tokens[i+2] << " " << Tokens[i+3] ;
                    i+=4;
                }
            }
            SchemaFile << endl;

        }
        SchemaFile << ">>" << endl << endl;
        SchemaFile.close();

        cout << "Table Created Successfully"<<endl;
        
    }
        
}
    

int dropTable()
{
    cout<<"drop";
    return 0;
}

int updateTable()
{

    return 0;
}
int selectFromTable()
{

    return 0;
}
int deletetFromTable()
{

    return 0;
}