#include <iostream>
#include <string>
#define interface struct

interface Shape { // Shape �������̽� ����
	virtual void draw() = 0; // draw �Լ�
	virtual ~Shape() {} // �Ҹ���
};

class RoundedRectangle : public Shape { //RoundedRectangleŬ���� ����
public:
	void draw() {
		std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
	}
 };

class RoundedSquare : public Shape { //RoundedSquareŬ���� ����
public:
	void draw() {
		std::cout << "Inside RoundedSquare::draw() method." << std::endl;
	}
};

class Rectangle : public Shape {//RectangleŬ���� ����
public:
	void draw() {
		std::cout << "Inside Rectangle::draw() method." << std::endl;
	}
};

class Square : public Shape {//SquareŬ���� ����
public:
	void draw() {
		std::cout << "Inside Square::draw() method." << std::endl;
	}
};

class AbstractFactory {//AbstractFactory �߻� Ŭ���� ����
public:
	virtual Shape* getShape(const std::string& shapeType)=0; // Shape ��ü�� �����ϴ� �߻� �޼ҵ�
	virtual ~AbstractFactory() {} // �Ҹ���
};

class ShapeFactory : public  AbstractFactory {//ShapeFactory Ŭ���� ����
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

class RoundedShapeFactory : public  AbstractFactory { // RoundedShapeFactory Ŭ���� ����

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

class FactoryProducer {// FactoryProducer Ŭ���� ����
public:
	static AbstractFactory* getFactory(bool rounded) { // ���ǿ� �´� AbstractFactory�� �����ϴ� ���� �޼ҵ�
		if (rounded) {
			return new RoundedShapeFactory();
		}
		else {
			return new ShapeFactory();
		}
	}
};

int main() {
	AbstractFactory* shapeFactory = FactoryProducer::getFactory(false); // �Ϲ� ����� ���丮 ����

	Shape* shape1 = shapeFactory->getShape("RECTANGLE"); // RECTANGLE ��ü ���� �� �׸���
	shape1->draw();

	Shape* shape2 = shapeFactory->getShape("SQUARE");// SQUARE ��ü ���� �� �׸���
	shape2->draw();

	// �޸� ����
	delete shape1;
	delete shape2;
	delete shapeFactory;

	AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true); // �ձ� ��� ���� ���丮 ����

	Shape* shape3 = shapeFactory1->getShape("RECTANGLE");// RECTANGLE ��ü ���� �� �׸���
	shape3->draw();

	Shape* shape4 = shapeFactory1->getShape("SQUARE");// SQUARE ��ü ���� �� �׸���
	shape4->draw();

	// �޸� ����
	delete shape3;
	delete shape4;
	delete shapeFactory1;

	return 0;
}	