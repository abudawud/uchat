/* COPYRIGHT
 * Copyright (C) 2016  Ahmad Waris Al H
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * AUTHOR
 * Amad Waris Al H (warisafidz@gmail.com)
*/

#include <ncurses.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>

#define UDP_PROTO    17
#define MINPUT       3


static WINDOW *winses, *winmsg;

static void initwin(void);
static int geti(void);
static void puto(const char c);
static void refi(void);
static void refo(void);
static void printe(const char *msg);

int main(int argc, char *argv[]){
   int sfd;
   struct sockaddr_in addr;
   initwin();

   sfd = socket(AF_INET, SOCK_DGRAM, UDP_PROTO);
   if(sfd == -1){
      printe("Socket: ");
      exit(EXIT_FAILURE);
   }

   if (SERVER)


   while(1){
      refi();
      puto(geti());
      refo();
   }

   getch();
   endwin();

   return 0;
}
  
static void initwin(void){
   int t_line, t_col,
       i, j;
   char ses[] = "-[ Seasion ]-";
   initscr();
   nocbreak();
   refresh();


   start_color();
   init_pair(1, COLOR_BLACK, COLOR_WHITE);

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
}

static int geti(void){
   return (wgetch(winmsg));
}

static void puto(const char c){
   waddch(winses, c);
}

static void refi(void){
   wrefresh(winmsg);
}

static void refo(void){
   wrefresh(winses);
}
