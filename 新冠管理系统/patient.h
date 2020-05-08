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

	void Patient_getPid() {//输入患者编号
		while (1) {
			cout << setw(50) << "请输入患者编号: ";
			cin >> Pid;
			if (E.Error_judge_id(Pid)) {
				break;
			}
		}

	}
	void Patient_getname() {//输入姓名
		cout << setw(50) << "请输入姓名: ";
		cin >> name;
	}
	void Patient_getage() {//输入年龄
		cout << setw(50) << "请输入年龄: ";
		cin >> age;
	}
	void Patient_getsex() {//输入性别  M\W
		while (1) {
			cout << setw(50) << "请输入性别(男 M，女 W): ";
			cin >> sex;
			if (E.Error_judge_sex(sex)) {
				break;
			}
		}

	}
	void Patient_getcard_id() {//输入身份证号
		while (1) {
			cout << setw(50) << "请输入身份证号: ";
			cin >> card_id;
			if (E.Error_judge_card_id(card_id)) {
				break;
			}
		}
	}
	void Patient_getphonenumber() {//输入电话号码号
		while (1) {
			cout << setw(50) << "请输入电话号码: ";
			cin >> phonenumber;
			if (E.Error_judge_phonenumber(phonenumber)) {
				break;
			}
		}
	}
	void Patient_getaddress() {//输入地址
		cout << setw(50) << "请输入地址: ";
		cin >> address;
	}
	void Patient_getdata() {//输入日期
		cout << setw(50) << "请输入日期: ";
		cin >> data;
	}
	void Patient_getbody_status() {//输入身体状况  2重症 1轻症  0健康
		cout << setw(50) << "请输入身体状况(2重症 1轻症  0健康): ";
		cin >> body_status;
	}
	void Patient_gettempurter() {//输入体温
		cout << setw(50) << "请输入体温(精确到小数点后一位): ";
		cin >> tempurter;
	}
	void Patient_getplaces() {//输入活动区域范围
		cout << setw(50) << "请输入活动区域范围: ";
		cin >> places;
	}
	void Patient_getinhospital() {//输入是否住院观察 Y\N 
		cout << setw(50) << "请输入是否住院观察(是 Y，否 N): ";
		cin >> inhospital;
	}
	void Patient_getsureget() {//输入是否确诊新冠Y\N
		cout << setw(50) << "请输入是否确诊新冠(是 Y，否 N): ";
		cin >> sureget;
	}
	void Patient_getsymptom() {//输入并发症状
		cout << setw(50) << "请输入并发症状: ";
		cin >> symptom;
	}
	void Patient_getDid() {//输入医生编号
		error E;
		while (1) {
			cout << setw(50) << "请输入主治医师编号: ";
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


	void Patient_save(patient P);//保存患者信息
	void Patient_Message_save(patient P);//保存患者个人信息
	void Patient_read();//读取患者信息
	void Patient_Message_read(string Fname);//读取患者个人信息

	void Patient_Pid_select();//按患者编号查询
	void Patient_Name_select();//按名字查询
	void Patient_Age_select();//按年龄查询
	void Patient_Sex_select();//按性别查询
	void Patient_Card_id_select();//按身份证号查询
	void Patient_Phonenumber_select();//按电话号查询
	void Patient_Address_select();//按地址查询
	void Patient_Message_select();//查询患者信息

	void Patient_Pid_update(int U);//按患者编号查询
	void Patient_Name_update(int U);//按名字查询
	void Patient_Age_update(int U);//按年龄查询
	void Patient_Sex_update(int U);//按性别查询
	void Patient_Card_id_update(int U);//按身份证号查询
	void Patient_Phonenumber_update(int U);//按电话号查询
	void Patient_Address_update(int U);//按地址查询

private:
	string Pid;//患者编号
	string name;  //姓名
	int age;     //年龄
	char sex;     //性别  M\W
	string card_id;  //身份证号
	string phonenumber; //电话号码
	string address;//地址
	string data;//日期 
	int body_status;  //身体状况  2重症 1轻症  0健康
	float tempurter;//体温
	string places;//活动区域范围
	char inhospital;//是否住院观察 Y\N 
	char sureget;//是否确诊新冠Y\N
	string symptom;//并发症状
	string Did;//主治医师编号
};

vector <patient> Pp;

void patient::Patient_save(patient P) {
	ofstream fp(Ppath, ofstream::app);
	if (fp.is_open()) {
		fp << P.Pid << "\t" << P.name << "\t" << P.age << "\t" << P.sex << "\t" << P.card_id << "\t" << P.phonenumber << "\t" << P.address << "\t" << endl;
	}
	else {
		cout << "\n文件打开失败！\n";
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
		cout << "\n文件打开失败！\n";
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
	int flag = 0;//信息存在标志  存在设为1
	cout << "按病人编号查询\n";
	string searchPid;
	while (1) {
		cout << "请输入您要查询的病人编号：";
		cin >> searchPid;
		if (E.Error_judge_id(searchPid)) {
			break;
		}
	}

	cout << "为您查询到如下信息：\n" << endl;
	cout << "*****************************************************患者信息***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " 患者编号\t姓名\t年龄\t性别\t身份证号\t\t电话号码\t地址" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		if (searchPid == Pp[i].Pid) {
			flag = 1;
			cout << " " << Pp[i].Pid << "\t\t" << Pp[i].name << "\t" << Pp[i].age << "\t" << Pp[i].sex << "\t" << Pp[i].card_id << "\t" << Pp[i].phonenumber << "\t" << Pp[i].address << endl;
		}
	}
	cout << "\n";
	if (flag == 0) {
		cout << "没有找到相关信息！" << endl;
	}
	Pp.clear();
}
void patient::Patient_Name_select() {
	Patient_read();
	int flag = 0;//信息存在标志  存在设为1
	cout << "按姓名查询\n请输入您要查询的姓名：";
	string searchname;
	cin >> searchname;
	cout << "为您查询到如下信息：\n" << endl;
	cout << "*****************************************************患者信息***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " 患者编号\t姓名\t年龄\t性别\t身份证号\t\t电话号码\t地址" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		if (searchname == Pp[i].name) {
			flag = 1;
			cout << " " << Pp[i].Pid << "\t\t" << Pp[i].name << "\t" << Pp[i].age << "\t" << Pp[i].sex << "\t" << Pp[i].card_id << "\t" << Pp[i].phonenumber << "\t" << Pp[i].address << endl;
		}
	}
	cout << "\n";
	if (flag == 0) {
		cout << "没有找到相关信息！" << endl;
	}
	Pp.clear();
}
void patient::Patient_Age_select() {
	Patient_read();
	int flag = 0;//信息存在标志  存在设为1
	cout << "按年龄查询\n请输入您要查询的年龄：";
	int searchage;
	cin >> searchage;
	cout << "为您查询到如下信息：\n" << endl;
	cout << "*****************************************************患者信息***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " 患者编号\t姓名\t年龄\t性别\t身份证号\t\t电话号码\t地址" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		if (searchage == Pp[i].age) {
			flag = 1;
			cout << " " << Pp[i].Pid << "\t\t" << Pp[i].name << "\t" << Pp[i].age << "\t" << Pp[i].sex << "\t" << Pp[i].card_id << "\t" << Pp[i].phonenumber << "\t" << Pp[i].address << endl;
		}
	}
	cout << "\n";
	if (flag == 0) {
		cout << "没有找到相关信息！" << endl;
	}
	Pp.clear();
}
void patient::Patient_Sex_select() {
	Patient_read();
	int flag = 0;//信息存在标志  存在设为1
	cout << "按性别查询\n";
	char searchsex;
	while (1) {
		cout << "请输入您要查询的性别(男 M，女 W)：";
		cin >> searchsex;
		if (E.Error_judge_sex(searchsex)) {
			break;
		}
	}
	cout << "为您查询到如下信息：\n" << endl;
	cout << "*****************************************************患者信息***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " 患者编号\t姓名\t年龄\t性别\t身份证号\t\t电话号码\t地址" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		if (searchsex == Pp[i].sex) {
			flag = 1;
			cout << " " << Pp[i].Pid << "\t\t" << Pp[i].name << "\t" << Pp[i].age << "\t" << Pp[i].sex << "\t" << Pp[i].card_id << "\t" << Pp[i].phonenumber << "\t" << Pp[i].address << endl;
		}
	}
	cout << "\n";
	if (flag == 0) {
		cout << "没有找到相关信息！" << endl;
	}
	Pp.clear();
}
void patient::Patient_Card_id_select() {
	Patient_read();
	int flag = 0;//信息存在标志  存在设为1
	string searchCard_id;
	cout << "按身份证号查询\n";
	while (1) {
		cout << "请输入您要查询的身份证号：";
		cin >> searchCard_id;
		if (E.Error_judge_card_id(searchCard_id)) {
			break;
		}
	}
	cout << "为您查询到如下信息：\n" << endl;
	cout << "*****************************************************患者信息***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " 患者编号\t姓名\t年龄\t性别\t身份证号\t\t电话号码\t地址" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		if (searchCard_id == Pp[i].card_id) {
			flag = 1;
			cout << " " << Pp[i].Pid << "\t\t" << Pp[i].name << "\t" << Pp[i].age << "\t" << Pp[i].sex << "\t" << Pp[i].card_id << "\t" << Pp[i].phonenumber << "\t" << Pp[i].address << endl;
		}
	}
	cout << "\n";
	if (flag == 0) {
		cout << "没有找到相关信息！" << endl;
	}
	Pp.clear();
}
void patient::Patient_Phonenumber_select() {
	Patient_read();
	int flag = 0;//信息存在标志  存在设为1
	cout << "按电话号查询\n";
	string searchPhonenumber;
	while (1) {
		cout << "请输入您要查询的电话号：";
		cin >> searchPhonenumber;
		if (E.Error_judge_phonenumber(searchPhonenumber)) {
			break;
		}
	}
	cout << "为您查询到如下信息：\n" << endl;
	cout << "*****************************************************患者信息***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " 患者编号\t姓名\t年龄\t性别\t身份证号\t\t电话号码\t地址" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		if (searchPhonenumber == Pp[i].phonenumber) {
			flag = 1;
			cout << " " << Pp[i].Pid << "\t\t" << Pp[i].name << "\t" << Pp[i].age << "\t" << Pp[i].sex << "\t" << Pp[i].card_id << "\t" << Pp[i].phonenumber << "\t" << Pp[i].address << endl;
		}
	}
	cout << "\n";
	if (flag == 0) {
		cout << "没有找到相关信息！" << endl;
	}
	Pp.clear();
}
void patient::Patient_Address_select() {
	Patient_read();
	int flag = 0;//信息存在标志  存在设为1
	cout << "按地址查询\n请输入您要查询的地址：";
	string searchaddress;
	cin >> searchaddress;
	cout << "为您查询到如下信息：\n" << endl;
	cout << "*****************************************************患者信息***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " 患者编号\t姓名\t年龄\t性别\t身份证号\t\t电话号码\t地址" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		if (searchaddress == Pp[i].address) {
			flag = 1;
			cout << " " << Pp[i].Pid << "\t\t" << Pp[i].name << "\t" << Pp[i].age << "\t" << Pp[i].sex << "\t" << Pp[i].card_id << "\t" << Pp[i].phonenumber << "\t" << Pp[i].address << endl;
		}
	}
	cout << "\n";
	if (flag == 0) {
		cout << "没有找到相关信息！" << endl;
	}
	Pp.clear();
}
void patient::Patient_Message_select() {
	cout << "请输入所查询的患者姓名：";
	int flag = 0;//信息存在标志  存在设为1
	string searchname;
	cin >> searchname;
	string Fname = searchname + ".txt";
	Patient_Message_read(Fname);
	cout << "为您查询到如下信息：\n" << endl;
	cout << "*****************************************************患者信息***********************************************************" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << " 日期\t\t身体状况(2重症 1轻症 0健康) 体温   活动区域范围 是否住院观察(Y\N) 是否确诊新冠(Y\N) 并发症状 主治医师编号" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Pp.size(); i++) {
		flag = 1;
		cout << " " << Pp[i].data << "\t" << Pp[i].body_status << "\t\t\t     " << Pp[i].tempurter << "\t" << Pp[i].places << "\t  " << Pp[i].inhospital << "\t\t  " << Pp[i].sureget << "\t\t    " << Pp[i].symptom << "\t\t" << Pp[i].Did << endl;
	}
	cout << "\n";
	if (flag == 0) {
		cout << "没有找到相关信息！" << endl;
	}
	Pp.clear();
}

