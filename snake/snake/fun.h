#pragma once
#ifndef hello

#define hello
extern "C"{

	void link();    //画格子
	void move();    //移动与游戏进程
	void point(int, int);   //改变坐标
	void write();    //画蛇
	void food();     //生成食物
	bool eat();     //判断是否吃到食物
	bool correct(char step);   //判别有效键入
	bool limit();    //判定是否出界与咬到自身
}
#endif // !hello