/*
 * Point.h
 *
 *  Created on: Apr 30, 2018
 *      Author: muzi
 */

#ifndef POINT_H_
#define POINT_H_
#include <cmath>
#include "util.h"
class Point {
protected:
	float cX;
	float cY;

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

public:
	Point( float l1x1,float l1y1,float l1x2,float l1y2,float l2x1,float l2y1,float l2x2,float l2y2,float l3x1,float l3y1,float l3x2,float l3y2/*,float recX,float recY*/);
	Point  & rotate(bool isLeft);

	~Point();
	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);
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
	float getL3x1() const;
	void setL3x1(float l3x1);
	float getL3x2() const;
	void setL3x2(float l3x2);
	float getL3y1() const;
	void setL3y1(float l3y1);
	float getL3y2() const;
	void setL3y2(float l3y2);


};

#endif /* POINT_H_ */
