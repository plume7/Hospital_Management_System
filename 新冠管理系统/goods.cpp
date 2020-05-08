#include "stdafx.h"
#include "goods.h"

//������ݵı����ַ
char filename_goods_information1[] = "./tables/goods_information.txt";
char* filename_goods_information = filename_goods_information1;
char filename_goods_supplier1[] = "./tables/goods_supplier.txt";
char* filename_goods_supplier = filename_goods_supplier1;
char filename_goods_supply1[] = "./tables/goods_supply.txt";
char* filename_goods_supply = filename_goods_supply1;
char filename_log1[] = "./tables/log.txt";
char* filename_log = filename_log1;

//���static list��Ա�����ĳ�ʼ��
list<goods_information> goods_information_manage::goods = {};
list<goods_supplier> goods_supplier_manage::suppliers = {};
list<goods_supply> goods_supply_manage::supplies = {};

//���list����¼������ţ�
int  goods_information_manage::max_num = 0;
int  goods_supplier_manage::max_num = 0;


/*
�����������
*/

//���캯������ȡ�ļ���list
goods_information_manage::goods_information_manage() {
	goods.clear();
	ifstream file(filename_goods_information);
	string line;
	char buf[1024];
	char temp[256];
	getline(file, line);//��ȡ��¼�������
	max_num = atoi(line.c_str());//�������
	goods_information good;
	while (getline(file, line)) {
		unsigned int i = 0;//line��λ��
		int j = 0;//buf��λ��
		int pos = 0;//��ȡ�����ݶ�Ӧ��ϵ
		strcpy_s(buf, line.c_str());
		for (i; i <= line.length(); i++) {
			if (buf[i] == '\0') {
				temp[j] = '\0';
				j = 0;
				good.in_comment = temp;
				//std::cout << temp << endl;
				pos = 0;
				break;
			}
			else if (buf[i] == ' '&&pos <= 5) {
				temp[j] = '\0';
				switch (pos) {
				case 0:good.in_key = atoi(temp); break;
				case 1:good.in_name = temp; break;
				case 2:good.in_type = temp; break;
				case 3:good.in_quantity = atoi(temp); break;
				case 4:good.in_use = atoi(temp); break;
				case 5:good.in_hospital = temp; break;
				}
				pos++;
				//std::cout << temp<<" ";
				j = 0;
			}
			else {
				temp[j] = buf[i];
				j++;
			}
		}
		//max_num = max_num > good.in_key ? max_num:good.in_key;
		goods.push_back(good);
	}

	file.close();

	//д����־
	FILE* file1;
	fopen_s(&file1, filename_log, "a");
	string str;
	gettime(str);
	str += "��ȡgoods_information���������ࣩ�ļ�";
	str += "\n";
	fwrite(str.c_str(), str.length(), 1, file1);
	fclose(file1);
}

goods_information_manage::~goods_information_manage() {
	FILE* file;
	fopen_s(&file, filename_goods_information, "w");
	if (file == NULL) {
		cout << "error" << endl;
	}
	char buf[10];
	_itoa_s(max_num, buf, 10);
	string s(buf);
	s += "\n";
	fwrite(s.c_str(), s.length(), 1, file);
	//fwrite("\n", 1, 1, file);
	//������list�������
	for_each(goods.begin(), goods.end(), [&file](list<goods_information>::reference a) {			//����lamda��������
		string result;
		result << a;
		fwrite(result.c_str(), result.length(), 1, file);
	});
	fclose(file);

	//д����־
	FILE* file1;
	fopen_s(&file1, filename_log, "a");
	string str;
	gettime(str);
	str += "�ر�goods_information���������ࣩ�ļ�";
	str += "\n";
	fwrite(str.c_str(), str.length(), 1, file1);
	fclose(file1);
}

