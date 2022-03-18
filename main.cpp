#include <bits/stdc++.h>
#include "functions.cpp"
#include "HelpCommands.cpp"
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

    for(int i=0;i<Query.size();i++)
    {
        char c = Query[i];

        if(c==' ' || c=='(' || c==')' || c==',' || c==';')
        {
            if(temp!="")
                Tokens.push_back(temp);
            temp = "";
        }
        else if(Query[i]=='!' && Query[i+1]=='=')
        {
            if(temp!="")
                Tokens.push_back(temp);
            temp = "";

            Tokens.push_back("!=");
            i++;
        }
        else if(c=='<' || c=='>'|| c=='=')//OR other operators
        {
            if(temp!="")
                Tokens.push_back(temp);
            temp = "";

            Tokens.push_back(string(1,c));
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
    {CreateTable(Tokens);}

    else if(Tokens[0]=="drop" && Tokens[1]=="table")
    {DropTable(Tokens);}

    else if(Tokens[0]=="describe")
    {DescribeTable(Tokens);}

    else if(Tokens[0]=="help" && Tokens[1]=="tables")
    {HelpTables();}

    else if(Tokens[0]=="help")
    {HelpCommand(Tokens);}

    else if(Tokens[0]=="insert" && Tokens[1]=="into")
    {
        cout<<"== insert into"<<endl;
    }
    
    else if(Tokens[0]=="delete" && Tokens[1]=="from")
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
    
    
    else if(Tokens[0]=="quit")
    {
        cout<<"== quit"<<endl;
        exit(0);
    }
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