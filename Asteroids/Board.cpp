/*
 * Board.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Sibt ul Hussain
 */

#include "Board.h"
#include <cstdio>

// Asteroids board

// Note that all these enum constants from NILL onwards
// have been given numbers in increasing order
// e.g. NILL=0, and so on
// and these numbers are represented in the board array...
enum BoardParts {
	NILL, S_BRICK, G_BRICK, R_BRICK
};
// defining some utility functions...

/* board_array[Board::BOARD_Y][Board::BOARD_X] = { { 0 } };*/

// Destructor
Board::~Board(void) {
}
void Board::InitalizeBoard(int w, int h) {
	cout << "Initialize board" << endl;
	width = w;
	height = h;
	for (int i = 0; i < BOARD_Y - 1; ++i) {
		for (int j = 0; j < BOARD_X; ++j) {
			// can use G_BRICK, R_BRICK, or S_BRICK here
			board_array[i][j] = NILL;
		}
	}

	for (int i = 0; i < size; i++) {
		if (i == 0) {
			gameEnvironment[i] = new Shooter;
			player = dynamic_cast<Shooter *>(gameEnvironment[0]);
		}
		if (i > 2 && i < size)
			gameEnvironment[i] = new BigAsteroid;
		if (i == 1) {
			gameEnvironment[i] = new BigSaucer;
			bigSaucer = dynamic_cast<BigSaucer *>(gameEnvironment[1]);
		}
		if (i == 2) {
			gameEnvironment[i] = new SmallSaucer;
			smallSaucer = dynamic_cast<SmallSaucer *>(gameEnvironment[2]);
		}
	}
}
//Constructor
Board::Board(int xsize, int ysize) {
	cout << "Constructor board" << endl;
	xcellsize = xsize;
	ycellsize = ysize;
	pcolor = CHOCOLATE;
	bcolor = ORANGE_RED;
	gcolor = PINK;
	for (int i = 0; i < BOARD_Y; ++i)
		for (int j = 0; j < BOARD_X; ++j)
			board_array[i][j] = 0;

	score = 0;
	size = 7;
	livesCount = 5;
	level = 1;
	startUp = 0;
	saucerTimer = 0;
	gameEnvironment = new Object *[size];
	immunity = 0;
//set up board
}

