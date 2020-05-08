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
	string name;  //姓名
	string region;//来源地
	int age;     //年龄
	char sex;     //性别  M\W
	string card_id;  //身份证号
	string phonenumber; //电话号码
	string clinic;//科室
	string job;  //职位
	int body_status;  //身体状况  1健康  0感染
	float work_time;  //连续工作时间 hour
	int patient_num;   //负责患者数量
	string doctor_num;  //医生编号
};
void save(doctor d);
void DelLineData(int i);



void doctor::func_new() {
	char choice;
	doctor newinformation;
	system("cls");
	while (1) {
		system("cls");
		cout << setw(20) << "请依次输入以下几项:" << endl;
		cout << setw(30) << "医生编号:  ";
		cin >> newinformation.doctor_num;
		cout << setw(30) << "医生姓名:  ";
		cin >> newinformation.name;
		cout << setw(30) << "来源地:  ";
		cin >> newinformation.region;
		cout << setw(30) << "身份证号:  ";
		cin >> newinformation.card_id;
		cout << setw(30) << "性别(W/M):  ";
		cin >> newinformation.sex;
		cout << setw(30) << "年龄:  ";
		cin >> newinformation.age;
		cout << setw(30) << "电话号码:  ";
		cin >> newinformation.phonenumber;
		cout << setw(30) << "科室:  ";
		cin >> newinformation.clinic;
		cout << setw(30) << "职位:  ";
		cin >> newinformation.job;
		cout << setw(30) << "身体状况(1.健康,0.感染):  ";
		cin >> newinformation.body_status;
		cout << setw(30) << "连续工作时间(h):  ";
		cin >> newinformation.work_time;
		cout << setw(30) << "负责患者数量:  ";
		cin >> newinformation.patient_num;
		cout << setw(20) << "是否保存该信息?(Y/N)   :";
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			save(newinformation);
		}
		else {
			cout << setw(20) << "\n该信息未保存!\n";
		}
		cout << setw(20) << "\n是否继续添加信息?(Y/N)\n";
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
		cout << "\n成功!\n";
	}
	else {
		cout << "\n文件打开失败！\n";
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
				cout << "系统中没有信息！" << endl;
				cout << "按任意键返回上一级菜单！" << endl;
				cin.get();
				cin.get();
				break;
			}
			else {
				cout << "\t\t\t\t\t\t欢迎来到医患人员及医疗物资管理系统！" << endl;
				cout << "****************************************************";
				cout << "医护人员管理系统";
				cout << "****************************************************" << endl;
				cout << "\t\t\t\t\t\t---------------------------------" << endl;
				cout << "\t\t\t\t\t\t| 按编号查询------------------>1 |" << endl;
				cout << "\t\t\t\t\t\t| 按姓名查询------------------>2 |" << endl;
				cout << "\t\t\t\t\t\t| 按来源地查询---------------->3 |" << endl;
				cout << "\t\t\t\t\t\t| 按健康状况查询(1健康,0感染)->4 |" << endl;
				cout << "\t\t\t\t\t\t| 返回上一级菜单-------------->0 |" << endl;
				cout << "\t\t\t\t\t\t---------------------------------" << endl;
				cout << "\t\t\t\t\t\t请选择查询方式: ";
				cin >> choice;
				switch (choice) {
				case '1':
					system("cls");
					cout << "按编号查询\n请输入您要查询的编号：";
					f1();
					break;
				case '2':
					system("cls");
					cout << "按姓名查询\n请输入您要查询的姓名：";
					f2();
					break;
				case '3':
					system("cls");
					cout << "按来源地查询\n请输入您要查询的来源地：";
					f3();
					break;
				case '4':
					system("cls");
					cout << "按健康状况查询\n请输入您要查询的健康状况(1健康，0感染)：";
					f4();
					break;
				case '0':
					cin.get();
					break;
					break;
				default:
					cout << "请输入正确的查询方式!" << endl;
					cin.get();
					cin.get();
					break;
				}
				if (choice != '0') {
					cout << "是否继续查询？(Y/N)" << endl;
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
			cout << "\n文件打开失败！\n";
		}
	}
}

