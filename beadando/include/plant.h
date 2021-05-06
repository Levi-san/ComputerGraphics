#include "model.h"


#include <stdio.h>
#include <GL/glut.h>
#include "SOIL/SOIL.h"

extern int movingWhichplant;

void move_plant(World* world);

void draw_plant(World* world);

void init_plant(Plant* plant, int x, int z, int y);