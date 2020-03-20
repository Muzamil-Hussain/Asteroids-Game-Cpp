#include "SmallAsteroid.h"
SmallAsteroid::SmallAsteroid(int cx, int cy) {
	// TODO Auto-generated constructor stub
	Degree = GetRandInRange(-360, 360);
	this->cx = cx;
	this->cy = cy;
	randomPoint = GetRandInRange(0, 9);
	npoints = MAX(5, randomPoint);
	storeTempX = new int[npoints];
	storeTempY = new int[npoints];
	dtheta = 360 / npoints;
	theta = GetRandInRange(0, dtheta);
	storeX = new int[npoints];
	storeY = new int[npoints];
	radius = 30;
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
void SmallAsteroid::draw() {
	for (int i = 0; i < npoints; i++) {
		DrawLine(storeTempX[i] + cx, storeTempY[i] + cy,
				storeTempX[(i + 1) % npoints] + cx,
				storeTempY[(i + 1) % npoints] + cy, 3, colors[WHITE]);
	}
	wrap();
}
void SmallAsteroid::performAction(int check) {
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
void SmallAsteroid::move() {
	cx += sin(Deg2Rad(Degree)) * 5;
	cy += cos(Deg2Rad(Degree)) * 5;
}
void SmallAsteroid::rotate(bool) {
	rotationDegree += 1;
	for (int i = 0; i < npoints; i++) {
		storeTempX[i] = ((storeX[i] * cos(Deg2Rad(rotationDegree)))
				- (storeY[i] * sin(Deg2Rad(rotationDegree))));
		storeTempY[i] = ((storeX[i] * sin(Deg2Rad(rotationDegree)))
				+ (storeY[i] * cos(Deg2Rad(rotationDegree))));
	}
}
void SmallAsteroid::wrap() {
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
void SmallAsteroid::setCenter(float cx,float cy)
{
	this->cx=cx;
	this->cy=cy;
}

float SmallAsteroid::getRadius()
{
	return radius;
}
float SmallAsteroid::getCenterX()
{
	return cx;
}
float SmallAsteroid::getCenterY()
{
	return cy;
}
int SmallAsteroid::getCx() const {
	return cx;
}

void SmallAsteroid::setCx(int cx) {
	this->cx = cx;
}

int SmallAsteroid::getCy() const {
	return cy;
}

void SmallAsteroid::setCy(int cy) {
	this->cy = cy;
}

int SmallAsteroid::getDegree() const {
	return Degree;
}

void SmallAsteroid::setDegree(int degree) {
	Degree = degree;
}

int SmallAsteroid::getDtheta() const {
	return dtheta;
}

void SmallAsteroid::setDtheta(int dtheta) {
	this->dtheta = dtheta;
}

int SmallAsteroid::getNpoints() const {
	return npoints;
}

void SmallAsteroid::setNpoints(int npoints) {
	this->npoints = npoints;
}

int SmallAsteroid::getRandomPoint() const {
	return randomPoint;
}

void SmallAsteroid::setRandomPoint(int randomPoint) {
	this->randomPoint = randomPoint;
}

int SmallAsteroid::getRotationDegree() const {
	return rotationDegree;
}

void SmallAsteroid::setRotationDegree(int rotationDegree) {
	this->rotationDegree = rotationDegree;
}

int* SmallAsteroid::getStoreTempX() const {
	return storeTempX;
}

void SmallAsteroid::setStoreTempX(int* storeTempX) {
	this->storeTempX = storeTempX;
}

int* SmallAsteroid::getStoreTempY() const {
	return storeTempY;
}

void SmallAsteroid::setStoreTempY(int* storeTempY) {
	this->storeTempY = storeTempY;
}

int* SmallAsteroid::getStoreX() const {
	return storeX;
}

void SmallAsteroid::setStoreX(int* storeX) {
	this->storeX = storeX;
}

int* SmallAsteroid::getStoreY() const {
	return storeY;
}

void SmallAsteroid::setStoreY(int* storeY) {
	this->storeY = storeY;
}

float SmallAsteroid::getTheta() const {
	return theta;
}

int SmallAsteroid::getRadius() const {
	return radius;
}

void SmallAsteroid::setRadius(int radius) {
	this->radius = radius;
}

void SmallAsteroid::setTheta(float theta) {
	this->theta = theta;
}

SmallAsteroid::~SmallAsteroid() {
	// TODO Auto-generated destructor stub
}