void doctor::f1() {  //按编号查询
	string searchdoctor_num;
	ifstream fp(path);
	vector<doctor>doc;
	cin >> searchdoctor_num;
	int i = 0;  //统计信息数
	int flag = 0;//信息存在标志  存在设为1
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
		cout << "为您查询到如下信息：\n" << endl;
		cout << "***************************************医护人员信息*********************************************" << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "  医生          来源                             电话                           身体 连续 负责  " << endl;
		cout << "  编号 姓名     地   年龄 性别    身份证号       号码            科室     职位  状况 工作 患者  " << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		for (int j = 0; j < doc.size(); j++) {
			cout << setw(4) << doc[j].doctor_num << setw(8) << doc[j].name << setw(8) << doc[j].region << setw(4) << doc[j].age << setw(3) << doc[j].sex;
			cout << setw(19) << doc[j].card_id << setw(12) << doc[j].phonenumber << setw(10) << doc[j].clinic << setw(10) << doc[j].job;
			cout << setw(4) << doc[j].body_status << setw(5) << doc[j].work_time << setw(6) << doc[j].patient_num << endl;
		}
		cout << "\n";
		if (flag == 0) {
			cout << "没有找到相关信息！" << endl;
		}
	}
	else {
		cout << "\n文件打开失败！\n";
	}
}

void doctor::f2() { //按姓名查询
	string searchname;
	ifstream fp(path);
	vector<doctor>doc;
	cin >> searchname;
	int i = 0;  //统计信息数
	int flag = 0;//信息存在标志  存在设为1
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
		cout << "为您查询到如下信息：\n" << endl;
		cout << "***************************************医护人员信息*********************************************" << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "  医生          来源                             电话                           身体 连续 负责  " << endl;
		cout << "  编号 姓名     地   年龄 性别    身份证号       号码            科室     职位  状况 工作 患者  " << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		for (int j = 0; j < doc.size(); j++) {
			cout << setw(4) << doc[j].doctor_num << setw(8) << doc[j].name << setw(8) << doc[j].region << setw(4) << doc[j].age << setw(3) << doc[j].sex;
			cout << setw(19) << doc[j].card_id << setw(12) << doc[j].phonenumber << setw(10) << doc[j].clinic << setw(10) << doc[j].job;
			cout << setw(4) << doc[j].body_status << setw(5) << doc[j].work_time << setw(6) << doc[j].patient_num << endl;
		}
		cout << "\n";
		if (flag == 0) {
			cout << "没有找到相关信息！" << endl;
		}

	}
	else {
		cout << "\n文件打开失败！\n";
	}
}
void doctor::f3() { //按来源地查询
	string searchregion;
	ifstream fp(path);
	vector<doctor>doc;
	cin >> searchregion;
	int i = 0;  //统计信息数
	int flag = 0;//信息存在标志  存在设为1
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
		cout << "为您查询到如下信息：\n" << endl;
		cout << "***************************************医护人员信息*********************************************" << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "  医生          来源                             电话                           身体 连续 负责  " << endl;
		cout << "  编号 姓名     地   年龄 性别    身份证号       号码            科室     职位  状况 工作 患者  " << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		for (int j = 0; j < doc.size(); j++) {
			cout << setw(4) << doc[j].doctor_num << setw(8) << doc[j].name << setw(8) << doc[j].region << setw(4) << doc[j].age << setw(3) << doc[j].sex;
			cout << setw(19) << doc[j].card_id << setw(12) << doc[j].phonenumber << setw(10) << doc[j].clinic << setw(10) << doc[j].job;
			cout << setw(4) << doc[j].body_status << setw(5) << doc[j].work_time << setw(6) << doc[j].patient_num << endl;
		}
		cout << "\n";
		if (flag == 0) {
			cout << "没有找到相关信息！" << endl;
		}

	}
	else {
		cout << "\n文件打开失败！\n";
	}
}
void doctor::f4() { //按健康状况查询
	int searchbody_status;
	ifstream fp(path);
	vector<doctor>doc;
	cin >> searchbody_status;
	int i = 0;  //统计信息数
	int flag = 0;//信息存在标志  存在设为1
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
		cout << "为您查询到如下信息：\n" << endl;
		cout << "***************************************医护人员信息*********************************************" << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "  医生          来源                             电话                           身体 连续 负责  " << endl;
		cout << "  编号 姓名     地   年龄 性别    身份证号       号码            科室     职位  状况 工作 患者  " << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		for (int j = 0; j < doc.size(); j++) {
			cout << setw(4) << doc[j].doctor_num << setw(8) << doc[j].name << setw(8) << doc[j].region << setw(4) << doc[j].age << setw(3) << doc[j].sex;
			cout << setw(19) << doc[j].card_id << setw(12) << doc[j].phonenumber << setw(10) << doc[j].clinic << setw(10) << doc[j].job;
			cout << setw(4) << doc[j].body_status << setw(5) << doc[j].work_time << setw(6) << doc[j].patient_num << endl;
		}
		cout << "\n";
		if (flag == 0) {
			cout << "没有找到相关信息！" << endl;
		}
	}
	else {
		cout << "\n文件打开失败！\n";
	}
}

