#include "Shooter.h"
#include <cmath>

Shooter::Shooter() {

	l1x1 = 480;
	l1y1 = 200;
	l1x2 = 460;
	l1y2 = 140;

	l2x1 = 480;
	l2y1 = 200;
	l2x2 = 500;
	l2y2 = 140;

	l3x1 = 465;
	l3y1 = 150;
	l3x2 = 495;
	l3y2 = 150;

	velocity = 15;
	Degree = 0;

	bul = new Bullet*[15];
	for (int i = 0; i < 15; i++) {
		bul[i] = new Bullet;
	}

	timeCount = 0;
	hyper = 150;

}
void Shooter::drawRed() {
	DrawLine(l1x1, l1y1, l1x2, l1y2, 200, colors[RED]);
	DrawLine(l2x1, l2y1, l2x2, l2y2, 200, colors[RED]);
	DrawLine(l3x1, l3y1, l3x2, l3y2, 200, colors[RED]);

	wrap();

	for (int i = 0; i < 15; i++) {
		if (bul[i]->isIsReady() == true) {
			bul[i]->draw();
		}
	}
	timeCount++;
	hyper++;

	if (hyper >= 150) {
		DrawTriangle(950, 750, 970, 800, 990, 750, colors[RED]);
	}
}
void Shooter::draw() {
	DrawLine(l1x1, l1y1, l1x2, l1y2, 200, colors[WHITE]);
	DrawLine(l2x1, l2y1, l2x2, l2y2, 200, colors[WHITE]);
	DrawLine(l3x1, l3y1, l3x2, l3y2, 200, colors[WHITE]);

	wrap();

	for (int i = 0; i < 15; i++) {
		if (bul[i]->isIsReady() == true) {
			bul[i]->draw();
		}
	}
	timeCount++;
	hyper++;

	if (hyper >= 150) {
		DrawTriangle(950, 750, 970, 800, 990, 750, colors[RED]);
	}
}
void Shooter::performAction(int check) {
	if (check == 1) {
		move();
	}
	if (check == 2) {
		rotate(true);
	}
	if (check == 3) {
		rotate(false);
	}
	if (check == 4) {
		for (int i = 0; i < 15; i++) {
			if (bul[i]->isIsReady() == false) {
				bul[i]->setIsReady(true);
				bul[i]->initializeBullet(this->getL1x1(), this->getL1y1(),
						this->getDegree());
				break;
			}
		}
	}
	for (int i = 0; i < 15; i++) {
		if (bul[i]->isIsReady() == true)
			bul[i]->move();
		if (bul[i]->getTimer() >= 60) {
			destoryBullet(i);
		}
	}
	if (check == 5) {
		hyperSpace();
	}

}
void Shooter::move() {
	l1x1 += sin(Deg2Rad(Degree)) * velocity;
	l1y1 += cos(Deg2Rad(Degree)) * velocity;
	l1x2 += sin(Deg2Rad(Degree)) * velocity;
	l1y2 += cos(Deg2Rad(Degree)) * velocity;

	l2x1 += sin(Deg2Rad(Degree)) * velocity;
	l2y1 += cos(Deg2Rad(Degree)) * velocity;
	l2x2 += sin(Deg2Rad(Degree)) * velocity;
	l2y2 += cos(Deg2Rad(Degree)) * velocity;

	l3x1 += sin(Deg2Rad(Degree)) * velocity;
	l3y1 += cos(Deg2Rad(Degree)) * velocity;
	l3x2 += sin(Deg2Rad(Degree)) * velocity;
	l3y2 += cos(Deg2Rad(Degree)) * velocity;

}
void Shooter::rotate(bool isLeft) {

	Point p(l1x1, l1y1, l1x2, l1y2, l2x1, l2y1, l2x2, l2y2, l3x1, l3y1, l3x2,
			l3y2);
	Point temp = p.rotate(isLeft);

	l1x1 = temp.getL1x1();
	l1y1 = temp.getL1y1();
	l1x2 = temp.getL1x2();
	l1y2 = temp.getL1y2();

	l2x1 = temp.getL2x1();
	l2y1 = temp.getL2y1();
	l2x2 = temp.getL2x2();
	l2y2 = temp.getL2y2();

	l3x1 = temp.getL3x1();
	l3y1 = temp.getL3y1();
	l3x2 = temp.getL3x2();
	l3y2 = temp.getL3y2();

	if (isLeft == true)
		Degree -= 15;
	else
		Degree += 15;
}
void Shooter::wrap() {
	if (l1y2 >= 840) {
		l1y1 -= 840;
		l1y2 -= 840;
		l2y1 -= 840;
		l2y2 -= 840;
		l3y1 -= 840;
		l3y2 -= 840;
	}
	if (l1x2 >= 1020) {
		l1x1 -= 1020;
		l1x2 -= 1020;
		l2x1 -= 1020;
		l2x2 -= 1020;
		l3x1 -= 1020;
		l3x2 -= 1020;
	}
	if (l1x2 < 0) {
		l1x1 += 1020;
		l1x2 += 1020;
		l2x1 += 1020;
		l2x2 += 1020;
		l3x1 += 1020;
		l3x2 += 1020;
	}
	if (l1y2 < 0) {
		l1y1 += 840;
		l1y2 += 840;
		l2y1 += 840;
		l2y2 += 840;
		l3y1 += 840;
		l3y2 += 840;
	}
	//cout<<"l1x1 "<<l1x1<<"l1x2 "<<l1x2<<"l2x1 "<<l2x1<<"l2x2 "<<l2x2<<"l3x1 "<<l3x1<<"l3x2 "<<l3x2<<endl;
}
void Shooter::hyperSpace() {
	int rand = GetRandInRange(1, 2);

	if (timeCount >= 150) {

		if (rand == 1) {
			l1y1 -= 340;
			l1y2 -= 340;
			l2y1 -= 340;
			l2y2 -= 340;
			l3y1 -= 340;
			l3y2 -= 340;
			l1x1 -= 300;
			l1x2 -= 300;
			l2x1 -= 300;
			l2x2 -= 300;
			l3x1 -= 300;
			l3x2 -= 300;
			timeCount = 0;
		}
		if (rand == 2) {
			l1x1 += 300;
			l1x2 += 300;
			l2x1 += 300;
			l2x2 += 300;
			l3x1 += 300;
			l3x2 += 300;
			l1y1 += 340;
			l1y2 += 340;
			l2y1 += 340;
			l2y2 += 340;
			l3y1 += 340;
			l3y2 += 340;
			timeCount = 0;
		}
	}
}
void Shooter::setCenter(float cx, float cy) {

}
void Shooter::destoryBullet(int i) {
	bul[i]->setIsReady(false);
}

