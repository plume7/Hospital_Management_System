#ifndef __DOCTOR_H_
#define __DOCTOR_H_
#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
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
};
void menu();
void save(doctor d);
void DelLineData(int i);

void menu() {
	doctor doctor;
	char function;
	cout << "\n\n\n\n\n\n\n";
	system("cls");
	int flag = 1;
	while (flag) {
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t\t��ӭʹ��ҽ����Ա����ϵͳ\n\n";
		cout << "\t\t\t\t\t1.�½�ҽ����Ա��Ϣ\n";
		cout << "\t\t\t\t\t2.��ѯҽ����Ա��Ϣ\n";
		cout << "\t\t\t\t\t3.�޸�ҽ����Ա��Ϣ\n";
		cout << "\t\t\t\t\t0.��ȫ�˳���ϵͳ\n\n";
		cout << "\t\t\t\t\t��ѡ������Ҫ���еĹ���: ";
		cin >> function;
		switch (function) {
		case '1':
			doctor.func_new();
			break;
		case '2':
			doctor.func_select();
			cin;
			break;
		case '3':
			doctor.func_update();
			break;
		case '0':
			cout << "\n\n\t\t\t\t\tллʹ��,�ټ�!\n\t\t\t\t\t�밴������˳�!\n";
			cin;
			flag = 0;
			break;
		default:
			cout << "\n\n\t\t\t\t\t������˵��е�����!(0~3)";
			cin.get();
			break;
		}
	}
}

