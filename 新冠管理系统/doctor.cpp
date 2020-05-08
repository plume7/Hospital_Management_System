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
		cout << "\n\n\n\n\n\n\t\t\t\t\t欢迎使用医护人员管理系统\n\n";
		cout << "\t\t\t\t\t1.新建医护人员信息\n";
		cout << "\t\t\t\t\t2.查询医护人员信息\n";
		cout << "\t\t\t\t\t3.修改医护人员信息\n";
		cout << "\t\t\t\t\t0.安全退出此系统\n\n";
		cout << "\t\t\t\t\t请选择您想要进行的功能: ";
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
			cout << "\n\n\t\t\t\t\t谢谢使用,再见!\n\t\t\t\t\t请按任意键退出!\n";
			cin;
			flag = 0;
			break;
		default:
			cout << "\n\n\t\t\t\t\t请输入菜单中的数字!(0~3)";
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
		cout << "请输入姓名:";
		cin >> newinformation.name;
		cout << "请输入来源地:";
		cin >> newinformation.region;
		cout << "请输入身份证号:";
		cin >> newinformation.card_id;
		cout << "请输入性别(W/M):";
		cin >> newinformation.sex;
		cout << "请输入年龄:";
		cin >> newinformation.age;
		cout << "请输入电话号码:";
		cin >> newinformation.phonenumber;
		cout << "请输入科室:";
		cin >> newinformation.clinic;
		cout << "请输入职位:";
		cin >> newinformation.job;
		cout << "请输入身体状况(1表示健康，0表示感染):";
		cin >> newinformation.body_status;
		cout << "请输入连续工作时间(h):";
		cin >> newinformation.work_time;
		cout << "请输入负责患者数量:";
		cin >> newinformation.patient_num;
		cout << "是否保存该信息?(Y/N)\n";
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			save(newinformation);
		}
		else {
			cout << "\n该信息未保存!\n";
		}
		cout << "\n是否继续添加信息?(Y/N)\n";
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
		cout << "\n\n\n\n\n\n\t\t\t\t\t欢迎使用医护人员管理系统\n\n";
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
				cout << "系统中没有信息！" << endl;
				cout << "按任意键返回上一级菜单！" << endl;
				cin.get();
				cin.get();
				break;
			}
			else {
				cout << "\t\t\t\t\t请选择查询方式\n";
				cout << "\t\t\t\t\t1、按姓名查询\n";
				cout << "\t\t\t\t\t2、按来源地查询\n";
				cout << "\t\t\t\t\t3、按健康状况查询(1健康，0感染)\n";
				cout << "\t\t\t\t\t0.返回上一级菜单\n\n";
				cin >> choice;
				switch (choice) {
				case '1':
					system("cls");
					cout << "按姓名查询\n请输入您要查询的姓名：";
					f1();
					break;
				case '2':
					f2();
					system("cls");
					cout << "按来源地查询\n请输入您要查询的来源地：";
					break;
				case '3':
					f3();
					cout << "按健康状况查询\n请输入您要查询的健康状况(1健康，0感染)：";
					system("cls");
					break;
				case '0':
					cin.get();
					break;
					break;
				default:
					printf("请输入正确的查询方式！\n");
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

void doctor::f1() { //按姓名查询
	string searchname;
	ifstream fp(path);
	doctor d[100];
	int i = 0;  //统计信息数
	int flag = 0;//信息存在标志  存在设为1
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
		cout << "为您查询到如下信息：\n" << endl;
		cout << "姓名   来源地  年龄  性别       身份证号    电话号码\t科室\t职位\t身体状况(1健康，0感染)|连续工作时间(h)|负责患者数量" << endl;
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
			cout << "没有找到相关信息！" << endl;
		}

	}
	else {
		cout << "\n文件打开失败！\n";
	}
}
void doctor::f2() { //按来源地查询
	string searchregion;
	ifstream fp(path);
	doctor d[100];
	int i = 0;  //统计信息数
	int flag = 0;//信息存在标志  存在设为1
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
		cout << "为您查询到如下信息：\n" << endl;
		cout << "姓名   来源地  年龄  性别       身份证号    电话号码\t科室\t职位\t身体状况(1健康，0感染)|连续工作时间(h)|负责患者数量" << endl;
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
			cout << "没有找到相关信息！" << endl;
		}

	}
	else {
		cout << "\n文件打开失败！\n";
	}
}
void doctor::f3() { //按健康状况查询
	int searchbody_status;
	ifstream fp(path);
	doctor d[100];
	int i = 0;  //统计信息数
	int flag = 0;//信息存在标志  存在设为1
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
		cout << "为您查询到如下信息：\n" << endl;
		cout << "姓名   来源地  年龄  性别       身份证号    电话号码\t科室\t职位\t身体状况(1健康，0感染)|连续工作时间(h)|负责患者数量" << endl;
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
			cout << "没有找到相关信息！" << endl;
		}
	}
	else {
		cout << "\n文件打开失败！\n";
	}
}

void doctor::func_update() {
	while (1) {
		string searchname;
		ifstream fp(path);
		doctor d[100];
		int i = 0;  //统计信息数
		int j;  //查询到的信息
		int flag = 0;//信息存在标志  存在设为1
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
			if (i > 0) { //有信息
				system("cls");
				cout << "请输入要修改信息的人员姓名：";
				cin >> searchname;
				cout << "为您查询到如下信息：\n" << endl;
				cout << "姓名   来源地  年龄  性别       身份证号    电话号码\t科室\t职位\t身体状况(1健康，0感染)|连续工作时间(h)|负责患者数量" << endl;
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
							d[j].phonenumber = new_phonenumber;
							save(d[j]);
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
							d[j].body_status = new_body_status;
							save(d[j]);
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
							d[j].work_time = new_work_time;
							save(d[j]);
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
							d[j].patient_num = new_patient_num;
							save(d[j]);
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