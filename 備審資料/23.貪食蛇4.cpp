#include<iostream>
#include<conio.h>
#include<windows.h>
#include<ctime>
using namespace std;


int length=3; //蛇身長度

int z=0; //方向
char de; //上下左右
int snake[2][10000]; //座標
int s=0; //步驟
int s2=0;
int nowX=38; //現x座標
int nowY=9; //現y座標

int eggX;
int eggY;
int eg=25;
bool gg=1;
bool eaten=1;

int teggX;
int teggY;
int teg;
bool tgg=1;
bool teaten=1;

int pxy[20][80]={
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
};

bool k=1; //結束變數


void SetColor(int color = 7){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,color);
}


void gotoxy(int xpos, int ypos){
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
}


void wall(int num){
    for(int i=0;i<20;i++){
        for(int j=0;j<80;j++){
            switch(pxy[i][j]){
                case 2:
                    if(num==0){
                        gotoxy(j,i);
                        cout<<"W";
                    }
                    if(num==1){
                        if(nowX==j && nowY==i)
                            k=0;
                    }
                    break;
            }
        }
    }
}


void end(){
	wall(1);
	for(int i=s-1;i>s2;i--){
	    if(nowX==snake[0][i] && nowY==snake[1][i])
	        k=0;
    }
}


void keyboardControll(){
    while( kbhit() ){
		switch( de=getch() ){
	        case -32:
	            switch( de=getch() ){
	                case 0x48: //上
	                	if(z!=-1)
	                    	z=1;
						break;
	                case 0x50: //下
	                	if(z!=1)
	                	    z=-1;
                        break;
	                case 0x4B: //左
	                	if(z!=-2)
	                    	z=2;
                        break;
	                case 0x4D: //右
	                	if(z!=2)
	                    	z=-2;
                        break;
	                default:
	                	break;
	            }
			default:
            	break;
	    }
    }
}


void body(){
    keyboardControll();
    switch(z){
    	case 1:
    		nowY+=-1;
    		break;
    	case -1:
    		nowY+=1;
    		break;
    	case 2:
    		nowX+=-1;
    		break;
    	case -2:
    		nowX+=1;
    		break;
	}
	snake[0][s]=nowX;
	snake[1][s]=nowY;
	end();
	gotoxy(nowX,nowY);
	cout<<"O";
    if(nowX==eggX&&nowY==eggY){
        length+=1;
        eg=20;
        eaten=1;
        teaten=1;
    }
    else if(nowX==teggX&&nowY==teggY){
        length+=4;
        teg=40;
        teaten=1;
    }
    else{
        gotoxy(snake[0][s2],snake[1][s2]);
        cout<<" ";
    }
}


void eggBorn(bool num){
    if(num==1&&eg<=0){
        do{
            eggX=rand()%47+1;
            eggY=rand()%17+1;
            for(int i=s;i>=s2;i--){
            	int j=i;
            	if(i<0)
            		j+1600;
                if(snake[0][j]==eggX&&snake[1][j]==eggY)
                    gg=0;
                else
                    gg=1;
            }
        } while(gg==0);
        gotoxy(eggX,eggY);
        cout<<"Q";
        eaten=0;
        eg=20;
    }
    if(num==1)
        eg--;
}


void timeLimitEgg(){
    if(length%10==0 && teaten==1){
        do{
            teggX=rand()%47+1;
            teggY=rand()%17+1;
            for(int i=s;i>=s2;i--){
            	int j=i;
            	if(i<0)
            		j+1600;
                if(snake[0][j]==teggX&&snake[1][j]==teggY)
                    tgg=0;
                else
                    tgg=1;
            }
        } while(tgg==0);
        SetColor(12);
        gotoxy(teggX,teggY);
        cout<<"w";
        SetColor(7);
        teg=10;
        teaten=0;
    }
    if(teg<=0){
        gotoxy(teggX,teggY);
        cout<<" ";
    }
    teg--;
}


void run(){
	s2=s-length+1;
    s++;
    eggBorn(eaten);
    timeLimitEgg();
    eg--;
    if(length>30)
        Sleep(10);
    else
        Sleep(100-length*3);
    body();
}


int main(){
    srand(time(0));
    wall(0);
    gotoxy(38,9);
    cout<<"O";
    gotoxy(38,9);
    while(z==0){
        keyboardControll();
    }
    cout<<" ";
    eaten=1;
    wall(0);
    while(k){
        run();
        gotoxy(1,21);
        cout<<"長度： "<<length;
    };
    wall(0);
    system("cls");
    system("color CE");
    gotoxy(2,2);
    cout<<"GameOver.\n  總長： "<<length;
    gotoxy(2,6);
    system("pause");
    return 0;
}
