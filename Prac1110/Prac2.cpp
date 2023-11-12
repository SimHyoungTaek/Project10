#include <iostream>
#include <string>
#define interface struct

interface DrawAPI { // DrawAPI �������̽� ����
public:
	virtual void drawCircle(int radius, int x, int y)=0; // �����Լ��� drawCircle �Լ��� ������
};

class RedCircle :public DrawAPI { // DrawAPI �������̽��� ������ Ŭ����
public:
	void drawCircle(int radius, int x, int y) {
		std::cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

class GreenCircle :public DrawAPI {// DrawAPI �������̽��� ������ Ŭ����
public:
	void drawCircle(int radius, int x, int y) {
		std::cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

class Shape { // Shape �߻�Ŭ���� ����
protected:
	DrawAPI* drawAPI; // DrawAPIŸ���� ������
	Shape(DrawAPI* drawAPI) : drawAPI(drawAPI) {} // �����ڿ��� drawAPI �ʱ�ȭ
	
public:
	virtual void draw() = 0; //�����Լ��� draw �Լ� ����
};

class Circle : public Shape { // Shape ��ӹ޾� Circle Ŭ���� ���� 
private:
	int x, y, radius; // �� ��ġ�� �������� �Ӽ����� ����
public:
	Circle(int x, int y, int radius, DrawAPI* drawAPI) : Shape(drawAPI), x(x), y(y), radius(radius) {}; // �����ڷ� �� �ʱ�ȭ
	
	void draw() override {
		drawAPI->drawCircle(radius, x, y); // drawAPI�� Ȱ���� drawCircle �Լ� ȣ��
	}
};

int main(){
	// Circle ��ü�� �������� �����ϰ�, DrawAPI�� ����ü�� ����
	Shape* redCircle = new Circle(100, 100, 10, new RedCircle());
	Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle());

	// �������� ������ ��ü���� draw �޼ҵ带 ȣ��
	redCircle->draw();
	greenCircle->draw();

	// �޸� ���� 
	delete redCircle;
	delete greenCircle;
}