#ifndef WALLDOOR_H
#define WALLDOOR_H

typedef struct
{
	vect3D position, gridPosition;
	u8 orientation;
	// rectangle_struct* walls;
	modelInstance_struct modelInstance;
	material_struct* frameMaterial;
	rectangle_struct* rectangle;
	elevator_struct elevator;
	bool used;
}wallDoor_struct;

extern wallDoor_struct entryWallDoor;

void initWallDoors(void);
void updateWallDoors(void);
void setupWallDoor(room_struct* r, wallDoor_struct* wd, vect3D position, u8 orientation);
void drawWallDoors(void);

#endif