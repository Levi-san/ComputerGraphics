#include <stdio.h>  
#include <time.h> 
#include <unistd.h>
#include <math.h>
#include "model.h"
#include "callbacks.h"
#include "fish.h"
#include "draw.h"
#include <conio.h>


float heading = 0.0;

double ConvertToRadian(double DegreeValue)
{
    double pi = 3.14159;
    double RadianValue = DegreeValue * (pi/180.0);
    return RadianValue;
}

void move_fish(World* world) {
	
	for (int i = 0; i < 5; i++)
	{
		
		if (world->fish.position.x > -140 && world->fish.position.x < 140)
		{

			/*if(i%2==0)
			{*/
				world->fish.position.z -= 0.04 * sin(ConvertToRadian(heading));
				world->fish.position.x += 0.04 * sin(ConvertToRadian(heading));
				world->fish.position.x += 0.1;
			
			//}
			/*else{
				//world->fish.position.z += 0.05f * cos(heading);
				world->fish.position.x += 0.05f * sin(ConvertToRadian(heading));
			}*/
			
			heading++;


		}

	}
}
void draw_fish(World* world){
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
		glTranslatef(world->fish.position.x, world->fish.position.y, world->fish.position.z);
		glBindTexture(GL_TEXTURE_2D, world->fish.texture);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, world->fish.material_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, world->fish.material_diffusion);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, world->fish.material_specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, world->fish.material_shininess);
		 
		glScalef(20.0f, 20.0f, 20.0f);

		draw_model(&world->fish.model);
    glPopMatrix();
}

void init_fish(Fish* fish, int x, int z, int y)
{

	fish->position.x = x;
	fish->position.y = y;
	fish->position.z = z;
	
	fish->material_ambient[0] = 1.0f;
	fish->material_ambient[1] = 1.0f;
	fish->material_ambient[2] = 1.0f;
	fish->material_ambient[3] = 0.5f;
	
	fish->material_diffusion[0] = 1.0f;
	fish->material_diffusion[1] = 0.5f;
	fish->material_diffusion[2] = 0.31f;
	fish->material_diffusion[3] = 1.0f;
	
	fish->material_specular[0] = 0.5f;
	fish->material_specular[1] = 0.5f;
	fish->material_specular[2] = 0.5f;
	fish->material_specular[3] = 1.0f;
	
	fish->material_shininess = 100.0f;
	
}