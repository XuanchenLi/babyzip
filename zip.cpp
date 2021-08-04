#include<iostream>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<io.h>
#include <algorithm>
#include"zip.h"
#include"ui.h"
using namespace std;
void zip_it()
{
	printf("��������Ҫѹ����txt�ļ��ľ���·��������0����\n");
	string s;
	cin >> s;
	if (s == "0")return;
	zipper zip(s);
	Hoffman hof;
	zip.compress(hof);
}
void unzip_it()
{
	printf("��������Ҫ��ѹ��.lxc�ļ��ľ���·��������0����\n");
	string s;
	cin >> s;
	if (s == "0")return;
	zipper uzip(s);
	Hoffman hof;
	uzip.unzip(hof);
}
Hoffman::Hoffman()
{
	root = nullptr;
	while (!builder.empty())
	{
		builder.pop();
	}
}
void Hoffman::del(node* rt)
{
	if (rt == nullptr) return;
	if (rt->lchild) del(rt->lchild);
	if (rt->rchild) del(rt->rchild);
	free(rt);
}
Hoffman::~Hoffman()
{
	del(root);
	root = nullptr;
	while (!builder.empty()) builder.pop();
}
void Hoffman::build_tree(const zipper&a)
{
	for (auto it : a.frequency)
	{
		node* word = new node;
		word->ch = it.first;
		word->lchild = word->rchild = nullptr;
		word->weight = it.second;
		//cout << it.first << " " << it.second << endl;
		builder.push(word);
	}
	while (builder.size() != 1)
	{
		node* lptr, * rptr,*res;
		lptr = builder.top();
		//cout << lptr->ch << lptr->weight<<endl;
		builder.pop();
		rptr = builder.top();
		builder.pop();
		res = new node;
		res->weight = lptr->weight + rptr->weight;
		res->lchild = lptr;
		res->rchild = rptr;
		res->ch = '\0';
		builder.push(res);
	}
	root = builder.top();
	builder.pop();
}
void Hoffman::get_code(zipper&a,node*rt,string code)
{
	if (rt == nullptr) return;
	if (rt->lchild == nullptr && rt->rchild == nullptr)
	{
		a.mappa[rt->ch] = code;
		//cout << rt->ch << endl;
		return;
	}
	if (rt->lchild != nullptr) get_code(a, rt->lchild, code + "0");
	if (rt->rchild != nullptr) get_code(a, rt->rchild, code + "1");

}
void Hoffman::print_tree(const zipper&a)
{
	cout << "���ַ�����" << root->weight << endl;
	for (auto it : a.mappa)
	{
		if (it.first == '\n')
		{
			cout << "char:" << "\\n" << " " << "code:";
			printf("%-35s", it.second.c_str());
			cout<<"Ƶ�ʣ�"<<a.frequency.find(it.first)->second<< endl;
			continue;
		}
		cout << "char:" << it.first << "  " << "code:";
		printf("%-35s", it.second.c_str());
		cout << "Ƶ�ʣ�" << a.frequency.find(it.first)->second << endl;
	}
}
long long zipper::get_size(string file)
{
	ifstream in(file);
	if (!in) return (-1);

	in.seekg(0, ios_base::end);
	streampos pos = in.tellg();
	return pos;
}
int  zipper::count()
{
	ifstream in(filename);
	in>> std::noskipws;
	int sum = 0;
	if (!in)
	{
		cout << "���ļ�ʧ��" << endl;
		exit(-1);
	}
	char ch;
	while (in >> ch)
	{
		frequency[ch]++;
		sum++;
	}
	in.close();
	/*for (auto it : frequency)
	{
		cout << it.first << " " << it.second << " ";
	}*/
	return sum;
}
void zipper::write_tree(Hoffman::node*rt,ostream&out)
{
	if (rt == nullptr) return;
	 //ofstream out(result, ios::out | ios::app | ios::binary);
	/*if (rt->lchild == nullptr && rt->rchild == nullptr)
	{
		bool t = true;
		out.write((char*)&t, sizeof(bool));
		char ch = rt->ch;
		out.write((char*)&ch, sizeof(char));
		out.close();
		return;
	}
	else
	{
		bool t = false;
		out.write((char*)&t, sizeof(bool));
		out.close();
		write_tree(rt->lchild);
		write_tree(rt->rchild);
	}*/
	for (auto it : frequency)
	{
		int val = it.second;
		char ch = it.first;
		out.write((char*)&ch, sizeof(unsigned char));
		out.write((char*)&val, sizeof(int));
	}
	//out.close();
}
long GetFileSize(std::string filename)
{
	struct stat stat_buf;
	int rc = stat(filename.c_str(), &stat_buf);
	return rc == 0 ? stat_buf.st_size : -1;
}

