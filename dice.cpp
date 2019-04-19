///updated hack mode 06/23/18

#include<iostream>
    using std::cin;
    using std::cout;
    using std::endl;

#include<string>
    using std::string;

#include <sstream>
    using std::ostringstream;

#include<unistd.h>

#include<iomanip>
    using std::left;
    using std::setw;
#include<cstdlib>
#include<ctime>
#include<limits>

#include "password.h"
#include<vector>
    using std::vector;
    
#include<fstream>
    using std::ifstream;

#include<random>

void diceShow(); //first up display
void readClear(string filename = "dice.cpp"); //show all code
int getDice(bool cmd = false, int index = 0);
int getRandomInt(int lowerBound, int upperBound);
void loading();
bool nich = false; // get colors dice
int color = 0; //dice color //1::red 2::light blue 3::green 4::blue

int main()
{


    cout << "\n\nPress ENTER to Play!! ";
    cin.get();
    cin.clear();
    
    system("clear");
    
    cout.imbue(std::locale("")); //comma for monatary base
    srand(time(0));
    
    diceShow(); // display dice before the game begin
    loading(); // show loading game

    cout << "Created by: \033[1;31m120TH-grammer\033[0m\n";

    ////////=-================== game begin


    bool cmd = false; // command access
    //bool nich = false; // red dice
    unsigned int cash = 0;
    unsigned int beginCash = 0;
    cout << "\n\n\n\nEnter the buy-in amount(MAX 100): ";
    cin >> cash;

    if(cash == 2170421704)
    {
        cout << "\033[32;40m\n";
        system("clear");
        cout << "\nUsername: ";
        string user;
        cin >> user;
        cin.clear();
        cin.ignore(256, '\n');
        //cout << "user: " << user << endl;

        if(password("piteak", 1))
        {
            cash = 500000; // allow this cash for admin mode

            string mode = "Administrator"; 

            if(user == "roth" || user == "Roth")
            {
                cout << "\n\nWelcome, Roth.\nPlease enter your PIN below";
                if(password("1996", 1))
                {
                    mode = "\033[30;4;47mRoth In, Creator\033[0;32;40m";
                    cout << "*\n*\n*\n--> Full access: \033[37;42mGranted\033[0;32;40m\n";
                    usleep(2710033);
                    cash = 1000000; // allow this cash for roth mode
                    readClear("/Users/rothin1553/Desktop/cpp/personal/dice/dice.cpp");
                }
                else
                {
                    cout << "*\n*\n*\n--> Full access: \033[37;41mDenied\033[0;32;40m\n";
                    usleep(2710033);
                }
            }

            system("clear");
            cout << "\033[32;40m*\n";
            usleep(217040);
            cout << "*\n";
            usleep(217040);
            cout << "*\n*";
            usleep(217040);
            cout << "\nAccess mode: " << mode << "\n\n\n";

            string command;
            cout << ">> ";
            getline(cin, command);


            do{

                //cout << "'" << command << "'\n";

                if(command == "cash" || command == "money")
                {
                    cout << "\n>> " << command << " >> ";
                    cin >> cash;

                    cin.clear();
                    cin.ignore(256, '\n');

                    cout << "|DONE|\n\n";
                }

                else if(command == "win" || command == "roth")
                {
                    if(password("vy", 1))
                    {
                        cout << "\n>> " << command << " >> DONE\n\n";
                        cmd = true;
                    }

                    else
                    {
                        cout << "\n>> " << command << " >> FAILED\n\n";
                    }
                }

                else if(command == "lose")
                {
                    cout << "\n'lose' still working\n";
                }

                else if(command == "nich" || command == "Nich")
                {
                    if(password("mozzie", 1))
                    {
                        nich = true;
                        cout << "\nChange color dice: 1. Red   2. LG Blue   3. Green   4. Blue\n";
                        cout << ">> " << command << " >> " ;
                        cin >> color;
                        cin.clear();
                        cin.ignore(256, '\n');

                        if(color > 4 || color < 1)
                        {
                            nich = false;
                            cout << "|FAILED|\n\n";
                        }
                        else
                        {
                            cout << "|DONE|\n\n";
                        }
                    }
                    else
                    {
                        cout << "\n>> " << command << " >> FAILED\n\n";
                    }
                }

                else if(command == "" || command == "exit" || command == "end" || cin.fail())
                {
                    cout << "\n*";
                    usleep(217040);
                    cout << "\n*";
                    usleep(21704);
                    cout << "\n*";
                    usleep(217040);
                    cout << "\nExit Administrator Access Mode...\n";
                    usleep(2170400);
                    break;
                }

                else
                {
                    cout << "\n\nInvalid command...\n\n\n";
                }

                cout << ">> ";
                getline(cin, command);
            }while(true);
        }

        else
        {
            cout << "\n\n\nFAILED to login to Admin. Mode\n\n\n";
            usleep(2170400);
            cash = 500;
        }

        cout << "\033[0m\n";
    }

    else if(cash == 11503 || cash == 3112)
    {
        cout << "\n\n\n\033[4mHIDDEN CODE\033[0m: You earn \033[33m1000\033[0m coins!!!\n\n\n";
        cash = 1000;
        usleep(5900000);

    }

    else if(cash <= 0 || cash > 100)
    {
        cash = 25;
        cout << "\n\nInvalid input amount...\n\n\n";
        usleep(1800000);
        
        if(cin.fail())
        {
            cout << "ERROR CODE: 'ID10T' :(\n\n\n";
            exit(1);
        }
    }
    
    //cin.clear();
    //cin.ignore(256, '\n'); // to clear cash input "50f"
    
    beginCash = cash; // record the begin amount
    bool playing = true;
    vector<int> hack; //vector for hacked number (no repeat)

    while(playing)
    {
        system("clear");

        cout << "\033[43;4;30mCoin(s):\033[0;33m " << cash << "\033[0m\n\n";


        unsigned int bet = 0;
        cout << "\nEnter the amount to bet: ";
        cin >> bet;

        if(bet > cash || bet == 0)
        {
            playing = false;
            system("clear");

            cout << "\033[43;4;30mCoin(s):\033[0;33m " << cash << "\033[0m\n\n\n";
            if(beginCash > cash)
            {
                cout << "\n\nYou've lost " << beginCash - cash << " coins\n\n\n";
            }
            else
            {
                cout << "\n\nCongratulation! You've won " << cash - beginCash << " coins\n\n\n";
            }
            cout << "\n\nGOOD BYE, COME AGAIN!!\n\n\n\n\n\n";
            break;
        }


        int betDice = -1;
        cout << "\nEnter the \033[31mRED\033[0m number to bet.\n\033[37m================================\033[0m"
        << "\n  |\033[31;4m1\033[0m|  |\033[31;4m2\033[0m|  |\033[31;4m3\033[0m|  |\033[31;4m4\033[0m|  |\033[31;4m5\033[0m|  |\033[31;4m6\033[0m|\n"
        << "\033[37m  ----------------------------\033[0m\n"
        << "   |\033[31m0\033[0m| = \033[47;30;1mLOW \033[0m      |\033[31m9\033[0m| = \033[30;47;1mHIGH\033[0m\n"
        << "\033[37m  ----------------------------\033[0m\n"
        << "   |\033[31m7\033[0m| = \033[30;47;1mODD \033[0m      |\033[31m8\033[0m| = \033[30;47;1mEVEN\033[0m\n"
        << "\033[37m================================\033[0m\nBET: ";
        cin >> betDice;

        if(betDice < 0 || betDice > 9 || cin.bad() || cin.fail())
        {
            if((betDice >= 115030 && betDice <= 115039) || (betDice >= 217040 && betDice <= 217049));

            else
            {
                cout << "\n\nInvalid Input!!\n\n";
                break;
            }
        }

        cout << "\n\n\n\033[4;37mRolling....\n\n";
        cout << "\033[1;31m.\n";
        usleep(540000);
        cout << "\033[1;33m.\n";
        usleep(540000);
        cout << "\033[1;32m.\033[0m\n\n\n";
        usleep(540000);

        int rollDice;

        if(cmd && betDice <= 9) //admin playing
        {
            int cmdDice = betDice;
            if(betDice == 9)
            {
                cmdDice = rand() % 3 + 4;
            }
            else if(betDice == 0)
            {
                cmdDice = rand() % 3 + 1;
            }
            else if(betDice == 7)
            {
                cmdDice = (rand() % 3) * 2 + 1;
            }
            else if(betDice == 8)
            {
                cmdDice = ((rand() % 3) + 1) * 2;
            }
            rollDice = getDice(true, cmdDice);
        }
        else if((betDice >= 115030 && betDice <= 115039) || (betDice >= 217040 && betDice <= 217049))
        {
            bool used = false;
            for(unsigned long i = 0; i < hack.size(); i++)
            {
                //cout << "loop\n";
                if(betDice == hack[i])
                {
                    betDice = betDice % 10;
                    used = true;
                    break;
                }
            }

            if(used == false)
            {
                //cout << "in if\n";
                hack.push_back(betDice);
                betDice = betDice % 10;
                int cmdDice = betDice;
                if(betDice == 9)
                {
                    cmdDice = rand() % 3 + 4;
                }
                else if(betDice == 0)
                {
                    cmdDice = rand() % 3 + 1;
                }
                else if(betDice == 7)
                {
                    cmdDice = (rand() % 3) * 2 + 1;
                }
                else if(betDice == 8)
                {
                    cmdDice = ((rand() % 3) + 1) * 2;
                }
                rollDice = getDice(true, cmdDice);
            }

            else
            {
                //cout << "in else\n";
                rollDice = getDice();
            }

            //cout << "vector size: " << hack.size() << endl;

        }
        else
        {
            rollDice = getDice();
        }

        //debug
        //rollDice = 1;

        //------------------ paying start calculate

        if(betDice > 0 && betDice < 7) //pay if win in ONE number bet
        {
            if(betDice == rollDice)
            {
                cout << "\n\nYOU WIN " << bet*5+bet << " coins!!!\n";
                cash = cash + (bet * 5);
            }

            else
            {
                cout << "\n\nBETTER LUCK NEXT TIME!!\n";
                cash = cash - bet;
            }
        }

        else
        {
            if(betDice == 0 && rollDice <= 3) // small win
            {
                cout << "\n\nYOU WIN " << bet*2 << " coins!!!\n";
                cash = cash + bet;
            }

            else if(betDice == 9 && rollDice >= 4) // large win
            {
                cout << "\n\nYOU WIN " << bet*2 << " coins!!!\n";
                cash = cash + bet;
            }

            else if(betDice == 8 && (rollDice % 2 == 0)) // even
            {
                cout << "\n\nYOU WIN " << bet*2 << " coins!!!\n";
                cash = cash + bet;
            }

            else if(betDice == 7 && (rollDice % 2 != 0)) // odd
            {
                cout << "\n\nYOU WIN " << bet*2 << " coins!!!\n";
                cash = cash + bet;
            }

            else // lose
            {
                cout << "\n\nBETTER LUCK NEXT TIME!!\n";
                cash = cash - bet;
            }
        }

        usleep(5000000); // hold result

        if(cash < 1)
        {
            playing = false;
            system("clear");

            cout << "\033[43;4;30mCoin(s):\033[0;33m " << cash << "\033[0m\n\n\n";
            if(beginCash > cash)
            {
                cout << "\n\nYou've lost " << beginCash - cash << " coins\n\n\n";
            }
            else
            {
                cout << "\n\nCongratulation! You've won " << cash - beginCash << " coins\n\n\n";
            }
            cout << "\n\nGOOD BYE, COME AGAIN!!\n\n\n\n\n\n";

        }

        if(cash > 1000000000) //overload cash
        {
            cout << "\n\n\n\t   CONGRATULATION!!!\n";
            usleep(217040);
            cout << "\tYOU ARE THE CHAMPION!!!\n";
            usleep(217040);
            cout << "\t     \033[32m$" << cash << endl;
            usleep(217040);
            cout << "\033[0m\t Thank you for playing.\n\n\n";
            usleep(2170421);
            playing = false;
            //cout a heart when have time
        }

    }

    return 0;
}


