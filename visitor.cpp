#include <string>
#include <iostream>

using namespace std;

class Man;
class Woman;

class Visitor
{
public:
	virtual void get_man_action(){};
	virtual void get_woman_action(){};
public:
	string state;
};

class Person
{
public:
	void accept(Visitor* visitor);
};

class Man: public Person
{
public:
	void accept(Visitor* visitor){
		visitor->get_man_action();
	}
};
class Woman:public Person
{
public:
	void accept(Visitor* visitor){
		visitor->get_woman_action();
	}
};
class Success: public Visitor
{
public:
	Success(){ state="Success"; }
	void get_man_action(){
		cout<<"when a man "<<state<<","<<"there is a good woman behind him."<<endl;
	}
	void get_woman_action(){
		cout<<"when a woman "<<state<<","<<"there is a bad man behind her."<<endl;
	}

};

class Failing: public Visitor
{
public:
	Failing(){state="Failed";}
	void get_man_action(){
		cout<<"when a man "<<state<<","<<"there is a bad woman behind him."<<endl;
	}
	void get_woman_action(){
		cout<<"when a woman "<<state<<","<<"there is a good man behind her."<<endl;
	}
};

int main(int argc,char* argv[])
{
	Man* man=new Man();
	Success* success=new Success();
	Failing* failing=new Failing();
	man->accept(success);
	man->accept(failing);
	Woman* woman=new Woman();
	woman->accept(success);
	woman->accept(failing);
	return 0;
}

