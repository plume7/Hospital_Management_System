#include "stdafx.h"
#include "goods.h"

//表格数据的保存地址
char filename_goods_information1[] = "./tables/goods_information.txt";
char* filename_goods_information = filename_goods_information1;
char filename_goods_supplier1[] = "./tables/goods_supplier.txt";
char* filename_goods_supplier = filename_goods_supplier1;
char filename_goods_supply1[] = "./tables/goods_supply.txt";
char* filename_goods_supply = filename_goods_supply1;
char filename_log1[] = "./tables/log.txt";
char* filename_log = filename_log1;

//类的static list成员变量的初始化
list<goods_information> goods_information_manage::goods = {};
list<goods_supplier> goods_supplier_manage::suppliers = {};
list<goods_supply> goods_supply_manage::supplies = {};

//类的list（记录的最大编号）
int  goods_information_manage::max_num = 0;
int  goods_supplier_manage::max_num = 0;


/*
物资种类管理
*/

//构造函数，读取文件到list
goods_information_manage::goods_information_manage() {
	goods.clear();
	ifstream file(filename_goods_information);
	string line;
	char buf[1024];
	char temp[256];
	getline(file, line);//获取记录的最大数
	max_num = atoi(line.c_str());//最大的序号
	goods_information good;
	while (getline(file, line)) {
		unsigned int i = 0;//line的位置
		int j = 0;//buf的位置
		int pos = 0;//读取的数据对应关系
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

	//写入日志
	FILE* file1;
	fopen_s(&file1, filename_log, "a");
	string str;
	gettime(str);
	str += "读取goods_information（物资种类）文件";
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
	//遍历对list输出重载
	for_each(goods.begin(), goods.end(), [&file](list<goods_information>::reference a) {			//采用lamda匿名函数
		string result;
		result << a;
		fwrite(result.c_str(), result.length(), 1, file);
	});
	fclose(file);

	//写入日志
	FILE* file1;
	fopen_s(&file1, filename_log, "a");
	string str;
	gettime(str);
	str += "关闭goods_information（物资种类）文件";
	str += "\n";
	fwrite(str.c_str(), str.length(), 1, file1);
	fclose(file1);
}

boolean goods_information_manage::add_goods_category() {
	query_goods_category();
	goods_information good = {};
	good.in_hospital = "null";
	good.in_comment = "null";

	//只能允许添加物资名称，和型号
	max_num++;
	int num = max_num;
	good.in_key = num;
	std::cout << setw(30) << "请输入物资名称：";
	cin >> good.in_name;
	std::cout << setw(30) << "请输入物资型号：";
	cin >> good.in_type;

	list<goods_information>::iterator iter = goods.begin();
	//检查是否存在
	while (iter != goods.end()) {
		if (iter->in_name == good.in_name&&iter->in_type == good.in_type) {
			std::cout << setw(30) << "Sorry, 此种类已经存在！！！" << endl;
			return FALSE;
		}
		else
			iter++;
	}

	goods.push_back(good);
	std::cout << setw(30) << "种类" << setw(30) << "型号" << endl;
	std::cout << setw(30) << good.in_name << setw(30) << good.in_type << endl;
	std::cout << setw(70) << " 添加成功!" << endl;
	return TRUE;
}

boolean goods_information_manage::modify_goods_category() {
	query_goods_category();

	std::cout << "请输入需修改的物资序号：" << endl;

	int num = -1;
	cin >> num;
	//获取迭代器
	list<goods_information>::iterator iter = goods.begin();
	bool find = false;
	while (iter != goods.end()) {
		if (iter->in_key == num) {
			find = true;
			break;
		}
		iter++;
	}
	//标号不存在
	if (!find) {
		std::cout << "输入的物资序号不存在！！！" << endl;
		return FALSE;
	}

	std::cout << "请重新输入物资详情。" << endl;
	goods_information good;
	good.in_key = iter->in_key;
	std::cout << "请输入物资名称：" << endl;
	cin >> good.in_name;
	std::cout << "请输入物资型号：" << endl;
	cin >> good.in_type;
	std::cout << "请输入物资数量：" << endl;
	cin >> good.in_quantity;
	std::cout << "请输入物资日报废数：" << endl;
	cin >> good.in_use;
	std::cout << "请输入物资重点需要的医院：" << endl;
	cin >> good.in_hospital;
	std::cout << "请输入备注：" << endl;
	cin >> good.in_comment;

	std::cout << "确定更改吗？？取消——输入NO，确定——任意输入" << endl;
	string choice = "NO";
	cin >> choice;
	if (choice == "NO" || choice == "no" || choice == "No") {
		return FALSE;
	}
	else {
		//修改物资种类信息

		iter->in_name = good.in_name;
		iter->in_type = good.in_type;
		iter->in_quantity = good.in_quantity;
		iter->in_hospital = good.in_hospital;
		iter->in_use = good.in_use;
		iter->in_comment = good.in_comment;
	}
	std::cout << "修改成功！！" << endl;
	std::cout << "修改物资信息如下：" << good << endl;

	return TRUE;
}

boolean goods_information_manage::delete_goods_category() {
	query_goods_category();
	cout << "请输入物资编号： " << endl;
	int num = -1;
	cin >> num;
	list<goods_information>::iterator iter = goods.begin();
	while (iter != goods.end()) {
		if (iter->in_key == num) {
			cout << "确定删除吗？		" << "q——取消， y——yes" << endl;

			char temp = getchar();;//输入的字符
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
	std::cout << "未找到改序号对应的物资！！" << endl;
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
	cout << setw(12) << "物资编号 " << setw(12) << "物资名称 " << setw(26) << "物资型号 " << setw(12) << "物资数量 "
		<< setw(12) << "日报废数量 " << setw(30) << "重点需求医院 " << setw(50) << "注释" << endl;
}


/*
物资捐赠，供应管理
*/

//读取文件
goods_supplier_manage::goods_supplier_manage() {
	suppliers.clear();
	ifstream file(filename_goods_supplier);
	string line;
	char buf[1024];
	char temp[256];
	getline(file, line);//获取记录的最大数
	max_num = atoi(line.c_str());//最大的序号
	goods_supplier supplier;
	while (getline(file, line)) {
		unsigned int i = 0;//line的位置
		int j = 0;//buf的位置
		int pos = 0;//读取的数据对应关系
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

	//写入日志
	FILE* file1;
	fopen_s(&file1, filename_log, "a");
	string str;
	gettime(str);
	str += "读取goods_suppliers（供应商）文件";
	str += "\n";
	fwrite(str.c_str(), str.length(), 1, file1);
	fclose(file1);

	//query_supplier();
}

//写入文件
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
	//遍历对list输出重载
	for_each(suppliers.begin(), suppliers.end(), [&file](list<goods_supplier>::reference a) {			//采用lamda匿名函数
		string result;
		result << a;
		fwrite(result.c_str(), result.length(), 1, file);
	});
	fclose(file);

	//写入日志
	FILE* file1;
	fopen_s(&file1, filename_log, "a");
	string str;
	gettime(str);
	str += "关闭suppliers（物资供应者）文件";
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
	std::cout << "请输入机构名称：" << endl;
	cin >> supplier.su_orgname;
	std::cout << "请输入机构地址：" << endl;
	cin >> supplier.su_address;
	std::cout << "请输入联系人姓名：" << endl;
	cin >> supplier.su_name;
	std::cout << "请输入联系人电话：" << endl;
	cin >> supplier.su_phone;
	std::cout << "请输入备注信息：" << endl;
	cin >> supplier.su_comment;

	list<goods_supplier>::iterator iter = suppliers.begin();
	//检查是否存在
	while (iter != suppliers.end()) {
		if (iter->su_orgname == supplier.su_orgname&&iter->su_address == supplier.su_address&&iter->su_name == supplier.su_name) {
			std::cout << "Sorry, 此机构联系人已经存在！！！" << endl;
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
	cout << "请输入供应者编号： " << endl;
	int num = -1;
	cin >> num;
	list<goods_supplier>::iterator iter = suppliers.begin();
	while (iter != suppliers.end()) {
		if (iter->su_key == num) {
			cout << "确定删除吗？		" << "q——取消， y——yes" << endl;

			char temp = getchar();;//输入的字符
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
	cout << "未找到改序号对应的供应者！！" << endl;
	return TRUE;
}

boolean goods_supplier_manage::modify_supplier() {
	query_supplier();

	std::cout << "请输入需修改的供应商序号：" << endl;

	int num = -1;
	cin >> num;
	//获取迭代器
	list<goods_supplier>::iterator iter = suppliers.begin();
	bool find = false;
	while (iter != suppliers.end()) {
		if (iter->su_key == num) {
			find = true;
			break;
		}
		iter++;
	}
	//标号不存在
	if (!find) {
		std::cout << "输入的供应商序号不存在！！！" << endl;
		return FALSE;
	}

	std::cout << "请重新输入物资详情。" << endl;
	goods_supplier supplier;
	supplier.su_key = iter->su_key;
	std::cout << "请输入供应机构名称：" << endl;
	cin >> supplier.su_orgname;
	std::cout << "请输入机构地址：" << endl;
	cin >> supplier.su_address;
	std::cout << "请输入联系人姓名：" << endl;
	cin >> supplier.su_name;
	std::cout << "请输入联系人电话：" << endl;
	cin >> supplier.su_phone;
	std::cout << "请输入备注：" << endl;
	cin >> supplier.su_comment;

	std::cout << "确定更改吗？？取消——输入NO，确定——任意输入" << endl;
	string choice = "NO";
	cin >> choice;
	if (choice == "NO" || choice == "no" || choice == "No") {
		return FALSE;
	}
	else {
		//修改物资种类信息

		iter->su_orgname = supplier.su_orgname;
		iter->su_address = supplier.su_address;
		iter->su_name = supplier.su_name;
		iter->su_phone = supplier.su_phone;
		iter->su_comment = supplier.su_comment;
	}
	std::cout << "修改成功！！" << endl;
	std::cout << "修改物资信息如下：" << supplier << endl;


	return TRUE;
}

//查询物资供应者
boolean goods_supplier_manage::query_supplier() {
	listColumns();
	for (goods_supplier supplier : suppliers) {
		cout << supplier;
	}
	return TRUE;
}

void goods_supplier_manage::listColumns() {
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(8) << "编号 " << setw(20) << "机构名称 " << setw(30) << "机构地址 " << setw(14) << "联系人姓名 "
		<< setw(15) << "联系电话 " << setw(30) << "注释" << endl;
}



/*
物资流转
*/

//读取文件

goods_supply_manage::goods_supply_manage() :s1(1), s2(2) {
	ifstream file(filename_goods_supply);
	string line;
	char buf[1024];
	char temp[256];
	goods_supply supply;
	while (getline(file, line)) {
		unsigned int i = 0;//line的位置
		int j = 0;//buf的位置
		int pos = 0;//读取的数据对应关系
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

	//写入日志
	FILE* file1;
	fopen_s(&file1, filename_log, "a");
	string str;
	gettime(str);
	str += "读取goods_supply（物资流转）文件";
	str += "\n";
	fwrite(str.c_str(), str.length(), 1, file1);
	fclose(file1);

	//query_circulation();
}

//写入文件
goods_supply_manage::~goods_supply_manage() {

	FILE* file;
	fopen_s(&file, filename_goods_supply, "w");
	if (file == NULL) {
		cout << "error" << endl;
	}

	//遍历对list输出重载
	for_each(supplies.begin(), supplies.end(), [&file](list<goods_supply>::reference a) {			//采用lamda匿名函数
		string result;
		result << a;
		fwrite(result.c_str(), result.length(), 1, file);
	});
	fclose(file);

	//写入日志
	FILE* file1;
	fopen_s(&file1, filename_log, "a");
	string str;
	gettime(str);
	str += "关闭supplies（物资流转）文件";
	str += "\n";
	fwrite(str.c_str(), str.length(), 1, file1);
	fclose(file1);
}

boolean goods_supply_manage::add_circulation() {
	query_circulation();
	goods_supply supply = {};

	std::cout << "请输入对应物资编号：" << endl;
	cin >> supply.in_key;
	std::cout << "请输入对应捐赠机构编号：" << endl;
	cin >> supply.su_key;

	//主键约束
	list<goods_information>::iterator iter1 = s1.getIteratorBegin();
	list<goods_information>::iterator iter2 = s1.getIteratorEnd();
	list<goods_supplier>::iterator iter3 = s2.getIteratorBegin();
	list<goods_supplier>::iterator iter4 = s2.getIteratorEnd();

	bool find1 = false, find2 = false;
	//检查是否存在
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
		cout << "未找到对应的物资类型！！" << endl;
		return FALSE;
	}

	if (!find2) {
		cout << "未找到捐赠机构或个人！！" << endl;
		return FALSE;
	}

	std::cout << "请输入捐赠数量：" << endl;
	cin >> supply.s_quantity;
	std::cout << "请输入当地捐赠物品单价：" << endl;
	cin >> supply.s_price;
	std::cout << "请输入批次：" << endl;
	cin >> supply.batch;
	std::cout << "请输入备注信息：" << endl;
	cin >> supply.s_comment;
	supplies.push_back(supply);
	cout << setw(12) << "物资编号" << setw(12) << "机构编号" << setw(12) << "捐赠数量"
		<< setw(12) << "捐赠单价" << setw(12) << "捐赠批次" << setw(30) << "注释" << endl;
	cout << supply;
	return TRUE;
}

boolean goods_supply_manage::delete_circulation() {
	query_circulation();
	int in_key = -1, su_key = -1;
	string batch;

	cout << "请输入物资编号： " << endl;
	cin >> in_key;
	cout << "请输入捐赠者编号： " << endl;
	cin >> su_key;
	cout << "请输入物资批次： " << endl;
	cin >> batch;
	list<goods_supply>::iterator iter = supplies.begin();
	while (iter != supplies.end()) {
		if (iter->in_key == in_key && iter->su_key == su_key && iter->batch == batch) {
			cout << "确定删除吗？		" << "q——取消， y——yes" << endl;

			char temp = getchar();;//输入的字符
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
	cout << "未找到改流转信息！！" << endl;

	return TRUE;
}

boolean goods_supply_manage::modify_circulation() {
	cout << "物资种类详情：" << endl;
	s1.query_goods_category();
	cout << "捐赠者详情：" << endl;
	s2.query_supplier();
	cout << endl << endl;

	query_circulation();

	int which = -1;
	bool find = false;

	cout << "请输入对应的流转序号：" << endl;
	cin >> which;

	//获取迭代器
	list<goods_supply>::iterator iter = supplies.begin();

	if (which <= signed(supplies.size())) {
		for (int i = 0; i < which - 1; i++) {
			iter++;
		}
		find = true;
	}
	//标号不存在
	if (!find) {
		std::cout << "输入的流转信息不存在！！！" << endl;
		return FALSE;
	}

	std::cout << "请重新输入流转信息详情。" << endl;
	goods_supply supply;
	std::cout << "请输入物资编号：" << endl;
	cin >> supply.in_key;
	std::cout << "请输入捐赠者编号：" << endl;
	cin >> supply.su_key;
	std::cout << "请输入捐赠数量：" << endl;
	cin >> supply.s_quantity;
	std::cout << "请输入捐赠品单价：" << endl;
	cin >> supply.s_price;
	std::cout << "请输入备注：" << endl;
	cin >> supply.s_comment;

	std::cout << "确定更改吗？？取消——输入NO，确定——任意输入" << endl;
	string choice = "NO";
	cin >> choice;
	if (choice == "NO" || choice == "no" || choice == "No") {
		return FALSE;
	}
	else {
		//修改物资种类信息

		iter->in_key = supply.in_key;
		iter->su_key = supply.su_key;
		iter->s_quantity = supply.s_quantity;
		iter->s_price = supply.s_price;
		iter->s_comment = supply.s_comment;
	}
	std::cout << "修改成功！！" << endl;
	std::cout << "修改物资流转信息如下：" << supply << endl;

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
	cout << setw(12) << "流转序号" << setw(12) << "物资编号" << setw(12) << "机构编号" << setw(12) << "捐赠数量"
		<< setw(12) << "捐赠单价" << setw(12) << "捐赠批次" << setw(30) << "注释" << endl;
}

////级联删除
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