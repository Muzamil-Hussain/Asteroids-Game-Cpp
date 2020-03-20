#include "MediumAsteroid.h"
MediumAsteroid::MediumAsteroid(int cx,int cy) {
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
	radius = 50;
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
	timer=0;
}
void MediumAsteroid::draw() {
	for (int i = 0; i < npoints; i++) {
		DrawLine(storeTempX[i] + cx, storeTempY[i] + cy,
				storeTempX[(i + 1) % npoints] + cx,
				storeTempY[(i + 1) % npoints] + cy, 3, colors[WHITE]);
	}
	wrap();
}
void MediumAsteroid::performAction(int check) {
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
void MediumAsteroid::move() {
	cx += sin(Deg2Rad(Degree)) * 4;
	cy += cos(Deg2Rad(Degree)) * 4;

	timer++;
	if (timer>=90)
	{
		Degree=GetRandInRange(-360,360);
		timer=0;
	}
}
void MediumAsteroid::rotate(bool) {
	rotationDegree += 1;
	for (int i = 0; i < npoints; i++) {
		storeTempX[i] = ((storeX[i] * cos(Deg2Rad(rotationDegree)))
				- (storeY[i] * sin(Deg2Rad(rotationDegree))));
		storeTempY[i] = ((storeX[i] * sin(Deg2Rad(rotationDegree)))
				+ (storeY[i] * cos(Deg2Rad(rotationDegree))));
	}
}
void MediumAsteroid::wrap() {
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
float MediumAsteroid::getRadius()
{
	return radius;
}
float MediumAsteroid::getCenterX()
{
	return cx;
}
float MediumAsteroid::getCenterY()
{
	return cy;
}
void MediumAsteroid::setCenter(float cx,float cy)
{
	this->cx=cx;
	this->cy=cy;
}

int MediumAsteroid::getCx() const {
	return cx;
}

void MediumAsteroid::setCx(int cx) {
	this->cx = cx;
}

int MediumAsteroid::getCy() const {
	return cy;
}

void MediumAsteroid::setCy(int cy) {
	this->cy = cy;
}

int MediumAsteroid::getDegree() const {
	return Degree;
}

void MediumAsteroid::setDegree(int degree) {
	Degree = degree;
}

int MediumAsteroid::getDtheta() const {
	return dtheta;
}

void MediumAsteroid::setDtheta(int dtheta) {
	this->dtheta = dtheta;
}

int MediumAsteroid::getNpoints() const {
	return npoints;
}

void MediumAsteroid::setNpoints(int npoints) {
	this->npoints = npoints;
}

int MediumAsteroid::getRandomPoint() const {
	return randomPoint;
}

void MediumAsteroid::setRandomPoint(int randomPoint) {
	this->randomPoint = randomPoint;
}

int MediumAsteroid::getRotationDegree() const {
	return rotationDegree;
}

void MediumAsteroid::setRotationDegree(int rotationDegree) {
	this->rotationDegree = rotationDegree;
}

int* MediumAsteroid::getStoreTempX() const {
	return storeTempX;
}

void MediumAsteroid::setStoreTempX(int* storeTempX) {
	this->storeTempX = storeTempX;
}

int* MediumAsteroid::getStoreTempY() const {
	return storeTempY;
}

void MediumAsteroid::setStoreTempY(int* storeTempY) {
	this->storeTempY = storeTempY;
}

int* MediumAsteroid::getStoreX() const {
	return storeX;
}

void MediumAsteroid::setStoreX(int* storeX) {
	this->storeX = storeX;
}

int* MediumAsteroid::getStoreY() const {
	return storeY;
}

void MediumAsteroid::setStoreY(int* storeY) {
	this->storeY = storeY;
}

float MediumAsteroid::getTheta() const {
	return theta;
}

int MediumAsteroid::getRadius() const {
	return radius;
}

void MediumAsteroid::setRadius(int radius) {
	this->radius = radius;
}

void MediumAsteroid::setTheta(float theta) {
	this->theta = theta;
}

MediumAsteroid::~MediumAsteroid() {
	// TODO Auto-generated destructor stub
}
