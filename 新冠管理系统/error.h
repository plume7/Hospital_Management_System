#ifndef __ERROR_H_
#define __ERROR_H_
#include<iostream>
#include<string>
using namespace std;

class error {
public:
	error() {}
	bool Error_judge_id(string id);
	bool Error_judge_sex(char sex);
	bool Error_judge_card_id(string card_id);
	bool Error_judge_phonenumber(string phonenumber);
	bool Error_judge_data(string data);
	bool Error_judge_body_status(int body_status);
private:

};

bool error::Error_judge_id(string id) {
	if (id[0] == 'P' || id[0] == 'D') {
		return true;
	}
	else {
		cout << "���������󣡣�\n";
		return false;
	}
}
bool error::Error_judge_sex(char sex) {
	if (sex == 'M' || sex == 'W') {
		return true;
	}
	else {
		cout << "�Ա�������󣡣�\n";
		return false;
	}
}
bool error::Error_judge_card_id(string card_id) {
	if (card_id.size() != 18) {
		cout << "���֤��λ������\n";
		return false;
	}
	string S;
	for (int i = 0; i < 6; i++) {
		S = S + card_id[i];
	}
	if (S >= "830000") {
		cout << "���֤��ǰ8λ���д���\n";
		return false;
	}
	S.clear();
	S = S + card_id[10];
	S = S + card_id[11];
	if (S > "12" || S < "00") {
		cout << "���֤���·��д���\n";
		return false;
	}
	else {
		return true;

	}

}
bool error::Error_judge_phonenumber(string phonenumber) {
	if (phonenumber.size() != 11) {
		cout << "�ֻ���λ�����󣡣�\n";
		return false;
	}
	else {
		return true;
	}
}

#endif
#pragma once

