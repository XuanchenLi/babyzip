#include<cstdio>
#include <Windows.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<queue>
#include <algorithm>
using namespace std;
HANDLE hout;
int color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}
void print_menu()
{
	system("cls");
	color(11); printf("����������������������������ӭʹ��LXCѹ���������������������������������\n"); color(15);
	color(11); printf("������������������������----------------------������������������������\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          1.ѹ���ļ�                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          2.��ѹ�ļ�                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          3.�Ƚ��ļ�����                            "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          0.����                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------������������������������������������������������\n"); color(15);
	printf("----���������ֽ���ѡ��----\n");
}
void print_success()
{
	system("cls");
	color(11); printf("����������������������������ӭʹ��LXCѹ���������������������������������\n"); color(15);
	color(11); printf("������������������������----------------------������������������������\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          ��ѹ�ɹ���                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                       �ļ�λ����ͬĿ¼��                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        ����1�鿴����                               "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        ����0����                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------������������������������������������������������\n"); color(15);
}
void print_su(double rate)
{
	system("cls");
	color(11); printf("����������������������������ӭʹ��LXCѹ���������������������������������\n"); color(15);
	color(11); printf("������������������������----------------------������������������������\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          ѹ���ɹ���                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                       ѹ����Ϊ %.2lf%%                              ",rate); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                       �ļ�λ����ͬĿ¼��                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        ����1�鿴����                               "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        ����0����                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------������������������������������������������������\n"); color(15);
}
void print_chk()
{
	system("cls");
	color(11); printf("����������������������������ӭʹ��LXCѹ���������������������������������\n"); color(15);
	color(11); printf("������������������������----------------------������������������������\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                    �������ļ�A�ľ���·��                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        ����0����                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------������������������������������������������������\n"); color(15);
}
void print_chk2()
{
	system("cls");
	color(11); printf("����������������������������ӭʹ��LXCѹ���������������������������������\n"); color(15);
	color(11); printf("������������������������----------------------������������������������\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                    �������ļ�B�ľ���·��                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        ����0����                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------������������������������������������������������\n"); color(15);
}
void print_err()
{
	system("cls");
	color(11); printf("����������������������������ӭʹ��LXCѹ���������������������������������\n"); color(15);
	color(11); printf("������������������������----------------------������������������������\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                    Ŀ���ļ������ڻ򲻿ɶ�                          "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------������������������������������������������������\n"); color(15);
}