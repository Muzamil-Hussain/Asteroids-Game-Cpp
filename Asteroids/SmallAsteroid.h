/*
 * SmallAsteroid.h
 *
 *  Created on: May 8, 2018
 *      Author: muzi
 */

#ifndef SmallAsteroid_H_
#define SmallAsteroid_H_
#include "Asteroid.h"
class SmallAsteroid:public Asteroid {
protected:
	int cx;
	int cy;
	int randomPoint;
	int npoints;
	int radius;
	int dtheta;
	float theta;
	int *storeX;
	int *storeY;
	int Degree;
	int *storeTempX;
	int *storeTempY;
	int rotationDegree;
public:
	SmallAsteroid(int cx,int cy);
	void draw();
	void performAction(int);
	void move();
	void rotate(bool);
	void wrap();

	float getRadius();
	float getCenterX();
	float getCenterY();
	void setCenter(float cx,float cy);

	int getCx() const;
	void setCx(int cx);
	int getCy() const;
	void setCy(int cy);
	int getDegree() const;
	void setDegree(int degree);
	int getDtheta() const;
	void setDtheta(int dtheta);
	int getNpoints() const;
	void setNpoints(int npoints);
	int getRandomPoint() const;
	void setRandomPoint(int randomPoint);
	int getRotationDegree() const;
	void setRotationDegree(int rotationDegree);
	int* getStoreTempX() const;
	void setStoreTempX(int* storeTempX);
	int* getStoreTempY() const;
	void setStoreTempY(int* storeTempY);
	int* getStoreX() const;
	void setStoreX(int* storeX);
	int* getStoreY() const;
	void setStoreY(int* storeY);
	float getTheta() const;
	void setTheta(float theta);
	int getRadius() const;
	void setRadius(int radius);
	virtual ~SmallAsteroid();
};

#endif /* SmallAsteroid_H_ */
