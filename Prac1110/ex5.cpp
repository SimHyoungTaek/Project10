#include <iostream>
#include <cassert>

class CPO {//Ŭ���� ����
public:
	virtual ~CPO() {}// ���� �Ҹ���
};

class CEO {//CEO Ŭ���� ����
public:
	virtual ~CEO() {}// ���� �Ҹ���
};

class Manager :public CPO, public CEO {//Manager Ŭ���� CPO�� CEO��� �޾Ƽ� ����
public:
	virtual ~Manager() {}// ���� �Ҹ���
};

class Staff : public Manager {//Staff Ŭ���� CEO, CPO�� ��ӹ޾� ���ǵ� Manager��ӹ޾� ����
public:
	virtual ~Staff() {}// ���� �Ҹ���
};
int main() {
	Staff staff;// staff �ν��Ͻ� ����
	CPO* cpo = &staff;//staff �ν��Ͻ� CPO�����ͷ� ��ĳ����
	CEO* ceo = &staff;//staff �ν��Ͻ� CEO�����ͷ� ��ĳ����

	Staff* staff1 = dynamic_cast<Staff*>(cpo);//���̳��� ĳ��Ʈ�� ���� CPO�����͸� Staff�����ͷ� �ٿ�ĳ����
	Staff* staff2 = dynamic_cast<Staff*>(ceo);//���̳��� ĳ��Ʈ�� ���� CEO�����͸� Staff�����ͷ� �ٿ�ĳ����
	Manager* manager = dynamic_cast<Manager*>(ceo);//���̳��� ĳ��Ʈ�� ���� CEO�����͸� Manager�����ͷ� �ٿ�ĳ����

	// assert������ �ش� �����͵��� nullptr�� �ƴ��� Ȯ��
	assert(staff1 != nullptr);
	assert(staff2 != nullptr);
	assert(manager != nullptr);
	return 0;
}