#pragma once

#include "stdafx.h"
//物资信息

//1.物资表：goods_information
//①物资编号：in_key
//②物资名称：in_name
//③物资型号：in_type
//④物资数量：in_quantity
//⑤重点需要该物资的医院：in_hospital
//⑥物资日报废数量：in_use
//⑦备注：in_comment
typedef struct goods_information {
	int in_key;
	string in_name;
	string in_type;
	int in_quantity;
	int in_use;
	string in_hospital;
	string in_comment;

	//对结构体数据输出重载
	friend ostream & operator<< (ostream &, goods_information &t) {
		cout.setf(ios::left, ios::adjustfield);
		std::cout << setw(12) << t.in_key << setw(12) << t.in_name << setw(26) << t.in_type << setw(12) <<
			t.in_quantity << setw(12) << t.in_use << setw(30) << t.in_hospital << setw(50) << t.in_comment << endl;
		return std::cout;
	}
	//对结构体数据转为string重载
	friend string& operator << (string &str, const goods_information &t) {
		stringstream sstr;
		sstr << setfill('0') << setw(4) << t.in_key << " " << t.in_name << " " << t.in_type << " " <<
			t.in_quantity << " " << t.in_use << " " << t.in_hospital << " " << t.in_comment << endl;
		str = sstr.str();
		return str;
	}
}goods_information;


//供应信息

//2.捐赠机构信息：goods_supplier
//①编号：su_key
//②机构名称：su_organname
//③机构地址：su_address
//④联系人姓名：su_name
//⑤联系电话：su_phone
//⑥备注：su_comment
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

//使用信息

//3.流转信息表（供给表 / 捐赠表）：goods_supply
//①捐赠物资(外键1)：in_key
//②捐赠机构(外键2)：su_key
//③捐赠数量：s_quantity
//④捐赠物资当地单价：s_price
//⑤捐赠批次：batch
//⑥备注：s_comment
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


//物资种类管理
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
	void listColumns();//列出字段
	list<goods_information>::iterator getIteratorBegin() { return goods.begin(); }
	list<goods_information>::iterator getIteratorEnd() { return goods.end(); }
};

//物资供应管理
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
	void listColumns();//列出字段
	list<goods_supplier>::iterator getIteratorBegin() { return suppliers.begin(); }
	list<goods_supplier>::iterator getIteratorEnd() { return suppliers.end(); }
};

//物资使用管理
class goods_supply_manage {
private:
	static list<goods_supply> supplies;
	goods_information_manage s1;
	goods_supplier_manage s2;
public:
	goods_supply_manage();
	~goods_supply_manage();
	boolean add_circulation();//增加流转信息
	boolean delete_circulation();//删除
	boolean modify_circulation();//修改
	boolean query_circulation();//查询
	void listColumns();
};
