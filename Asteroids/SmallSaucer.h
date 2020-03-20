/*
 * SmallSaucer.h
 *
 *  Created on: May 6, 2018
 *      Author: muzi
 */

#ifndef SMALLSAUCER_H_
#define SMALLSAUCER_H_
#include "Saucer.h"
class SmallSaucer:public Saucer {
private:
//	int l1x1,l1y1,l1x2,l1y2;
//	int l2x1,l2y1,l2x2,l2y2;
//	int l3x1,l3y1,l3x2,l3y2;
//	int l4x1,l4y1,l4x2,l4y2;
//	int l5x1,l5y1,l5x2,l5y2;
//	int l6x1,l6y1,l6x2,l6y2;
//	int l7x1,l7y1,l7x2,l7y2;
//	int l8x1,l8y1,l8x2,l8y2;
//	int l9x1,l9y1,l9x2,l9y2;
//	int l10x1,l10y1,l10x2,l10y2;
	Bullet *bul;

public:
	SmallSaucer();
	void draw();
	void wrap();
	 void performAction(int);
	void move();
	float getRadius();
	float getCenterX();
	float getCenterY();
	void destoryBullet(int);
	virtual ~SmallSaucer();
};

#endif /* SMALLSAUCER_H_ */