void doctor::func_update() {
	while (1) {
		string searchdoctor_num;
		ifstream fp(path);
		vector<doctor>doc;
		doctor dj;
		int i = 0;  //统计信息数
		int j;  //查询到的信息
		int flag = 0;//信息存在标志  存在设为1
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
			if (i > 0) { //有信息
				system("cls");
				cout << "请输入要修改信息的医生编号：";
				cin >> searchdoctor_num;
				cout << "为您查询到如下信息：\n" << endl;
				cout << "***************************************医护人员信息*********************************************" << endl;
				cout << "-----------------------------------------------------------------------------------------------" << endl;
				cout << "  医生          来源                             电话                           身体 连续 负责  " << endl;
				cout << "  编号 姓名     地   年龄 性别    身份证号       号码            科室     职位  状况 工作 患者  " << endl;
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
					cout << "没有找到相关信息！" << endl;
				}
				else {
					cout << "请选择要修改的信息：1、电话号码  2、身体状况  3、连续工作时间  4、负责患者数量  0、返回上一级菜单" << endl;
					char choice;
					cin.get();
					cin >> choice;
					switch (choice) {
					case '1': { //修改电话号码
						string new_phonenumber;
						char choice2;
						cout << "请输入修改后的电话号码：";
						cin >> new_phonenumber;
						cout << "是否保存该信息?(Y/N)" << endl;
						cin >> choice2;
						if (choice2 == 'Y' || choice2 == 'y') {
							DelLineData(j + 1);
							dj.phonenumber = new_phonenumber;
							save(dj);
						}
						else {
							cout << "\n该信息未保存!\n";
						}
						cin.get();
						break;
					}
					case '2': { //修改身体状况
						int new_body_status;
						char choice2;
						cout << "请输入修改后的身体状况(1健康，0感染)：";
						cin >> new_body_status;
						cout << "是否保存该信息?(Y/N)" << endl;
						cin >> choice2;
						if (choice2 == 'Y' || choice2 == 'y') {
							DelLineData(j + 1);
							dj.body_status = new_body_status;
							save(dj);
						}
						else {
							cout << "\n该信息未保存!\n";
						}
						cin.get();
						break;
					}
					case '3': { //修改连续工作时间
						float new_work_time;
						char choice2;
						cout << "请输入修改后的连续工作时间：";
						cin >> new_work_time;
						cout << "是否保存该信息?(Y/N)" << endl;
						cin >> choice2;
						if (choice2 == 'Y' || choice2 == 'y') {
							DelLineData(j + 1);
							dj.work_time = new_work_time;
							save(dj);
						}
						else {
							cout << "\n该信息未保存!\n";
						}
						cin.get();
						break;
					}
					case '4': { //修改负责患者数量
						int new_patient_num;
						char choice2;
						cout << "请输入修改后的负责患者数量：";
						cin >> new_patient_num;
						cout << "是否保存该信息?(Y/N)" << endl;
						cin >> choice2;
						if (choice2 == 'Y' || choice2 == 'y') {
							DelLineData(j + 1);
							dj.patient_num = new_patient_num;
							save(dj);
						}
						else {
							cout << "\n该信息未保存!\n";
						}
						cin.get();
						break;
					}
					case '0': {
						cin.get();
						break;
					}
					default: {
						cout << "请输入正确的查询方式！\n";
						cin.get();
						break;
					}
					}
					char choice3;
					cout << "是否继续修改信息?(Y/N)" << endl;
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
				cout << "系统中没有信息！" << endl;
				cout << "按任意键返回上一级菜单！" << endl;
				cin.get();
				cin.get();
				break;
			}
		}
		else {
			cout << "\n文件打开失败！\n";
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
	//写入文件
	ofstream out;
	out.open(path);
	out.flush();
	out << strFileData;
	out.close();
}
#endif
#pragma once
