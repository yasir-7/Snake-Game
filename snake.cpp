#include <bits/stdc++.h>
#include <ncurses.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
bool finishGame;
int height = 30;
int width = 25;
int tX[100], tY[100];
int length = 0;
int fX, fY;
int x, y;
int score;

enum movement{
    start = 0,
    l,
    r,
    u,
    d
};
movement m;
void setup(){

    srand(time(NULL));

    m = start;
    finishGame = false;

    x = width/2 + 1;
    y = height/2;

    fX = rand()%width;
    fY = rand()%height;

    score = 0;
}
// enum movement{pause = 0, left, right, up, down};
void drawBound(){
    system("clear");
    for (int i = 0; i < width+2; i++)
    {
        cout << "-";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if(j == 0){
                cout << "-";
            }
            if (i == y && j == x)
            {
                cout << ">";
            }
            else if (i == fY && j == fX)
            {
                cout << "o";
            }
            else
            {   
                int s = 0;
                for (int k = 0; k < length; k++)
                {
                    if (tY[k] == i && tX[k] == j)
                    {
                        cout << ">";
                        s = 1;
                    }
                    
                }
                if (s == 0)
                {
                    cout << " ";
                }    
            }
            if (j == width - 1)
            {
                cout << "-";
            }
            
        }
        cout << endl;
    }
    for (int i = 0; i < width+2; i++)
    {
        cout << "-" ;
    }
    cout << endl<< "Score: " << score;
    cout << endl;
}
void takeInput(){
    char input;

    initscr();
    noecho();
    cbreak();

    input = getch();

    switch (input)
    {
    case 'a':
        m = l;
        break;
    case 'd':
        m = r;
        break;
    case 'w':
        m = u;
        break;
    case 's':
        m = d;
        break;
    case 'x':
        finishGame = true;
        break;
    }
    endwin();
}
void algorithm(){
    int pX1 = tX[0];
    int pY1 = tY[0];
    tX[0] = x;
    tY[0] = y;
    for (int i = 1; i < length; i++)
    {   
        int pX2 = tX[i];
        int pY2 = tY[i];
        tX[i] = pX1;
        tY[i] = pY1;
        pX1 = pX2;
        pY1 = pY2;
    }
    

    switch (m)
    {
    case l:
        x --;
        break;
    case r:
        x ++;
        break;
    case u:
        y --;
        break;
    case d:
        y ++;
        break;
    default:
        break;
    }

    if (x == fX && y == fY)
    {   
        
        score += 1;
        fX = rand()%width;
        fY = rand()%height;
        length ++;
    }
    if (x > width-1 || x < 0 || y > height-1 || y < 0)
    {
        finishGame = true;
    }
    
    
}
int main(){

    setup();
    while (!finishGame)
    {
        drawBound();
        takeInput();
        algorithm();
    }
    
}