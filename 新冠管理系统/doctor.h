#ifndef __DOCTOR_H_
#define __DOCTOR_H_
#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<vector>
#include<iomanip>
using namespace std;

string path = "doctor.txt";

class doctor {
public:
	doctor() {}
	void func_new();
	void func_select();
	void func_update();
	void f1();
	void f2();
	void f3();
	void f4();
	string name;  //����
	string region;//��Դ��
	int age;     //����
	char sex;     //�Ա�  M\W
	string card_id;  //���֤��
	string phonenumber; //�绰����
	string clinic;//����
	string job;  //ְλ
	int body_status;  //����״��  1����  0��Ⱦ
	float work_time;  //��������ʱ�� hour
	int patient_num;   //����������
	string doctor_num;  //ҽ�����
};
void save(doctor d);
void DelLineData(int i);



void doctor::func_new() {
	char choice;
	doctor newinformation;
	system("cls");
	while (1) {
		system("cls");
		cout << setw(20) << "�������������¼���:" << endl;
		cout << setw(30) << "ҽ�����:  ";
		cin >> newinformation.doctor_num;
		cout << setw(30) << "ҽ������:  ";
		cin >> newinformation.name;
		cout << setw(30) << "��Դ��:  ";
		cin >> newinformation.region;
		cout << setw(30) << "���֤��:  ";
		cin >> newinformation.card_id;
		cout << setw(30) << "�Ա�(W/M):  ";
		cin >> newinformation.sex;
		cout << setw(30) << "����:  ";
		cin >> newinformation.age;
		cout << setw(30) << "�绰����:  ";
		cin >> newinformation.phonenumber;
		cout << setw(30) << "����:  ";
		cin >> newinformation.clinic;
		cout << setw(30) << "ְλ:  ";
		cin >> newinformation.job;
		cout << setw(30) << "����״��(1.����,0.��Ⱦ):  ";
		cin >> newinformation.body_status;
		cout << setw(30) << "��������ʱ��(h):  ";
		cin >> newinformation.work_time;
		cout << setw(30) << "����������:  ";
		cin >> newinformation.patient_num;
		cout << setw(20) << "�Ƿ񱣴����Ϣ?(Y/N)   :";
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			save(newinformation);
		}
		else {
			cout << setw(20) << "\n����Ϣδ����!\n";
		}
		cout << setw(20) << "\n�Ƿ���������Ϣ?(Y/N)\n";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
			continue;
		else
			break;
	}
}

void save(doctor d) {
	ofstream fp(path, ofstream::app);
	if (fp.is_open()) {
		fp << d.doctor_num << "\t" << d.name << "\t" << d.region << "\t" << d.age << "\t" << d.sex << "\t" << d.card_id << "\t" << d.phonenumber << "\t" << d.clinic
			<< "\t" << d.job << "\t" << d.body_status << "\t" << d.work_time << "\t" << d.patient_num << endl;
		cout << "\n�ɹ�!\n";
	}
	else {
		cout << "\n�ļ���ʧ�ܣ�\n";
	}
	fp.close();
}

