/*
����Ӣ�����뷨��������Ϸ
���޷�����  �� www.easyx.cn ����������

*/

#include<conio.h>
#include<graphics.h>
#include<windows.h>
#include<cstdio>
#include<time.h>
void link();    //������
void move();    //�ƶ�����Ϸ����
void point(int,int);   //�ı�����
void write();    //����
void food();     //����ʳ��
bool eat();     //�ж��Ƿ�Ե�ʳ��
bool correct(char step);   //�б���Ч����
char s[100];    
char aim;
bool limit();    //�ж��Ƿ������ҧ������
int time_,wait;
struct snake_ {
	int x[300];
	int y[300];
	int length;

}snake;
char step,step_s;
int food_x;
int food_y;
int main() {
	snake.length = 0;
	printf("1.��   2.һ��    3.����   ������ͣ��ʱ�䣨���룩");
	scanf("%d", &time_);   //����ͣ�Ŷ�ʱ��
	switch (time_) {
	case 1:
		wait = 456;
		break;
	case 2:
		wait = 300;
		break;
	case 3:
		wait = 123;
		break;
	default:
		wait = time_;




	}

	initgraph(960, 720);

	setfillcolor(RGB(100,200,150));    //ǰ��ɫ
	setbkcolor(RGB(100,120,140));    //����ɫ
	clearrectangle(0, 0, 960, 720);
	srand((unsigned)time(NULL));
	//setorigin(rand() % 650 + 50, rand() % 550 + 50);
	snake.x[0] = rand() % 650%10*10+ 50;   //���ɳ�ʼλ��
	snake.y[0] = rand() % 550%10*10 + 50;

	link(); //setbkcolor(RED);
	food();
	fillrectangle(snake.x[0], snake.y[0], snake.x[0] + 10, snake.y[0] + 10);

	step =getch();
	while (!correct(step)) {   //ʶ���׷������Ч����
		step = getch();
	}
	move();

}

void link() {
	/*line(50, 50, 700, 50);
	line(50, 50, 50, 600);
	line(50, 600, 700, 600);
	line(700, 50, 700, 600);*/
	int heigh = 50;
	int longg = 50;
	for (heigh; heigh <= 600; heigh = heigh + 10)
		line(50, heigh, 600, heigh);
	for (; longg <= 600; longg = longg + 10)
		line(longg,50, longg, 600);
	sprintf(s, "����Ϊ �� %d", snake.length+1);
	outtextxy(750, 250, s);
}

void move() {
	fillrectangle(snake.x[0], snake.y[0], snake.x[0] + 10, snake.y[0] + 10);
	while (1) {
		switch (step) {
		case 'w':
		case 'W':
			point(0, -10);
			break;
		case 's':
		case 'S':
			point(0, 10);
			break;
		case 'a':
		case 'A':
			point(-10, 0);
			break;
		case 'd':
		case 'D':
			point(10, 0);
			break;
		}
		aim = step;
		if (limit())    //�ж��Ƿ�����
			break;
		if (eat()) {   //�ж��Ƿ�Ե�ʳ��
			snake.length++;   //���ӳ���
			snake.x[snake.length] = snake.x[snake.length - 1] + 10;
			snake.y[snake.length] = snake.y[snake.length - 1];    //��������λ��
			food();   //��������ʳ��
			 
		}
		write();
		Sleep(wait);  //�ȴ�ʱ��
		/*if (kbhit() ){

			step_s = _getch();
			if (((step == 's' || step == 'S') && (step_s != 'W' && step_s != 'W')) ||
				((step == 'w' || step == 'W') && (step_s != 's' && step_s != 'S')) ||
				((step == 'a' || step == 'A') && (step_s != 'd' && step_s != 'D')) ||
				((step == 'd' || step == 'D') && (step_s != 'a' && step_s != 'A')))

				step = step_s;

		}
		if (step != 'a'&&step != 'A'&&step != 's'&&step != 'S'&&step != 'w'&&step != 'W'&&step != 'd'&&step != 'D')
			step = 'a';

	}*/
		if (_kbhit()) {
			step_s = _getch();
			if (correct(step_s))   //��ֹ����ǰ��
				if (((step == 's' || step == 'S') && (step_s != 'W' && step_s != 'W')) ||
					((step == 'w' || step == 'W') && (step_s != 's' && step_s != 'S')) ||
					((step == 'a' || step == 'A') && (step_s != 'd' && step_s != 'D')) ||
					((step == 'd' || step == 'D') && (step_s != 'a' && step_s != 'A')))

					step = step_s;
		}
	}


	//����������ɼ�
		outtextxy(50, 50, "out");
		sprintf(s, "���гɼ� %d", snake.length + 1);
		outtextxy(150, 50, "out");
		Sleep(50000);
	
}

