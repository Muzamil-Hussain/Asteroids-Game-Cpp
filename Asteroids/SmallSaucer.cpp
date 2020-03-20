/*
 * SmallSaucer.cpp
 *
 *  Created on: May 6, 2018
 *      Author: muzi
 */

#include "SmallSaucer.h"

SmallSaucer::SmallSaucer() {
	// TODO Auto-generated constructor stub
	cx = GetRandInRange(-10,0 );
	cy = GetRandInRange(0, 840);
	Degree = GetRandInRange(-360, 360);
	bul = new Bullet;

}
void SmallSaucer::draw() {
	DrawLine(cx / 2, cy / 2, (cx - 25) / 2, (cy - 25) / 2);
	DrawLine((cx + 100) / 2, cy / 2, (cx + 125) / 2, (cy - 25) / 2);
	DrawLine(cx / 2, cy / 2, (cx + 100) / 2, cy / 2);
	DrawLine((cx - 25) / 2, (cy - 25) / 2, cx / 2, (cy - 50) / 2);
	DrawLine((cx + 125) / 2, (cy - 25) / 2, (cx + 100) / 2, (cy - 50) / 2);
	DrawLine((cx - 25) / 2, (cy - 25) / 2, (cx + 125) / 2, (cy - 25) / 2);
	DrawLine(cx / 2, (cy - 50) / 2, (cx + 100) / 2, (cy - 50) / 2);
	DrawLine((cx + 25) / 2, (cy + 25) / 2, (cx + 5) / 2, cy / 2);
	DrawLine((cx + 75) / 2, (cy + 25) / 2, (cx + 95) / 2, cy / 2);
	DrawLine((cx + 75) / 2, (cy + 25) / 2, (cx + 25) / 2, (cy + 25) / 2);
	wrap();

	if (bul->isIsReady() == true) {
		bul->draw();
	}
}
void SmallSaucer::performAction(int check) {
	if (check == 1) {
		move();
	}
	if (check == 4) {
		if (bul->isIsReady() == false) {
			bul->setIsReady(true);
			bul->initializeBullet(
					GetRandInRange(this->getCx() / 2,
							(this->getCx() + 100) / 2), cy / 2,
					GetRandInRange(90, 270));
		}
	}
	if (bul->isIsReady() == true)
		bul->move();
	if (bul->getTimer() >= 30) {
		destoryBullet(0);
	}
}
void SmallSaucer::move() {
	Degree += 1;
	cx += 10;
	cy += sin(Deg2Rad(Degree)) * 7;
}
void SmallSaucer::wrap() {
	if (cy - 50 >= 840 * 2) {
		cy -= 840 * 2;
	}
	if (cx - 50 >= 1020 * 2) {

		cx -= 1020 * 2;
	}
	if (cy + 50 < 0) {
		cy += 840 * 2;
	}
	if (cx + 50 < 0) {
		cx += 1020 * 2;
	}
}
float SmallSaucer::getRadius() {
	return 29;
}
float SmallSaucer::getCenterX() {
	return cx / 2;
}
float SmallSaucer::getCenterY() {
	return cy / 2;
}
void SmallSaucer::destoryBullet(int i) {
	//if ((abs(bul[i].getCx()-this->getL1x1())>=500) || (abs(bul[i].getCy()-this->getL1y1())>=500))
	bul->setIsReady(false);
}
SmallSaucer::~SmallSaucer() {
	// TODO Auto-generated destructor stub
}

