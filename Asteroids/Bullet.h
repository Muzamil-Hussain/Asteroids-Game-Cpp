/*
 * Bullet.h
 *
 *  Created on: May 6, 2018
 *      Author: muzi
 */

#ifndef BULLET_H_
#define BULLET_H_
#include "Object.h"
#include "util.h"
class Bullet:public Object {
	int cx;
	int cy;
	int Degree;
	bool isReady;
	int timer;
	int radius;
public:
	Bullet(int cx=0,int cy=0,int Degree=0);
	void draw();
	void performAction(int);
	void move();
	void wrap();
	void initializeBullet(int cx,int cy,int Degree);


	float getRadius();
	float getCenterX();
	float getCenterY();
	void setCenter(float cx,float cy);

	virtual ~Bullet();
	int getCx() const;
	void setCx(int cx);
	int getCy() const;
	void setCy(int cy);
	int getDegree() const;
	void setDegree(int degree);
	bool isIsReady() const;
	void setIsReady(bool isReady);
	int getTimer() const;
	void setTimer(int timer);
};

#endif /* BULLET_H_ */
