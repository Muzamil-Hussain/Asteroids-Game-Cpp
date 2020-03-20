/*
 * Saucer.cpp
 *
 *  Created on: May 5, 2018
 *      Author: muzi
 */

#include "Saucer.h"

Saucer::Saucer() {

	cx = GetRandInRange(-10, 0);
	cy = GetRandInRange(0, 840);
	Degree = GetRandInRange(-360, 360);
	bul = new Bullet;

}
void Saucer::draw() {
	DrawLine(cx, cy, cx - 25, cy - 25);
	DrawLine(cx + 100, cy, cx + 125, cy - 25);
	DrawLine(cx, cy, cx + 100, cy);
	DrawLine(cx - 25, cy - 25, cx, cy - 50);
	DrawLine(cx + 125, cy - 25, cx + 100, cy - 50);
	DrawLine(cx - 25, cy - 25, cx + 125, cy - 25);
	DrawLine(cx, cy - 50, cx + 100, cy - 50);
	DrawLine(cx + 25, cy + 25, cx + 5, cy);
	DrawLine(cx + 75, cy + 25, cx + 95, cy);
	DrawLine(cx + 75, cy + 25, cx + 25, cy + 25);

	wrap();

	if (bul->isIsReady() == true) {
		bul->draw();
	}
}
void Saucer::performAction(int check) {
	if (check == 1) {
		move();
	}
	if (check == 4) {
		if (bul->isIsReady() == false) {
			bul->setIsReady(true);
			bul->initializeBullet(
					GetRandInRange(this->getCx(), this->getCx() + 100), cy,
					GetRandInRange(90, 270));
		}
	}
	if (bul->isIsReady() == true)
		bul->move();
	if (bul->getTimer() >= 80) {
		destoryBullet(0);
	}
}
void Saucer::move() {
	Degree += 1;
	cx += 5;
	cy += sin(Deg2Rad(Degree)) * 5;

}
void Saucer::wrap() {
	if (cy - 50 >= 840) {
		cy -= 840;
	}
	if (cx - 50 >= 1020) {

		cx -= 1020;
	}
	if (cy + 50 < 0) {
		cy += 840;
	}
	if (cx + 50 < 0) {
		cx += 1020;
	}
}

void Saucer::setCenter(float cx,float cy)
{
	this->cx=cx;
	this->cy=cy;
}
void Saucer::destoryBullet(int i) {
	//if ((abs(bul[i].getCx()-this->getL1x1())>=500) || (abs(bul[i].getCy()-this->getL1y1())>=500))
	bul->setIsReady(false);
}
float Saucer::getRadius()
{
	return 69;
}
float Saucer::getCenterX()
{
	return cx;
}
float Saucer::getCenterY()
{
	return cy;
}
Saucer::~Saucer() {
	// TODO Auto-generated destructor stub
}

int Saucer::getCx() const {
	return cx;
}

void Saucer::setCx(int cx) {
	this->cx = cx;
}

int Saucer::getCy() const {
	return cy;
}

void Saucer::setCy(int cy) {
	this->cy = cy;
}

int Saucer::getDegree() const {
	return Degree;
}

void Saucer::setDegree(int degree) {
	Degree = degree;
}

Bullet* Saucer::getBul() {
	return bul;
}