void Board::Draw() {
	glColor3f(0, 0, 1);
	glPushMatrix();

	startUp++;
	saucerTimer++;
	immunity++;
	if (startUp >= 150) {
		if (livesCount > 0) {
			for (int i = 0; i < size; i++) {
				if (i == 0) {
					gameEnvironment[i]->draw();
					gameEnvironment[i]->performAction(0);
				}
				if (i > 0 and i < size) {
					if (i == 1 || i == 2) {
						if (saucerTimer >= 400) {
							gameEnvironment[i]->draw();
							gameEnvironment[i]->performAction(1);
							gameEnvironment[i]->performAction(2);
							gameEnvironment[i]->performAction(4);
						}
					} else {
						gameEnvironment[i]->draw();
						gameEnvironment[i]->performAction(1);
						gameEnvironment[i]->performAction(2);
						gameEnvironment[i]->performAction(4);
					}

				}
			}
			DrawString(30, 800, "Score ");
			DrawString(100, 800, Num2Str(score));
			DrawString(450, 800, "Level ");
			DrawString(520, 800, Num2Str(level));
			for (int i = 0; i < livesCount; i++) {
				if (i == livesCount - 1) {
					DrawTriangle(30, 750, 50, 790, 70, 750, colors[GREEN]);
				}
				if (i == livesCount - 2) {
					DrawTriangle(70, 750, 90, 790, 110, 750, colors[GREEN]);
				}
				if (i == livesCount - 3) {
					DrawTriangle(110, 750, 130, 790, 150, 750, colors[GREEN]);
				}
				if (i == livesCount - 4) {
					DrawTriangle(150, 750, 170, 790, 190, 750, colors[GREEN]);
				}
				if (i == livesCount - 5) {
					DrawTriangle(190, 750, 210, 790, 230, 750, colors[GREEN]);
				}
			}
			collision();
			levelUp();
		} else {
			DrawString(450, 420, "Game Over", colors[RED]);
			DrawString(450, 380, "Score ");
			DrawString(510, 380, Num2Str(score));
		}

	} else {
		DrawString(450, 420, "ASTEROIDS", colors[WHITE]);
		for (int i = 3; i < 6; i++) {
			gameEnvironment[i]->draw();
			gameEnvironment[i]->performAction(2);
		}

	}
	glPopMatrix();
}
void Board::addAsteroid(int index) {
	if (gameEnvironment[index]->getRadius() == 70) {
		Object **temp;
		int tempSize = size + 2;
		temp = new Object *[tempSize];

		for (int i = 0; i < tempSize - 2; i++) {
			temp[i] = gameEnvironment[i];
		}
		temp[tempSize - 1] = new MediumAsteroid(
				gameEnvironment[index]->getCenterX(),
				gameEnvironment[index]->getCenterY());
		temp[tempSize - 2] = new MediumAsteroid(
				gameEnvironment[index]->getCenterX(),
				gameEnvironment[index]->getCenterY());
		delete[] gameEnvironment;
		size = tempSize;
		gameEnvironment = new Object *[size];

		for (int i = 0; i < size; i++) {
			gameEnvironment[i] = temp[i];
		}

	}
	if (gameEnvironment[index]->getRadius() == 50) {
		Object **temp;
		int tempSize = size + 4;
		temp = new Object *[tempSize];

		for (int i = 0; i < tempSize - 4; i++) {
			temp[i] = gameEnvironment[i];
		}
		temp[tempSize - 1] = new SmallAsteroid(
				gameEnvironment[index]->getCenterX(),
				gameEnvironment[index]->getCenterY());
		temp[tempSize - 2] = new SmallAsteroid(
				gameEnvironment[index]->getCenterX(),
				gameEnvironment[index]->getCenterY());
		temp[tempSize - 3] = new SmallAsteroid(
				gameEnvironment[index]->getCenterX(),
				gameEnvironment[index]->getCenterY());
		temp[tempSize - 4] = new SmallAsteroid(
				gameEnvironment[index]->getCenterX(),
				gameEnvironment[index]->getCenterY());
		delete[] gameEnvironment;
		size = tempSize;
		gameEnvironment = new Object *[size];

		for (int i = 0; i < size; i++) {
			gameEnvironment[i] = temp[i];
		}

	}
}
void Board::removeObject(int index) {
	Object **temp;
	temp = new Object *[size - 1];

	for (int i = 0; i < index; i++) {
		temp[i] = gameEnvironment[i];
	}
	for (int i = index + 1, j = index; i < size; i++, j++) {
		temp[j] = gameEnvironment[i];
	}
	delete[] gameEnvironment;
	size = size - 1;

	gameEnvironment = new Object *[size];

	for (int i = 0; i < size; i++) {
		gameEnvironment[i] = temp[i];
	}
}
void Board::collision() {
	float distanceXcomp = 0;
	float distanceYcomp = 0;
	float distanceFinal = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 1; j < size; j++) {
			distanceXcomp = (player->getBul(i)->getCenterX()
					+ player->getBul(i)->getRadius())
					- (gameEnvironment[j]->getCenterX()
							+ gameEnvironment[j]->getRadius());
			distanceYcomp = (player->getBul(i)->getCenterY()
					+ player->getBul(i)->getRadius())
					- (gameEnvironment[j]->getCenterY()
							+ gameEnvironment[j]->getRadius());
			distanceFinal = sqrt(
					distanceXcomp * distanceXcomp
							+ distanceYcomp * distanceYcomp);

			if (distanceFinal
					< player->getBul(i)->getRadius()
							+ gameEnvironment[j]->getRadius()
					&& player->getBul(i)->isIsReady() == true) {

				if (gameEnvironment[j]->getRadius() == 70) {
					score += 10;
				}

				if (gameEnvironment[j]->getRadius() == 50) {
					score += 20;
				}
				if (gameEnvironment[j]->getRadius() == 30) {
					score += 40;
				}
				if (gameEnvironment[j]->getRadius() == 29) {
					score += 500;
				}

				if (gameEnvironment[j]->getRadius() == 69) {
					score += 100;
				}
				player->getBul(i)->setIsReady(false);
				addAsteroid(j);
				removeObject(j);

			}
		}

	}

	if (immunity >= 200) {
		for (int j = 1; j < size; j++) {
			distanceXcomp = (player->getCenterX() + player->getRadius())
					- (gameEnvironment[j]->getCenterX()
							+ gameEnvironment[j]->getRadius() - 30);
			distanceYcomp = (player->getCenterY() + player->getRadius())
					- (gameEnvironment[j]->getCenterY()
							+ gameEnvironment[j]->getRadius() - 30);
			distanceFinal = sqrt(
					distanceXcomp * distanceXcomp
							+ distanceYcomp * distanceYcomp);

			if (distanceFinal
					< player->getRadius() + gameEnvironment[j]->getRadius()
							- 20) {
				addAsteroid(j);
				removeObject(j);
				livesCount -= 1;
				player->setL1x1(480);
				player->setL1y1(200);
				player->setL1x2(460);
				player->setL1y2(140);

				player->setL2x1(480);
				player->setL2y1(200);
				player->setL2x2(500);
				player->setL2y2(140);

				player->setL3x1(465);
				player->setL3y1(150);
				player->setL3x2(495);
				player->setL3y2(150);
				player->setDegree(0);
				immunity=0;

			}
		}
	}
	for (int i = 0; i < size; i++) {
		if (gameEnvironment[i]->getRadius() == 29) {
			for (int j = 1; j < size; j++) {
				distanceXcomp = (gameEnvironment[i]->getCenterX()
						+ gameEnvironment[i]->getRadius())
						- (gameEnvironment[j]->getCenterX()
								+ gameEnvironment[j]->getRadius() - 40);
				distanceYcomp = (gameEnvironment[i]->getCenterY()
						+ gameEnvironment[i]->getRadius())
						- (gameEnvironment[j]->getCenterY()
								+ gameEnvironment[j]->getRadius() - 40);
				distanceFinal = sqrt(
						distanceXcomp * distanceXcomp
								+ distanceYcomp * distanceYcomp);

				if (distanceFinal
						< gameEnvironment[i]->getRadius()
								+ gameEnvironment[j]->getRadius() - 40) {
					addAsteroid(j);
					removeObject(j);

				}
			}
		}
	}

	for (int i = 0; i < size; i++) {
		if (gameEnvironment[i]->getRadius() == 69) {
			for (int j = 1; j < size; j++) {
				distanceXcomp = (gameEnvironment[i]->getCenterX()
						+ gameEnvironment[i]->getRadius())
						- (gameEnvironment[j]->getCenterX()
								+ gameEnvironment[j]->getRadius() - 60);
				distanceYcomp = (gameEnvironment[i]->getCenterY()
						+ gameEnvironment[i]->getRadius())
						- (gameEnvironment[j]->getCenterY()
								+ gameEnvironment[j]->getRadius() - 60);
				distanceFinal = sqrt(
						distanceXcomp * distanceXcomp
								+ distanceYcomp * distanceYcomp);

				if (distanceFinal
						< gameEnvironment[i]->getRadius()
								+ gameEnvironment[j]->getRadius() - 60) {
					addAsteroid(j);
					removeObject(j);

				}
			}
		}
	}

	distanceXcomp = (player->getCenterX() + player->getRadius())
			- (bigSaucer->getBul()->getCenterX()
					+ bigSaucer->getBul()->getRadius());
	distanceYcomp = (player->getCenterY() + player->getRadius())
			- (bigSaucer->getBul()->getCenterY()
					+ bigSaucer->getBul()->getRadius());
	distanceFinal = sqrt(
			distanceXcomp * distanceXcomp + distanceYcomp * distanceYcomp);

	if (distanceFinal < player->getRadius() + bigSaucer->getRadius()
			&& bigSaucer->getBul()->isIsReady() == true) {
		bigSaucer->getBul()->setIsReady(false);

		livesCount -= 1;
		player->setL1x1(480);
		player->setL1y1(200);
		player->setL1x2(460);
		player->setL1y2(140);

		player->setL2x1(480);
		player->setL2y1(200);
		player->setL2x2(500);
		player->setL2y2(140);

		player->setL3x1(465);
		player->setL3y1(150);
		player->setL3x2(495);
		player->setL3y2(150);
		player->setDegree(0);
	}

	distanceXcomp = (player->getCenterX() + player->getRadius())
			- (smallSaucer->getBul()->getCenterX()
					+ smallSaucer->getBul()->getRadius());
	distanceYcomp = (player->getCenterY() + player->getRadius())
			- (smallSaucer->getBul()->getCenterY()
					+ smallSaucer->getBul()->getRadius());
	distanceFinal = sqrt(
			distanceXcomp * distanceXcomp + distanceYcomp * distanceYcomp);

	if (distanceFinal < player->getRadius() + smallSaucer->getRadius()
			&& smallSaucer->getBul()->isIsReady() == true) {
		smallSaucer->getBul()->setIsReady(false);

		livesCount -= 1;
		player->setL1x1(480);
		player->setL1y1(200);
		player->setL1x2(460);
		player->setL1y2(140);

		player->setL2x1(480);
		player->setL2y1(200);
		player->setL2x2(500);
		player->setL2y2(140);

		player->setL3x1(465);
		player->setL3y1(150);
		player->setL3x2(495);
		player->setL3y2(150);
		player->setDegree(0);
	}
}
void Board::levelUp() {
	if (size == 1) {
		saucerTimer = 0;
		level += 1;
		score += level * 1000;
		delete[] gameEnvironment;
		size = (level * 3) + 2;

		gameEnvironment = new Object *[size];
		for (int i = 0; i < size; i++) {
			if (i == 0) {
				gameEnvironment[i] = new Shooter;
				player = dynamic_cast<Shooter *>(gameEnvironment[0]);
			}
			if (i > 2 && i < size)
				gameEnvironment[i] = new BigAsteroid;
			if (i == 1) {
				gameEnvironment[i] = new BigSaucer;
				bigSaucer = dynamic_cast<BigSaucer *>(gameEnvironment[1]);
			}
			if (i == 2) {
				gameEnvironment[i] = new SmallSaucer;
				smallSaucer = dynamic_cast<SmallSaucer *>(gameEnvironment[2]);
			}
		}
	}

}
void Board::GetInitTextPosition(int &x, int &y) {
	x = xcellsize;
	y = (BOARD_Y - 1) * ycellsize + ycellsize / 2;
}