void patient::Patient_Pid_update(int U) {
	Patient_read();
	string updatePid;
	char choice2;
	while (1) {
		cout << "请输入修改后的患者编号：";
		cin >> updatePid;
		if (E.Error_judge_id(updatePid)) {
			break;
		}
	}
	cout << "是否保存该信息?(Y/N)" << endl;
	cin >> choice2;
	if (choice2 == 'Y' || choice2 == 'y') {
		fstream file(Ppath, ios::out);
		Pp[U].Pid = updatePid;
		for (int k = 0; k < Pp.size(); k++)
		{
			Patient_save(Pp[k]);
		}
		cout << "\n成功!\n";
	}
	else {
		cout << "\n该信息未保存!\n";
	}
	cin.get();
	Pp.clear();
}
void patient::Patient_Name_update(int U) {
	Patient_read();
	string updatename;
	char choice2;
	cout << "请输入修改后的患者姓名：";
	cin >> updatename;
	cout << "是否保存该信息?(Y/N)" << endl;
	cin >> choice2;
	if (choice2 == 'Y' || choice2 == 'y') {
		fstream file(Ppath, ios::out);
		Pp[U].name = updatename;
		for (int k = 0; k < Pp.size(); k++)
		{
			Patient_save(Pp[k]);
		}
		cout << "\n成功!\n";
	}
	else {
		cout << "\n该信息未保存!\n";
	}
	cin.get();
	Pp.clear();
}
void patient::Patient_Age_update(int U) {
	Patient_read();
	int updateage;
	char choice2;
	cout << "请输入修改后的患者性别：";
	cin >> updateage;
	cout << "是否保存该信息?(Y/N)" << endl;
	cin >> choice2;
	if (choice2 == 'Y' || choice2 == 'y') {
		fstream file(Ppath, ios::out);
		Pp[U].age = updateage;
		for (int k = 0; k < Pp.size(); k++)
		{
			Patient_save(Pp[k]);
		}
		cout << "\n成功!\n";
	}
	else {
		cout << "\n该信息未保存!\n";
	}
	cin.get();
	Pp.clear();
}
void patient::Patient_Sex_update(int U) {
	Patient_read();
	char updatesex;
	char choice2;
	while (1) {
		cout << "请输入修改后的患者性别：";
		cin >> updatesex;
		if (E.Error_judge_sex(updatesex)) {
			break;
		}
	}
	cout << "是否保存该信息?(Y/N)" << endl;
	cin >> choice2;
	if (choice2 == 'Y' || choice2 == 'y') {
		fstream file(Ppath, ios::out);
		Pp[U].sex = updatesex;
		for (int k = 0; k < Pp.size(); k++)
		{
			Patient_save(Pp[k]);
		}
		cout << "\n成功!\n";
	}
	else {
		cout << "\n该信息未保存!\n";
	}
	cin.get();
	Pp.clear();
}
void patient::Patient_Card_id_update(int U) {
	Patient_read();
	string updateCard_id;
	char choice2;
	while (1) {
		cout << "请输入修改后的身份证号：";
		cin >> updateCard_id;
		if (E.Error_judge_card_id(updateCard_id)) {
			break;
		}
	}
	cout << "是否保存该信息?(Y/N)" << endl;
	cin >> choice2;
	if (choice2 == 'Y' || choice2 == 'y') {
		fstream file(Ppath, ios::out);
		Pp[U].card_id = updateCard_id;
		for (int k = 0; k < Pp.size(); k++)
		{
			Patient_save(Pp[k]);
		}
		cout << "\n成功!\n";
	}
	else {
		cout << "\n该信息未保存!\n";
	}
	cin.get();
	Pp.clear();
}
void patient::Patient_Phonenumber_update(int U) {
	Patient_read();
	string updatephonenumber;
	char choice2;
	while (1) {
		cout << "请输入修改后的电话号码：";
		cin >> updatephonenumber;
		if (E.Error_judge_phonenumber(updatephonenumber)) {
			break;
		}
	}
	cout << "是否保存该信息?(Y/N)" << endl;
	cin >> choice2;
	if (choice2 == 'Y' || choice2 == 'y') {
		fstream file(Ppath, ios::out);
		Pp[U].phonenumber = updatephonenumber;
		for (int k = 0; k < Pp.size(); k++)
		{
			Patient_save(Pp[k]);
		}
		cout << "\n成功!\n";
	}
	else {
		cout << "\n该信息未保存!\n";
	}
	cin.get();
	Pp.clear();
}
void patient::Patient_Address_update(int U) {
	Patient_read();
	string updateaddress;
	char choice2;
	cout << "请输入修改后的患者地址：";
	cin >> updateaddress;
	cout << "是否保存该信息?(Y/N)" << endl;
	cin >> choice2;
	if (choice2 == 'Y' || choice2 == 'y') {
		fstream file(Ppath, ios::out);
		Pp[U].address = updateaddress;
		for (int k = 0; k < Pp.size(); k++)
		{
			Patient_save(Pp[k]);
		}
		cout << "\n成功!\n";
	}
	else {
		cout << "\n该信息未保存!\n";
	}
	cin.get();
	Pp.clear();
}

#endif
#pragma once