int getDice(bool cmd, int index)
{
    vector<string> vectorStr1, vectorStr2, vectorStr3;

    ostringstream line1, line2, line3;

    //red dice
    if(nich)
    {
        if(color == 1)
        {   
            vectorStr1.push_back("\033[37;1;41m       ");
            vectorStr2.push_back("\033[37;1;41m   •   ");
            vectorStr3.push_back("\033[37;1;41m       ");
    
            vectorStr1.push_back("\033[37;1;41m     • ");
            vectorStr2.push_back("\033[37;1;41m       ");
            vectorStr3.push_back("\033[37;1;41m •     ");
    
            vectorStr1.push_back("\033[37;1;41m     • ");
            vectorStr2.push_back("\033[37;1;41m   •   ");
            vectorStr3.push_back("\033[37;1;41m •     ");
    
            vectorStr1.push_back("\033[37;1;41m •   • ");
            vectorStr2.push_back("\033[37;1;41m       ");
            vectorStr3.push_back("\033[37;1;41m •   • ");
    
            vectorStr1.push_back("\033[37;1;41m •   • ");
            vectorStr2.push_back("\033[37;1;41m   •   ");
            vectorStr3.push_back("\033[37;1;41m •   • ");
    
            vectorStr1.push_back("\033[37;1;41m •   • ");
            vectorStr2.push_back("\033[37;1;41m •   • ");
            vectorStr3.push_back("\033[37;1;41m •   • ");
            
        }

        else if(color == 2)
        {   
            vectorStr1.push_back("\033[37;1;46m       ");
            vectorStr2.push_back("\033[37;1;46m   •   ");
            vectorStr3.push_back("\033[37;1;46m       ");
    
            vectorStr1.push_back("\033[37;1;46m     • ");
            vectorStr2.push_back("\033[37;1;46m       ");
            vectorStr3.push_back("\033[37;1;46m •     ");
    
            vectorStr1.push_back("\033[37;1;46m     • ");
            vectorStr2.push_back("\033[37;1;46m   •   ");
            vectorStr3.push_back("\033[37;1;46m •     ");
    
            vectorStr1.push_back("\033[37;1;46m •   • ");
            vectorStr2.push_back("\033[37;1;46m       ");
            vectorStr3.push_back("\033[37;1;46m •   • ");
    
            vectorStr1.push_back("\033[37;1;46m •   • ");
            vectorStr2.push_back("\033[37;1;46m   •   ");
            vectorStr3.push_back("\033[37;1;46m •   • ");
    
            vectorStr1.push_back("\033[37;1;46m •   • ");
            vectorStr2.push_back("\033[37;1;46m •   • ");
            vectorStr3.push_back("\033[37;1;46m •   • ");
        }

        else if(color == 3)
        {            
            vectorStr1.push_back("\033[37;1;42m       ");
            vectorStr2.push_back("\033[37;1;42m   •   ");
            vectorStr3.push_back("\033[37;1;42m       ");
    
            vectorStr1.push_back("\033[37;1;42m     • ");
            vectorStr2.push_back("\033[37;1;42m       ");
            vectorStr3.push_back("\033[37;1;42m •     ");
    
            vectorStr1.push_back("\033[37;1;42m     • ");
            vectorStr2.push_back("\033[37;1;42m   •   ");
            vectorStr3.push_back("\033[37;1;42m •     ");
    
            vectorStr1.push_back("\033[37;1;42m •   • ");
            vectorStr2.push_back("\033[37;1;42m       ");
            vectorStr3.push_back("\033[37;1;42m •   • ");
    
            vectorStr1.push_back("\033[37;1;42m •   • ");
            vectorStr2.push_back("\033[37;1;42m   •   ");
            vectorStr3.push_back("\033[37;1;42m •   • ");
    
            vectorStr1.push_back("\033[37;1;42m •   • ");
            vectorStr2.push_back("\033[37;1;42m •   • ");
            vectorStr3.push_back("\033[37;1;42m •   • ");
        }

        else if(color == 4)
        {            
            vectorStr1.push_back("\033[37;1;44m       ");
            vectorStr2.push_back("\033[37;1;44m   •   ");
            vectorStr3.push_back("\033[37;1;44m       ");
    
            vectorStr1.push_back("\033[37;1;44m     • ");
            vectorStr2.push_back("\033[37;1;44m       ");
            vectorStr3.push_back("\033[37;1;44m •     ");
    
            vectorStr1.push_back("\033[37;1;44m     • ");
            vectorStr2.push_back("\033[37;1;44m   •   ");
            vectorStr3.push_back("\033[37;1;44m •     ");
    
            vectorStr1.push_back("\033[37;1;44m •   • ");
            vectorStr2.push_back("\033[37;1;44m       ");
            vectorStr3.push_back("\033[37;1;44m •   • ");
    
            vectorStr1.push_back("\033[37;1;44m •   • ");
            vectorStr2.push_back("\033[37;1;44m   •   ");
            vectorStr3.push_back("\033[37;1;44m •   • ");
    
            vectorStr1.push_back("\033[37;1;44m •   • ");
            vectorStr2.push_back("\033[37;1;44m •   • ");
            vectorStr3.push_back("\033[37;1;44m •   • ");
        }
    }

    else
    {
        vectorStr1.push_back("\033[47;30;1m       ");
        vectorStr2.push_back("\033[47;31;1m   •   ");
        vectorStr3.push_back("\033[47;30;1m       ");

        vectorStr1.push_back("\033[47;30;1m     • ");
        vectorStr2.push_back("\033[47;30;1m       ");
        vectorStr3.push_back("\033[47;30;1m •     ");

        vectorStr1.push_back("\033[47;30;1m     • ");
        vectorStr2.push_back("\033[47;30;1m   •   ");
        vectorStr3.push_back("\033[47;30;1m •     ");

        vectorStr1.push_back("\033[47;30;1m •   • ");
        vectorStr2.push_back("\033[47;30;1m       ");
        vectorStr3.push_back("\033[47;30;1m •   • ");

        vectorStr1.push_back("\033[47;30;1m •   • ");
        vectorStr2.push_back("\033[47;30;1m   •   ");
        vectorStr3.push_back("\033[47;30;1m •   • ");

        vectorStr1.push_back("\033[47;30;1m •   • ");
        vectorStr2.push_back("\033[47;30;1m •   • ");
        vectorStr3.push_back("\033[47;30;1m •   • ");
    }

    if(cmd)
    {
        index = index - 1;
    }
    else
    {
        index = rand() % 6;
    }
    
    //display rolling
    
    for(int i = 0; i < 6; i++)
    {
        if(i == 0)
        {
            system("clear");
        }
        
        cout << "\n\n\n\t\tRolling...\n\n\n\n\n";
        
        line1 << vectorStr1[i] << "\033[0m   ";
        line2 << vectorStr2[i] << "\033[0m   ";
        line3 << vectorStr3[i] << "\033[0m   ";
    
        cout << "\t\t"<< line1.str() << '\n'
             << "\t\t"<< line2.str() << '\n'
             << "\t\t"<< line3.str() << "\033[0m\n\n";
    
        line1.str("");
        line2.str("");
        line3.str("");
    
        line1.clear();
        line2.clear();
        line3.clear();
        
        usleep(50000);
        system("clear");
        
        for(int j = 5; j >= 0; j--)
        {
            cout << "\n\n\n\t\tRolling...\n\n\n\n\n";
            
            line1 << vectorStr1[j] << "\033[0m   ";
            line2 << vectorStr2[j] << "\033[0m   ";
            line3 << vectorStr3[j] << "\033[0m   ";
        
            cout << "\t\t"<< line1.str() << '\n'
                 << "\t\t"<< line2.str() << '\n'
                 << "\t\t"<< line3.str() << "\033[0m\n\n";
        
            line1.str("");
            line2.str("");
            line3.str("");
        
            line1.clear();
            line2.clear();
            line3.clear();
            
            usleep(50000);
            
            //slow down the dice display
            if(i > 3)
            {
                usleep(50000);
            }
            if(i == 5)
            {
                usleep(25000);
            }
            
            system("clear");
            
            
        }
        
        
        
    }
    
    ///
    
    
    
    
    cout << "\n\n\n\t\tAnd it is...\n\n\n\n\n";
    line1 << vectorStr1[index] << "\033[0m   ";
    line2 << vectorStr2[index] << "\033[0m   ";
    line3 << vectorStr3[index] << "\033[0m   ";

    cout << "\t\t"<< line1.str() << '\n'
         << "\t\t"<< line2.str() << '\n'
         << "\t\t"<< line3.str() << "\033[0m\n\n";

    line1.str("");
    line2.str("");
    line3.str("");

    line1.clear();
    line2.clear();
    line3.clear();

    return index+1;
}

