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
	color(11); printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª»¶Ó­Ê¹ÓÃLXCÑ¹ËõÈí¼þ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
	color(11); printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª----------------------¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          1.Ñ¹ËõÎÄ¼þ                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          2.½âÑ¹ÎÄ¼þ                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          3.±È½ÏÎÄ¼þÄÚÈÝ                            "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          0.·µ»Ø                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
	printf("----ÇëÊäÈëÊý×Ö½øÐÐÑ¡Ôñ----\n");
}
void print_success()
{
	system("cls");
	color(11); printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª»¶Ó­Ê¹ÓÃLXCÑ¹ËõÈí¼þ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
	color(11); printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª----------------------¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          ½âÑ¹³É¹¦£¡                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                       ÎÄ¼þÎ»ÓÚÏàÍ¬Ä¿Â¼ÏÂ                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        ÊäÈë1²é¿´±àÂë                               "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        ÊäÈë0·µ»Ø                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
}
void print_su(double rate)
{
	system("cls");
	color(11); printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª»¶Ó­Ê¹ÓÃLXCÑ¹ËõÈí¼þ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
	color(11); printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª----------------------¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                          Ñ¹Ëõ³É¹¦£¡                                "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                       Ñ¹Ëõ±ÈÎª %.2lf%%                              ",rate); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                       ÎÄ¼þÎ»ÓÚÏàÍ¬Ä¿Â¼ÏÂ                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        ÊäÈë1²é¿´±àÂë                               "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        ÊäÈë0·µ»Ø                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
}
void print_chk()
{
	system("cls");
	color(11); printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª»¶Ó­Ê¹ÓÃLXCÑ¹ËõÈí¼þ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
	color(11); printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª----------------------¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                    ÇëÊäÈëÎÄ¼þAµÄ¾ø¶ÔÂ·¾¶                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        ÊäÈë0·µ»Ø                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
}
void print_chk2()
{
	system("cls");
	color(11); printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª»¶Ó­Ê¹ÓÃLXCÑ¹ËõÈí¼þ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
	color(11); printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª----------------------¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                    ÇëÊäÈëÎÄ¼þBµÄ¾ø¶ÔÂ·¾¶                           "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                        ÊäÈë0·µ»Ø                                   "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
}
void print_err()
{
	system("cls");
	color(11); printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª»¶Ó­Ê¹ÓÃLXCÑ¹ËõÈí¼þ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
	color(11); printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª----------------------¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                    Ä¿±êÎÄ¼þ²»´æÔÚ»ò²»¿É¶Á                          "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11); printf("|"); color(15); printf("                                                                    "); color(11); printf("|\n"); color(15);
	color(11);   printf("----------------------¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n"); color(15);
}