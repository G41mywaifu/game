#pragma once
#ifndef hello

#define hello
extern "C"{

	void link();    //������
	void move();    //�ƶ�����Ϸ����
	void point(int, int);   //�ı�����
	void write();    //����
	void food();     //����ʳ��
	bool eat();     //�ж��Ƿ�Ե�ʳ��
	bool correct(char step);   //�б���Ч����
	bool limit();    //�ж��Ƿ������ҧ������
}
#endif // !hello