void doctor::func_new() {
	char choice;
	doctor newinformation;
	system("cls");
	while (1) {
		while (getchar() != '\n');
		cout << "����������:";
		cin >> newinformation.name;
		cout << "��������Դ��:";
		cin >> newinformation.region;
		cout << "���������֤��:";
		cin >> newinformation.card_id;
		cout << "�������Ա�(W/M):";
		cin >> newinformation.sex;
		cout << "����������:";
		cin >> newinformation.age;
		cout << "������绰����:";
		cin >> newinformation.phonenumber;
		cout << "���������:";
		cin >> newinformation.clinic;
		cout << "������ְλ:";
		cin >> newinformation.job;
		cout << "����������״��(1��ʾ������0��ʾ��Ⱦ):";
		cin >> newinformation.body_status;
		cout << "��������������ʱ��(h):";
		cin >> newinformation.work_time;
		cout << "�����븺��������:";
		cin >> newinformation.patient_num;
		cout << "�Ƿ񱣴����Ϣ?(Y/N)\n";
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			save(newinformation);
		}
		else {
			cout << "\n����Ϣδ����!\n";
		}
		cout << "\n�Ƿ���������Ϣ?(Y/N)\n";
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
		fp << d.name << "\t" << d.region << "\t" << d.age << "\t" << d.sex << "\t" << d.card_id << "\t" << d.phonenumber << "\t" << d.clinic
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
		cout << "\n\n\n\n\n\n\t\t\t\t\t��ӭʹ��ҽ����Ա����ϵͳ\n\n";
		int count = 0;
		char choice;
		char choice2;
		string str;
		ifstream fp(path);
		if (fp.is_open()) {
			while (!fp.eof()) {
				getline(fp, str);
				count++;
				//cout << str << endl;
			}
			fp.close();
			count--;
			//cout << count << endl;
			if (count == 0) {
				cout << "ϵͳ��û����Ϣ��" << endl;
				cout << "�������������һ���˵���" << endl;
				cin.get();
				cin.get();
				break;
			}
			else {
				cout << "\t\t\t\t\t��ѡ���ѯ��ʽ\n";
				cout << "\t\t\t\t\t1����������ѯ\n";
				cout << "\t\t\t\t\t2������Դ�ز�ѯ\n";
				cout << "\t\t\t\t\t3��������״����ѯ(1������0��Ⱦ)\n";
				cout << "\t\t\t\t\t0.������һ���˵�\n\n";
				cin >> choice;
				switch (choice) {
				case '1':
					system("cls");
					cout << "��������ѯ\n��������Ҫ��ѯ��������";
					f1();
					break;
				case '2':
					f2();
					system("cls");
					cout << "����Դ�ز�ѯ\n��������Ҫ��ѯ����Դ�أ�";
					break;
				case '3':
					f3();
					cout << "������״����ѯ\n��������Ҫ��ѯ�Ľ���״��(1������0��Ⱦ)��";
					system("cls");
					break;
				case '0':
					cin.get();
					break;
					break;
				default:
					printf("��������ȷ�Ĳ�ѯ��ʽ��\n");
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

void doctor::f1() { //��������ѯ
	string searchname;
	ifstream fp(path);
	doctor d[100];
	int i = 0;  //ͳ����Ϣ��
	int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
	if (fp.is_open()) {
		while (!fp.eof()) {
			fp >> d[i].name;
			fp >> d[i].region;
			fp >> d[i].age;
			fp >> d[i].sex;
			fp >> d[i].card_id;
			fp >> d[i].phonenumber;
			fp >> d[i].clinic;
			fp >> d[i].job;
			fp >> d[i].body_status;
			fp >> d[i].work_time;
			fp >> d[i].patient_num;
			i++;
		}
		fp.close();
		cin >> searchname;
		cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
		cout << "����   ��Դ��  ����  �Ա�       ���֤��    �绰����\t����\tְλ\t����״��(1������0��Ⱦ)|��������ʱ��(h)|����������" << endl;
		for (int j = 0; j < i - 1; j++) {
			if (searchname == d[j].name) {
				flag = 1;

				cout << d[j].name << "\t" << d[j].region << "\t" << d[j].age << "    " << d[j].sex << "\t"
					<< d[j].card_id << "  " << d[j].phonenumber << "\t" << d[j].clinic << "\t"
					<< d[j].job << "\t" << d[j].body_status << " \t\t\t" << d[j].work_time << "\t\t" << d[j].patient_num << endl;
			}
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
void doctor::f2() { //����Դ�ز�ѯ
	string searchregion;
	ifstream fp(path);
	doctor d[100];
	int i = 0;  //ͳ����Ϣ��
	int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
	if (fp.is_open()) {
		while (!fp.eof()) {
			fp >> d[i].name;
			fp >> d[i].region;
			fp >> d[i].age;
			fp >> d[i].sex;
			fp >> d[i].card_id;
			fp >> d[i].phonenumber;
			fp >> d[i].clinic;
			fp >> d[i].job;
			fp >> d[i].body_status;
			fp >> d[i].work_time;
			fp >> d[i].patient_num;
			i++;
		}
		fp.close();
		cin >> searchregion;
		cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
		cout << "����   ��Դ��  ����  �Ա�       ���֤��    �绰����\t����\tְλ\t����״��(1������0��Ⱦ)|��������ʱ��(h)|����������" << endl;
		for (int j = 0; j < i - 1; j++) {
			if (searchregion == d[j].region) {
				flag = 1;

				cout << d[j].name << "\t" << d[j].region << "\t" << d[j].age << "    " << d[j].sex << "\t"
					<< d[j].card_id << "  " << d[j].phonenumber << "\t" << d[j].clinic << "\t"
					<< d[j].job << "\t" << d[j].body_status << " \t\t\t" << d[j].work_time << "\t\t" << d[j].patient_num << endl;
			}
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
void doctor::f3() { //������״����ѯ
	int searchbody_status;
	ifstream fp(path);
	doctor d[100];
	int i = 0;  //ͳ����Ϣ��
	int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
	if (fp.is_open()) {
		while (!fp.eof()) {
			fp >> d[i].name;
			fp >> d[i].region;
			fp >> d[i].age;
			fp >> d[i].sex;
			fp >> d[i].card_id;
			fp >> d[i].phonenumber;
			fp >> d[i].clinic;
			fp >> d[i].job;
			fp >> d[i].body_status;
			fp >> d[i].work_time;
			fp >> d[i].patient_num;
			i++;
		}
		fp.close();
		cin >> searchbody_status;
		cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
		cout << "����   ��Դ��  ����  �Ա�       ���֤��    �绰����\t����\tְλ\t����״��(1������0��Ⱦ)|��������ʱ��(h)|����������" << endl;
		for (int j = 0; j < i - 1; j++) {
			if (searchbody_status == d[j].body_status) {
				flag = 1;

				cout << d[j].name << "\t" << d[j].region << "\t" << d[j].age << "    " << d[j].sex << "\t"
					<< d[j].card_id << "  " << d[j].phonenumber << "\t" << d[j].clinic << "\t"
					<< d[j].job << "\t" << d[j].body_status << " \t\t\t" << d[j].work_time << "\t\t" << d[j].patient_num << endl;
			}
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
		string searchname;
		ifstream fp(path);
		doctor d[100];
		int i = 0;  //ͳ����Ϣ��
		int j;  //��ѯ������Ϣ
		int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
		if (fp.is_open()) {
			while (!fp.eof()) {
				fp >> d[i].name;
				fp >> d[i].region;
				fp >> d[i].age;
				fp >> d[i].sex;
				fp >> d[i].card_id;
				fp >> d[i].phonenumber;
				fp >> d[i].clinic;
				fp >> d[i].job;
				fp >> d[i].body_status;
				fp >> d[i].work_time;
				fp >> d[i].patient_num;
				i++;
			}
			fp.close();
			if (i > 0) { //����Ϣ
				system("cls");
				cout << "������Ҫ�޸���Ϣ����Ա������";
				cin >> searchname;
				cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
				cout << "����   ��Դ��  ����  �Ա�       ���֤��    �绰����\t����\tְλ\t����״��(1������0��Ⱦ)|��������ʱ��(h)|����������" << endl;
				for (j = 0; j < i - 1; j++) {
					if (searchname == d[j].name) {
						flag = 1;
						cout << d[j].name << "\t" << d[j].region << "\t" << d[j].age << "    " << d[j].sex << "\t"
							<< d[j].card_id << "  " << d[j].phonenumber << "\t" << d[j].clinic << "\t"
							<< d[j].job << "\t" << d[j].body_status << " \t\t\t" << d[j].work_time << "\t\t" << d[j].patient_num << endl;
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
							d[j].phonenumber = new_phonenumber;
							save(d[j]);
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
							d[j].body_status = new_body_status;
							save(d[j]);
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
							d[j].work_time = new_work_time;
							save(d[j]);
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
							d[j].patient_num = new_patient_num;
							save(d[j]);
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