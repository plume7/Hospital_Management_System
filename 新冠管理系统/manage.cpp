#include "stdafx.h"
#include "manage.h"


manage::manage()
{
	goods_information_manage s1;
	s1.~goods_information_manage();
	goods_supplier_manage s2;
	s2.~goods_supplier_manage();
}


manage::~manage()
{
}


//医疗物资种类管理
void manage::goods_manage() {
	int choice;
	goods_information_manage s;

	while (1) {
		system("cls");
		std::cout << endl << endl << endl << endl;
		std::cout << "****************************************************";
		std::cout << "医疗物资种类管理";
		std::cout << "****************************************************" << endl;
		std::cout.setf(ios::right, ios::adjustfield);
		std::cout << setw(70) << "----------------------------------------" << endl;
		std::cout << setw(70) << "| 查询现有物资种类----->1              |" << endl;
		std::cout << setw(70) << "| 增加物资种类----->2                  |" << endl;
		std::cout << setw(70) << "| 删除物资种类--->3                    |" << endl;
		std::cout << setw(70) << "| 修改物资种类信息--->4                |" << endl;
		std::cout << setw(70) << "| 安全退出此系统->0                    |" << endl;
		std::cout << setw(70) << "----------------------------------------" << endl;
		std::cout << setw(65) << "请选择查询方式: ";

		cin >> choice;

		switch (choice)
		{
		case 0:return; break;
		case 1:s.query_goods_category(); break;
		case 2:s.add_goods_category(); break;
		case 3:s.delete_goods_category(); break;
		case 4:s.modify_goods_category(); break;
		default:
			break;
		}

		std::cout << "退出请输入-->	q" << endl;

		char a = getchar();
		a = getchar();
		if (a == 'q')
			return;
	}
}

//捐赠者和物资供应商管理
void manage::suppliers_manage() {
	int choice;

	goods_supplier_manage s;

	while (1) {
		system("cls");
		std::cout << endl << endl << endl << endl;
		std::cout << "****************************************************";
		std::cout << "捐赠和供应商管理";
		std::cout << "****************************************************" << endl;
		std::cout.setf(ios::right, ios::adjustfield);
		std::cout << setw(90) << "--------------------------------------------------" << endl;
		std::cout << setw(90) << "| 查询现有捐赠人和供应商信息----->1              |" << endl;
		std::cout << setw(90) << "| 增加现有捐赠人或供应商----->2                  |" << endl;
		std::cout << setw(90) << "| 删除现有捐赠人或供应商--->3                    |" << endl;
		std::cout << setw(90) << "| 修改现有捐赠人或供应商--->4                    |" << endl;
		std::cout << setw(90) << "| 安全退出此系统->0                              |" << endl;
		std::cout << setw(90) << "--------------------------------------------------" << endl;
		std::cout << setw(85) << "请选择查询方式: ";

		cin >> choice;
		switch (choice)
		{
		case 0:return; break;
		case 1:s.query_supplier(); break;
		case 2:s.add_supplier(); break;
		case 3:s.delete_supplier(); break;
		case 4:s.modify_supplier(); break;
		default:
			break;
		}

		std::cout << "退出请输入-->	q" << endl;

		char a = getchar();
		a = getchar();

		if (a == 'q')
			return;
	}
}

//物资流转信息管理
void manage::supplies_manage() {
	goods_supply_manage s;

	int choice;
	while (1) {
		system("cls");
		std::cout << endl << endl << endl << endl;
		std::cout << "****************************************************";
		std::cout << "物资流转信息管理";
		std::cout << "****************************************************" << endl;
		std::cout.setf(ios::right, ios::adjustfield);
		std::cout << setw(70) << "--------------------------------------------" << endl;
		std::cout << setw(70) << "| 查询现有物资流转信息----->1              |" << endl;
		std::cout << setw(70) << "| 增加物资流转记录----->2                  |" << endl;
		std::cout << setw(70) << "| 删除物资流转记录--->3                    |" << endl;
		std::cout << setw(70) << "| 修改物资流转记录信息--->4                |" << endl;
		std::cout << setw(70) << "| 安全退出此系统->0                        |" << endl;
		std::cout << setw(70) << "--------------------------------------------" << endl;
		std::cout << setw(65) << "请选择查询方式: ";
		cin >> choice;
		switch (choice)
		{
		case 0:return; break;
		case 1:s.query_circulation(); break;
		case 2:s.add_circulation(); break;
		case 3:s.delete_circulation(); break;
		case 4:s.modify_circulation(); break;
		default:
			break;
		}

		std::cout << "退出请输入-->	q" << endl;

		char a = getchar();
		a = getchar();

		if (a == 'q')
			return;
	}
}

void manage::run() {

	int choice;

	while (1) {
		system("cls");
		std::cout << endl << endl << endl << endl;
		std::cout << "****************************************************";
		std::cout << "医疗物资管理";
		std::cout << "****************************************************" << endl;
		std::cout.setf(ios::right, ios::adjustfield);
		std::cout << setw(70) << "----------------------------------------" << endl;
		std::cout << setw(70) << "| 物资种类管理----->1                    |" << endl;
		std::cout << setw(70) << "| 捐赠个人或机构----->2                  |" << endl;
		std::cout << setw(70) << "| 物资流转信息--->3                      |" << endl;
		std::cout << setw(70) << "| 安全退出此系统->0                      |" << endl;
		std::cout << setw(70) << "----------------------------------------" << endl;
		std::cout << setw(65) << "请选择查询方式: ";

		cin >> choice;

		switch (choice)
		{
		case 0:return; break;
		case 1:goods_manage(); break;
		case 2:suppliers_manage(); break;
		case 3:supplies_manage(); break;
		default:
			break;
		}

		std::cout << "退出请输入-->	q" << endl;

		char a = getchar();
		a = getchar();
		if (a == 'q')
			return;
	}
	system("pause");
	return;
}