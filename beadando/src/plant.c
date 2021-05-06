#include <stdio.h>  
#include <time.h> 
#include <unistd.h>
#include <math.h>
#include "model.h"
#include "callbacks.h"
#include "plant.h"
#include "draw.h"

int movingWhichplant = 0;

void draw_plant(World* world){
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
		glTranslatef(world->plant1.position.x, world->plant1.position.y, world->plant1.position.z);

		glMaterialfv(GL_FRONT, GL_AMBIENT, world->plant1.material_ambient);
		glBindTexture(GL_TEXTURE_2D, world->plant1.texture);
		glScalef(15.0f, 15.0f, 15.0f);

		draw_model(&world->plant1.model);
    glPopMatrix();


	glPushMatrix();
		glTranslatef(world->plant2.position.x, world->plant2.position.y, world->plant2.position.z);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, world->plant2.material_ambient);

		glBindTexture(GL_TEXTURE_2D, world->plant2.texture);
		glScalef(10.0f, 10.0f, 10.0f);

		draw_model(&world->plant2.model);
    glPopMatrix();
}


void move_plant(World* world) {
	if(movingWhichplant == 0)
	{
		if(abs((int)(camera.position.x - world->plant1.position.x)) + abs((int)(camera.position.z - world->plant1.position.z)) <
				abs((int)(camera.position.x - world->plant2.position.x)) + abs((int)(camera.position.z - world->plant2.position.z)))
		{
			movingWhichplant = 1;
		}
		else if(abs((int)(camera.position.x - world->plant2.position.x)) + abs((int)(camera.position.z - world->plant2.position.z)) <
				abs((int)(camera.position.x - world->plant3.position.x)) + abs((int)(camera.position.z - world->plant3.position.z))){
			movingWhichplant = 2;
		}
		else
		{
			movingWhichplant = 3;
		}

	}

	if(abs(camera.position.x) <= 170 && abs(camera.position.z) <= 170)
	{
		switch (movingWhichplant) {
			case 1:
				if (abs((int)(camera.position.x - world->plant1.position.x)) < 50 && abs((int)(camera.position.z - world->plant1.position.z)) < 50 && camera.position.y < 150)
				{
					world->plant1.position.x = camera.position.x + 10;
					world->plant1.position.z = camera.position.z + 10;

					
				}

				break;
			case 2:
				if (abs((int)(camera.position.x - world->plant2.position.x)) < 50 && abs((int)(camera.position.z - world->plant2.position.z)) < 50 && camera.position.y < 150)
				{
					world->plant2.position.x = camera.position.x + 10;
					world->plant2.position.z = camera.position.z + 10;

					
				}

				break;
			case 3:
				if (abs((int)(camera.position.x - world->plant3.position.x)) < 50 && abs((int)(camera.position.z - world->plant3.position.z)) < 50 && camera.position.y < 150)
				{
					world->plant3.position.x = camera.position.x + 10;
					world->plant3.position.z = camera.position.z + 10;	
				}

				break;
		}
	}
}

void init_plant(Plant* plant, int x, int z, int y)
{
	plant->position.x = x;
	plant->position.y = y;
	plant->position.z = z;

	plant->material_ambient[0] = 1;
	plant->material_ambient[1] = 1;
	plant->material_ambient[2] = 1;
	plant->material_ambient[3] = 0.5;
	
}
