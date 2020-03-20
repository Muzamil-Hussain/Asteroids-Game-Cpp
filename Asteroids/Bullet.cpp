/*
 * Bullet.cpp
 *
 *  Created on: May 6, 2018
 *      Author: muzi
 */

#include "Bullet.h"

Bullet::Bullet(int cx, int cy, int Degree) {
	this->cx = cx;
	this->cy = cy;
	this->Degree = Degree;
	isReady = false;
	timer = 0;
	radius=2;
}
void Bullet::initializeBullet(int cx, int cy, int Degree) {
	this->cx = cx;
	this->cy = cy;
	this->Degree = Degree;
	timer = 0;
}
void Bullet::draw() {
	DrawCircle(cx, cy, 2, colors[WHITE]);
	wrap();
	timer++;
}
void Bullet::performAction(int check) {
	if (check == 1) {
		move();
	}
}
void Bullet::move() {
	cx += sin(Deg2Rad(Degree)) * 5;
	cy += cos(Deg2Rad(Degree)) * 5;
}
void Bullet::wrap() {
	if (cy >= 840) {
		cy -= 840;
	}
	if (cx >= 1020) {

		cx -= 1020;
	}
	if (cy < 0) {
		cy += 840;
	}
	if (cx < 0) {
		cx += 1020;
	}
}
float Bullet::getRadius()
{
	return radius;
}
float Bullet::getCenterX()
{
	return cx;
}
float Bullet::getCenterY()
{
	return cy;
}
void Bullet::setCenter(float cx,float cy)
{

}

int Bullet::getCx() const {
	return cx;
}

void Bullet::setCx(int cx) {
	this->cx = cx;
}

int Bullet::getCy() const {
	return cy;
}

void Bullet::setCy(int cy) {
	this->cy = cy;
}

int Bullet::getDegree() const {
	return Degree;
}

void Bullet::setDegree(int degree) {
	Degree = degree;
}

bool Bullet::isIsReady() const {
	return isReady;
}

void Bullet::setIsReady(bool isReady) {
	this->isReady = isReady;
}

Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}

int Bullet::getTimer() const {
	return timer;
}

void Bullet::setTimer(int timer) {
	this->timer = timer;
}