void diceShow()
{
    vector<string> vectorStr1, vectorStr2, vectorStr3;

    ostringstream line1, line2, line3;
    //ostringstream l1,l2,l3;


    vectorStr1.push_back("\033[47;30;1m       ");
    vectorStr2.push_back("\033[47;31;1m   •   ");
    vectorStr3.push_back("\033[47;30;1m       ");

    vectorStr1.push_back("\033[47;30;1m     • ");
    vectorStr2.push_back("\033[47;30;1m       ");
    vectorStr3.push_back("\033[47;30;1m •     ");

    vectorStr1.push_back("\033[47;30;1m     • ");
    vectorStr2.push_back("\033[47;30;1m   •   ");
    vectorStr3.push_back("\033[47;30;1m •     ");

    vectorStr1.push_back("\033[47;30;1m •   • ");
    vectorStr2.push_back("\033[47;30;1m       ");
    vectorStr3.push_back("\033[47;30;1m •   • ");

    vectorStr1.push_back("\033[47;30;1m •   • ");
    vectorStr2.push_back("\033[47;30;1m   •   ");
    vectorStr3.push_back("\033[47;30;1m •   • ");

    vectorStr1.push_back("\033[47;30;1m •   • ");
    vectorStr2.push_back("\033[47;30;1m •   • ");
    vectorStr3.push_back("\033[47;30;1m •   • ");


    //mix red dice
    vectorStr1.push_back("\033[37;41;1m       ");
    vectorStr2.push_back("\033[37;41;1m   •   ");
    vectorStr3.push_back("\033[37;41;1m       ");

    vectorStr1.push_back("\033[37;46;1m     • ");
    vectorStr2.push_back("\033[37;46;1m       ");
    vectorStr3.push_back("\033[37;46;1m •     ");

    vectorStr1.push_back("\033[37;41;1m     • ");
    vectorStr2.push_back("\033[37;41;1m   •   ");
    vectorStr3.push_back("\033[37;41;1m •     ");

    vectorStr1.push_back("\033[37;42;1m •   • ");
    vectorStr2.push_back("\033[37;42;1m       ");
    vectorStr3.push_back("\033[37;42;1m •   • ");

    vectorStr1.push_back("\033[37;41;1m •   • ");
    vectorStr2.push_back("\033[37;41;1m   •   ");
    vectorStr3.push_back("\033[37;41;1m •   • ");

    vectorStr1.push_back("\033[37;44;1m •   • ");
    vectorStr2.push_back("\033[37;44;1m •   • ");
    vectorStr3.push_back("\033[37;44;1m •   • ");


    // --- full white dice from 1 to 6 to 1
    for(int i = 0; i < 6; i++)
    {
        line1 << vectorStr1[i] << "\033[0m   ";
        line2 << vectorStr2[i] << "\033[0m   ";
        line3 << vectorStr3[i] << "\033[0m   ";

        cout << line1.str() << '\n'
         << line2.str() << '\n'
         << line3.str() << "\033[0m\n\n";

        usleep(100000);
    }

    line1.str("");
    line2.str("");
    line3.str("");

    line1.clear();
    line2.clear();
    line3.clear();


    for(int i = 0; i < 6; i++) // upside down display white
    {
        for(int j = 0; j < 5-i; j++)
        {
            line1 << vectorStr1[j] << "\033[0m   ";
            line2 << vectorStr2[j] << "\033[0m   ";
            line3 << vectorStr3[j] << "\033[0m   ";
        }

        cout << line1.str() << '\n'
             << line2.str() << '\n'
             << line3.str() << "\033[0m\n\n";

        usleep(100000);

        //clear out string for effect
        line1.str("");
        line2.str("");
        line3.str("");

        line1.clear();
        line2.clear();
        line3.clear();
    }
    
    //---------------------------------
    system("clear");
    
    // color dice display from 6 to 1 to 6
    for(int i = 0; i < 5; i++) // upside down display
    {
        for(int j = 6; j < 12-i; j++)
        {
            line1 << vectorStr1[j] << "\033[0m   ";
            line2 << vectorStr2[j] << "\033[0m   ";
            line3 << vectorStr3[j] << "\033[0m   ";
        }
    
        cout << line1.str() << '\n'
             << line2.str() << '\n'
             << line3.str() << "\033[0m\n\n";
    
        usleep(100000);
    
        //clear out string for effect
        line1.str("");
        line2.str("");
        line3.str("");
    
        line1.clear();
        line2.clear();
        line3.clear();
    }
    
    for(int i = 6; i < 12; i++)
    {
        line1 << vectorStr1[i] << "\033[0m   ";
        line2 << vectorStr2[i] << "\033[0m   ";
        line3 << vectorStr3[i] << "\033[0m   ";

        cout << line1.str() << '\n'
         << line2.str() << '\n'
         << line3.str() << "\033[0m\n\n";

        usleep(100000);
    }
    //-----------------------------------
    system("clear");
    
    // --- full white dice from 1 to 6 to 1
    
    //clear out string for effect
    line1.str("");
    line2.str("");
    line3.str("");
    
    line1.clear();
    line2.clear();
    line3.clear();
    for(int i = 0; i < 6; i++)
    {
        line1 << vectorStr1[i] << "\033[0m   ";
        line2 << vectorStr2[i] << "\033[0m   ";
        line3 << vectorStr3[i] << "\033[0m   ";

        cout << line1.str() << '\n'
         << line2.str() << '\n'
         << line3.str() << "\033[0m\n\n";

        usleep(100000);
    }

    line1.str("");
    line2.str("");
    line3.str("");

    line1.clear();
    line2.clear();
    line3.clear();

    for(int i = 0; i < 6; i++) // upside down display white
    {
        for(int j = 0; j < 5-i; j++)
        {
            line1 << vectorStr1[j] << "\033[0m   ";
            line2 << vectorStr2[j] << "\033[0m   ";
            line3 << vectorStr3[j] << "\033[0m   ";
        }

        cout << line1.str() << '\n'
             << line2.str() << '\n'
             << line3.str() << "\033[0m\n\n";

        usleep(100000);

        //clear out string for effect
        line1.str("");
        line2.str("");
        line3.str("");

        line1.clear();
        line2.clear();
        line3.clear();
    }
    
    //---------------------------------
    system("clear");
}

