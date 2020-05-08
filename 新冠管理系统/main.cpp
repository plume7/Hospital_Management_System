#include"load.h"
#include"patient.h"
#include"doctor.h"
#include "stdafx.h"
#include "manage.h"

void Patient_func_new(patient P) {
	char choice;
	system("cls");
	cout << "\t\t\t\t\t\t欢迎来到医患人员及医疗物资管理系统！" << endl;
	cout << setw(20) << "请依次输入以下几项:" << endl;
	while (1) {
		int T = 0;
		P.Patient_getname();
		P.Patient_read();
		for (int j = 0; j < Pp.size(); j++) {
			if (P.Patient_outname() == Pp[j].Patient_outname()) {
				T = 1;
				break;
			}
		}
		Pp.clear();
		if (T == 0) {
			P.Patient_getPid();
			P.Patient_getage();
			P.Patient_getsex();
			P.Patient_getcard_id();
			P.Patient_getphonenumber();
			P.Patient_getaddress();
		}
		P.Patient_getdata();
		P.Patient_getbody_status();
		P.Patient_gettempurter();
		P.Patient_getplaces();
		P.Patient_getinhospital();
		P.Patient_getsureget();
		P.Patient_getsymptom();
		P.Patient_getDid();
		cout << "是否保存该信息?(Y/N)\n";
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			if (T == 0) {
				P.Patient_save(P);
			}
			P.Patient_Message_save(P);
			cout << "\n成功!\n";
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

void Patient_select(patient P) {
	int choice;
	char choice2;
	while (1) {
		system("cls");
		cout << "\t\t\t\t\t\t欢迎来到医患人员及医疗物资管理系统！" << endl;
		cout << "****************************************************";
		cout << "欢迎使用患者管理系统";
		cout << "****************************************************" << endl;
		cout << "\t\t\t\t\t\t请选择查询方式\n";
		cout << "\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t| 按患者编号查询--->1 |" << endl;
		cout << "\t\t\t\t\t\t| 按患者名字查询--->2 |" << endl;
		cout << "\t\t\t\t\t\t| 按患者年龄查询--->3 |" << endl;
		cout << "\t\t\t\t\t\t| 按患者性别查询--->4 |" << endl;
		cout << "\t\t\t\t\t\t| 按身份证号查询--->5 |" << endl;
		cout << "\t\t\t\t\t\t| 按患者电话号查询->6 |" << endl;
		cout << "\t\t\t\t\t\t| 按患者地址查询--->7 |" << endl;
		cout << "\t\t\t\t\t\t| 查询患者信息----->8 |" << endl;
		cout << "\t\t\t\t\t\t| 返回上一级菜单--->0 |" << endl;
		cout << "\t\t\t\t\t\t-----------------------" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			P.Patient_Pid_select();
			break;
		case 2:
			system("cls");
			P.Patient_Name_select();
			break;
		case 3:
			system("cls");
			P.Patient_Age_select();
			break;
		case 4:
			system("cls");
			P.Patient_Sex_select();
			break;
		case 5:
			system("cls");
			P.Patient_Card_id_select();
			break;
		case 6:
			system("cls");
			P.Patient_Phonenumber_select();
			break;
		case 7:
			system("cls");
			P.Patient_Address_select();
			break;
		case 8:
			system("cls");
			P.Patient_Message_select();
			break;
		case 0:
			cin.get();
			break;
			break;
		default:
			printf("请输入正确的查询方式！\n");
			cin.get();
			cin.get();
			break;
		}
		if (choice != 0) {
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

void Patient_update(patient P,string id) {
	system("cls");
	while (1) {
		int flag = 0;//信息存在标志  存在设为1
		int j, choice;
		P.Patient_read();
		string sPid=id;
		while (1) {
			if (E.Error_judge_id(sPid)) {
				break;
			}
		}
		cout << "为您查询到如下信息：\n" << endl;
		cout << "*****************************************************患者信息***********************************************************" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << " 患者编号\t姓名\t年龄\t性别\t身份证号\t\t电话号码\t地址" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < Pp.size(); i++) {
			if (sPid == Pp[i].Patient_outPid()) {
				flag = 1;
				cout << " " << Pp[i].Patient_outPid() << "\t\t" << Pp[i].Patient_outname() << "\t" << Pp[i].Patient_outage() << "\t" << Pp[i].Patient_outsex() << "\t" << Pp[i].Patient_outcard_id() << "\t" << Pp[i].Patient_outphonenumber() << "\t" << Pp[i].Patient_outaddress() << endl;
				j = i;
				break;
			}
		}
		cout << "\n";
		if (flag == 0) {
			cout << "没有找到相关信息！" << endl;
			cin.get();
			cin.get();
			continue;
		}
		Pp.clear();
		cout << "请选择要修改的信息：1.姓名  2.年龄  3.性别  M\W  4.身份证号  5.电话号码 6.地址 0、返回上一级菜单" << endl;
		cin.get();
		cin >> choice;
		switch (choice) {
		case 1:
			P.Patient_Name_update(j);
			break;
		case 2:
			P.Patient_Age_update(j);
			break;
		case 3:
			P.Patient_Sex_update(j);
			break;
		case 4:
			P.Patient_Card_id_update(j);
			break;
		case 5:
			P.Patient_Phonenumber_update(j);
			break;
		case 6:
			P.Patient_Address_update(j);
			break;
		case 0:
			cin.get();
			break;
		default:
			cout << "请输入正确的查询方式！\n";
			cin.get();
			break;
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

void Pmenu(patient P,string id) {
	char function;
	cout << "\n\n\n\n\n\n\n";
	system("cls");
	int flag = 1;
	while (flag) {
		system("cls");
		cout << "\t\t\t\t\t\t欢迎来到医患人员及医疗物资管理系统！" << endl;
		cout << "**************************************************";
		cout << "欢迎使用患者管理系统";
		cout << "**************************************************" << endl;
		cout << "\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t| 录入患者信息------>1 |" << endl;
		cout << "\t\t\t\t\t\t| 修改患者信息------>2 |" << endl;
		cout << "\t\t\t\t\t\t| 安全退出此系统---->0 |" << endl;
		cout << "\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t请选择您想要进行的功能: ";
		cin >> function;
		switch (function) {
		case '1':
			Patient_func_new(P);
			break;
		case '2':
			Patient_update(P,id);
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

void Dmenu(doctor D) {
	char function;
	system("cls");
	int flag = 1;
	while (flag) {
		system("cls");
		cout<<"\t\t\t\t\t\t欢迎来到医患人员及医疗物资管理系统！"<<endl;
		cout << "**************************************************";
		cout << "欢迎使用医护管理系统";
		cout << "**************************************************" << endl;
		cout << "\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t| 新建医护信息------>1 |" << endl;
		cout << "\t\t\t\t\t\t| 查询医护信息------>2 |" << endl;
		cout << "\t\t\t\t\t\t| 修改医护信息------>3 |" << endl;
		cout << "\t\t\t\t\t\t| 安全退出此系统---->0 |" << endl;
		cout << "\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t请选择您想要进行的操作: ";
		cin >> function;
		switch (function) {
		case '1':
			D.func_new();
			break;
		case '2':
			D.func_select();
			cin;
			break;
		case '3':
			D.func_update();
			break;
		case '0':
			cout << endl << endl;
			cout << setw(65) << "谢谢使用,再见!" << endl;
			cout << setw(65) << "请按任意键退出!" << endl;
			cin.get();
			flag = 0;
			break;
		default:
			cout << setw(65) << "请输入菜单中的数字!(0~3)";
			cin.get();
			break;
		}
	}
}

int main() {
	patient Patient;
	doctor Doctor;
	string id=load_on();
	manage m;
	switch (id[0])
	{
	case 'P':
		Pmenu(Patient,id);
		break;
	case 'D':
		Dmenu(Doctor);
		break;
	case 'G': {
		system("cls");
	
		m.goods_manage();
		m.supplies_manage();
		//suppliers_manage();
		m.goods_manage();

		system("pause");
		break;
	}

	default:
		break;
	}
	
	
	return 0;
}