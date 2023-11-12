#include <iostream>

class BaseClass { // 클래스 BaseClass 정의
public:
	virtual ~BaseClass() {}; // 소멸자
};

class DerivedClass : public BaseClass { // BaseClass를 상속받아 DerivedClass 클래스 정의

};

int main() {
	BaseClass* base = new DerivedClass(); // DerivedClass를  BaseClass포인터에 동적으로 할당
	DerivedClass* derived = dynamic_cast<DerivedClass*>(base); // dynamic_cast를 활용한 다운캐스팅
	if (derived != nullptr) {// 다운캐스팅이 잘되었다면
		std::cout << "Everything is OKAY" << std::endl; // 이 문장 출력
	}
	else { // 안되었다면
		std::cout << "Downcasting failed" << std::endl; // 이 문장 출력
	}
}