boolean goods_information_manage::add_goods_category() {
	query_goods_category();
	goods_information good = {};
	good.in_hospital = "null";
	good.in_comment = "null";

	//ֻ����������������ƣ����ͺ�
	max_num++;
	int num = max_num;
	good.in_key = num;
	std::cout << setw(30) << "�������������ƣ�";
	cin >> good.in_name;
	std::cout << setw(30) << "�����������ͺţ�";
	cin >> good.in_type;

	list<goods_information>::iterator iter = goods.begin();
	//����Ƿ����
	while (iter != goods.end()) {
		if (iter->in_name == good.in_name&&iter->in_type == good.in_type) {
			std::cout << setw(30) << "Sorry, �������Ѿ����ڣ�����" << endl;
			return FALSE;
		}
		else
			iter++;
	}

	goods.push_back(good);
	std::cout << setw(30) << "����" << setw(30) << "�ͺ�" << endl;
	std::cout << setw(30) << good.in_name << setw(30) << good.in_type << endl;
	std::cout << setw(70) << " ��ӳɹ�!" << endl;
	return TRUE;
}

boolean goods_information_manage::modify_goods_category() {
	query_goods_category();

	std::cout << "���������޸ĵ�������ţ�" << endl;

	int num = -1;
	cin >> num;
	//��ȡ������
	list<goods_information>::iterator iter = goods.begin();
	bool find = false;
	while (iter != goods.end()) {
		if (iter->in_key == num) {
			find = true;
			break;
		}
		iter++;
	}
	//��Ų�����
	if (!find) {
		std::cout << "�����������Ų����ڣ�����" << endl;
		return FALSE;
	}

	std::cout << "�����������������顣" << endl;
	goods_information good;
	good.in_key = iter->in_key;
	std::cout << "�������������ƣ�" << endl;
	cin >> good.in_name;
	std::cout << "�����������ͺţ�" << endl;
	cin >> good.in_type;
	std::cout << "����������������" << endl;
	cin >> good.in_quantity;
	std::cout << "�����������ձ�������" << endl;
	cin >> good.in_use;
	std::cout << "�����������ص���Ҫ��ҽԺ��" << endl;
	cin >> good.in_hospital;
	std::cout << "�����뱸ע��" << endl;
	cin >> good.in_comment;

	std::cout << "ȷ�������𣿣�ȡ����������NO��ȷ��������������" << endl;
	string choice = "NO";
	cin >> choice;
	if (choice == "NO" || choice == "no" || choice == "No") {
		return FALSE;
	}
	else {
		//�޸�����������Ϣ

		iter->in_name = good.in_name;
		iter->in_type = good.in_type;
		iter->in_quantity = good.in_quantity;
		iter->in_hospital = good.in_hospital;
		iter->in_use = good.in_use;
		iter->in_comment = good.in_comment;
	}
	std::cout << "�޸ĳɹ�����" << endl;
	std::cout << "�޸�������Ϣ���£�" << good << endl;

	return TRUE;
}

boolean goods_information_manage::delete_goods_category() {
	query_goods_category();
	cout << "���������ʱ�ţ� " << endl;
	int num = -1;
	cin >> num;
	list<goods_information>::iterator iter = goods.begin();
	while (iter != goods.end()) {
		if (iter->in_key == num) {
			cout << "ȷ��ɾ����		" << "q����ȡ���� y����yes" << endl;

			char temp = getchar();;//������ַ�
			while (temp != 'q' && temp != 'y') {
				temp = getchar();
				if (temp == 'q')
					return FALSE;
				else if (temp == 'y') {
					goods.erase(iter);
					return TRUE;
				}
			}

		}
		iter++;
	}
	std::cout << "δ�ҵ�����Ŷ�Ӧ�����ʣ���" << endl;
	return TRUE;
}

boolean goods_information_manage::query_goods_category() {
	listColumns();
	for (goods_information good : goods) {
		cout << good;
	}
	return TRUE;
}