double zipper::zip_rate()
{
	return (double)GetFileSize(result) / GetFileSize(filename);
}
string fill_str(string s)
{
	int len = s.length();
	int m = 8 - (len % 8);
	for (int i = 0; i < m; ++i)
	{
		s += "0";
	}
	return s;
}
/*string trans_to_byte(string s)
{
	string Byt = "";
	int turn = s.length() / 8;
	for (int i = 0; i < turn; ++i)
	{
		int num = 0;
		for (int j = 0; j < 8; ++j)
		{
			if (s[i * 8 + j] == '1')
				num += (1 << (7 - j));
		}
		char rt = (char)num;
		Byt += rt;
	}
	return Byt;
}*/
int zipper::compress(Hoffman&hu)
{
	result = filename.substr(0, filename.length() - 4) + ".lxc";
	ofstream out(result, ios::out | ios::app | ios::binary);
	if (!out.is_open())
	{
		printf("ѹ��ʧ�ܣ��ļ������ڻ���·������\n");
		return -1;
	}
	int len=count();//�õ����ַ�Ƶ��
	int kinds = frequency.size();//�ַ�����
	//cout << kinds << endl;
	//system("pause");
	hu.build_tree(*this);//����
	hu.get_code(*this, hu.root, "");//�õ�����
	//hu.print_tree(*this);
	out.write((char*)&kinds, sizeof(int));//д���ַ�������
	//system("pause");
	write_tree(hu.root,out);//д���ַ������Ӧ��Ƶ��
	/*char c = '+';
	out.write((char*)&c, sizeof(char));*/
	out.write((char*)&len, sizeof(int));//д�����ַ���
	ifstream in(filename);
	char ch;
	in >> std::noskipws;//��ֹ�����ո�
	in >> ch;
	string code="";
	while (!in.eof())
	{
		code += mappa[ch];
		while (code.length() >= 8)//ÿ��λ�ض�д��
		{
			ch = '\0';
			for (int i = 0; i < 8; ++i)
			{
				ch <<= 1;
				if (code[i] == '1')
					ch |= 1;
			}
			out.write((char*)&ch, sizeof(unsigned char));
			code = code.substr(8);
		}
		in >> ch;
	}
	if (code.length() > 0)//����ʣ�࣬���油0
	{
		ch = '\0';
		for (int i = 0; i < code.length(); ++i)
		{
			ch <<= 1;
			if (code[i] == '1')
				ch |= 1;
		}
		ch <<= (8 - code.length());
		out.write((char*)&ch, sizeof(unsigned char));
	}
	out.close();
	//cout << len << endl;
	print_su( zip_rate() * 100);
	int choice;
	cin >> choice;
	if (choice != 1) return 1;
	else
	{
		hu.print_tree(*this);
		system("pause");
	}
	return 1;
}
int zipper::unzip(Hoffman& hof)
{
	result = filename.substr(0, filename.length() - 4) + "_lxced.txt";
	ifstream in(filename, ios::in|ios::binary);
	if (!in.is_open())
	{
		printf("��ѹʧ�ܣ��ļ������ڻ���·������");
		system("pause");
		return -1;
	}
	ofstream out(result);
	int kinds;
	in.read((char*)&kinds, sizeof(int));
	//cout << kinds << endl;
	//system("pause");
	for (int i = 0; i < kinds; ++i)
	{
		char ch;
		int val;
		in.read((char*)&ch, sizeof(char));
		in.read((char*)&val, sizeof(int));
		//cout << ch << " " << val << endl;
		frequency[ch] = val;
	}
	int tot;
	in.read((char*)&tot, sizeof(int));
	hof.build_tree(*this);
	hof.get_code(*this, hof.root, "");
	//hof.print_tree(*this);
	char ch;
	int sum = 0;
	Hoffman::node* p = hof.root;
	while (1)
	{//һ���ֽ�һ���ֽڴ�������һ�ֽ�ʱp��ָ��Ҳ����ı�
		in.read((char*)&ch, sizeof(unsigned char));//��һ���ֽ�
		for (int i = 0; i < 8; ++i)
		{
			if (ch & 128)//Ϊ1����
			{
				p = p->rchild;
			}
			else//Ϊ0����
			{
				p = p->lchild;
			}
			if (p->lchild == nullptr && p->rchild == nullptr)//�ִ�Ҷ�ӽڵ�
			{
				char t = p->ch;//Ҷ�ӽڵ������ַ�
				//cout << t;
				//if (p->ch == ' ') system("pause");
				out.write((char*)&t, sizeof(unsigned char));//д���ļ�
				sum++;//����
				p = hof.root;//�ص����ڵ�
				if (sum == tot)break;
			}
			ch <<= 1;//����
		}
		if (tot == sum) break;
	}
	in.close();
	out.close();
	print_success();
	int choice;
	cin >> choice;
	if (choice != 1)return 1;
	else
	{
		hof.print_tree(*this);
		system("pause");
	}
	return 1;
}
void cmp_file()
{
	string a, b;
	print_chk();
	cin >> a;
	if (a == "0") return;
	print_chk2();
	cin >> b;
	if (b == "0") return;
	if (_access(a.c_str(), 0) == -1 || _access(b.c_str(), 0) == -1)
	{
		print_err();
		system("pause");
		return;
	}
	string cmd = "fc " + a + " " + b;
	system(cmd.c_str());
	system("pause");
	return;
}