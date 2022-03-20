#include <bits/stdc++.h>
using namespace std;


void HelpTables()
{
    fstream SchemaFile;
    SchemaFile.open("SchemaFile.txt",ios::in);

    if(!SchemaFile)
    {cout<<"Schema File not found"<<endl;return;}
    
    
    if(SchemaFile.peek()==-1)
    {cout<<"No tables found"<<endl;return;}

    cout<<"Tables in the database are : "<<endl;
    string line;
    while(!SchemaFile.eof())
    {
        getline(SchemaFile,line);
        if(line.front()=='*' && line.back()=='*')// *Teacher*
            cout << line.substr(1,line.size()-2) << endl;
    }
}


void HelpCommand(vector<string> Tokens)
{
    if(Tokens[1]=="create")
    {
        cout<<"Used to create tables in SQL"<<endl;
        cout<<"SYNTAX : ";
        cout<<"create table table_name (attr1 type1, attr2 type2 check(cond1 AND cond2), primary key(attr1));"<<endl;
        cout<<"Eg -"<<endl;
        cout<<"create table Student(roll int check(roll>0), name varchar(20) check(name!=\"ABC\"), dob date, percent decimal(4,2), primary key(roll));";
    }

    else if(Tokens[1]=="drop")
    {
        cout<<"Used to drop the tables from the SQL"<<endl;
        cout<<"SYNTAX : ";
        cout<<"drop table table_name;"<<endl;
        cout<<"Eg -"<<endl;
        cout<<"drop table Students;";
    }

    else if(Tokens[1]=="insert")
    {
        cout<<"Used to insert data into the tables in SQL"<<endl;
        cout<<"SYNTAX : ";
        cout<<"insert into table_name values(val1 , val2 ,... );"<<endl;
        cout<<"Eg -"<<endl;
        cout<<"insert into Students values(100,\"Saurabh Yelmame\",24-02-2001,84.25);";
    }

    else if(Tokens[1]=="select")
    {
        cout<<"Used to select tuples from tables with specified conditions in sql."<<endl;
        cout<<"SYNTAX : ";
        cout<<"select attribute_list from table _list where condition_list"<<endl; 
        cout<<"Eg -"<<endl;
        cout<<"select name,dob from Students where percent>85.00";
    }
     
    else if(Tokens[1]=="delete")
    {
        cout<<"Used to delete tables in sql."<<endl;
        cout<<"SYNTAX : ";
        cout<<"delete from table_name where condition_list ;"<<endl;
        cout<<"Eg -"<<endl;
        cout<<"delete from Students where percent<40.00";
    }

    else if(Tokens[1]=="update")
    {
        cout<<"Used to update tuples from the tables in sql."<<endl;
        cout<<"SYNTAX : ";
        cout<<"update table_name set attr1=val1 ,attr2 = val2 where condition_list ;"<<endl;
        cout<<"Eg -"<<endl;
        cout<<"update Students set percent=90 where percent>90";
    }
    
    cout<<endl;
 } 