void goods_information_manage::listColumns() {
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(12) << "���ʱ�� " << setw(12) << "�������� " << setw(26) << "�����ͺ� " << setw(12) << "�������� "
		<< setw(12) << "�ձ������� " << setw(30) << "�ص�����ҽԺ " << setw(50) << "ע��" << endl;
}


/*
���ʾ�������Ӧ����
*/

//��ȡ�ļ�
goods_supplier_manage::goods_supplier_manage() {
	suppliers.clear();
	ifstream file(filename_goods_supplier);
	string line;
	char buf[1024];
	char temp[256];
	getline(file, line);//��ȡ��¼�������
	max_num = atoi(line.c_str());//�������
	goods_supplier supplier;
	while (getline(file, line)) {
		unsigned int i = 0;//line��λ��
		int j = 0;//buf��λ��
		int pos = 0;//��ȡ�����ݶ�Ӧ��ϵ
		strcpy_s(buf, line.c_str());
		for (i; i <= line.length(); i++) {
			if (buf[i] == '\0') {
				temp[j] = '\0';
				j = 0;
				supplier.su_comment = temp;
				//std::cout << temp << endl;
				pos = 0;
				break;
			}
			else if (buf[i] == ' '&&pos <= 4) {
				temp[j] = '\0';
				switch (pos) {
				case 0:supplier.su_key = atoi(temp); break;
				case 1:supplier.su_orgname = temp; break;
				case 2:supplier.su_address = temp; break;
				case 3:supplier.su_name = temp; break;
				case 4:supplier.su_phone = temp; break;
				}
				pos++;
				//std::cout << temp<<" ";
				j = 0;
			}
			else {
				temp[j] = buf[i];
				j++;
			}
		}
		//max_num = max_num > supplier.su_key ? max_num : supplier.su_key;
		suppliers.push_back(supplier);
	}

	file.close();

	//д����־
	FILE* file1;
	fopen_s(&file1, filename_log, "a");
	string str;
	gettime(str);
	str += "��ȡgoods_suppliers����Ӧ�̣��ļ�";
	str += "\n";
	fwrite(str.c_str(), str.length(), 1, file1);
	fclose(file1);

	//query_supplier();
}

//д���ļ�
goods_supplier_manage::~goods_supplier_manage() {
	FILE* file;
	fopen_s(&file, filename_goods_supplier, "w");
	if (file == NULL) {
		cout << "error" << endl;
	}

	char buf[10];
	_itoa_s(max_num, buf, 10);
	string s(buf);
	s += "\n";
	fwrite(s.c_str(), s.length(), 1, file);
	//fwrite("\n", 1, 1, file);
	//������list�������
	for_each(suppliers.begin(), suppliers.end(), [&file](list<goods_supplier>::reference a) {			//����lamda��������
		string result;
		result << a;
		fwrite(result.c_str(), result.length(), 1, file);
	});
	fclose(file);

	//д����־
	FILE* file1;
	fopen_s(&file1, filename_log, "a");
	string str;
	gettime(str);
	str += "�ر�suppliers�����ʹ�Ӧ�ߣ��ļ�";
	str += "\n";
	fwrite(str.c_str(), str.length(), 1, file1);
	fclose(file1);
}

boolean goods_supplier_manage::add_supplier() {
	query_supplier();
	goods_supplier supplier = {};

	max_num++;
	int num = max_num;
	supplier.su_key = num;
	std::cout << "������������ƣ�" << endl;
	cin >> supplier.su_orgname;
	std::cout << "�����������ַ��" << endl;
	cin >> supplier.su_address;
	std::cout << "��������ϵ��������" << endl;
	cin >> supplier.su_name;
	std::cout << "��������ϵ�˵绰��" << endl;
	cin >> supplier.su_phone;
	std::cout << "�����뱸ע��Ϣ��" << endl;
	cin >> supplier.su_comment;

	list<goods_supplier>::iterator iter = suppliers.begin();
	//����Ƿ����
	while (iter != suppliers.end()) {
		if (iter->su_orgname == supplier.su_orgname&&iter->su_address == supplier.su_address&&iter->su_name == supplier.su_name) {
			std::cout << "Sorry, �˻�����ϵ���Ѿ����ڣ�����" << endl;
			return FALSE;
		}
		else
			iter++;
	}

	suppliers.push_back(supplier);
	listColumns();
	cout << supplier;
	return TRUE;
}

