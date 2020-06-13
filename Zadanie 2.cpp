#include <iostream>
#include <limits>

using namespace std;

struct Point {
	double x, y;
};

class Square {
	Point A, B, C, D;
public:
	Square(Point& ,Point&);
	void show();
	void change(Point& ,Point&);
	void OX_rotation();
	void OY_rotation();
};

void data_correctness(int&, int, int);
void data_correctness(double&, double, double);
void square_point(Point&);

int main() {
	setlocale(LC_ALL, "");
	Point A, C;
	A.x = A.y = 0;
	C.x = C.y = 1;
	Square S(A, C);
	while (true) {
		cout << "\nCo chcesz zrobić?\n";
		cout << "1. Dodaj nowy kwadrat\n";
		cout << "2. Pokaż współrzędne wierzchołków kwadratu\n";
		cout << "3. Obróć kwadrat względem osi OX\n";
		cout << "4. Obróć kwadrat względem osi OY\n";
		cout << "5. Zakończ działanie programu\n";
		cout << "Twój wybór: ";
		int n;
		data_correctness(n, 1, 5);
		if (n == 1) {
			while (true) {
				cout << "\nPodaj współrzędne dwóch przeciwległych wierzchołków\n";
				square_point(A);
				square_point(C);
				if (C.y - A.y == C.x - A.x) break;
				else cout << "To nie jest kwadrat!\n";
			}
			S.change(A, C);
		}
		else if (n == 2) S.show();
		else if (n == 3) S.OX_rotation();
		else if (n == 4) S.OY_rotation();
		else if (n == 5) exit(0);
	}
	return 0;
}

void data_correctness(int& x, int min, int maks) {
	cin >> x;
	while ((cin.fail()) || (x < min) || (x > maks)) {
		cout << "Wprowadzono błędne dane!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Twój wybór: ";
		cin >> x;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void data_correctness(double& x, double min, double maks) {
	cin >> x;
	while ((cin.fail()) || (x < min) || (x > maks)) {
		cout << "Wprowadzono błędne dane!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Twój wybór: ";
		cin >> x;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void square_point(Point& A) {
	cout << "\nPodaj współrzędne wierzchołka (liczba z przedziału <-1000,1000>)\n";
	double x, y;
	cout << "x = ";
	data_correctness(x, -1000, 1000);
	cout << "y = ";
	data_correctness(y, -1000, 1000);
	A.x = x;
	A.y = y;
}

Square::Square(Point& corner1, Point& corner2) {
	this->A = corner1;
	this->C = corner2;
	this->B.x = corner2.x;
	this->B.y = corner1.y;
	this->D.x = corner1.x;
	this->D.y = corner2.y;	
}
void Square::show() {
	cout << "\nWspółrzędne punktu A: (" << A.x << ";" << A.y << ")\n";
	cout << "Współrzędne punktu B: (" << B.x << ";" << B.y << ")\n";
	cout << "Współrzędne punktu C: (" << C.x << ";" << C.y << ")\n";
	cout << "Współrzędne punktu D: (" << D.x << ";" << D.y << ")\n\n";
}
void Square::change(Point& corner1, Point& corner2) {
	this->A = corner1;
	this->C = corner2;
	this->B.x = corner2.x;
	this->B.y = corner1.y;
	this->D.x = corner1.x;
	this->D.y = corner2.y;
}
void Square::OX_rotation() {
	if (this->A.y!=0) this->A.y *= -1;
	if (this->B.y!=0) this->B.y *= -1;
	if (this->C.y!=0) this->C.y *= -1;
	if (this->D.y!=0) this->D.y *= -1;
}
void Square::OY_rotation() {
	if (this->A.x != 0) this->A.x *= -1;
	if (this->B.x != 0) this->B.x *= -1;
	if (this->C.x != 0) this->C.x *= -1;
	if (this->D.x != 0) this->D.x *= -1;
}