#include <ncurses.h>
#include <string.h>

#define MINPUT    3
int main(int argc, char *argv[]){
   WINDOW *winses, *winmsg;
   int t_line, t_col,
       i, j;
   char ses[] = "-[ Seasion ]-";
   initscr();
   nocbreak();
   refresh();


   start_color();
   init_pair(1, COLOR_BLACK, COLOR_WHITE);
//   init_pair(0, 0, 0);

   getmaxyx(stdscr, t_line, t_col);
   printw("+%s",ses);
   for(i = 0; i < (t_col - strlen(ses)) - 2; i++){
      addch('-');
   }
   addch('+');
   
   for(i = 0; i < (t_line - MINPUT) - 1; i++){
      addch('|');
      for (j = 0; j < t_col - 2; j++)
         addch(' ');
      printw("|");
   } 
   addch('+');
   for(i = 0; i < (t_col - strlen(ses)) - 2; i++){
      addch('-');
   }
   printw("%s+", ses);

   attron(COLOR_PAIR(1));
   printw("[ UDP Local Chat ] - Remote 192.168.0.10, Duration MM:SS");
   use_default_colors();
   printw("\n>");

   wrefresh(stdscr);
   winses = newwin(t_line - (MINPUT + 2), t_col - 4, 0, 0);
   mvwin(winses, 2, 2);
   scrollok(winses, TRUE);
   wrefresh(winses);
 
   refresh();
   winmsg = newwin(1, t_col-3, 0, 0);
   mvwin(winmsg, t_line - 1, 2);
   scrollok(winmsg, TRUE);
   wrefresh(winmsg);

   while(1){
      wrefresh(winmsg);
      waddch(winses,wgetch(winmsg));
      wrefresh(winses);
   }

   getch();
   endwin();

   return 0;
}
