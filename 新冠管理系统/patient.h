#ifndef __PATIENT_H_
#define __PATIENT_H_
#include<iostream>
#include<fstream>
#include <vector>
#include<stdlib.h>
#include <iomanip>
#include"error.h"
using namespace std;

string Ppath = "patient.txt";
error E;

class patient {
public:
	patient() {}

	void Patient_getPid() {//���뻼�߱��
		while (1) {
			cout << setw(50) << "�����뻼�߱��: ";
			cin >> Pid;
			if (E.Error_judge_id(Pid)) {
				break;
			}
		}

	}
	void Patient_getname() {//��������
		cout << setw(50) << "����������: ";
		cin >> name;
	}
	void Patient_getage() {//��������
		cout << setw(50) << "����������: ";
		cin >> age;
	}
	void Patient_getsex() {//�����Ա�  M\W
		while (1) {
			cout << setw(50) << "�������Ա�(�� M��Ů W): ";
			cin >> sex;
			if (E.Error_judge_sex(sex)) {
				break;
			}
		}

	}
	void Patient_getcard_id() {//�������֤��
		while (1) {
			cout << setw(50) << "���������֤��: ";
			cin >> card_id;
			if (E.Error_judge_card_id(card_id)) {
				break;
			}
		}
	}
	void Patient_getphonenumber() {//����绰�����
		while (1) {
			cout << setw(50) << "������绰����: ";
			cin >> phonenumber;
			if (E.Error_judge_phonenumber(phonenumber)) {
				break;
			}
		}
	}
	void Patient_getaddress() {//�����ַ
		cout << setw(50) << "�������ַ: ";
		cin >> address;
	}
	void Patient_getdata() {//��������
		cout << setw(50) << "����������: ";
		cin >> data;
	}
	void Patient_getbody_status() {//��������״��  2��֢ 1��֢  0����
		cout << setw(50) << "����������״��(2��֢ 1��֢  0����): ";
		cin >> body_status;
	}
	void Patient_gettempurter() {//��������
		cout << setw(50) << "����������(��ȷ��С�����һλ): ";
		cin >> tempurter;
	}
	void Patient_getplaces() {//��������Χ
		cout << setw(50) << "����������Χ: ";
		cin >> places;
	}
	void Patient_getinhospital() {//�����Ƿ�סԺ�۲� Y\N 
		cout << setw(50) << "�������Ƿ�סԺ�۲�(�� Y���� N): ";
		cin >> inhospital;
	}
	void Patient_getsureget() {//�����Ƿ�ȷ���¹�Y\N
		cout << setw(50) << "�������Ƿ�ȷ���¹�(�� Y���� N): ";
		cin >> sureget;
	}
	void Patient_getsymptom() {//���벢��֢״
		cout << setw(50) << "�����벢��֢״: ";
		cin >> symptom;
	}
	void Patient_getDid() {//����ҽ�����
		error E;
		while (1) {
			cout << setw(50) << "����������ҽʦ���: ";
			cin >> Did;
			if (E.Error_judge_id(Did)) {
				break;
			}
		}
	}

	string Patient_outPid() {
		return Pid;
	}
	string Patient_outname() {
		return name;
	}
	int Patient_outage() {
		return age;
	}
	char Patient_outsex() {
		return sex;
	}
	string Patient_outcard_id() {
		return card_id;
	}
	string Patient_outphonenumber() {
		return phonenumber;
	}
	string Patient_outaddress() {
		return address;
	}


	void Patient_save(patient P);//���滼����Ϣ
	void Patient_Message_save(patient P);//���滼�߸�����Ϣ
	void Patient_read();//��ȡ������Ϣ
	void Patient_Message_read(string Fname);//��ȡ���߸�����Ϣ

	void Patient_Pid_select();//�����߱�Ų�ѯ
	void Patient_Name_select();//�����ֲ�ѯ
	void Patient_Age_select();//�������ѯ
	void Patient_Sex_select();//���Ա��ѯ
	void Patient_Card_id_select();//�����֤�Ų�ѯ
	void Patient_Phonenumber_select();//���绰�Ų�ѯ
	void Patient_Address_select();//����ַ��ѯ
	void Patient_Message_select();//��ѯ������Ϣ

