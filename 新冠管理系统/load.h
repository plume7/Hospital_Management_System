#ifndef __LOAD_H_
#define __LOAD_H_
#include<iostream>
#include<fstream>
#include <vector>
#include<stdlib.h>
#include <iomanip>
#include"error.h"
using namespace std;

string PassPath = "password.txt";

class load {
public:
	load (){}
	void Load_id_get(string S){
		Load_id = S;
	}
	void Load_password_get(string S) {
		Load_password = S;
	}
	string Load_id_out() {
		return Load_id;
	}
	string Load_password_out() {
		return Load_password;
	}
	void Load_read();
private:
	string Load_id;
	string Load_password;
};

vector<load> PW;

void load::Load_read() {
	string id;
	string password;
	load L;
	ifstream fp(PassPath);
	if (fp.is_open()) {
		while (!fp.eof()) {
			fp >> id;
			fp >> password;
			L.Load_id_get(id);
			L.Load_password_get(password);
			PW.push_back(L);
		}
		fp.close();
	}
}

string load_on() {
	string tryword;
	string tryid;
	load L;
	int j,w;
	L.Load_read();
	for (int i=1; i <4; i++) {
		system("cls");
		cout<<"\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t��ӭ����ҽ����Ա��ҽ�����ʹ���ϵͳ��\n";
		cout << "\t\t\t\t\t�����������˺�: ";
		cin >> tryid;
		cout << "\t\t\t\t\t��������������: ";
		cin >> tryword;
		for (int k = 0; k < PW.size(); k++) {
			if (tryid == PW[k].Load_id_out()) {
				j = k;
				w = i;
				break;
			}
		}
		if (tryword == PW[j].Load_password_out()) {
			system("cls");  //����
			break;
		}
		else {
			cout << "\t\t\t\t\t������󣡣�"<<endl;
			cout<<"\t\t\t\t\t���Ѵ���"<<i<<"��(��3��)"<<endl;
			cin.get();
			cin.get();
		}
		w = i;
	}
	char C;
	if (w > 3) {
		return 0;
	}
	string id= PW[j].Load_id_out();
	return id;
}
#endif
#pragma once
