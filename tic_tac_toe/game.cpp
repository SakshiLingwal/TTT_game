#include<iostream>
using namespace std;
char matrix[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//global variable declaration
int row,column;
string nm1=" ";
string nm2=" ";
int digit;
char token='x';
bool draw=false;
//this func. shows the current status of game 
void show()
{
    cout<<"   |     |     \n";
    cout<<" "<<matrix[0][0]<<" | "<<matrix[0][1]<<"   | "<<matrix[0][2]<<" \n";
    cout<<"___|_____|_____\n";
    cout<<"   |     |     \n";
    cout<<" "<<matrix[1][0]<<" | "<<matrix[1][1]<<"   | "<<matrix[1][2]<<" \n";
    cout<<"___|_____|_____\n";
    cout<<"   |     |     \n";
    cout<<" "<<matrix[2][0]<<" | "<<matrix[2][1]<<"   | "<<matrix[2][2]<<" \n";
    cout<<"   |     |     \n";
}
//this func get player i/p & update the game status
void player_turn()
{
    if(token=='x')
    {
        cout<<nm1<<" Please enter a digit b/w 1 to 9 ";   //digit should be b/w 1 to 9
        cin>>digit;
    }
    else if(token=='O')
    {
        cout<<nm2<<" Please enter "; //similar to player 1
        cin>>digit;       
    }
    switch(digit)
    {
    case 1:row=0;column=0;break;
    case 2:row=0;column=1;break;
    case 3:row=0;column=2;break;
    case 4:row=1;column=0;break;
    case 5:row=1;column=1;break;
    case 6:row=1;column=2;break;
    case 7:row=2;column=0;break;
    case 8:row=2;column=1;break;
    case 9:row=2;column=2;break;

    default: cout<<"Invalid input !!"<<endl;
        //break;
    }  

    if(token=='x' && matrix[row][column]!='x' && matrix[row][column]!='O')   //if there is any unused space in matrix then-
    {
        matrix[row][column]='x';
        token='O';
    }
    
    else if(token=='O' && matrix[row][column]!='x' && matrix[row][column]!='O')
    {
        matrix[row][column]='O';
        token='x';
    }
    else
    {
        cout<<"There is no empty space in the matrix"<<endl;
        player_turn();
    }
    show();
}
//this function checks whether the game is finished or not
bool end()
{
    for(int i=0;i<3;i++)    //cond. to win the game!!
    {
        //check straight line ele are same or not
        if(matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2] || matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i])
        {
            return false;
        }
        //check in diagonal ele
        if(matrix[0][0]==matrix[1][1] && matrix[0][0]==matrix[2][2] || matrix[0][2]==matrix[1][1] && matrix[0][2]==matrix[2][0])
        {
            return false;
        }
    }
    //check whether game is still going on
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(matrix[i][j]!='x' && matrix[i][j]!='O')      //means some space is left in the matrix
            {
                return true;
            }                
        }
    }
    draw=true;   //when game is draw
    return false;
}
int main()
{
    cout<<"\t\t\tT I C K -- T A C -- T O E -- G A M E\n";
    cout<<"\t\t\t\tFOR 2 PLAYERS\n";
    cout<<"Enter the name of player 1 :";
    getline(cin,nm1);
    cout<<"Enter the name of player 1 :";
    getline(cin,nm2);

    cout<<nm1<<"[X]"<<endl;
    cout<<nm2<<"[O]"<<endl;

    while(end())     //loop runs till any one of the player will win or game will be draw
    {
       //show();
       player_turn();
       end();
    }
    if(token=='x' && draw==false)
    {
        cout<<nm2<<" Wins !!"<<endl;
    }
    else if(token=='O' && draw==false)
    {
        cout<<nm1<<" Wins !!"<<endl;
    }
    else
    {
        cout<<"It's a draw !!"<<endl;
    }
}