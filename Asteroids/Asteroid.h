/*
 * Asteroid.h
 *
 *  Created on: May 8, 2018
 *      Author: muzi
 */

#ifndef ASTEROID_H_
#define ASTEROID_H_

#include "Object.h"
#include "util.h"
#include <cmath>
#include "util.h"
class Asteroid: public Object {
protected:

public:
	Asteroid();
	void draw()=0;
	void performAction(int)=0;
	void move();
	void rotate(bool);
	void wrap();

	float getRadius()=0;
	float getCenterX()=0;
	float getCenterY()=0;
	void setCenter(float cx,float cy);

	virtual ~Asteroid();
};

#endif /* ASTEROID_H_ */
