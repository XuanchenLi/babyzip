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
	color(11); printf("！！！！！！！！！！！！！散哭聞喘LXC儿抹罷周！！！！！！！！！！！！！！\n"); color(15);
	color(11); printf("！！！！！！！！！！！！----------------------！！！！！！！！！！！！\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          1.儿抹猟周                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          2.盾儿猟周                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          3.曳熟猟周坪否                            "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          0.卦指                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------！！！！！！！！！！！！！！！！！！！！！！！！\n"); color(15);
	printf("----萩補秘方忖序佩僉夲----\n");
}
void print_success()
{
	system("cls");
	color(11); printf("！！！！！！！！！！！！！散哭聞喘LXC儿抹罷周！！！！！！！！！！！！！！\n"); color(15);
	color(11); printf("！！！！！！！！！！！！----------------------！！！！！！！！！！！！\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          盾儿撹孔��                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                       猟周了噐�猴�朕村和                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        補秘1臥心園鷹                               "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        補秘0卦指                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------！！！！！！！！！！！！！！！！！！！！！！！！\n"); color(15);
}
void print_su(double rate)
{
	system("cls");
	color(11); printf("！！！！！！！！！！！！！散哭聞喘LXC儿抹罷周！！！！！！！！！！！！！！\n"); color(15);
	color(11); printf("！！！！！！！！！！！！----------------------！！！！！！！！！！！！\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          儿抹撹孔��                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                       儿抹曳葎 %.2lf%%                              ",rate); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                       猟周了噐�猴�朕村和                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        補秘1臥心園鷹                               "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        補秘0卦指                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------！！！！！！！！！！！！！！！！！！！！！！！！\n"); color(15);
}
void print_chk()
{
	system("cls");
	color(11); printf("！！！！！！！！！！！！！散哭聞喘LXC儿抹罷周！！！！！！！！！！！！！！\n"); color(15);
	color(11); printf("！！！！！！！！！！！！----------------------！！！！！！！！！！！！\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                    萩補秘猟周A議蒸斤揃抄                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        補秘0卦指                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------！！！！！！！！！！！！！！！！！！！！！！！！\n"); color(15);
}
void print_chk2()
{
	system("cls");
	color(11); printf("！！！！！！！！！！！！！散哭聞喘LXC儿抹罷周！！！！！！！！！！！！！！\n"); color(15);
	color(11); printf("！！！！！！！！！！！！----------------------！！！！！！！！！！！！\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                    萩補秘猟周B議蒸斤揃抄                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        補秘0卦指                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------！！！！！！！！！！！！！！！！！！！！！！！！\n"); color(15);
}
void print_err()
{
	system("cls");
	color(11); printf("！！！！！！！！！！！！！散哭聞喘LXC儿抹罷周！！！！！！！！！！！！！！\n"); color(15);
	color(11); printf("！！！！！！！！！！！！----------------------！！！！！！！！！！！！\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                    朕炎猟周音贋壓賜音辛響                          "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------！！！！！！！！！！！！！！！！！！！！！！！！\n"); color(15);
}