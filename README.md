#DataLite

Developed a CLI(Command Line) application named - **`DataLite`**.

DataLite is a lite clone to a real DataBase Management System.

Users get the result in the same way as they would if the query was executed in a real DataBase Management System.


### Commands DataLite handles - 
- create table
- drop table
- insert into 
- select
- update
- delete from
- describe table
- help

### How DataLite work?

- User types the query in the command-line interface.
- The query which is in string datatype is parsed and stored in a vector of strings called Tokens.
- Then SQL keywords (like create, delete, describe, etc) are handled so that the applications works in case-insensitive mode.
- Then, the Tokens are checked for any kind of errors and if any, corresponding error messages are printed.
- If no errors, then corresponding function calls are made.
- Thus query gets executed and success message is printed accordingly.

### Features of DataLite : 
-  A very lightweight program
-  Is `case-insensitive` but only for keywords in SQL
-  A `Schema File` which is a text file is maintained that contains information of attributes of all the tables.
-  Different text files are created for storing tuples of different tables.
-  Also works fine with `where clause in select, update, delete from`
    
    
 Purpose of developing the software was to learn how complex is a database management system.
