/*
 * Point.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: muzi
 */

#include "Point.h"

Point::Point(float l1x1, float l1y1, float l1x2, float l1y2, float l2x1,
		float l2y1, float l2x2, float l2y2, float l3x1, float l3y1, float l3x2,
		float l3y2) {
	this->cX = cX;
	this->cY = cY;

	this->l1x1 = l1x1;
	this->l1y1 = l1y1;
	this->l1x2 = l1x2;
	this->l1y2 = l1y2;

	this->l2x1 = l2x1;
	this->l2y1 = l2y1;
	this->l2x2 = l2x2;
	this->l2y2 = l2y2;

	this->l3x1 = l3x1;
	this->l3y1 = l3y1;
	this->l3x2 = l3x2;
	this->l3y2 = l3y2;

}
Point & Point::rotate(bool isLeft) {
	int degree = 15;
	if (!isLeft) {
		degree *= -1;

	}
	cX = (l1x1 + l1x2 + l2x2) / 3;
	cY = (l1y1 + l1y2 + l2y2) / 3;
	float templ1x1 = l1x1 - cX;
	float templ1y1 = l1y1 - cY;
	float templ1x2 = l1x2 - cX;
	float templ1y2 = l1y2 - cY;

	float templ2x1 = l2x1 - cX;
	float templ2y1 = l2y1 - cY;
	float templ2x2 = l2x2 - cX;
	float templ2y2 = l2y2 - cY;

	float templ3x1 = l3x1 - cX;
	float templ3y1 = l3y1 - cY;
	float templ3x2 = l3x2 - cX;
	float templ3y2 = l3y2 - cY;

	float tStorel1x1 = templ1x1 * cos(Deg2Rad(degree))
			- templ1y1 * sin(Deg2Rad(degree));
	float tStorel1y1 = templ1x1 * sin(Deg2Rad(degree))
			+ templ1y1 * cos(Deg2Rad(degree));
	float tStorel1x2 = templ1x2 * cos(Deg2Rad(degree))
			- templ1y2 * sin(Deg2Rad(degree));
	float tStorel1y2 = templ1x2 * sin(Deg2Rad(degree))
			+ templ1y2 * cos(Deg2Rad(degree));

	float tStorel2x1 = templ2x1 * cos(Deg2Rad(degree))
			- templ2y1 * sin(Deg2Rad(degree));
	float tStorel2y1 = templ2x1 * sin(Deg2Rad(degree))
			+ templ2y1 * cos(Deg2Rad(degree));
	float tStorel2x2 = templ2x2 * cos(Deg2Rad(degree))
			- templ2y2 * sin(Deg2Rad(degree));
	float tStorel2y2 = templ2x2 * sin(Deg2Rad(degree))
			+ templ2y2 * cos(Deg2Rad(degree));

	float tStorel3x1 = templ3x1 * cos(Deg2Rad(degree))
			- templ3y1 * sin(Deg2Rad(degree));
	float tStorel3y1 = templ3x1 * sin(Deg2Rad(degree))
			+ templ3y1 * cos(Deg2Rad(degree));
	float tStorel3x2 = templ3x2 * cos(Deg2Rad(degree))
			- templ3y2 * sin(Deg2Rad(degree));
	float tStorel3y2 = templ3x2 * sin(Deg2Rad(degree))
			+ templ3y2 * cos(Deg2Rad(degree));

	l1x1 = tStorel1x1 + cX;
	l1y1 = tStorel1y1 + cY;
	l1x2 = tStorel1x2 + cX;
	l1y2 = tStorel1y2 + cY;

	l2x1 = tStorel2x1 + cX;
	l2y1 = tStorel2y1 + cY;
	l2x2 = tStorel2x2 + cX;
	l2y2 = tStorel2y2 + cY;

	l3x1 = tStorel3x1 + cX;
	l3y1 = tStorel3y1 + cY;
	l3x2 = tStorel3x2 + cX;
	l3y2 = tStorel3y2 + cY;

	return *this;

}

float Point::getX() const {
	return cX;
}

void Point::setX(float x) {
	cX = x;
}

float Point::getY() const {
	return cY;
}

void Point::setY(float y) {
	cY = y;
}

float Point::getL1x1() const {
	return l1x1;
}

void Point::setL1x1(float l1x1) {
	this->l1x1 = l1x1;
}

float Point::getL1x2() const {
	return l1x2;
}

void Point::setL1x2(float l1x2) {
	this->l1x2 = l1x2;
}

float Point::getL1y1() const {
	return l1y1;
}

void Point::setL1y1(float l1y1) {
	this->l1y1 = l1y1;
}

float Point::getL1y2() const {
	return l1y2;
}

void Point::setL1y2(float l1y2) {
	this->l1y2 = l1y2;
}

float Point::getL2x1() const {
	return l2x1;
}

void Point::setL2x1(float l2x1) {
	this->l2x1 = l2x1;
}

float Point::getL2x2() const {
	return l2x2;
}

void Point::setL2x2(float l2x2) {
	this->l2x2 = l2x2;
}

float Point::getL2y1() const {
	return l2y1;
}

void Point::setL2y1(float l2y1) {
	this->l2y1 = l2y1;
}

float Point::getL2y2() const {
	return l2y2;
}

void Point::setL2y2(float l2y2) {
	this->l2y2 = l2y2;
}

float Point::getL3x1() const {
	return l3x1;
}

void Point::setL3x1(float l3x1) {
	this->l3x1 = l3x1;
}

float Point::getL3x2() const {
	return l3x2;
}

void Point::setL3x2(float l3x2) {
	this->l3x2 = l3x2;
}

float Point::getL3y1() const {
	return l3y1;
}

void Point::setL3y1(float l3y1) {
	this->l3y1 = l3y1;
}

float Point::getL3y2() const {
	return l3y2;
}

void Point::setL3y2(float l3y2) {
	this->l3y2 = l3y2;
}

Point::~Point() {
	// TODO Auto-generated destructor stub
}