void doctor::func_select() {
	while (1) {
		system("cls");
		int count = 0;
		char choice;
		char choice2;
		string str;
		ifstream fp(path);
		if (fp.is_open()) {
			while (!fp.eof()) {
				getline(fp, str);
				count++;
			}
			fp.close();
			count--;
			if (count == 0) {
				cout << "ϵͳ��û����Ϣ��" << endl;
				cout << "�������������һ���˵���" << endl;
				cin.get();
				cin.get();
				break;
			}
			else {
				cout << "\t\t\t\t\t\t��ӭ����ҽ����Ա��ҽ�����ʹ���ϵͳ��" << endl;
				cout << "****************************************************";
				cout << "ҽ����Ա����ϵͳ";
				cout << "****************************************************" << endl;
				cout << "\t\t\t\t\t\t---------------------------------" << endl;
				cout << "\t\t\t\t\t\t| ����Ų�ѯ------------------>1 |" << endl;
				cout << "\t\t\t\t\t\t| ��������ѯ------------------>2 |" << endl;
				cout << "\t\t\t\t\t\t| ����Դ�ز�ѯ---------------->3 |" << endl;
				cout << "\t\t\t\t\t\t| ������״����ѯ(1����,0��Ⱦ)->4 |" << endl;
				cout << "\t\t\t\t\t\t| ������һ���˵�-------------->0 |" << endl;
				cout << "\t\t\t\t\t\t---------------------------------" << endl;
				cout << "\t\t\t\t\t\t��ѡ���ѯ��ʽ: ";
				cin >> choice;
				switch (choice) {
				case '1':
					system("cls");
					cout << "����Ų�ѯ\n��������Ҫ��ѯ�ı�ţ�";
					f1();
					break;
				case '2':
					system("cls");
					cout << "��������ѯ\n��������Ҫ��ѯ��������";
					f2();
					break;
				case '3':
					system("cls");
					cout << "����Դ�ز�ѯ\n��������Ҫ��ѯ����Դ�أ�";
					f3();
					break;
				case '4':
					system("cls");
					cout << "������״����ѯ\n��������Ҫ��ѯ�Ľ���״��(1������0��Ⱦ)��";
					f4();
					break;
				case '0':
					cin.get();
					break;
					break;
				default:
					cout << "��������ȷ�Ĳ�ѯ��ʽ!" << endl;
					cin.get();
					cin.get();
					break;
				}
				if (choice != '0') {
					cout << "�Ƿ������ѯ��(Y/N)" << endl;
					cin >> choice2;
					if (choice2 == 'Y' || choice2 == 'y')
						continue;
					else
						break;
				}
				else {
					break;
				}
			}
		}
		else {
			cout << "\n�ļ���ʧ�ܣ�\n";
		}
	}
}

void doctor::f1() {  //����Ų�ѯ
	string searchdoctor_num;
	ifstream fp(path);
	vector<doctor>doc;
	cin >> searchdoctor_num;
	int i = 0;  //ͳ����Ϣ��
	int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
	if (fp.is_open()) {
		while (!fp.eof()) {
			doctor d;
			fp >> d.doctor_num;
			fp >> d.name;
			fp >> d.region;
			fp >> d.age;
			fp >> d.sex;
			fp >> d.card_id;
			fp >> d.phonenumber;
			fp >> d.clinic;
			fp >> d.job;
			fp >> d.body_status;
			fp >> d.work_time;
			fp >> d.patient_num;
			if (searchdoctor_num == d.doctor_num) {
				doc.push_back(d);
				flag = 1;
			}
			i++;
		}
		fp.close();
		cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
		cout << "***************************************ҽ����Ա��Ϣ*********************************************" << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "  ҽ��          ��Դ                             �绰                           ���� ���� ����  " << endl;
		cout << "  ��� ����     ��   ���� �Ա�    ���֤��       ����            ����     ְλ  ״�� ���� ����  " << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		for (int j = 0; j < doc.size(); j++) {
			cout << setw(4) << doc[j].doctor_num << setw(8) << doc[j].name << setw(8) << doc[j].region << setw(4) << doc[j].age << setw(3) << doc[j].sex;
			cout << setw(19) << doc[j].card_id << setw(12) << doc[j].phonenumber << setw(10) << doc[j].clinic << setw(10) << doc[j].job;
			cout << setw(4) << doc[j].body_status << setw(5) << doc[j].work_time << setw(6) << doc[j].patient_num << endl;
		}
		cout << "\n";
		if (flag == 0) {
			cout << "û���ҵ������Ϣ��" << endl;
		}
	}
	else {
		cout << "\n�ļ���ʧ�ܣ�\n";
	}
}

