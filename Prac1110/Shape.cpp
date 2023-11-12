#include <iostream>
#include <string>
#define interface struct

interface Shape { // Shape 인터페이스 정의
	virtual void draw() = 0; // draw 함수
	virtual ~Shape() {} // 소멸자
};

class RoundedRectangle : public Shape { //RoundedRectangle클래스 정의
public:
	void draw() {
		std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
	}
 };

class RoundedSquare : public Shape { //RoundedSquare클래스 정의
public:
	void draw() {
		std::cout << "Inside RoundedSquare::draw() method." << std::endl;
	}
};

class Rectangle : public Shape {//Rectangle클래스 정의
public:
	void draw() {
		std::cout << "Inside Rectangle::draw() method." << std::endl;
	}
};

class Square : public Shape {//Square클래스 정의
public:
	void draw() {
		std::cout << "Inside Square::draw() method." << std::endl;
	}
};

class AbstractFactory {//AbstractFactory 추상 클래스 정의
public:
	virtual Shape* getShape(const std::string& shapeType)=0; // Shape 객체를 생성하는 추상 메소드
	virtual ~AbstractFactory() {} // 소멸자
};

class ShapeFactory : public  AbstractFactory {//ShapeFactory 클래스 정의
public:
	Shape* getShape(const std::string& shapeType) {
		if (shapeType == "RECTANGLE") {
			return new Rectangle();
		}
		else if (shapeType == "SQUARE") {
			return new Square();
		}
		return nullptr;
	}
};

class RoundedShapeFactory : public  AbstractFactory { // RoundedShapeFactory 클래스 정의

public:
	Shape* getShape(const std::string& shapeType) {
		if (shapeType=="RECTANGLE") {
			return new RoundedRectangle();
		}
		else if (shapeType == "SQUARE") {
			return new RoundedSquare();
		}
		return nullptr;
	}
};

class FactoryProducer {// FactoryProducer 클래스 정의
public:
	static AbstractFactory* getFactory(bool rounded) { // 조건에 맞는 AbstractFactory를 생성하는 정적 메소드
		if (rounded) {
			return new RoundedShapeFactory();
		}
		else {
			return new ShapeFactory();
		}
	}
};

int main() {
	AbstractFactory* shapeFactory = FactoryProducer::getFactory(false); // 일반 모양의 팩토리 생성

	Shape* shape1 = shapeFactory->getShape("RECTANGLE"); // RECTANGLE 객체 생성 및 그리기
	shape1->draw();

	Shape* shape2 = shapeFactory->getShape("SQUARE");// SQUARE 객체 생성 및 그리기
	shape2->draw();

	// 메모리 해제
	delete shape1;
	delete shape2;
	delete shapeFactory;

	AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true); // 둥근 모양 도형 팩토리 생성

	Shape* shape3 = shapeFactory1->getShape("RECTANGLE");// RECTANGLE 객체 생성 및 그리기
	shape3->draw();

	Shape* shape4 = shapeFactory1->getShape("SQUARE");// SQUARE 객체 생성 및 그리기
	shape4->draw();

	// 메모리 해제
	delete shape3;
	delete shape4;
	delete shapeFactory1;

	return 0;
}	