	void Patient_Pid_update(int U);//�����߱�Ų�ѯ
	void Patient_Name_update(int U);//�����ֲ�ѯ
	void Patient_Age_update(int U);//�������ѯ
	void Patient_Sex_update(int U);//���Ա��ѯ
	void Patient_Card_id_update(int U);//�����֤�Ų�ѯ
	void Patient_Phonenumber_update(int U);//���绰�Ų�ѯ
	void Patient_Address_update(int U);//����ַ��ѯ

private:
	string Pid;//���߱��
	string name;  //����
	int age;     //����
	char sex;     //�Ա�  M\W
	string card_id;  //���֤��
	string phonenumber; //�绰����
	string address;//��ַ
	string data;//���� 
	int body_status;  //����״��  2��֢ 1��֢  0����
	float tempurter;//����
	string places;//�����Χ
	char inhospital;//�Ƿ�סԺ�۲� Y\N 
	char sureget;//�Ƿ�ȷ���¹�Y\N
	string symptom;//����֢״
	string Did;//����ҽʦ���
};

vector <patient> Pp;

void patient::Patient_save(patient P) {
	ofstream fp(Ppath, ofstream::app);
	if (fp.is_open()) {
		fp << P.Pid << "\t" << P.name << "\t" << P.age << "\t" << P.sex << "\t" << P.card_id << "\t" << P.phonenumber << "\t" << P.address << "\t" << endl;
	}
	else {
		cout << "\n�ļ���ʧ�ܣ�\n";
	}
	fp.close();
}
void patient::Patient_Message_save(patient P) {
	string filename = P.name + ".txt";
	ofstream fp(filename, ofstream::app);
	if (fp.is_open()) {
		fp << P.data << "\t" << P.body_status << "\t" << P.tempurter << "\t" << P.places << "\t" << P.inhospital << "\t" << P.sureget << "\t" << P.symptom << "\t" << P.Did << endl;
	}
	else {
		cout << "\n�ļ���ʧ�ܣ�\n";
	}
	fp.close();
}
void patient::Patient_read() {
	ifstream fp(Ppath);
	patient P;
	if (fp.is_open()) {
		while (!fp.eof()) {
			fp >> P.Pid;
			fp >> P.name;
			fp >> P.age;
			fp >> P.sex;
			fp >> P.card_id;
			fp >> P.phonenumber;
			fp >> P.address;
			Pp.push_back(P);
		}
		fp.close();
	}
}
void patient::Patient_Message_read(string Fname) {
	ifstream fp(Fname);
	patient P;
	if (fp.is_open()) {
		while (!fp.eof()) {
			fp >> P.data;
			fp >> P.body_status;
			fp >> P.tempurter;
			fp >> P.places;
			fp >> P.inhospital;
			fp >> P.sureget;
			fp >> P.symptom;
			fp >> P.Did;
			Pp.push_back(P);
		}
		fp.close();
	}
}

