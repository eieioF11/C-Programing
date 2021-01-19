#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstdlib>
#include <fcntl.h>
#include <termios.h>
#include <time.h>
#include "screen/screen.h"
#include "brock/brock.h"

static struct termios old, now;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
	tcgetattr(0, &old);					/* grab old terminal i/o settings */
	now = old;							/* make new settings same as old settings */
	now.c_lflag &= ~ICANON;				/* disable buffered i/o */
	now.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
	tcsetattr(0, TCSANOW, &now);		/* use these new terminal i/o settings now */
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

int kbhit(void)
{
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

	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}

void InputKey(int *cmd, int *x, int *y, int *angle, bool xlstop, bool xrstop, bool ystop)
{
	/* 変数の定義 */
	int key;
	/* キー入力がある場合 */
	if (kbhit())
	{
		/* キーの値を読み込む */
		key = getch();
		*cmd = 1;
		switch (key)
		{
		//case 'w':*y-=1;break;
		case 's':
			if (!ystop)
				*y += 1;
			break;
		case 'a':
			if (!xlstop)
				*x -= 1;
			break;
		case 'd':
			if (!xrstop)
				*x += 1;
			break;
		case 'z':
			if (*angle <= 0)
				*angle = 3;
			else
				*angle -= 1;
			break;
		case 'x':
			if (*angle >= 3)
				*angle = 0;
			else
				*angle += 1;
			break;
		case 'q':
			*cmd = 0;
			break;
		}
	}
	else
		*cmd = 2;
}

void VariableClear()
{
	for (int i = 0; i < fy; i++)
	{
		for (int j = 0; j < fx; j++)
		{
			if (brockloceation[i - 1][j - 1] == 0)
				field[i][j] = BLACK;
			//else field[i][j]=WHITE;
			if (i == 0)
				field[i][j] = WHITE;
			if (j == 0)
				field[i][j] = WHITE;
			if (i == fy - 1)
				field[i][j] = WHITE;
			if (j == fx - 1)
				field[i][j] = WHITE;
		}
	}
}

int main(void)
{
	int x, y, angle;
	int cmd = 0;
	int type = 0;
	int color = RED;
	int t = 0;
	bool end = false;
	int score = 0;
	bool xlstop = false, xrstop = false, ystop = false;
	x = y = 1;
	angle = 0;
	clearScreen();
	while (true)
	{
		if (t > 500)
		{
			t = 0;
			if (brockloceation[y][x - 1] != 1)
				y++;
		}
		VariableClear();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (brock[type][angle][i][j])
				{
					if (end)
						brockloceation[y + i - 1][x + j - 1] = 1;
					else
					{
						if (brockloceation[y + i - 1][x + j] == 1)
							xrstop = true;
						//else xrstop=false;
						if (brockloceation[y + i - 1][x + j - 2] == 1)
							xlstop = true;
						//else xlstop=false;
						if (brockloceation[y + i][x + j - 1] == 1)
						{
							ystop = true;
							if (cmd == 2)
							{
								i = j = -1;
								end = true;
							}
						}
					}
					if (!end && x + j < 1)
						x = 1 - j;
					if (!end && y + i < 1)
						y = 1 - i;
					if (!end && x + j > fx - 2)
						x = (fx - 2) - j;
					if (!end && y + i > fy - 2)
					{
						y = (fy - 2) - i;
						if (cmd == 2)
						{
							i = j = -1;
							end = true;
						}
					}
					if (i != -1 || j != -1)
						field[y + i][x + j] = color;
				}
			}
		}
		if (end)
		{
			x = y = 1;
			type = rand() % brocknum + 0;
			color = rand() % CYAN + RED;
			xlstop = xrstop = ystop = end = false;
			for (int j = 0; j < fx - 2; j++)
			{
				if (brockloceation[0][j] == 1)
				{
					end = true;
					break;
				}
			}
		}
		ScreenOutput(&score);
		InputKey(&cmd, &x, &y, &angle, xlstop, xrstop, ystop);
		if (cmd == 0)
			break;
		t += 5;
		if (end)
			break;
		wait(5);
	}
	setCharColor(DEFAULT);
	setBackColor(DEFAULT);
	clearScreen();
	if (end)
		printf("\nGAME OVER!!\n");
	printf("\nExit\n");
	return 0;
}