boolean goods_supplier_manage::delete_supplier() {
	query_supplier();
	cout << "�����빩Ӧ�߱�ţ� " << endl;
	int num = -1;
	cin >> num;
	list<goods_supplier>::iterator iter = suppliers.begin();
	while (iter != suppliers.end()) {
		if (iter->su_key == num) {
			cout << "ȷ��ɾ����		" << "q����ȡ���� y����yes" << endl;

			char temp = getchar();;//������ַ�
			while (temp != 'q' && temp != 'y') {
				temp = getchar();
				if (temp == 'q')
					return FALSE;
				else if (temp == 'y') {
					suppliers.erase(iter);
					return TRUE;
				}
			}
		}
		iter++;
	}
	cout << "δ�ҵ�����Ŷ�Ӧ�Ĺ�Ӧ�ߣ���" << endl;
	return TRUE;
}

boolean goods_supplier_manage::modify_supplier() {
	query_supplier();

	std::cout << "���������޸ĵĹ�Ӧ����ţ�" << endl;

	int num = -1;
	cin >> num;
	//��ȡ������
	list<goods_supplier>::iterator iter = suppliers.begin();
	bool find = false;
	while (iter != suppliers.end()) {
		if (iter->su_key == num) {
			find = true;
			break;
		}
		iter++;
	}
	//��Ų�����
	if (!find) {
		std::cout << "����Ĺ�Ӧ����Ų����ڣ�����" << endl;
		return FALSE;
	}

	std::cout << "�����������������顣" << endl;
	goods_supplier supplier;
	supplier.su_key = iter->su_key;
	std::cout << "�����빩Ӧ�������ƣ�" << endl;
	cin >> supplier.su_orgname;
	std::cout << "�����������ַ��" << endl;
	cin >> supplier.su_address;
	std::cout << "��������ϵ��������" << endl;
	cin >> supplier.su_name;
	std::cout << "��������ϵ�˵绰��" << endl;
	cin >> supplier.su_phone;
	std::cout << "�����뱸ע��" << endl;
	cin >> supplier.su_comment;

	std::cout << "ȷ�������𣿣�ȡ����������NO��ȷ��������������" << endl;
	string choice = "NO";
	cin >> choice;
	if (choice == "NO" || choice == "no" || choice == "No") {
		return FALSE;
	}
	else {
		//�޸�����������Ϣ

		iter->su_orgname = supplier.su_orgname;
		iter->su_address = supplier.su_address;
		iter->su_name = supplier.su_name;
		iter->su_phone = supplier.su_phone;
		iter->su_comment = supplier.su_comment;
	}
	std::cout << "�޸ĳɹ�����" << endl;
	std::cout << "�޸�������Ϣ���£�" << supplier << endl;


	return TRUE;
}

//��ѯ���ʹ�Ӧ��
boolean goods_supplier_manage::query_supplier() {
	listColumns();
	for (goods_supplier supplier : suppliers) {
		cout << supplier;
	}
	return TRUE;
}

void goods_supplier_manage::listColumns() {
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(8) << "��� " << setw(20) << "�������� " << setw(30) << "������ַ " << setw(14) << "��ϵ������ "
		<< setw(15) << "��ϵ�绰 " << setw(30) << "ע��" << endl;
}



/*
������ת
*/

//��ȡ�ļ�

