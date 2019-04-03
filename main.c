#define _GNU_SOURCE
#include <ncursesw/ncurses.h>

//#include <ncursesw/cursesw.h>
#include <locale.h>
#include <math.h>
#include <wchar.h>
#include <string.h>

float Bm, g, Hg, U1min, U2, Kt, I1, I1ef, I2, I2ef, Le, Hm, IW, f, J, ko, Pu;
float ScSo, Sc, So, ew, w1, w2;
const float mo = 4 * M_PI * 1e-7;

int mx, my, x, y, s, a1, a2;
wchar_t sim[]= { 0x0000L, 0x0000L};
//lomg int sim[2];
//sim[1]=L0x0000;
#define COLOR_BLUE_YELLOW 1

int main(int argc, char *argv[])
{


//    printw("y=%d  x=%d", my, mx);

    setlocale(LC_ALL, "en_US.UTF-8"); // Включення підтримки юнікод
    //SetConsoleOutputCP (1251);
//    setlocale(LC_CTYPE,"UA");
//
//    // Ініціалізація ncurses (зчитування конфігурації термінала)
    WINDOW *stdscr = initscr();
    getmaxyx(stdscr, my, mx);
//    // Ініціалізація кольорового режиму і створення пари кольорів для фону і тексту
    start_color();
    
    init_pair(COLOR_BLUE_YELLOW, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
//    // Початок відображення в заданому кольоровому режимі
    attron(COLOR_PAIR(COLOR_BLUE_YELLOW));

//    //COLOR_YELLOW фактично є коричневим. Для того щоб отримати жовтий, використовують COLOR_YELLOW 
//    //в поєднанні з атрибутом A_BOLD.
//    attron(A_BOLD);
//	erase();
//	refresh();



bkgdset (COLOR_PAIR(COLOR_BLUE_YELLOW));
clear();
sim[0]=0x2550;
for (x=1; x < (mx-1); x++)
{
//sim++;
//mvaddwstr(1,x,y);
sim[0]=0x2550;
//move (0,x);
//echochar('=');
mvaddwstr (0,x,sim);
//mvadd_wch (0,x,sim);
//printw ("%s",'=');
//move (my-1,x);
//printw ("%s",'*');
//move (3,x);
//echochar('=');
//move (5,x);
//echochar ('-');
//move (x/3,x);
//printw ("%c", sim );
//while (1)
//{

mvaddwstr (my-1,x,sim);
//move (25,25);
//printw ("%s", sim);
sim[0]=0x2550;
mvaddwstr (2,x,sim);
//}
}
sim[0]=0x2551;
for (x=0; x < (my); x++)
{
//y++;
//mvaddwstr(1,x,y);

//move (x,0);
//echochar('|');
//printw ("%s",'*');
//move (x,mx-1);
//printw ("%s",'*');
//move (3,x);
//echochar('|');
mvaddwstr (x,0,sim);
mvaddwstr (x,mx-1,sim);
}

sim[0]=0x2554;
mvaddwstr (0,0,sim);
sim[0]=0x255a;
mvaddwstr (my-1,0,sim);
sim[0]=0x2557;
mvaddwstr (0,mx-1,sim);
sim[0]=0x255d;
mvaddwstr (my-1,mx-1,sim);
sim[0]=0x2560;
mvaddwstr (2,0,sim);
sim[0]=0x2563;
mvaddwstr (2,mx-1,sim);


sim[0]=0x2566;
mvaddwstr (0,108,sim);
sim[0]=0x2569;
mvaddwstr (2,108,sim);
sim[0]=0x2551;
mvaddwstr (1,108,sim);
refresh();
attron(COLOR_PAIR(2));
//0x2500
int start = 0x2500;
for (a2=0;a2<8;a2++)
{
    move (5+a2*2,3);
    printw("%x", start+a2*32);
    for (a1=0;a1<32;a1++)
    {
	sim[0]=start+a1+a2*32;
	//mvaddwstr (5+a2*2, a1*2+10, sim);
	move (5+a2*2,a1*2+10);
	echochar(0x400000+a1+a2*32);
    }
    refresh();
//    beep();


}

for (a2=0;a2<8;a2++)
{
    move (5+a2*2,3);
    printw("%x", start+a2*32);
    for (a1=0;a1<32;a1++)
    {
	sim[0]=start+a1+a2*32;
	//mvaddwstr (5+a2*2, a1*2+10, sim);
	move (5+(a2+8)*2,a1*2+10);
	echochar(0x000000+a1+a2*32);
    }
    refresh();
//    beep();


}



	sim[0]=ACS_PI;
	mvaddwstr (1, 10, sim);
	move (1,15);
	echochar(ACS_ULCORNER);
	echochar(ACS_HLINE);
	echochar(ACS_LLCORNER);
	echochar(ACS_URCORNER);
	echochar(ACS_LRCORNER);
	echochar(ACS_LTEE);
	echochar(ACS_RTEE);
	echochar(ACS_BTEE);
	echochar(ACS_TTEE);
echochar('-');
printw("%x",ACS_VLINE);

//move (1,20);
//printw ("color white = %d color black = %d color green = %d", COLOR_WHITE, COLOR_BLACK, COLOR_GREEN);

attron(COLOR_PAIR(COLOR_BLUE_YELLOW));
refresh();
move (1,114);
printw ("y=%d x=%d", my, mx);
//erase();
refresh();



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
    printw("The End!");

//    attroff(A_BOLD);

    // Вивести текст без налаштування кольору
    attroff(COLOR_PAIR(1));

move (20,27);
    printw("OUT");
*/
    // Оновлення екрану
    refresh();

    // Очікування натиснення клавіші перед завершенням програми
    getch();

    // Відновлення початкового налаштування терміналу
    endwin();
}
// gcc main.c  !!!! -lncurses
