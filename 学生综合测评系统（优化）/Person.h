#pragma once
#include <string>

// 基类 Person =====================================================================================================================
class Person {
public:
	Person(std::string acc, std::string pass, std::string nm, std::string gend, std::string ph_num);
	~Person();
protected:
    void view_individual_inf(); //查看个人信息
	void modify_pass(); //修改密码
private:
	std::string account;
	std::string password;
	std::string name;
	std::string gender;
	std::string phoneNumber;
};

// 三个子类 ==============================================================================================================================
class Student : public Person{
public:
	Student(std::string acc, std::string pass, std::string nm, std::string gend, std::string ph_num, std::string address);
	~Student();
	Student& operator=(const Student&);
protected:
	void check_individual_score();//查询个人成绩
private:
	std::string address;
	double textScore[4];
	double qualScore[4];
	double comphScore;
	int textRand;
	int comphscoreRand;
	Student* next;
};

class Teacher :public Person{
public:
	Teacher(std::string acc, std::string pass, std::string nm, std::string gend, std::string ph_num, std::string subject);
	~Teacher();
	Teacher& operator=(const Teacher&);
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
