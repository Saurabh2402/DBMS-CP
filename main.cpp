#include <bits/stdc++.h>
#include "functions.cpp"
using namespace std;

vector<string>Tokens;

void DisplayTokens()
{
    for(string x:Tokens)
        cout<<x<<endl;
}

void ParseIntoTokens(string Query)
{
    
    string temp="";

    for(char c:Query)
    {
        if(c==' ' || c=='(' || c==')' || c==',' || c==';')
        {
            if(temp!="")
                Tokens.push_back(temp);
            /*if(c!=' ')
                Tokens.push_back(string(1,c));*/
            
            temp = "";
        }
        else 
        {
            temp += c; 
        }
    }
    if(temp!="")
        Tokens.push_back(temp);
}

void Execute()
{
    if(Tokens.empty())
        return;

    if(Tokens[0]=="create" && Tokens[1]=="table") 
    {
        CreateTable(Tokens);
    }

    /*
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
    }*/
    
    else
    {
        cout<<"INVALID QUERY"<<endl;
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
        cout<<endl;
        ParseIntoTokens(Query);
        //DisplayTokens();
        Execute();  
    }
    
    return 0;
}