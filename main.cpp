#include <bits/stdc++.h>
using namespace std;

vector<string>Tokens;

void DisplayTokens()
{
    for(string x:Tokens)
        cout<<x<<",";
}

void ParseIntoTokens(string token)
{
    stringstream space(token);
    string i;

    while(getline(space,i,' '))
        Tokens.push_back(i);
}

void Execute()
{
    
    if(Tokens[0]=="create" && Tokens[1]=="table") 
    {
        cout<<"== create table"<<endl;
    }
    else if(Tokens[0]=="drop" && Tokens[1]=="table")
    {
        cout<<"== drop table"<<endl;
    }
    else if(Tokens[0]=="describe")
    {
        cout<<"== describe"<<endl;
    }
    else if(Tokens[0]=="insert" && Tokens[0]=="into")
    {
        cout<<"== insert into"<<endl;
    }
    
    else if(Tokens[0]=="delete" && Tokens[0]=="from")
    {
        cout<<"== delete from"<<endl;
    }
    else if(Tokens[0]=="update")
    {
        cout<<"== update"<<endl;
    }
    else if(Tokens[0]=="select")
    {
        cout<<"== create table"<<endl;
    }
    else if(Tokens[0]=="help" && Tokens[0]=="tables")
    {
        cout<<"== help tables"<<endl;
    }
    else if(Tokens[0]=="help")
    {
        cout<<"== help cmd"<<endl;
    }
    else if(Tokens[0]=="quit")
    {
        cout<<"== quit"<<endl;
        exit(0);
    }
    
}

int main()
{
    system("cls");
    string Query;
    
    while(1)
    {
        Tokens.clear(); 
        cout<<endl<<">> ";

        getline(cin,Query);
        
        ParseIntoTokens(Query);

        Execute();  
    }
    
    return 0;
}