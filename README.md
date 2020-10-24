# 50-30-20-Budget-Project
- Repository for the 50/30/20 Budget Project 
- Programmer: Arianna Gaskins
- Email Address: arianna.gaskins698@gmail.com
- Date: 20 October 2020
- Environment:  Microsoft Visual Studio Code
- Language: C++
- Description:
This program is meant to separate income into 50% for needs, 30% for wants, &
20% for savings. It will store purchases and savings amounts that are entered 
by the user. The information is saved in files which can also be viewed and edited 
by the user. 

Project Notes:
- Make appending user controlled so it only happens when necessary and so it can always have a value when needed
- funtion pointers: (type)(*new name)(parameters); (new name) = function; can also typedef first part, can also create array where functions take up that memory space. Example:
        typedef void (*fnPtr)(int,int);
        fnPtr lookupTable [5];
        lookupTable[0] = Nop;
        lookupTable[1] = Add;
        lookupTable[2] = Sub;
        lookupTable[3] = Mul;
        lookupTable[4] = Div;
- Change Bills and Frivolity append file functions to also append needs and wants files respectively
- Add savings purchase file?
- Make masterEdit function to remove things just in case as well
- read about pointers and polymorphism