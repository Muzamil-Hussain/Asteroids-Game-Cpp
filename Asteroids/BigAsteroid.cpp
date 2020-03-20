#include "BigAsteroid.h"
BigAsteroid::BigAsteroid() {
	// TODO Auto-generated constructor stub
	Degree = GetRandInRange(-360, 360);
	cx = GetRandInRange(0, 1020);
	cy = GetRandInRange(400, 840);
	randomPoint = GetRandInRange(0, 9);
	npoints = MAX(5, randomPoint);
	storeTempX = new int[npoints];
	storeTempY = new int[npoints];
	dtheta = 360 / npoints;
	theta = GetRandInRange(0, dtheta);
	storeX = new int[npoints];
	storeY = new int[npoints];
	radius = 70;
	int sx = radius * cos(Deg2Rad(theta)), sy = radius * sin(Deg2Rad(theta));
	int x1 = sx;
	int y1 = sy;
	storeX[0] = x1;
	storeY[0] = y1;
	int stheta = dtheta;
	for (int i = 0; i < npoints - 1; ++i) {
		theta = stheta;
		int x2 = radius * cos(Deg2Rad(theta)), y2 = radius
				* sin(Deg2Rad(theta));
		if (i % 2 != 0) {
			storeX[i + 1] = x2;
			storeY[i + 1] = y2;
		}
		x1 = x2;
		y1 = y2;
		if (i % 2 == 0) {
			storeX[i + 1] = x1;
			storeY[i + 1] = y1;
		}
		stheta += dtheta;
	}
	rotationDegree = 0;
}
void BigAsteroid::draw() {
	for (int i = 0; i < npoints; i++) {
		DrawLine(storeTempX[i] + cx, storeTempY[i] + cy,
				storeTempX[(i + 1) % npoints] + cx,
				storeTempY[(i + 1) % npoints] + cy, 3, colors[WHITE]);
	}
	wrap();
}
void BigAsteroid::performAction(int check) {
	if (check == 1) {
		move();
	}
	if (check == 2) {
		rotate(true);
	}
	if (check == 3) {
		rotate(true);
	}
}
void BigAsteroid::move() {
	cx += sin(Deg2Rad(Degree)) * 3;
	cy += cos(Deg2Rad(Degree)) * 3;
}
void BigAsteroid::rotate(bool) {
	rotationDegree += 1;
	for (int i = 0; i < npoints; i++) {
		storeTempX[i] = ((storeX[i] * cos(Deg2Rad(rotationDegree)))
				- (storeY[i] * sin(Deg2Rad(rotationDegree))));
		storeTempY[i] = ((storeX[i] * sin(Deg2Rad(rotationDegree)))
				+ (storeY[i] * cos(Deg2Rad(rotationDegree))));
	}
}
void BigAsteroid::wrap() {
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
float BigAsteroid::getRadius()
{
	return radius;
}
float BigAsteroid::getCenterX()
{
	return cx;
}
float BigAsteroid::getCenterY()
{
	return cy;
}
void BigAsteroid::setCenter(float cx,float cy)
{
	this->cx=cx;
	this->cy=cy;
}
int BigAsteroid::getCx() const {
	return cx;
}

void BigAsteroid::setCx(int cx) {
	this->cx = cx;
}

int BigAsteroid::getCy() const {
	return cy;
}

void BigAsteroid::setCy(int cy) {
	this->cy = cy;
}

int BigAsteroid::getDegree() const {
	return Degree;
}

void BigAsteroid::setDegree(int degree) {
	Degree = degree;
}

int BigAsteroid::getDtheta() const {
	return dtheta;
}

void BigAsteroid::setDtheta(int dtheta) {
	this->dtheta = dtheta;
}

int BigAsteroid::getNpoints() const {
	return npoints;
}

void BigAsteroid::setNpoints(int npoints) {
	this->npoints = npoints;
}

int BigAsteroid::getRandomPoint() const {
	return randomPoint;
}

void BigAsteroid::setRandomPoint(int randomPoint) {
	this->randomPoint = randomPoint;
}

int BigAsteroid::getRotationDegree() const {
	return rotationDegree;
}

void BigAsteroid::setRotationDegree(int rotationDegree) {
	this->rotationDegree = rotationDegree;
}

int* BigAsteroid::getStoreTempX() const {
	return storeTempX;
}

void BigAsteroid::setStoreTempX(int* storeTempX) {
	this->storeTempX = storeTempX;
}

int* BigAsteroid::getStoreTempY() const {
	return storeTempY;
}

void BigAsteroid::setStoreTempY(int* storeTempY) {
	this->storeTempY = storeTempY;
}

int* BigAsteroid::getStoreX() const {
	return storeX;
}

void BigAsteroid::setStoreX(int* storeX) {
	this->storeX = storeX;
}

int* BigAsteroid::getStoreY() const {
	return storeY;
}

void BigAsteroid::setStoreY(int* storeY) {
	this->storeY = storeY;
}

float BigAsteroid::getTheta() const {
	return theta;
}

int BigAsteroid::getRadius() const {
	return radius;
}

void BigAsteroid::setRadius(int radius) {
	this->radius = radius;
}

void BigAsteroid::setTheta(float theta) {
	this->theta = theta;
}

BigAsteroid::~BigAsteroid() {
	// TODO Auto-generated destructor stub
}
