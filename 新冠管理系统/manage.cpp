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


//ҽ�������������
void manage::goods_manage() {
	int choice;
	goods_information_manage s;

	while (1) {
		system("cls");
		std::cout << endl << endl << endl << endl;
		std::cout << "****************************************************";
		std::cout << "ҽ�������������";
		std::cout << "****************************************************" << endl;
		std::cout.setf(ios::right, ios::adjustfield);
		std::cout << setw(70) << "----------------------------------------" << endl;
		std::cout << setw(70) << "| ��ѯ������������----->1              |" << endl;
		std::cout << setw(70) << "| ������������----->2                  |" << endl;
		std::cout << setw(70) << "| ɾ����������--->3                    |" << endl;
		std::cout << setw(70) << "| �޸�����������Ϣ--->4                |" << endl;
		std::cout << setw(70) << "| ��ȫ�˳���ϵͳ->0                    |" << endl;
		std::cout << setw(70) << "----------------------------------------" << endl;
		std::cout << setw(65) << "��ѡ���ѯ��ʽ: ";

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

		std::cout << "�˳�������-->	q" << endl;

		char a = getchar();
		a = getchar();
		if (a == 'q')
			return;
	}
}

//�����ߺ����ʹ�Ӧ�̹���
void manage::suppliers_manage() {
	int choice;

	goods_supplier_manage s;

	while (1) {
		system("cls");
		std::cout << endl << endl << endl << endl;
		std::cout << "****************************************************";
		std::cout << "�����͹�Ӧ�̹���";
		std::cout << "****************************************************" << endl;
		std::cout.setf(ios::right, ios::adjustfield);
		std::cout << setw(90) << "--------------------------------------------------" << endl;
		std::cout << setw(90) << "| ��ѯ���о����˺͹�Ӧ����Ϣ----->1              |" << endl;
		std::cout << setw(90) << "| �������о����˻�Ӧ��----->2                  |" << endl;
		std::cout << setw(90) << "| ɾ�����о����˻�Ӧ��--->3                    |" << endl;
		std::cout << setw(90) << "| �޸����о����˻�Ӧ��--->4                    |" << endl;
		std::cout << setw(90) << "| ��ȫ�˳���ϵͳ->0                              |" << endl;
		std::cout << setw(90) << "--------------------------------------------------" << endl;
		std::cout << setw(85) << "��ѡ���ѯ��ʽ: ";

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

		std::cout << "�˳�������-->	q" << endl;

		char a = getchar();
		a = getchar();

		if (a == 'q')
			return;
	}
}

//������ת��Ϣ����
void manage::supplies_manage() {
	goods_supply_manage s;

	int choice;
	while (1) {
		system("cls");
		std::cout << endl << endl << endl << endl;
		std::cout << "****************************************************";
		std::cout << "������ת��Ϣ����";
		std::cout << "****************************************************" << endl;
		std::cout.setf(ios::right, ios::adjustfield);
		std::cout << setw(70) << "--------------------------------------------" << endl;
		std::cout << setw(70) << "| ��ѯ����������ת��Ϣ----->1              |" << endl;
		std::cout << setw(70) << "| ����������ת��¼----->2                  |" << endl;
		std::cout << setw(70) << "| ɾ��������ת��¼--->3                    |" << endl;
		std::cout << setw(70) << "| �޸�������ת��¼��Ϣ--->4                |" << endl;
		std::cout << setw(70) << "| ��ȫ�˳���ϵͳ->0                        |" << endl;
		std::cout << setw(70) << "--------------------------------------------" << endl;
		std::cout << setw(65) << "��ѡ���ѯ��ʽ: ";
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

		std::cout << "�˳�������-->	q" << endl;

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
		std::cout << "ҽ�����ʹ���";
		std::cout << "****************************************************" << endl;
		std::cout.setf(ios::right, ios::adjustfield);
		std::cout << setw(70) << "----------------------------------------" << endl;
		std::cout << setw(70) << "| �����������----->1                    |" << endl;
		std::cout << setw(70) << "| �������˻����----->2                  |" << endl;
		std::cout << setw(70) << "| ������ת��Ϣ--->3                      |" << endl;
		std::cout << setw(70) << "| ��ȫ�˳���ϵͳ->0                      |" << endl;
		std::cout << setw(70) << "----------------------------------------" << endl;
		std::cout << setw(65) << "��ѡ���ѯ��ʽ: ";

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

		std::cout << "�˳�������-->	q" << endl;

		char a = getchar();
		a = getchar();
		if (a == 'q')
			return;
	}
	system("pause");
	return;
}