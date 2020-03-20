/*
 * BigSaucer.cpp
 *
 *  Created on: May 6, 2018
 *      Author: muzi
 */

#include "BigSaucer.h"

BigSaucer::BigSaucer() {
	cx = GetRandInRange(-10, 0);
	cy = GetRandInRange(0, 840);
	Degree = GetRandInRange(-360, 360);

}

BigSaucer::~BigSaucer() {
	// TODO Auto-generated destructor stub
}

