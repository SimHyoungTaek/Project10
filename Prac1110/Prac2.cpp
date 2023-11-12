#include <iostream>
#include <string>
#define interface struct

interface DrawAPI { // DrawAPI 인터페이스 정의
public:
	virtual void drawCircle(int radius, int x, int y)=0; // 가상함수로 drawCircle 함수를 정의함
};

class RedCircle :public DrawAPI { // DrawAPI 인터페이스를 구현한 클래스
public:
	void drawCircle(int radius, int x, int y) {
		std::cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

class GreenCircle :public DrawAPI {// DrawAPI 인터페이스를 구현한 클래스
public:
	void drawCircle(int radius, int x, int y) {
		std::cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

class Shape { // Shape 추상클래스 정의
protected:
	DrawAPI* drawAPI; // DrawAPI타입의 포인터
	Shape(DrawAPI* drawAPI) : drawAPI(drawAPI) {} // 생성자에서 drawAPI 초기화
	
public:
	virtual void draw() = 0; //가상함수로 draw 함수 정의
};

class Circle : public Shape { // Shape 상속받아 Circle 클래스 정의 
private:
	int x, y, radius; // 원 위치와 반지를을 속성으로 가짐
public:
	Circle(int x, int y, int radius, DrawAPI* drawAPI) : Shape(drawAPI), x(x), y(y), radius(radius) {}; // 생성자로 원 초기화
	
	void draw() override {
		drawAPI->drawCircle(radius, x, y); // drawAPI를 활용해 drawCircle 함수 호출
	}
};

int main(){
	// Circle 객체를 동적으로 생성하고, DrawAPI의 구현체를 주입
	Shape* redCircle = new Circle(100, 100, 10, new RedCircle());
	Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle());

	// 동적으로 생성된 객체들의 draw 메소드를 호출
	redCircle->draw();
	greenCircle->draw();

	// 메모리 해제 
	delete redCircle;
	delete greenCircle;
}