goods_supply_manage::goods_supply_manage() :s1(1), s2(2) {
	ifstream file(filename_goods_supply);
	string line;
	char buf[1024];
	char temp[256];
	goods_supply supply;
	while (getline(file, line)) {
		unsigned int i = 0;//line��λ��
		int j = 0;//buf��λ��
		int pos = 0;//��ȡ�����ݶ�Ӧ��ϵ
		strcpy_s(buf, line.c_str());
		for (i; i <= line.length(); i++) {
			if (buf[i] == '\0') {
				temp[j] = '\0';
				j = 0;
				supply.s_comment = temp;
				//std::cout << temp << endl;
				pos = 0;
				break;
			}
			else if (buf[i] == ' '&&pos <= 4) {
				temp[j] = '\0';
				switch (pos) {
				case 0:supply.in_key = atoi(temp); break;
				case 1:supply.su_key = atoi(temp); break;
				case 2:supply.s_quantity = atoi(temp); break;
				case 3:supply.s_price = float(atof(temp)); break;
				case 4:supply.batch = temp; break;
				}
				pos++;
				j = 0;
			}
			else {
				temp[j] = buf[i];
				j++;
			}
		}
		supplies.push_back(supply);
	}

	file.close();

	//д����־
	FILE* file1;
	fopen_s(&file1, filename_log, "a");
	string str;
	gettime(str);
	str += "��ȡgoods_supply��������ת���ļ�";
	str += "\n";
	fwrite(str.c_str(), str.length(), 1, file1);
	fclose(file1);

	//query_circulation();
}

//д���ļ�
goods_supply_manage::~goods_supply_manage() {

	FILE* file;
	fopen_s(&file, filename_goods_supply, "w");
	if (file == NULL) {
		cout << "error" << endl;
	}

	//������list�������
	for_each(supplies.begin(), supplies.end(), [&file](list<goods_supply>::reference a) {			//����lamda��������
		string result;
		result << a;
		fwrite(result.c_str(), result.length(), 1, file);
	});
	fclose(file);

	//д����־
	FILE* file1;
	fopen_s(&file1, filename_log, "a");
	string str;
	gettime(str);
	str += "�ر�supplies��������ת���ļ�";
	str += "\n";
	fwrite(str.c_str(), str.length(), 1, file1);
	fclose(file1);
}

boolean goods_supply_manage::add_circulation() {
	query_circulation();
	goods_supply supply = {};

	std::cout << "�������Ӧ���ʱ�ţ�" << endl;
	cin >> supply.in_key;
	std::cout << "�������Ӧ����������ţ�" << endl;
	cin >> supply.su_key;

	//����Լ��
	list<goods_information>::iterator iter1 = s1.getIteratorBegin();
	list<goods_information>::iterator iter2 = s1.getIteratorEnd();
	list<goods_supplier>::iterator iter3 = s2.getIteratorBegin();
	list<goods_supplier>::iterator iter4 = s2.getIteratorEnd();

	bool find1 = false, find2 = false;
	//����Ƿ����
	while (iter1 != iter2) {
		if (iter1->in_key == supply.in_key) {
			find1 = true;
			break;
		}
		else
			iter1++;
	}
	while (iter3 != iter4) {
		if (iter3->su_key == supply.su_key) {
			find2
				= true;
			break;
		}
		else
			iter3++;
	}

	if (!find1) {
		cout << "δ�ҵ���Ӧ���������ͣ���" << endl;
		return FALSE;
	}

	if (!find2) {
		cout << "δ�ҵ�������������ˣ���" << endl;
		return FALSE;
	}

	std::cout << "���������������" << endl;
	cin >> supply.s_quantity;
	std::cout << "�����뵱�ؾ�����Ʒ���ۣ�" << endl;
	cin >> supply.s_price;
	std::cout << "���������Σ�" << endl;
	cin >> supply.batch;
	std::cout << "�����뱸ע��Ϣ��" << endl;
	cin >> supply.s_comment;
	supplies.push_back(supply);
	cout << setw(12) << "���ʱ��" << setw(12) << "�������" << setw(12) << "��������"
		<< setw(12) << "��������" << setw(12) << "��������" << setw(30) << "ע��" << endl;
	cout << supply;
	return TRUE;
}

