#include <bits/stdc++.h>

using namespace std;

void show(char a[]){
    cout<<a[6]<<"|"<<a[7]<<"|"<<a[8]<<endl;
    cout<<"- - -"<<endl;
    cout<<a[3]<<"|"<<a[4]<<"|"<<a[5]<<endl;
    cout<<"- - -"<<endl;
    cout<<a[0]<<"|"<<a[1]<<"|"<<a[2]<<endl<<endl;
}

void play(char a[], int &i){
    if(i == 0){
        cout<<"We will follow the cartesian system for coordinates, starting from (1,1) as bottom left\n"<<endl;
    }
    else{
        cout<<"Player - "<<2 - i%2<<" Input the coordinates of your entry as X coord and Y coord"<<endl;
        int x, y;
        cin>>x>>y;
        if(x>3 || y>3 || x<1 || y<1){
            cout<<"Out of bounds, Please input correct coordinates !!\n";
            i--;
            return;
        }
        if(a[3*(y-1) + x-1] != ' '){
            cout<<"Used Cell, Please input correct coordinates !!\n";
            i--;
            return;
        }
        if(i % 2 == 1){
            a[3*(y-1) + x-1] = '#';
        }
        else{
            a[3*(y-1) + x-1] = 'o';
        }
        cout<<endl;
    }
}

int check(char a[]){
    for(int i = 0; i < 9; i += 3){
        if(a[i] == a[i+1] && a[i+1] == a[i+2] && a[i] != ' ')
            return 1;
    }
    for(int i = 0; i < 3; i++){
        if(a[i] == a[i+3] && a[i+3] == a[i+6] && a[i] != ' ')
            return 1;
    }
    if(a[0] == a[4] && a[4] == a[8] && a[4] != ' ')
        return 1;
    else if(a[2] == a[4] && a[4] == a[6] && a[4] != ' ')
        return 1;
    return 0;
}

void win(int i){
    cout<<"Congratulations Player "<<2 - i % 2<<"! You win\n";
}

int main()
{
    char a[9];
    for(int i = 0; i < 9; i++)
        a[i] = ' ';
    int cond = 0, i = 0;

    while(i <= 9){
        play(a, i);
        show(a);
        int cond = check(a);
        if(cond == 1){
            win(i);
            break;
        }
    i++;
    }
    if(i == 10){
        cout<<"No one wins :( Drawn game";
    }
}