void patient::Patient_Pid_select() {
	Patient_read();
	int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
	cout << "�����˱�Ų�ѯ\n";
	string searchPid;
	while (1) {
		cout << "��������Ҫ��ѯ�Ĳ��˱�ţ�";
		cin >> searchPid;
		if (E.Error_judge_id(searchPid)) {
			break;
		}
	}

	cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
	cout << "*****************************************************������Ϣ***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " ���߱��\t����\t����\t�Ա�\t���֤��\t\t�绰����\t��ַ" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		if (searchPid == Pp[i].Pid) {
			flag = 1;
			cout << " " << Pp[i].Pid << "\t\t" << Pp[i].name << "\t" << Pp[i].age << "\t" << Pp[i].sex << "\t" << Pp[i].card_id << "\t" << Pp[i].phonenumber << "\t" << Pp[i].address << endl;
		}
	}
	cout << "\n";
	if (flag == 0) {
		cout << "û���ҵ������Ϣ��" << endl;
	}
	Pp.clear();
}
void patient::Patient_Name_select() {
	Patient_read();
	int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
	cout << "��������ѯ\n��������Ҫ��ѯ��������";
	string searchname;
	cin >> searchname;
	cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
	cout << "*****************************************************������Ϣ***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " ���߱��\t����\t����\t�Ա�\t���֤��\t\t�绰����\t��ַ" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		if (searchname == Pp[i].name) {
			flag = 1;
			cout << " " << Pp[i].Pid << "\t\t" << Pp[i].name << "\t" << Pp[i].age << "\t" << Pp[i].sex << "\t" << Pp[i].card_id << "\t" << Pp[i].phonenumber << "\t" << Pp[i].address << endl;
		}
	}
	cout << "\n";
	if (flag == 0) {
		cout << "û���ҵ������Ϣ��" << endl;
	}
	Pp.clear();
}
void patient::Patient_Age_select() {
	Patient_read();
	int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
	cout << "�������ѯ\n��������Ҫ��ѯ�����䣺";
	int searchage;
	cin >> searchage;
	cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
	cout << "*****************************************************������Ϣ***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " ���߱��\t����\t����\t�Ա�\t���֤��\t\t�绰����\t��ַ" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		if (searchage == Pp[i].age) {
			flag = 1;
			cout << " " << Pp[i].Pid << "\t\t" << Pp[i].name << "\t" << Pp[i].age << "\t" << Pp[i].sex << "\t" << Pp[i].card_id << "\t" << Pp[i].phonenumber << "\t" << Pp[i].address << endl;
		}
	}
	cout << "\n";
	if (flag == 0) {
		cout << "û���ҵ������Ϣ��" << endl;
	}
	Pp.clear();
}
void patient::Patient_Sex_select() {
	Patient_read();
	int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
	cout << "���Ա��ѯ\n";
	char searchsex;
	while (1) {
		cout << "��������Ҫ��ѯ���Ա�(�� M��Ů W)��";
		cin >> searchsex;
		if (E.Error_judge_sex(searchsex)) {
			break;
		}
	}
	cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
	cout << "*****************************************************������Ϣ***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " ���߱��\t����\t����\t�Ա�\t���֤��\t\t�绰����\t��ַ" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		if (searchsex == Pp[i].sex) {
			flag = 1;
			cout << " " << Pp[i].Pid << "\t\t" << Pp[i].name << "\t" << Pp[i].age << "\t" << Pp[i].sex << "\t" << Pp[i].card_id << "\t" << Pp[i].phonenumber << "\t" << Pp[i].address << endl;
		}
	}
	cout << "\n";
	if (flag == 0) {
		cout << "û���ҵ������Ϣ��" << endl;
	}
	Pp.clear();
}
void patient::Patient_Card_id_select() {
	Patient_read();
	int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
	string searchCard_id;
	cout << "�����֤�Ų�ѯ\n";
	while (1) {
		cout << "��������Ҫ��ѯ�����֤�ţ�";
		cin >> searchCard_id;
		if (E.Error_judge_card_id(searchCard_id)) {
			break;
		}
	}
	cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
	cout << "*****************************************************������Ϣ***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " ���߱��\t����\t����\t�Ա�\t���֤��\t\t�绰����\t��ַ" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		if (searchCard_id == Pp[i].card_id) {
			flag = 1;
			cout << " " << Pp[i].Pid << "\t\t" << Pp[i].name << "\t" << Pp[i].age << "\t" << Pp[i].sex << "\t" << Pp[i].card_id << "\t" << Pp[i].phonenumber << "\t" << Pp[i].address << endl;
		}
	}
	cout << "\n";
	if (flag == 0) {
		cout << "û���ҵ������Ϣ��" << endl;
	}
	Pp.clear();
}
void patient::Patient_Phonenumber_select() {
	Patient_read();
	int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
	cout << "���绰�Ų�ѯ\n";
	string searchPhonenumber;
	while (1) {
		cout << "��������Ҫ��ѯ�ĵ绰�ţ�";
		cin >> searchPhonenumber;
		if (E.Error_judge_phonenumber(searchPhonenumber)) {
			break;
		}
	}
	cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
	cout << "*****************************************************������Ϣ***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " ���߱��\t����\t����\t�Ա�\t���֤��\t\t�绰����\t��ַ" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		if (searchPhonenumber == Pp[i].phonenumber) {
			flag = 1;
			cout << " " << Pp[i].Pid << "\t\t" << Pp[i].name << "\t" << Pp[i].age << "\t" << Pp[i].sex << "\t" << Pp[i].card_id << "\t" << Pp[i].phonenumber << "\t" << Pp[i].address << endl;
		}
	}
	cout << "\n";
	if (flag == 0) {
		cout << "û���ҵ������Ϣ��" << endl;
	}
	Pp.clear();
}
void patient::Patient_Address_select() {
	Patient_read();
	int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
	cout << "����ַ��ѯ\n��������Ҫ��ѯ�ĵ�ַ��";
	string searchaddress;
	cin >> searchaddress;
	cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
	cout << "*****************************************************������Ϣ***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " ���߱��\t����\t����\t�Ա�\t���֤��\t\t�绰����\t��ַ" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		if (searchaddress == Pp[i].address) {
			flag = 1;
			cout << " " << Pp[i].Pid << "\t\t" << Pp[i].name << "\t" << Pp[i].age << "\t" << Pp[i].sex << "\t" << Pp[i].card_id << "\t" << Pp[i].phonenumber << "\t" << Pp[i].address << endl;
		}
	}
	cout << "\n";
	if (flag == 0) {
		cout << "û���ҵ������Ϣ��" << endl;
	}
	Pp.clear();
}
void patient::Patient_Message_select() {
	cout << "����������ѯ�Ļ���������";
	int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
	string searchname;
	cin >> searchname;
	string Fname = searchname + ".txt";
	Patient_Message_read(Fname);
	cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
	cout << "*****************************************************������Ϣ***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " ����\t\t����״��(2��֢ 1��֢ 0����) ����   �����Χ �Ƿ�סԺ�۲�(Y\N) �Ƿ�ȷ���¹�(Y\N) ����֢״ ����ҽʦ���" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		flag = 1;
		cout << " " << Pp[i].data << "\t" << Pp[i].body_status << "\t\t\t     " << Pp[i].tempurter << "\t" << Pp[i].places << "\t  " << Pp[i].inhospital << "\t\t  " << Pp[i].sureget << "\t\t    " << Pp[i].symptom << "\t\t" << Pp[i].Did << endl;
	}
	cout << "\n";
	if (flag == 0) {
		cout << "û���ҵ������Ϣ��" << endl;
	}
	Pp.clear();
}

