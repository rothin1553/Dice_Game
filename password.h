/*
 *  password(char key[], int attempt = 3)
 *
 *  lock(char key[]) // lock the screen, need correct password to pass 
 *
 *  password(string key, int attempt = 3)
 *
 *  lock(string key)
 *
 *  getStrKey() // return string hidden
 *
 *
*/


#ifndef PASSWORD_H
#define PASSWORD_H

#include<iostream>
    using std::cin;
    using std::cout;
    using std::endl;
    
#include <termios.h>
#include <unistd.h>

#include <string>
    using std::string;

#include <cstring>


//password verification. pass parameter char[] and optinal attempt allow
bool password(char key[], int attempt = 3)
{
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    if(attempt < 0)
    {
        attempt = 1;
    }
    
    bool pass = true;
    
    char input[512];
    int tried = 0;
    
    do
    {
        cout << "\n\nEnter password(no space): ";
        cin.get(input, 512, '\n');
        cin.get();
        pass = true;
        
        for(int i = 0; key[i] != '\0' || input[i] != '\0'; i++)
        {
            
            //cout << key[i] << "\t" << input[i] <<endl;
            
            if(key[i] != input[i])
            {
                //cout << key[i] << "\t" << input[i] <<endl;
                pass = false;
                tried++;
                cout << "\n::Incorrect password.::\n\n\n";
                //tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                break; //break the for loop
                
            }

        }
        
    }while(pass == false && tried < attempt);
    
    cout << endl;
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    //cin.get();

    return pass;
}

//lock the code at a point. //exit if fail
void lock(char key[])
{
    if(!password(key))
    {
        termios oldt;
        tcgetattr(STDIN_FILENO, &oldt);
        termios newt = oldt;
        newt.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        exit(1);
    }
    
    
}



/// call this by char* key = &getKey();
char& getKey()
{
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    char static key[512];
    
    cout << "Enter key(no space): ";
    
    cin.get(key,512);
    cin.get();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    return *key;
}






//----------String password---------

bool password(string key = "roth", int attempt = 3)
{
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    if(attempt < 0)
    {
        attempt = 1;
    }
    
    bool pass = true;
    
    string input;
    int tried = 0;
    
    do
    {
        cout << "\n\nEnter password(no space): ";
        getline(cin, input);
        pass = true;
        
        if(input.size() != key.size())
        {
            pass = false;
            tried++;
            cout << "\n::Incorrect password.::\n\n\n";
            
        }

        
        else
        {
            for(int i = 0; key[i] != '\0' || input[i] != '\0' || input[i] == ' '; i++)
            {
                //cout << key[i] << "\t" << input[i] <<endl;
                
                if(key[i] != input[i])
                {
                    pass = false;
                    tried++;
                    cout << "\n::Incorrect password.::\n\n\n";
                    //tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                    break; //break the check string
                    
                }
            }
        }
        
    }while(pass == false && tried < attempt);
    
    cout << endl;
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    //cin.get();

    return pass;
}


void lock(string key = "roth")
{
    if(!password(key))
    {
        termios oldt;
        tcgetattr(STDIN_FILENO, &oldt);
        termios newt = oldt;
        newt.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        exit(1);
    }
    
    
}

string getStrKey()
{
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    string key;
    
    cout << "Enter key(no space): ";
    
    cin >> key;
    
    cin.get();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    return key;
}













#endif