/*
 * Saucer.h
 *
 *  Created on: May 5, 2018
 *      Author: muzi
 */

#ifndef SAUCER_H_
#define SAUCER_H_
#include "Object.h"
#include "util.h"
#include <cmath>
#include "Bullet.h"
class Saucer: public Object {
protected:
	int cx;
	int cy;
	int Degree;
	Bullet *bul;
public:
	Saucer();
	virtual void draw();
	virtual void move();
    void performAction(int);
	virtual void wrap();
	void destoryBullet(int);
	float getRadius();
	float getCenterX();
	float getCenterY();
	void setCenter(float cx,float cy);


   ~Saucer();
	int getCx() const;
	void setCx(int cx);
	int getCy() const;
	void setCy(int cy);
	int getDegree() const;
	void setDegree(int degree);
	Bullet* getBul() ;
};

#endif /* SAUCER_H_ */
