#define _GNU_SOURCE
#include <ncursesw/ncurses.h>
#include <locale.h>
#include <math.h>
#include <wchar.h>
#include <string.h>
#include <time.h>
#include <stdio.h>	//for fopen
#include "face.h"

#define pair1 1
#define pair2 2
#define pair3 3

struct tm *tim;
time_t ntim;
char a[50];


void mwin_init (void)
{


    int mx, my, x;
    setlocale(LC_ALL, "en_US.UTF-8");
    WINDOW *stdscr = initscr();
    getmaxyx(stdscr, my, mx);
	
	raw();
	keypad(stdscr, TRUE);
	halfdelay(1);
	curs_set(0);
    start_color();

    init_pair(pair1, COLOR_BLACK, COLOR_WHITE);
    init_pair(pair2, COLOR_GREEN, COLOR_WHITE);
    init_pair(pair3, COLOR_RED, COLOR_WHITE);

    attron(COLOR_PAIR(pair1));
    bkgdset (COLOR_PAIR(pair1));
    clear();
    refresh();
    //attron(A_BOLD);
    move (0,0);
    echochar(0x400043);
    for (x=1; x < (mx-1); x++)
    {
	if ((x ==14 )  || (x == (mx-15)) )
	{
	    echochar(0x400049);
	}
	else
	{
	    echochar(0x400052);
	}
    }
    echochar(0x400042);
    move (1,0);
    echochar(0x400059);
    move (1,14);
    echochar(0x400059);
    move (1,mx-15);
    echochar(0x400059);
    move (1,mx-1);
    echochar(0x400059);
    move (2,0);
    echochar(0x400046);
    for (x=1; x < (mx-1); x++)
    {
	if ((x ==14 )  || (x == (mx-15)) )
	{
	    echochar(0x400048);
	}
	else
	{
	    echochar(0x400052);
	}
    }
    echochar(0x400047);
    //attron(COLOR_PAIR(2));
    for (x=3; x < (my-2); x++)
    {
	move (x,0);
	echochar(0x400059);
	move (x,mx-1);
	echochar(0x400059);
    }
    move (my-2,0);
    echochar(0x400044);
    for (x=1; x < (mx-1); x++)
    {
	echochar(0x400052);
    }
    echochar(0x400041);
////////////////////////////////////////////////////////////
    pltab(5,5);


/////////////////////////////////////////////////////////////

    move (1,3);
    printw ("y=%d x=%d", my, mx);
    refresh();

    ntim=time(NULL);
    tim=localtime(&ntim);
//    move (7,7);
//    printw("ttttt=%d", ntim);
//    printw(asctime(tim));
//    move (8,7);
//    printw("%d:%d:%d", tim->tm_hour, tim->tm_min, tim->tm_sec);

    move (1,117);
    strftime(a,50,"%H:%M:%S",tim);
    attron(COLOR_PAIR(pair2));
    printw("%s",a);
    

    refresh();
}
//erase();
/*

for (a1=0; a1<117; a1++)
{
move(5,5+a1);
echochar(0x400052);
move(31,5+a1);
echochar(0x400052);
}
for (a1=0; a1<25; a1++)
{
move(6+a1,4);
echochar(0x400059);
move(6+a1,122);
echochar(0x400059);
}
move(5,4);
echochar(0x400043);
move(31,4);
echochar(0x400044);
move(5,122);
echochar(0x400042);
move(31,122);
echochar(0x400041);

//  uuuu

move(6,5);
echochar(0x40006c);
echochar(0x400071);
echochar(0x400071);
echochar(0x400077);
echochar(0x400071);
echochar(0x400071);
echochar(0x40006b);
move(7,5);
echochar(0x400078);
echochar(0x400066);
echochar(0x400067);
echochar(0x400078);
echochar(0x400079);
echochar(0x40007a);
echochar(0x400078);
move(8,5);
echochar(0x400074);
echochar(0x400071);
echochar(0x400071);
echochar(0x40006e);
echochar(0x400071);
echochar(0x400071);
echochar(0x400075);
move(9,5);
echochar(0x400078);
echochar(0x40007b);
echochar(0x400061);
echochar(0x400078);
echochar(0x400061);
echochar(0x400061);
echochar(0x400078);
move(10,5);
echochar(0x40006d);
echochar(0x400071);
echochar(0x400071);
echochar(0x400076);
echochar(0x400071);
echochar(0x400071);
echochar(0x40006a);


move(6,20);
echochar(0x400043);
echochar(0x400052);
echochar(0x400052);
echochar(0x400049);
echochar(0x400052);
echochar(0x400052);
echochar(0x400042);
move(7,20);
echochar(0x400059);
echochar(0x400020);
echochar(0x40002b);
echochar(0x400059);
echochar(0x40002c);
echochar(0x400020);
echochar(0x400059);
move(8,20);
echochar(0x400046);
echochar(0x400052);
echochar(0x400052);
echochar(0x400045);
echochar(0x400052);
echochar(0x400052);
echochar(0x400047);
move(9,20);
echochar(0x400059);
echochar(0x400061);
echochar(0x40002d);
echochar(0x400059);
echochar(0x40002e);
echochar(0x400061);
echochar(0x400059);
move(10,20);
echochar(0x400044);
echochar(0x400052);
echochar(0x400052);
echochar(0x400048);
echochar(0x400052);
echochar(0x400052);
echochar(0x400041);

*/

//refresh();



/*    
move (10, 20);

//getyx(10,10);


	curs_set(2);
	printw ("Bm=\t");
//    refresh();
	scanw ("%f", &Bm);
	move (11,20);
	printw ("g=\t");
//    refresh();
	scanw ("%f", &g);
//	curs_set(0);
	Hg = Bm /mo;
	move (11,30);
	printw ("Hg=\t%8.4f", Hg);
	refresh();
	move (12,20);
	printw ("Le=\t");
	scanw ("%f", &Le);
	move (13,20);
	printw ("Hm=\t");
	scanw ("%f", &Hm);

	move (15,25);
	IW = Hg * g * 1e-3 + Hm * 1e-3 * Le;
	printw ("IW=\t%3.1f", IW);
	
	
	move (18,25);    

*/
//    attroff(A_BOLD);

//    refresh();

//    getch();
void mwin_out (void)
{
    endwin();
}
void pltab (int py, int px)
{
    int ptx, pty;
    for (pty=0; pty<16; pty++)
    {
	for (ptx=0; ptx<8; ptx++)
		{
	
	
	
		}
    }


}


void wrefr (void)
{
	FILE *fl;
	char cap[5];
    ntim=time(NULL);
    tim=localtime(&ntim);
//    move (7,7);
//    printw("ttttt=%d", ntim);
//    printw(asctime(tim));
//    move (8,7);
//    printw("%d:%d:%d", tim->tm_hour, tim->tm_min, tim->tm_sec);

    move (1,117);
    strftime(a,50,"%H:%M:%S",tim);
    attron(COLOR_PAIR(pair2));
    printw("%s",a);
///////////
	//char pathf[]="/sys/class/power_supply/BAT0/capasity";
	fl = fopen( "/sys/class/power_supply/BAT0/capacity", "r");
    if ( fl != 0 )
	{
		fscanf (fl, "%s", cap);
		move (1,108);
		attron(COLOR_PAIR(pair1));
		printw ("%s%% ", cap);
		fclose(fl);
	}
	else
	{
	move (1,108);
	attron(COLOR_PAIR(pair3));
	printw ("%s","err");
	}

    refresh();


}
