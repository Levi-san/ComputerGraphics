#include "model.h"


#include <stdio.h>
#include <GL/glut.h>
#include "SOIL/SOIL.h"

double ConvertToRadian(double DegreeValue);

void move_fish(World* world);

void draw_fish(World* world);

void init_fish(Fish* fish, int x, int z, int y);