/*
请在英文输入法下运行游戏
如无法编译  与 www.easyx.cn 下载所需插件

*/

#include<conio.h>
#include<graphics.h>
#include<windows.h>
#include<cstdio>
#include<time.h>
void link();    //画格子
void move();    //移动与游戏进程
void point(int,int);   //改变坐标
void write();    //画蛇
void food();     //生成食物
bool eat();     //判断是否吃到食物
bool correct(char step);   //判别有效键入
char s[100];    
char aim;
bool limit();    //判定是否出界与咬到自身
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
	printf("1.简单   2.一般    3.困难   或输入停顿时间（毫秒）");
	scanf("%d", &time_);   //设置停放顿时间
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

	setfillcolor(RGB(100,200,150));    //前景色
	setbkcolor(RGB(100,120,140));    //背景色
	clearrectangle(0, 0, 960, 720);
	srand((unsigned)time(NULL));
	//setorigin(rand() % 650 + 50, rand() % 550 + 50);
	snake.x[0] = rand() % 650%10*10+ 50;   //生成初始位置
	snake.y[0] = rand() % 550%10*10 + 50;

	link(); //setbkcolor(RED);
	food();
	fillrectangle(snake.x[0], snake.y[0], snake.x[0] + 10, snake.y[0] + 10);

	step =getch();
	while (!correct(step)) {   //识别首方向的有效键入
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
	sprintf(s, "长度为 ： %d", snake.length+1);
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
		if (limit())    //判断是否死亡
			break;
		if (eat()) {   //判断是否吃到食物
			snake.length++;   //增加长度
			snake.x[snake.length] = snake.x[snake.length - 1] + 10;
			snake.y[snake.length] = snake.y[snake.length - 1];    //增加蛇身位置
			food();   //重新生成食物
			 
		}
		write();
		Sleep(wait);  //等待时间
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
			if (correct(step_s))   //防止反向前进
				if (((step == 's' || step == 'S') && (step_s != 'W' && step_s != 'W')) ||
					((step == 'w' || step == 'W') && (step_s != 's' && step_s != 'S')) ||
					((step == 'a' || step == 'A') && (step_s != 'd' && step_s != 'D')) ||
					((step == 'd' || step == 'D') && (step_s != 'a' && step_s != 'A')))

					step = step_s;
		}
	}


	//死亡后输出成绩
		outtextxy(50, 50, "out");
		sprintf(s, "最中成绩 %d", snake.length + 1);
		outtextxy(150, 50, "out");
		Sleep(50000);
	
}

void point(int x, int y) {

	//擦去蛇尾
	clearrectangle(snake.x[snake.length], snake.y[snake.length], snake.x[snake.length] + 10, 10 + snake.y[snake.length]);
	//重画消失边框
	line(snake.x[snake.length], snake.y[snake.length], snake.x[snake.length] + 10, snake.y[snake.length]);
	line(snake.x[snake.length], snake.y[snake.length], snake.x[snake.length] , 10+snake.y[snake.length]);
	line(snake.x[snake.length]+10, snake.y[snake.length], snake.x[snake.length] + 10, snake.y[snake.length]+10);
	line(snake.x[snake.length], snake.y[snake.length]+10, snake.x[snake.length] + 10, snake.y[snake.length]+10);
	
	for (int i = snake.length;i>=1; i--) {
		snake.x[i] = snake.x[i - 1];

		snake.y[i] = snake.y[i - 1];

		//设身坐标转换
	}
	
	snake.x[0] += x;
	snake.y[0] += y;
}


void write() {
	//clearellipse(50, 50, 700, 600);
	//clearrectangle(snake.x[snake.length-1], snake.y[snake.length-1], snake.x[snake.length-1] + 10, 10 + snake.y[snake.length-1]);
	//link();
	sprintf(s, "长度为 ： %d", snake.length + 1);
	outtextxy(750, 250, s);
	solidcircle(food_x, food_y, 5);
	for (int i = 0; snake.x[i] != 0 || snake.y[i] != 0; i++)
		fillrectangle(snake.x[i], snake.y[i], 10 + snake.x[i], 10 + snake.y[i]);

}


void food() {
	srand((unsigned)time(0));
	food_x = (rand() % 650) % 10 * 10 + 55+100*(rand()%10);
	food_y = (rand() % 550) % 10 * 10 + 55 + 100 * (rand() % 10);   //规范食物坐标位置
	food_x = food_x % 650 + 50;
	food_y = food_y % 550 + 50;
	food_x = food_x % 600;

	food_y = food_y % 600;
	//打散及规范坐标
	setfillcolor(RGB(100, 200, 150));
	solidcircle(food_x, food_y, 5);
	setfillcolor(RGB(100, 200, 150));
}


bool eat() {
	if ((snake.x[0]-food_x)==-5 && (snake.y[0]-food_y)==-5)  //吃到食物判断
		return true;
	return false;
	
}

bool limit() {   //死亡判断
	if (snake.x[0] < 50 || snake.x[0] + 10 > 600 || snake.y[0] < 50 || snake.y[0] + 10 > 600)
		return true;
	for (int i = 1; i<snake.length; i++)
		if (snake.x[i] == snake.x[0] && snake.y[i] == snake.y[0])
			return true;
	return false;


}

bool correct(char astep) {  //有效键入判断
	if (astep != 'a'&&astep != 'A'&&astep != 's'&&astep != 'S'&&astep != 'w'&&astep != 'W'&&astep != 'd'&&astep != 'D')
		return false;
	
	if (((step == 's' || step == 'S') && (astep != 'W' && astep != 'W')) ||
		((step == 'w' || step == 'W') && (astep != 's' && astep != 'S')) ||
		((step == 'a' || step == 'A') && (astep != 'd' && astep != 'D')) ||
		((step == 'd' || step == 'D') && (astep != 'a' && astep != 'A')))
		return true;


	return true;


}