void doctor::f2() { //��������ѯ
	string searchname;
	ifstream fp(path);
	vector<doctor>doc;
	cin >> searchname;
	int i = 0;  //ͳ����Ϣ��
	int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
	if (fp.is_open()) {
		while (!fp.eof()) {
			doctor d;
			fp >> d.doctor_num;
			fp >> d.name;
			fp >> d.region;
			fp >> d.age;
			fp >> d.sex;
			fp >> d.card_id;
			fp >> d.phonenumber;
			fp >> d.clinic;
			fp >> d.job;
			fp >> d.body_status;
			fp >> d.work_time;
			fp >> d.patient_num;
			if (searchname == d.name) {
				doc.push_back(d);
				flag = 1;
			}
			i++;
		}
		fp.close();
		cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
		cout << "***************************************ҽ����Ա��Ϣ*********************************************" << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "  ҽ��          ��Դ                             �绰                           ���� ���� ����  " << endl;
		cout << "  ��� ����     ��   ���� �Ա�    ���֤��       ����            ����     ְλ  ״�� ���� ����  " << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		for (int j = 0; j < doc.size(); j++) {
			cout << setw(4) << doc[j].doctor_num << setw(8) << doc[j].name << setw(8) << doc[j].region << setw(4) << doc[j].age << setw(3) << doc[j].sex;
			cout << setw(19) << doc[j].card_id << setw(12) << doc[j].phonenumber << setw(10) << doc[j].clinic << setw(10) << doc[j].job;
			cout << setw(4) << doc[j].body_status << setw(5) << doc[j].work_time << setw(6) << doc[j].patient_num << endl;
		}
		cout << "\n";
		if (flag == 0) {
			cout << "û���ҵ������Ϣ��" << endl;
		}

	}
	else {
		cout << "\n�ļ���ʧ�ܣ�\n";
	}
}
void doctor::f3() { //����Դ�ز�ѯ
	string searchregion;
	ifstream fp(path);
	vector<doctor>doc;
	cin >> searchregion;
	int i = 0;  //ͳ����Ϣ��
	int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
	if (fp.is_open()) {
		while (!fp.eof()) {
			doctor d;
			fp >> d.doctor_num;
			fp >> d.name;
			fp >> d.region;
			fp >> d.age;
			fp >> d.sex;
			fp >> d.card_id;
			fp >> d.phonenumber;
			fp >> d.clinic;
			fp >> d.job;
			fp >> d.body_status;
			fp >> d.work_time;
			fp >> d.patient_num;
			if (searchregion == d.region) {
				doc.push_back(d);
				flag = 1;
			}
			i++;
		}
		fp.close();
		cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
		cout << "***************************************ҽ����Ա��Ϣ*********************************************" << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "  ҽ��          ��Դ                             �绰                           ���� ���� ����  " << endl;
		cout << "  ��� ����     ��   ���� �Ա�    ���֤��       ����            ����     ְλ  ״�� ���� ����  " << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		for (int j = 0; j < doc.size(); j++) {
			cout << setw(4) << doc[j].doctor_num << setw(8) << doc[j].name << setw(8) << doc[j].region << setw(4) << doc[j].age << setw(3) << doc[j].sex;
			cout << setw(19) << doc[j].card_id << setw(12) << doc[j].phonenumber << setw(10) << doc[j].clinic << setw(10) << doc[j].job;
			cout << setw(4) << doc[j].body_status << setw(5) << doc[j].work_time << setw(6) << doc[j].patient_num << endl;
		}
		cout << "\n";
		if (flag == 0) {
			cout << "û���ҵ������Ϣ��" << endl;
		}

	}
	else {
		cout << "\n�ļ���ʧ�ܣ�\n";
	}
}
void doctor::f4() { //������״����ѯ
	int searchbody_status;
	ifstream fp(path);
	vector<doctor>doc;
	cin >> searchbody_status;
	int i = 0;  //ͳ����Ϣ��
	int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
	if (fp.is_open()) {
		while (!fp.eof()) {
			doctor d;
			fp >> d.doctor_num;
			fp >> d.name;
			fp >> d.region;
			fp >> d.age;
			fp >> d.sex;
			fp >> d.card_id;
			fp >> d.phonenumber;
			fp >> d.clinic;
			fp >> d.job;
			fp >> d.body_status;
			fp >> d.work_time;
			fp >> d.patient_num;
			if (searchbody_status == d.body_status) {
				doc.push_back(d);
				flag = 1;
			}
			i++;
		}
		fp.close();
		cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
		cout << "***************************************ҽ����Ա��Ϣ*********************************************" << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "  ҽ��          ��Դ                             �绰                           ���� ���� ����  " << endl;
		cout << "  ��� ����     ��   ���� �Ա�    ���֤��       ����            ����     ְλ  ״�� ���� ����  " << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		for (int j = 0; j < doc.size(); j++) {
			cout << setw(4) << doc[j].doctor_num << setw(8) << doc[j].name << setw(8) << doc[j].region << setw(4) << doc[j].age << setw(3) << doc[j].sex;
			cout << setw(19) << doc[j].card_id << setw(12) << doc[j].phonenumber << setw(10) << doc[j].clinic << setw(10) << doc[j].job;
			cout << setw(4) << doc[j].body_status << setw(5) << doc[j].work_time << setw(6) << doc[j].patient_num << endl;
		}
		cout << "\n";
		if (flag == 0) {
			cout << "û���ҵ������Ϣ��" << endl;
		}
	}
	else {
		cout << "\n�ļ���ʧ�ܣ�\n";
	}
}

