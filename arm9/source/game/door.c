#include "game/game_main.h"

door_struct door[NUMDOORS];
md2Model_struct doorModel;

void initDoors(void)
{
	int i;
	for(i=0;i<NUMDOORS;i++)
	{
		door[i].used=false;
		door[i].id=i;
	}

	loadMd2Model("models/door.md2", "door.pcx", &doorModel);
	generateModelDisplayLists(&doorModel, false, true);
}

void initDoor(door_struct* d, room_struct* r, vect3D position, bool orientation)
{
	if(!d || !r)return;

	initModelInstance(&d->modelInstance, &doorModel);
	d->position=convertVect(vect(position.x+r->position.x, position.y, position.z+r->position.y));
	d->orientation=orientation;
	d->used=true;
}

door_struct* createDoor(room_struct* r, vect3D position, bool orientation)
{
	if(!r)r=&gameRoom;
	int i;
	for(i=0;i<NUMDOORS;i++)
	{
		if(!door[i].used)
		{
			initDoor(&door[i], r, position, orientation);
			return &door[i];
		}
	}
	return NULL;
}

void updateDoor(door_struct* d)
{
	if(!d || !d->used)return;


}

void updateDoors(void)
{
	int i;
	for(i=0;i<NUMDOORS;i++)
	{
		if(door[i].used)updateDoor(&door[i]);
	}
}

void drawDoor(door_struct* d)
{
	if(!d || !d->used)return;

	glPushMatrix();
		u32 params=POLY_ALPHA(31)|POLY_CULL_FRONT|POLY_ID(30+d->id)|POLY_TOON_HIGHLIGHT;
		setupObjectLighting(NULL, d->position, &params);

		glTranslate3f32(d->position.x,d->position.y,d->position.z);
		
		if(d->orientation)glRotateYi(8192);
		
		renderModelFrameInterp(d->modelInstance.currentFrame,d->modelInstance.nextFrame,d->modelInstance.interpCounter,d->modelInstance.model,params,false,d->modelInstance.palette,RGB15(31,31,31));
	glPopMatrix(1);
}

void drawDoors(void)
{
	int i;
	for(i=0;i<NUMDOORS;i++)
	{
		if(door[i].used)drawDoor(&door[i]);
	}
}