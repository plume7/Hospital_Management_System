#include"load.h"
#include"patient.h"
#include"doctor.h"
#include "stdafx.h"
#include "manage.h"

void Patient_func_new(patient P) {
	char choice;
	system("cls");
	cout << "\t\t\t\t\t\t��ӭ����ҽ����Ա��ҽ�����ʹ���ϵͳ��" << endl;
	cout << setw(20) << "�������������¼���:" << endl;
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
		cout << "�Ƿ񱣴����Ϣ?(Y/N)\n";
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			if (T == 0) {
				P.Patient_save(P);
			}
			P.Patient_Message_save(P);
			cout << "\n�ɹ�!\n";
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

void Patient_select(patient P) {
	int choice;
	char choice2;
	while (1) {
		system("cls");
		cout << "\t\t\t\t\t\t��ӭ����ҽ����Ա��ҽ�����ʹ���ϵͳ��" << endl;
		cout << "****************************************************";
		cout << "��ӭʹ�û��߹���ϵͳ";
		cout << "****************************************************" << endl;
		cout << "\t\t\t\t\t\t��ѡ���ѯ��ʽ\n";
		cout << "\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t| �����߱�Ų�ѯ--->1 |" << endl;
		cout << "\t\t\t\t\t\t| ���������ֲ�ѯ--->2 |" << endl;
		cout << "\t\t\t\t\t\t| �����������ѯ--->3 |" << endl;
		cout << "\t\t\t\t\t\t| �������Ա��ѯ--->4 |" << endl;
		cout << "\t\t\t\t\t\t| �����֤�Ų�ѯ--->5 |" << endl;
		cout << "\t\t\t\t\t\t| �����ߵ绰�Ų�ѯ->6 |" << endl;
		cout << "\t\t\t\t\t\t| �����ߵ�ַ��ѯ--->7 |" << endl;
		cout << "\t\t\t\t\t\t| ��ѯ������Ϣ----->8 |" << endl;
		cout << "\t\t\t\t\t\t| ������һ���˵�--->0 |" << endl;
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
			printf("��������ȷ�Ĳ�ѯ��ʽ��\n");
			cin.get();
			cin.get();
			break;
		}
		if (choice != 0) {
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

void Patient_update(patient P,string id) {
	system("cls");
	while (1) {
		int flag = 0;//��Ϣ���ڱ�־  ������Ϊ1
		int j, choice;
		P.Patient_read();
		string sPid=id;
		while (1) {
			if (E.Error_judge_id(sPid)) {
				break;
			}
		}
		cout << "Ϊ����ѯ��������Ϣ��\n" << endl;
		cout << "*****************************************************������Ϣ***********************************************************" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << " ���߱��\t����\t����\t�Ա�\t���֤��\t\t�绰����\t��ַ" << endl;
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
			cout << "û���ҵ������Ϣ��" << endl;
			cin.get();
			cin.get();
			continue;
		}
		Pp.clear();
		cout << "��ѡ��Ҫ�޸ĵ���Ϣ��1.����  2.����  3.�Ա�  M\W  4.���֤��  5.�绰���� 6.��ַ 0��������һ���˵�" << endl;
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
			cout << "��������ȷ�Ĳ�ѯ��ʽ��\n";
			cin.get();
			break;
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

void Pmenu(patient P,string id) {
	char function;
	cout << "\n\n\n\n\n\n\n";
	system("cls");
	int flag = 1;
	while (flag) {
		system("cls");
		cout << "\t\t\t\t\t\t��ӭ����ҽ����Ա��ҽ�����ʹ���ϵͳ��" << endl;
		cout << "**************************************************";
		cout << "��ӭʹ�û��߹���ϵͳ";
		cout << "**************************************************" << endl;
		cout << "\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t| ¼�뻼����Ϣ------>1 |" << endl;
		cout << "\t\t\t\t\t\t| �޸Ļ�����Ϣ------>2 |" << endl;
		cout << "\t\t\t\t\t\t| ��ȫ�˳���ϵͳ---->0 |" << endl;
		cout << "\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t��ѡ������Ҫ���еĹ���: ";
		cin >> function;
		switch (function) {
		case '1':
			Patient_func_new(P);
			break;
		case '2':
			Patient_update(P,id);
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

void Dmenu(doctor D) {
	char function;
	system("cls");
	int flag = 1;
	while (flag) {
		system("cls");
		cout<<"\t\t\t\t\t\t��ӭ����ҽ����Ա��ҽ�����ʹ���ϵͳ��"<<endl;
		cout << "**************************************************";
		cout << "��ӭʹ��ҽ������ϵͳ";
		cout << "**************************************************" << endl;
		cout << "\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t| �½�ҽ����Ϣ------>1 |" << endl;
		cout << "\t\t\t\t\t\t| ��ѯҽ����Ϣ------>2 |" << endl;
		cout << "\t\t\t\t\t\t| �޸�ҽ����Ϣ------>3 |" << endl;
		cout << "\t\t\t\t\t\t| ��ȫ�˳���ϵͳ---->0 |" << endl;
		cout << "\t\t\t\t\t\t-----------------------" << endl;
		cout << "\t\t\t\t\t\t��ѡ������Ҫ���еĲ���: ";
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
			cout << setw(65) << "ллʹ��,�ټ�!" << endl;
			cout << setw(65) << "�밴������˳�!" << endl;
			cin.get();
			flag = 0;
			break;
		default:
			cout << setw(65) << "������˵��е�����!(0~3)";
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