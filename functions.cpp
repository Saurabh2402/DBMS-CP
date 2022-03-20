#include <bits/stdc++.h>
#include<regex>
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
        SchemaFile << ">>" << endl <<endl;
        SchemaFile.close();

        cout << "Table Created Successfully"<<endl;
        
    }
        
}

void delete_last_line()
{   
    ifstream fileIn( "SchemaFile.txt" );                   // Open for reading

    stringstream buffer;                             // Store contents in a std::string
    buffer << fileIn.rdbuf();
    string contents = buffer.str();

    fileIn.close();
    contents.pop_back();                                  // Remove last character


    ofstream fileOut( "SchemaFile.txt" , ios::trunc); // Open for writing (while also clearing file)
    fileOut << contents;                                  // Output contents with removed character
    fileOut.close(); 
}
void DropTable(vector<string>&Tokens)
{
    //drop table Students;
    fstream SchemaFile;
    SchemaFile.open("SchemaFile.txt",ios::in);
    if(!SchemaFile)
        {cout<<"Schema File does not exists!"<<endl;return;}
    
    fstream temp;
    temp.open("temp.txt",ios::out);

    bool hasDropped = false;
    
    string line;
    while(!SchemaFile.eof())
    {
        getline(SchemaFile,line);
        if(line[0]=='*' && line.substr(1,line.size()-2)==Tokens[2])// *Teacher*
        {
            while(line!=">>")
                getline(SchemaFile,line);

            getline(SchemaFile,line);
            getline(SchemaFile,line);
            
            hasDropped = true;
        }
        
        temp << line << endl;
    }
    if(hasDropped)
        cout<<"<"<<Tokens[2]<<"> Dropped Successfully"<<endl;
    else
        cout<<"<"<<Tokens[2]<<"> Not Found"<<endl;

    
    temp.close();
    SchemaFile.close();
    remove("SchemaFile.txt");
    rename("temp.txt","SchemaFile.txt");

   
    delete_last_line();
}

void DescribeTable(vector<string>&Tokens)
{
    fstream SchemaFile;
    SchemaFile.open("SchemaFile.txt",ios::in);

    if(!SchemaFile)
        {cout<<"Schema File does not exists!"<<endl;return;}

    bool found=false;
    string line;
    while(!SchemaFile.eof())
    {
        getline(SchemaFile,line);
        if(line[0]=='*' && line.substr(1,line.size()-2)==Tokens[1])// *Teacher*
        {
            getline(SchemaFile,line);
            while(1)
            {
                getline(SchemaFile,line);
                if(line==">>")
                    break;
                cout<<line<<endl;
            }
            found = true;
            break;
        }
        
    }
    if(!found)
        cout<<"<"<<Tokens[1]<<"> Table does not exists"<<endl;

}

string ExtractCol(string tuple,int colno)//<102,Saurabh Yelmame,24-02-2001>
{
    //tuple = <103,Saurabh Yelmame,24-02-2001>
    int comma=0;
    int i=1;
    while(comma<colno)
    {
        if(tuple[i]==',')
            comma++;
        i++;
    }
    
    string pk="";
    while(tuple[i]!=','&& tuple[i]!='>')
    {
        pk+=tuple[i];
        i++;
    }
    //cout<<"pk: "<<pk<<endl;
    return pk;
}

void InsertInto(vector<string>&Tokens)
{
    ifstream SchemaFile("SchemaFile.txt");
    if(!SchemaFile)
    {cout<<"SchemaFile doesn't exists"<<endl;return;}

    //1. Checking whether the table exists in the Schema File or not
    string line;
    bool doesExist = false;
    while(!SchemaFile.eof())
    {
        getline(SchemaFile,line);
        if(line[0]=='*' && line.substr(1,line.size()-2)==Tokens[2])
        {
            doesExist = true;
            break;
        }
    }
    if(!doesExist)//does not exists
    {cout<<"<"<<Tokens[2]<<"> table does not exists"<<endl;return;}
    
    //cout<<"Table exists in schema file"<<endl;

    //If control comes here, means the specified table exists in schema file;
    
    //1.Checking whether primary key already exists in the table or not
    fstream table;
    table.open(Tokens[2]+".txt",ios::in);
    string tuple;
    while(!table.eof())
    {
        getline(table,tuple);

        if(Tokens[4]==ExtractCol(tuple,0))//0 means primary key
        {cout<<"PK already exists"<<endl;return;}
    }
    table.close();



    //2.If the control comes here, means primary key doesn't exits
    //  And we can append the tuple;
    fstream TABLE;
    TABLE.open(Tokens[2]+".txt",ios::app);
    TABLE <<"<";

    int i=4;
    while(i<Tokens.size()-1)
    {
        TABLE << Tokens[i] <<",";
        i++;
    }
    TABLE << Tokens[i] << ">" << endl;

    TABLE.close();
    SchemaFile.close();

    cout<<"Tuple inserted successfully"<<endl;
    
}