void patient::Patient_Pid_update(int U) {
	Patient_read();
	string updatePid;
	char choice2;
	while (1) {
		cout << "�������޸ĺ�Ļ��߱�ţ�";
		cin >> updatePid;
		if (E.Error_judge_id(updatePid)) {
			break;
		}
	}
	cout << "�Ƿ񱣴����Ϣ?(Y/N)" << endl;
	cin >> choice2;
	if (choice2 == 'Y' || choice2 == 'y') {
		fstream file(Ppath, ios::out);
		Pp[U].Pid = updatePid;
		for (int k = 0; k < Pp.size(); k++)
		{
			Patient_save(Pp[k]);
		}
		cout << "\n�ɹ�!\n";
	}
	else {
		cout << "\n����Ϣδ����!\n";
	}
	cin.get();
	Pp.clear();
}
void patient::Patient_Name_update(int U) {
	Patient_read();
	string updatename;
	char choice2;
	cout << "�������޸ĺ�Ļ���������";
	cin >> updatename;
	cout << "�Ƿ񱣴����Ϣ?(Y/N)" << endl;
	cin >> choice2;
	if (choice2 == 'Y' || choice2 == 'y') {
		fstream file(Ppath, ios::out);
		Pp[U].name = updatename;
		for (int k = 0; k < Pp.size(); k++)
		{
			Patient_save(Pp[k]);
		}
		cout << "\n�ɹ�!\n";
	}
	else {
		cout << "\n����Ϣδ����!\n";
	}
	cin.get();
	Pp.clear();
}
void patient::Patient_Age_update(int U) {
	Patient_read();
	int updateage;
	char choice2;
	cout << "�������޸ĺ�Ļ����Ա�";
	cin >> updateage;
	cout << "�Ƿ񱣴����Ϣ?(Y/N)" << endl;
	cin >> choice2;
	if (choice2 == 'Y' || choice2 == 'y') {
		fstream file(Ppath, ios::out);
		Pp[U].age = updateage;
		for (int k = 0; k < Pp.size(); k++)
		{
			Patient_save(Pp[k]);
		}
		cout << "\n�ɹ�!\n";
	}
	else {
		cout << "\n����Ϣδ����!\n";
	}
	cin.get();
	Pp.clear();
}
void patient::Patient_Sex_update(int U) {
	Patient_read();
	char updatesex;
	char choice2;
	while (1) {
		cout << "�������޸ĺ�Ļ����Ա�";
		cin >> updatesex;
		if (E.Error_judge_sex(updatesex)) {
			break;
		}
	}
	cout << "�Ƿ񱣴����Ϣ?(Y/N)" << endl;
	cin >> choice2;
	if (choice2 == 'Y' || choice2 == 'y') {
		fstream file(Ppath, ios::out);
		Pp[U].sex = updatesex;
		for (int k = 0; k < Pp.size(); k++)
		{
			Patient_save(Pp[k]);
		}
		cout << "\n�ɹ�!\n";
	}
	else {
		cout << "\n����Ϣδ����!\n";
	}
	cin.get();
	Pp.clear();
}
void patient::Patient_Card_id_update(int U) {
	Patient_read();
	string updateCard_id;
	char choice2;
	while (1) {
		cout << "�������޸ĺ�����֤�ţ�";
		cin >> updateCard_id;
		if (E.Error_judge_card_id(updateCard_id)) {
			break;
		}
	}
	cout << "�Ƿ񱣴����Ϣ?(Y/N)" << endl;
	cin >> choice2;
	if (choice2 == 'Y' || choice2 == 'y') {
		fstream file(Ppath, ios::out);
		Pp[U].card_id = updateCard_id;
		for (int k = 0; k < Pp.size(); k++)
		{
			Patient_save(Pp[k]);
		}
		cout << "\n�ɹ�!\n";
	}
	else {
		cout << "\n����Ϣδ����!\n";
	}
	cin.get();
	Pp.clear();
}
void patient::Patient_Phonenumber_update(int U) {
	Patient_read();
	string updatephonenumber;
	char choice2;
	while (1) {
		cout << "�������޸ĺ�ĵ绰���룺";
		cin >> updatephonenumber;
		if (E.Error_judge_phonenumber(updatephonenumber)) {
			break;
		}
	}
	cout << "�Ƿ񱣴����Ϣ?(Y/N)" << endl;
	cin >> choice2;
	if (choice2 == 'Y' || choice2 == 'y') {
		fstream file(Ppath, ios::out);
		Pp[U].phonenumber = updatephonenumber;
		for (int k = 0; k < Pp.size(); k++)
		{
			Patient_save(Pp[k]);
		}
		cout << "\n�ɹ�!\n";
	}
	else {
		cout << "\n����Ϣδ����!\n";
	}
	cin.get();
	Pp.clear();
}
void patient::Patient_Address_update(int U) {
	Patient_read();
	string updateaddress;
	char choice2;
	cout << "�������޸ĺ�Ļ��ߵ�ַ��";
	cin >> updateaddress;
	cout << "�Ƿ񱣴����Ϣ?(Y/N)" << endl;
	cin >> choice2;
	if (choice2 == 'Y' || choice2 == 'y') {
		fstream file(Ppath, ios::out);
		Pp[U].address = updateaddress;
		for (int k = 0; k < Pp.size(); k++)
		{
			Patient_save(Pp[k]);
		}
		cout << "\n�ɹ�!\n";
	}
	else {
		cout << "\n����Ϣδ����!\n";
	}
	cin.get();
	Pp.clear();
}

#endif
#pragma once
