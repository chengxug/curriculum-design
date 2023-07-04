#pragma once
#include <string>
#include "Define.h"

// 基类 Person =====================================================================================================================
class Person {
public:
	Person(std::string acc , std::string pass, std::string nm = "", std::string gend = "男", std::string ph_num = "");
	~Person();
	Person& operator=(const Person&);//重载赋值运算符
protected:
    void view_per_info(); //查看个人信息
	void modify_pass(); //修改密码
private:
	std::string account;
	std::string password;
	std::string name;
	std::string gender;
	std::string phoneNumber;
};

// Student类 ==============================================================================================================================

class Student : public Person{
public:
	Student(std::string acc = ACCOUNT[STUDENT], std::string pass = PASSWORD[STUDENT], std::string nm, std::string gend, std::string ph_num, std::string addr = "");
	~Student();
	Student& operator=(const Student&);
protected:
	void view_per_score();//查询个人成绩
private:
	std::string address;
	double testScore[4];//考试成绩：语文、数学、英语，平均
	double qualScore[5];//素质成绩：语文教师评分、数学教师评分、英语教师评分、同学互评分、品德成绩
	double comphScore;//综测总分
	int testRand;//考试排名
	int comphscoreRand;//综测总评排名
	Student* next;//指向下个节点的后继指针
};

class Teacher :public Person{
public:
	Teacher(std::string acc, std::string pass, std::string nm, std::string gend, std::string ph_num, std::string subject);
	~Teacher();
	Teacher& operator=(const Teacher&);//重载赋值运算符
protected:
	void input_stu_score(); //录入学生成绩
	void announce_score(); //发布学生成绩
	void correct_score(); //修改学生成绩
	void check_score(); //查看学生成绩
private:
	std::string subject; //所教科目
	Teacher* next; //指向下个节点的后继指针
};

class Administrator : public Person{
public:
	Administrator();
	~Administrator();
	Administrator& operator=(const Administrator&);
protected:
	void view_member();//查看成员信息
	void input_member();//录入成员
	void correct_member();//修改成员信息
	void delete_member();//删除成员信息
private:
	Administrator* next;//指向下个节点的后继指针
};

// 在内存中存储、操作信息的 Data 类====================================================================================================
template <class User>
class Data {
public:
	Data();
	~Data();
protected:
	void find_elem(); //查询元素
	User& get_elem(); //获取元素
	void data_insert(); //插入元素
	void data_delete(); //删除元素
	void match(); //登录时匹配账号信息
};