float Shooter::getRadius() {
	return 40;
}
float Shooter::getCenterX() {
	return (l1x1 + l1x2 + l2x2) / 3;
}
float Shooter::getCenterY() {
	return (l1y1 + l1y2 + l2y2) / 3;
}
float Shooter::getL1x1() const {
	return l1x1;
}

void Shooter::setL1x1(float l1x1) {
	this->l1x1 = l1x1;
}

float Shooter::getL1x2() const {
	return l1x2;
}

void Shooter::setL1x2(float l1x2) {
	this->l1x2 = l1x2;
}

float Shooter::getL1y1() const {
	return l1y1;
}

void Shooter::setL1y1(float l1y1) {
	this->l1y1 = l1y1;
}

float Shooter::getL1y2() const {
	return l1y2;
}

void Shooter::setL1y2(float l1y2) {
	this->l1y2 = l1y2;
}

float Shooter::getL2x1() const {
	return l2x1;
}

void Shooter::setL2x1(float l2x1) {
	this->l2x1 = l2x1;
}

float Shooter::getL2x2() const {
	return l2x2;
}

void Shooter::setL2x2(float l2x2) {
	this->l2x2 = l2x2;
}

float Shooter::getL2y1() const {
	return l2y1;
}

void Shooter::setL2y1(float l2y1) {
	this->l2y1 = l2y1;
}

float Shooter::getL2y2() const {
	return l2y2;
}

void Shooter::setL2y2(float l2y2) {
	this->l2y2 = l2y2;
}

int Shooter::getDegree() const {
	return Degree;
}
void Shooter::setDegree(int degree) {
	Degree = degree;
}

Shooter::~Shooter() {

}

float Shooter::getL3x1() const {
	return l3x1;
}

void Shooter::setL3x1(float l3x1) {
	this->l3x1 = l3x1;
}

float Shooter::getL3x2() const {
	return l3x2;
}

void Shooter::setL3x2(float l3x2) {
	this->l3x2 = l3x2;
}

float Shooter::getL3y1() const {
	return l3y1;
}

void Shooter::setL3y1(float l3y1) {
	this->l3y1 = l3y1;
}

float Shooter::getL3y2() const {
	return l3y2;
}

void Shooter::setL3y2(float l3y2) {
	this->l3y2 = l3y2;
}

int Shooter::getVelocity() const {
	return velocity;
}

Bullet* Shooter::getBul(int i) {
	return bul[i];
}

int Shooter::getTimeCount() const {
	return timeCount;
}

void Shooter::setTimeCount(int timeCount) {
	this->timeCount = timeCount;
}

void Shooter::setVelocity(int velocity) {
	this->velocity = velocity;
}

int Shooter::getHyper() const {
	return hyper;
}

void Shooter::setHyper(int hyper) {
	this->hyper = hyper;
}
