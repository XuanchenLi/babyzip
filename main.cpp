#include<iostream>
#include"zip.h"
#include"ui.h"
#include<Windows.h>
int main()
{
	int choose;
	print_menu();
	cin >> choose;
	while (1) {
		switch (choose) {
		case 1:zip_it(); break;
		case 2:unzip_it(); break;
		case 3:cmp_file(); break;
		case 0:printf("��ӭ�ٴ�ʹ��\n"); Sleep(2000); return 0;
		}
		print_menu();
		cin >> choose;
	}
}