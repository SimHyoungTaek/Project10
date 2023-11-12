#include <iostream>
#include <cassert>

class CPO {//클래스 정의
public:
	virtual ~CPO() {}// 가상 소멸자
};

class CEO {//CEO 클래스 정의
public:
	virtual ~CEO() {}// 가상 소멸자
};

class Manager :public CPO, public CEO {//Manager 클래스 CPO와 CEO상속 받아서 정의
public:
	virtual ~Manager() {}// 가상 소멸자
};

class Staff : public Manager {//Staff 클래스 CEO, CPO를 상속받아 정의된 Manager상속받아 정의
public:
	virtual ~Staff() {}// 가상 소멸자
};
int main() {
	Staff staff;// staff 인스턴스 생성
	CPO* cpo = &staff;//staff 인스턴스 CPO포인터로 업캐스팅
	CEO* ceo = &staff;//staff 인스턴스 CEO포인터로 업캐스팅

	Staff* staff1 = dynamic_cast<Staff*>(cpo);//다이나믹 캐스트를 통해 CPO포인터를 Staff포인터로 다운캐스팅
	Staff* staff2 = dynamic_cast<Staff*>(ceo);//다이나믹 캐스트를 통해 CEO포인터를 Staff포인터로 다운캐스팅
	Manager* manager = dynamic_cast<Manager*>(ceo);//다이나믹 캐스트를 통해 CEO포인터를 Manager포인터로 다운캐스팅

	// assert문으로 해당 포인터들이 nullptr이 아닌지 확인
	assert(staff1 != nullptr);
	assert(staff2 != nullptr);
	assert(manager != nullptr);
	return 0;
}