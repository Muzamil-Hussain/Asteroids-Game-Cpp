/*
 * Shooter.h
 *
 *  Created on: Apr 29, 2018
 *      Author: muzi
 */

#ifndef SHOOTER_H_
#define SHOOTER_H_
#include "Object.h"
#include "util.h"
#include "Point.h"
#include "Bullet.h"
class Shooter: public Object {
protected:

	float l1x1;
	float l1y1;
	float l1x2;
	float l1y2;

	float l2x1;
	float l2y1;
	float l2x2;
	float l2y2;

	float l3x1;
	float l3y1;
	float l3x2;
	float l3y2;
	float Degree;
	int velocity;

	Bullet **bul;
	int timeCount;

	int hyper;
public:
	Shooter();
	void draw();
	void drawRed();
	void move();
	void wrap();
	void rotate(bool);
	void performAction(int);
	void destoryBullet(int);
	void hyperSpace();

	float getRadius();
	float getCenterX();
	float getCenterY();
	void setCenter(float,float);

	float getL1x1() const;
	void setL1x1(float l1x1);
	float getL1x2() const;
	void setL1x2(float l1x2);
	float getL1y1() const;
	void setL1y1(float l1y1);
	float getL1y2() const;
	void setL1y2(float l1y2);
	float getL2x1() const;
	void setL2x1(float l2x1);
	float getL2x2() const;
	void setL2x2(float l2x2);
	float getL2y1() const;
	void setL2y1(float l2y1);
	float getL2y2() const;
	void setL2y2(float l2y2);

	~Shooter();
	int getDegree() const;
	void setDegree(int degree);
	float getL3x1() const;
	void setL3x1(float l3x1);
	float getL3x2() const;
	void setL3x2(float l3x2);
	float getL3y1() const;
	void setL3y1(float l3y1);
	float getL3y2() const;
	void setL3y2(float l3y2);
	int getVelocity() const;
	void setVelocity(int velocity);
    Bullet* getBul(int );
	int getTimeCount() const;
	void setTimeCount(int timeCount);
	int getHyper() const;
	void setHyper(int hyper);
};

#endif /* SHOOTER_H_ */
