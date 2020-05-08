#pragma once

#include "stdafx.h"
//������Ϣ

//1.���ʱ�goods_information
//�����ʱ�ţ�in_key
//���������ƣ�in_name
//�������ͺţ�in_type
//������������in_quantity
//���ص���Ҫ�����ʵ�ҽԺ��in_hospital
//�������ձ���������in_use
//�߱�ע��in_comment
typedef struct goods_information {
	int in_key;
	string in_name;
	string in_type;
	int in_quantity;
	int in_use;
	string in_hospital;
	string in_comment;

	//�Խṹ�������������
	friend ostream & operator<< (ostream &, goods_information &t) {
		cout.setf(ios::left, ios::adjustfield);
		std::cout << setw(12) << t.in_key << setw(12) << t.in_name << setw(26) << t.in_type << setw(12) <<
			t.in_quantity << setw(12) << t.in_use << setw(30) << t.in_hospital << setw(50) << t.in_comment << endl;
		return std::cout;
	}
	//�Խṹ������תΪstring����
	friend string& operator << (string &str, const goods_information &t) {
		stringstream sstr;
		sstr << setfill('0') << setw(4) << t.in_key << " " << t.in_name << " " << t.in_type << " " <<
			t.in_quantity << " " << t.in_use << " " << t.in_hospital << " " << t.in_comment << endl;
		str = sstr.str();
		return str;
	}
}goods_information;


//��Ӧ��Ϣ

//2.����������Ϣ��goods_supplier
//�ٱ�ţ�su_key
//�ڻ������ƣ�su_organname
//�ۻ�����ַ��su_address
//����ϵ��������su_name
//����ϵ�绰��su_phone
//�ޱ�ע��su_comment
typedef struct goods_supplier {
	int su_key;
	string su_orgname;
	string su_address;
	string su_name;
	string su_phone;
	string su_comment;
	friend ostream & operator<< (ostream &, goods_supplier &t) {
		cout.setf(ios::left, ios::adjustfield);
		std::cout << setw(8) << t.su_key << setw(20) << t.su_orgname << setw(30) << t.su_address <<
			setw(14) << t.su_name << setw(15) << t.su_phone << setw(30) << t.su_comment << endl;
		return std::cout;
	}
	friend string& operator << (string &str, const goods_supplier &t) {
		stringstream sstr;
		cout.setf(ios::left, ios::adjustfield);
		sstr << setfill('0') << setw(4) << t.su_key << " " << t.su_orgname << " " << t.su_address << " " << t.su_name << " " <<
			t.su_phone << " " << t.su_comment << endl;
		str = sstr.str();
		return str;
	}

}goods_supplier;

//ʹ����Ϣ

//3.��ת��Ϣ�������� / ��������goods_supply
//�پ�������(���1)��in_key
//�ھ�������(���2)��su_key
//�۾���������s_quantity
//�ܾ������ʵ��ص��ۣ�s_price
//�ݾ������Σ�batch
//�ޱ�ע��s_comment
typedef struct goods_supply {
	int in_key;
	int su_key;
	int s_quantity;
	float s_price;
	string batch;
	string s_comment;
	friend ostream & operator<< (ostream &, goods_supply &t) {
		cout.setf(ios::left, ios::adjustfield);
		std::cout << setw(12) << t.in_key << setw(12) << t.su_key << setw(12) << t.s_quantity << setw(12)
			<< t.s_price << setw(12) << t.batch << setw(30) << t.s_comment << endl;
		return std::cout;
	}
	friend string& operator << (string &str, const goods_supply &t) {
		stringstream sstr;
		sstr << setfill('0') << setw(4) << t.in_key << " " << setfill('0') << setw(4) << t.su_key << " " << t.s_quantity << " " << t.s_price << " " << t.batch << " " << t.s_comment << endl;
		str = sstr.str();
		return str;
	}
}goods_supply;


//�����������
class goods_information_manage {
private:
	static list<goods_information> goods;
	static int max_num;
public:
	goods_information_manage();
	goods_information_manage(int i) {};
	~goods_information_manage();
	boolean query_goods_category();
	boolean add_goods_category();
	boolean delete_goods_category();
	boolean modify_goods_category();
	void listColumns();//�г��ֶ�
	list<goods_information>::iterator getIteratorBegin() { return goods.begin(); }
	list<goods_information>::iterator getIteratorEnd() { return goods.end(); }
};

//���ʹ�Ӧ����
class goods_supplier_manage {
private:
	static list<goods_supplier> suppliers;
	static int max_num;
public:
	goods_supplier_manage();
	goods_supplier_manage(int i) {};
	~goods_supplier_manage();
	boolean query_supplier();
	boolean add_supplier();
	boolean delete_supplier();
	boolean modify_supplier();
	void listColumns();//�г��ֶ�
	list<goods_supplier>::iterator getIteratorBegin() { return suppliers.begin(); }
	list<goods_supplier>::iterator getIteratorEnd() { return suppliers.end(); }
};

//����ʹ�ù���
class goods_supply_manage {
private:
	static list<goods_supply> supplies;
	goods_information_manage s1;
	goods_supplier_manage s2;
public:
	goods_supply_manage();
	~goods_supply_manage();
	boolean add_circulation();//������ת��Ϣ
	boolean delete_circulation();//ɾ��
	boolean modify_circulation();//�޸�
	boolean query_circulation();//��ѯ
	void listColumns();
};
