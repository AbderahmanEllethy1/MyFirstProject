#include<bits/stdc++.h>
using namespace std;
int array1[3][3],h,j;
// take the place to play
bool insertindex(int score){
    cout<<"which turn it is? [1/2]\n";
cin>>score;
cout<<"enter place to play\n";
cin>>h;
cin>>j;
//check if the place is already taken
if(array1[h][j]==0 && h>=0 && h<3 && j>=0 && j<3){
array1[h][j]=score;
return true;}
else
    return false;
}
//put all the places with zeros
int resetarray1(){
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        array1[i][j]=0;
    }
}
}
//check if there is a draw or win
int check(){
 //check all the rows and coloums
for(int i=0;i<3;i++){
//check all of the rows
//array1[i][0]!=0 this is for checking the initial state of playing to avoid the win without playing
if(array1[i][0]==array1[i][1]&&array1[i][1]==array1[i][2]&&array1[i][0]!=0){
        cout<<array1[i][0]<<"wins\n";
        resetarray1();
        return 1;
}
//check all of the coloums
else if(array1[0][i]==array1[1][i]&&array1[1][i]==array1[2][i]&&array1[2][i]!=0){
        cout<<array1[0][i]<<"wins\n";
        resetarray1();
        return 1;}

}
// both of them is checking on the diagonal
        if(array1[0][0]==array1[1][1]&&array1[1][1]==array1[2][2]&&array1[0][0]!=0){
            cout<<array1[0][0]<<"wins\n";
            resetarray1();
            return 1;
        }
        else if(array1[0][2]==array1[1][1]&&array1[1][1]==array1[2][0]&&array1[2][0]!=0){
            cout<<array1[0][2]<<"wins\n";
            resetarray1();
            return 1;
        }
        // if there is a free space it means that the game is still running
        for (int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if (array1[i][j]==0)
                    return 0;
            }
        }
        cout<<"draw\n";
        resetarray1();
        return 2;
}
int main ()
{
int score=0;
//if the players want to play again
char r;
while(1){
//print the updated array
for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                cout<<array1[x][y]<<' ';
            }
            cout<<endl;
        }

//to check if the player enter in a wrong place
while(insertindex(score)==false){
    cout<<"please insert in another index";
}
//to clear the screen
system("cls");
cout<<endl;
//to the game if it is ended then ask them if they want to play again
        if(check()!=0){
            cout<<"do u want to play again?y or n";
            cin>>r;
            if(r=='n'){
                break;
            }
        }
}
return 0;
}