boolean goods_supply_manage::delete_circulation() {
	query_circulation();
	int in_key = -1, su_key = -1;
	string batch;

	cout << "���������ʱ�ţ� " << endl;
	cin >> in_key;
	cout << "����������߱�ţ� " << endl;
	cin >> su_key;
	cout << "�������������Σ� " << endl;
	cin >> batch;
	list<goods_supply>::iterator iter = supplies.begin();
	while (iter != supplies.end()) {
		if (iter->in_key == in_key && iter->su_key == su_key && iter->batch == batch) {
			cout << "ȷ��ɾ����		" << "q����ȡ���� y����yes" << endl;

			char temp = getchar();;//������ַ�
			while (temp != 'q' && temp != 'y') {
				temp = getchar();
				if (temp == 'q')
					return FALSE;
				else if (temp == 'y') {
					supplies.erase(iter);
					return TRUE;
				}
			}
		}
		iter++;
	}
	cout << "δ�ҵ�����ת��Ϣ����" << endl;

	return TRUE;
}

boolean goods_supply_manage::modify_circulation() {
	cout << "�����������飺" << endl;
	s1.query_goods_category();
	cout << "���������飺" << endl;
	s2.query_supplier();
	cout << endl << endl;

	query_circulation();

	int which = -1;
	bool find = false;

	cout << "�������Ӧ����ת��ţ�" << endl;
	cin >> which;

	//��ȡ������
	list<goods_supply>::iterator iter = supplies.begin();

	if (which <= signed(supplies.size())) {
		for (int i = 0; i < which - 1; i++) {
			iter++;
		}
		find = true;
	}
	//��Ų�����
	if (!find) {
		std::cout << "�������ת��Ϣ�����ڣ�����" << endl;
		return FALSE;
	}

	std::cout << "������������ת��Ϣ���顣" << endl;
	goods_supply supply;
	std::cout << "���������ʱ�ţ�" << endl;
	cin >> supply.in_key;
	std::cout << "����������߱�ţ�" << endl;
	cin >> supply.su_key;
	std::cout << "���������������" << endl;
	cin >> supply.s_quantity;
	std::cout << "���������Ʒ���ۣ�" << endl;
	cin >> supply.s_price;
	std::cout << "�����뱸ע��" << endl;
	cin >> supply.s_comment;

	std::cout << "ȷ�������𣿣�ȡ����������NO��ȷ��������������" << endl;
	string choice = "NO";
	cin >> choice;
	if (choice == "NO" || choice == "no" || choice == "No") {
		return FALSE;
	}
	else {
		//�޸�����������Ϣ

		iter->in_key = supply.in_key;
		iter->su_key = supply.su_key;
		iter->s_quantity = supply.s_quantity;
		iter->s_price = supply.s_price;
		iter->s_comment = supply.s_comment;
	}
	std::cout << "�޸ĳɹ�����" << endl;
	std::cout << "�޸�������ת��Ϣ���£�" << supply << endl;

	return TRUE;
}

boolean goods_supply_manage::query_circulation() {
	listColumns();
	int i = 1;
	cout.setf(ios::left, ios::adjustfield);
	for (goods_supply supply : supplies) {
		cout << setw(12) << i << " " << supply;
		i++;
	}

	return TRUE;
}

void goods_supply_manage::listColumns() {
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(12) << "��ת���" << setw(12) << "���ʱ��" << setw(12) << "�������" << setw(12) << "��������"
		<< setw(12) << "��������" << setw(12) << "��������" << setw(30) << "ע��" << endl;
}

////����ɾ��
//void goods_supply_manage::erase(int in_key) {
//	list<goods_supply>::iterator iter1 = supplies.begin();
//	while (iter1 != supplies.end()) {
//		if (iter1->in_key == in_key) {
//			iter1=supplies.erase(iter1);
//		}
//		else
//			iter1++;
//	}
//}