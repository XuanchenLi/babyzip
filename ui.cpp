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
	color(11); printf("—————————————欢迎使用LXC压缩软件——————————————\n"); color(15);
	color(11); printf("————————————----------------------————————————\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          1.压缩文件                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          2.解压文件                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          3.比较文件内容                            "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          0.返回                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------————————————————————————\n"); color(15);
	printf("----请输入数字进行选择----\n");
}
void print_success()
{
	system("cls");
	color(11); printf("—————————————欢迎使用LXC压缩软件——————————————\n"); color(15);
	color(11); printf("————————————----------------------————————————\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          解压成功！                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                       文件位于相同目录下                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        输入1查看编码                               "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        输入0返回                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------————————————————————————\n"); color(15);
}
void print_su(double rate)
{
	system("cls");
	color(11); printf("—————————————欢迎使用LXC压缩软件——————————————\n"); color(15);
	color(11); printf("————————————----------------------————————————\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          压缩成功！                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                       压缩比为 %.2lf%%                              ",rate); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                       文件位于相同目录下                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        输入1查看编码                               "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        输入0返回                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------————————————————————————\n"); color(15);
}
void print_chk()
{
	system("cls");
	color(11); printf("—————————————欢迎使用LXC压缩软件——————————————\n"); color(15);
	color(11); printf("————————————----------------------————————————\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                    请输入文件A的绝对路径                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        输入0返回                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------————————————————————————\n"); color(15);
}
void print_chk2()
{
	system("cls");
	color(11); printf("—————————————欢迎使用LXC压缩软件——————————————\n"); color(15);
	color(11); printf("————————————----------------------————————————\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                    请输入文件B的绝对路径                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        输入0返回                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------————————————————————————\n"); color(15);
}
void print_err()
{
	system("cls");
	color(11); printf("—————————————欢迎使用LXC压缩软件——————————————\n"); color(15);
	color(11); printf("————————————----------------------————————————\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                    目标文件不存在或不可读                          "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------————————————————————————\n"); color(15);
}