#include <iostream>

class BaseClass { // Ŭ���� BaseClass ����
public:
	virtual ~BaseClass() {}; // �Ҹ���
};

class DerivedClass : public BaseClass { // BaseClass�� ��ӹ޾� DerivedClass Ŭ���� ����

};

int main() {
	BaseClass* base = new DerivedClass(); // DerivedClass��  BaseClass�����Ϳ� �������� �Ҵ�
	DerivedClass* derived = dynamic_cast<DerivedClass*>(base); // dynamic_cast�� Ȱ���� �ٿ�ĳ����
	if (derived != nullptr) {// �ٿ�ĳ������ �ߵǾ��ٸ�
		std::cout << "Everything is OKAY" << std::endl; // �� ���� ���
	}
	else { // �ȵǾ��ٸ�
		std::cout << "Downcasting failed" << std::endl; // �� ���� ���
	}
}
