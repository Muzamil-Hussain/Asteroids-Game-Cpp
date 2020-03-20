/*
 * Object.h
 *
 *  Created on: Apr 29, 2018
 *      Author: muzi
 */

#ifndef OBJECT_H_
#define OBJECT_H_

class Object {
protected:
public:
	virtual void draw()=0;
	virtual void performAction(int)=0;
	virtual float getRadius()=0;
	virtual float getCenterX()=0;
	virtual float getCenterY()=0;
	virtual void setCenter(float,float)=0;

	virtual ~Object();
};

#endif /* OBJECT_H_ */
