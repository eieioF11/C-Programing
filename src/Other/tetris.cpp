#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstdlib>
#include <fcntl.h>
#include <termios.h>

#define ESC 0x1B
#define x 0
#define y 1

int location[2]={0};

static struct termios old, now;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  now = old; /* make new settings same as old settings */
  now.c_lflag &= ~ICANON; /* disable buffered i/o */
  now.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &now); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}

int kbhit(void){
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void InputKey(int *cmd){
	/* 変数の定義 */
	int key;
	/* キー入力がある場合 */
	if (kbhit())
    {
		/* 画面クリア*/
        printf("%c[2J", ESC);    /* 画面消去 */
        printf("%c[>5h", ESC);   /* カーソル消去 */
		/* キーの値を読み込む */
		key = getch();
        *cmd=1;
        switch(key)
        {
            case 'w':location[y]++;break;
            case 's':location[y]--;break;
            case 'a':location[x]--;break;
            case 'd':location[x]++;break;
            case 'q':*cmd = 0;printf("\nExit\n");break;
        }
	}
    else *cmd=2;

}
void clear()
{
    //struct winsize ws;
    //ioctl( STDOUT_FILENO, TIOCGWINSZ, &ws );
    printf("%c[2J",ESC);    /* 画面消去 */
    //printf("%c[K",ESC);
    //printf("%c[%dA",ESC,ws.ws_row);
}

int main(void)
{
    int cmd=0;
    clear();
    printf("%c[>5h",ESC);   /* カーソル消去 */
    printf("%c[33m", ESC);   /* 文字を黄色に */
    while(true)
    {
		InputKey(&cmd);
		if(cmd == 0)break;
        if(cmd==1)
        {
            clear();
            //printf("\x1b[49m");
            printf("%c[%d;%dH",ESC,location[y],location[x]);
            //printf("\x1b[47m \x1b[49m\n");
            printf("o\n");
        }
    }
    printf("%c[>5l",ESC);  /* カーソル表示 */
    printf("%c[39m",ESC);  /* 文字色を戻す */
    return 0;
}