void readClear(string filename)
{
    ifstream infile;
    infile.open(filename);
    bool open = true;
    
    if(!infile.is_open())
    {
        cout << "\nCannot open file.\n";
        usleep(2170444);
        open = false;
    }

    if(open) // if file is open
    {
        vector<string> codeVec;
        string codeLine;
        while(!infile.eof())
        {
            getline(infile, codeLine);
            
            codeVec.push_back(codeLine);
        }
        int setEnd = 0;
        int line = 0;
        bool check = false;
    
        infile.close();
   
        system("clear");
        for(unsigned long i = 0; i < codeVec.size(); i++)
        {
            if(check == false)
            {
                setEnd = rand() % 23 + 18;
                check = true;
                
                //cout << ">>>\t" << endl;
            }
            
            cout << ">>>\t" << codeVec[i] << endl;
            usleep(9000);
            
            line++;
            
            if(line == setEnd)
            {
                check = false;
                line = 0;
                system("clear");
            }
        }
    }
    
    system("clear");
         
    cout << "\n\n\n\033[37;40m====================***Status Checking\n";
    usleep(650000);
    cout << "Scan:     checked\n";
    usleep(360000);
    cout << "Download: checked\n";
    usleep(560000);
    cout << "Access:   granted\n";
    usleep(620000);
    cout << "Passcode: valid\n\n";
    usleep(740000);
    
    cout << "====================***Transfer Status\n";
    usleep(560000);
    cout << "Link:     connected\n";
    usleep(470000);
    cout << "Security: secured\n";
    usleep(650000);
    cout << "Speed:    72 Mbps\n";
    usleep(650000);
    cout << "Transmit: active\n";
    usleep(830000);
    
    cout << "\n\n\nAll systems go: \n";
    usleep(168000);
        
    cout << ".\n";
    usleep(168000);
    cout << ".\n";
    usleep(168000);
    cout << ".\n";
    usleep(168000);
             
    cout << "\n\n\n\n120TH: Completed...\n\n\n\n\n\033[0m";
    usleep(999000);
    system("clear");
}

void loading()
{
    string green{"\033[42m \033[0m"};
    //char dot = ' ';
    string tempStr;
    
    for(int i = 0; i < 25; i++)
    {
        int times = getRandomInt(41704,217044);
        system("clear");

        cout << "\n\n\t\tDice game by \033[1;31m120TH-Grammer\033[0m\n\nLOADING...\n\n";
        
        for(int j = 0; j <= i; j++)
        {
            cout << green << ' ';
        }
        cout << string(55-(i*2), ' ') <<  (i+1) * 4 << "%" << endl;
        usleep(times); 
    }
    usleep(957044);
    system("clear");
}

int getRandomInt(int lowerBound, int upperBound)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(lowerBound, upperBound);

    return dist(mt);
}