void point(int x, int y) {

	//��ȥ��β
	clearrectangle(snake.x[snake.length], snake.y[snake.length], snake.x[snake.length] + 10, 10 + snake.y[snake.length]);
	//�ػ���ʧ�߿�
	line(snake.x[snake.length], snake.y[snake.length], snake.x[snake.length] + 10, snake.y[snake.length]);
	line(snake.x[snake.length], snake.y[snake.length], snake.x[snake.length] , 10+snake.y[snake.length]);
	line(snake.x[snake.length]+10, snake.y[snake.length], snake.x[snake.length] + 10, snake.y[snake.length]+10);
	line(snake.x[snake.length], snake.y[snake.length]+10, snake.x[snake.length] + 10, snake.y[snake.length]+10);
	
	for (int i = snake.length;i>=1; i--) {
		snake.x[i] = snake.x[i - 1];

		snake.y[i] = snake.y[i - 1];

		//��������ת��
	}
	
	snake.x[0] += x;
	snake.y[0] += y;
}


void write() {
	//clearellipse(50, 50, 700, 600);
	//clearrectangle(snake.x[snake.length-1], snake.y[snake.length-1], snake.x[snake.length-1] + 10, 10 + snake.y[snake.length-1]);
	//link();
	sprintf(s, "����Ϊ �� %d", snake.length + 1);
	outtextxy(750, 250, s);
	solidcircle(food_x, food_y, 5);
	for (int i = 0; snake.x[i] != 0 || snake.y[i] != 0; i++)
		fillrectangle(snake.x[i], snake.y[i], 10 + snake.x[i], 10 + snake.y[i]);

}


void food() {
	srand((unsigned)time(0));
	food_x = (rand() % 650) % 10 * 10 + 55+100*(rand()%10);
	food_y = (rand() % 550) % 10 * 10 + 55 + 100 * (rand() % 10);   //�淶ʳ������λ��
	food_x = food_x % 650 + 50;
	food_y = food_y % 550 + 50;
	food_x = food_x % 600;

	food_y = food_y % 600;
	//��ɢ���淶����
	setfillcolor(RGB(100, 200, 150));
	solidcircle(food_x, food_y, 5);
	setfillcolor(RGB(100, 200, 150));
}


bool eat() {
	if ((snake.x[0]-food_x)==-5 && (snake.y[0]-food_y)==-5)  //�Ե�ʳ���ж�
		return true;
	return false;
	
}

bool limit() {   //�����ж�
	if (snake.x[0] < 50 || snake.x[0] + 10 > 600 || snake.y[0] < 50 || snake.y[0] + 10 > 600)
		return true;
	for (int i = 1; i<snake.length; i++)
		if (snake.x[i] == snake.x[0] && snake.y[i] == snake.y[0])
			return true;
	return false;


}

bool correct(char astep) {  //��Ч�����ж�
	if (astep != 'a'&&astep != 'A'&&astep != 's'&&astep != 'S'&&astep != 'w'&&astep != 'W'&&astep != 'd'&&astep != 'D')
		return false;
	
	if (((step == 's' || step == 'S') && (astep != 'W' && astep != 'W')) ||
		((step == 'w' || step == 'W') && (astep != 's' && astep != 'S')) ||
		((step == 'a' || step == 'A') && (astep != 'd' && astep != 'D')) ||
		((step == 'd' || step == 'D') && (astep != 'a' && astep != 'A')))
		return true;


	return true;


}