void doctor::func_update() {
	while (1) {
		string searchdoctor_num;
		ifstream fp(path);
		vector<doctor>doc;
		doctor dj;
		int i = 0;  //ͳ����Ϣ��
		int j;  //��ѯ������Ϣ
		int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
		if (fp.is_open()) {
			while (!fp.eof()) {
				doctor d;
				fp >> d.doctor_num;
				fp >> d.name;
				fp >> d.region;
				fp >> d.age;
				fp >> d.sex;
				fp >> d.card_id;
				fp >> d.phonenumber;
				fp >> d.clinic;
				fp >> d.job;
				fp >> d.body_status;
				fp >> d.work_time;
				fp >> d.patient_num;
				doc.push_back(d);
				i++;
			}
			fp.close();
			if (i > 0) { //����Ϣ
				system("cls");
				cout << "������Ҫ�޸���Ϣ��ҽ����ţ�";
				cin >> searchdoctor_num;
				cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
				cout << "***************************************ҽ����Ա��Ϣ*********************************************" << endl;
				cout << "-----------------------------------------------------------------------------------------------" << endl;
				cout << "  ҽ��          ��Դ                             �绰                           ���� ���� ����  " << endl;
				cout << "  ��� ����     ��   ���� �Ա�    ���֤��       ����            ����     ְλ  ״�� ���� ����  " << endl;
				cout << "-----------------------------------------------------------------------------------------------" << endl;
				for (j = 0; j < doc.size(); j++) {
					if (searchdoctor_num == doc[j].doctor_num) {
						flag = 1;
						dj = doc[j];
						cout << setw(4) << doc[j].doctor_num << setw(8) << doc[j].name << setw(8) << doc[j].region << setw(4) << doc[j].age << setw(3) << doc[j].sex;
						cout << setw(19) << doc[j].card_id << setw(12) << doc[j].phonenumber << setw(10) << doc[j].clinic << setw(10) << doc[j].job;
						cout << setw(4) << doc[j].body_status << setw(5) << doc[j].work_time << setw(6) << doc[j].patient_num << endl;
						break;
					}
				}
				cout << "\n";
				if (flag == 0)

				{
					cout << "û���ҵ������Ϣ��" << endl;
				}
				else {
					cout << "��ѡ��Ҫ�޸ĵ���Ϣ��1���绰����  2������״��  3����������ʱ��  4������������  0��������һ���˵�" << endl;
					char choice;
					cin.get();
					cin >> choice;
					switch (choice) {
					case '1': { //�޸ĵ绰����
						string new_phonenumber;
						char choice2;
						cout << "�������޸ĺ�ĵ绰���룺";
						cin >> new_phonenumber;
						cout << "�Ƿ񱣴����Ϣ?(Y/N)" << endl;
						cin >> choice2;
						if (choice2 == 'Y' || choice2 == 'y') {
							DelLineData(j + 1);
							dj.phonenumber = new_phonenumber;
							save(dj);
						}
						else {
							cout << "\n����Ϣδ����!\n";
						}
						cin.get();
						break;
					}
					case '2': { //�޸�����״��
						int new_body_status;
						char choice2;
						cout << "�������޸ĺ������״��(1������0��Ⱦ)��";
						cin >> new_body_status;
						cout << "�Ƿ񱣴����Ϣ?(Y/N)" << endl;
						cin >> choice2;
						if (choice2 == 'Y' || choice2 == 'y') {
							DelLineData(j + 1);
							dj.body_status = new_body_status;
							save(dj);
						}
						else {
							cout << "\n����Ϣδ����!\n";
						}
						cin.get();
						break;
					}
					case '3': { //�޸���������ʱ��
						float new_work_time;
						char choice2;
						cout << "�������޸ĺ����������ʱ�䣺";
						cin >> new_work_time;
						cout << "�Ƿ񱣴����Ϣ?(Y/N)" << endl;
						cin >> choice2;
						if (choice2 == 'Y' || choice2 == 'y') {
							DelLineData(j + 1);
							dj.work_time = new_work_time;
							save(dj);
						}
						else {
							cout << "\n����Ϣδ����!\n";
						}
						cin.get();
						break;
					}
					case '4': { //�޸ĸ���������
						int new_patient_num;
						char choice2;
						cout << "�������޸ĺ�ĸ�����������";
						cin >> new_patient_num;
						cout << "�Ƿ񱣴����Ϣ?(Y/N)" << endl;
						cin >> choice2;
						if (choice2 == 'Y' || choice2 == 'y') {
							DelLineData(j + 1);
							dj.patient_num = new_patient_num;
							save(dj);
						}
						else {
							cout << "\n����Ϣδ����!\n";
						}
						cin.get();
						break;
					}
					case '0': {
						cin.get();
						break;
					}
					default: {
						cout << "��������ȷ�Ĳ�ѯ��ʽ��\n";
						cin.get();
						break;
					}
					}
					char choice3;
					cout << "�Ƿ�����޸���Ϣ?(Y/N)" << endl;
					cin >> choice3;
					if (choice3 == 'Y' || choice3 == 'y') {
						continue;
					}
					else {
						break;
					}
				}
			}
			else {
				cout << "ϵͳ��û����Ϣ��" << endl;
				cout << "�������������һ���˵���" << endl;
				cin.get();
				cin.get();
				break;
			}
		}
		else {
			cout << "\n�ļ���ʧ�ܣ�\n";
		}
	}
}

string CharToStr(char * contentChar) {
	string tempStr;
	for (int i = 0; contentChar[i] != '\0'; i++) {
		tempStr += contentChar[i];
	}
	return tempStr;
}

void DelLineData(int lineNum) {
	ifstream in;
	in.open(path);
	string strFileData = "";
	int line = 1;
	char lineData[1024] = { 0 };
	while (in.getline(lineData, sizeof(lineData))) {
		if (line == lineNum) {
			strFileData += "";
		}
		else {
			strFileData += CharToStr(lineData);
			strFileData += "\n";
		}
		line++;
	}
	in.close();
	//д���ļ�
	ofstream out;
	out.open(path);
	out.flush();
	out << strFileData;
	out.close();
}
#endif
#pragma once
