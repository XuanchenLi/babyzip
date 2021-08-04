#pragma once
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<queue>
#include <algorithm>
#include <fstream>
using namespace std;
class zipper;
//struct Hoffman::node;
class Hoffman
{
	friend class zipper;
public:
	struct node;
	Hoffman();
	~Hoffman();
	void build_tree(const zipper&);
	//node* rebuild_tree(ifstream&);
	void print_tree(const zipper&a);
private:
	struct node
	{
		node* lchild;
		node* rchild;
		int weight;
		char ch;
	};
	struct cmp
	{
		bool operator()(const node*a, const node*b)
		{
			return a->weight > b->weight;
		}
	};
	void get_code(zipper&, node*, string);
	void del(node*);
	node* root;
	priority_queue<node*,vector<node*>,cmp> builder;
};
class zipper
{
	friend class Hoffman;
public:
	string filename;
	string result;
	zipper(string file):filename(file) {
		mappa.clear();
		frequency.clear();
	}
	int compress(Hoffman&);
	int unzip(Hoffman&);
	int  count();
	double zip_rate();
private:
	long long get_size(string );
	void write_tree(Hoffman::node*,ostream&out);
	map<char, string> mappa;
	map<char,int> frequency;
};
void zip_it();
void unzip_it();
void cmp_file();
