#ifndef __CAMERA9__
#define __CAMERA9__

typedef struct
{
	int32 A, B, C, D;
	vect3D point;
}plane_struct;

typedef struct
{
	plane_struct plane[6];
}frustum_struct;

typedef struct
{
	vect3D position, angle, angle2;
	frustum_struct frustum;
	vect3D space[3];
	int32 transformationMatrix[3*3];
	int32 projectionMatrix[4*4];
	int32 viewMatrix[4*4];
	bool lookAt;
	physicsObject_struct object;
}camera_struct;

static inline int32 evaluatePlanePoint(plane_struct* p, vect3D v)
{
	if(!p)return 0;
	return mulf32(p->A,v.x)+mulf32(p->B,v.y)+mulf32(p->C,v.z)+p->D;
}

void initCamera(camera_struct* c);
void projectCamera(camera_struct* c);
void transformCamera(camera_struct* c);
void moveCamera(camera_struct* c, vect3D v);
void rotateCamera(camera_struct* c, vect3D a);
vect3D getCameraPosition(camera_struct* c);
void setCamera(camera_struct* c, vect3D v);
void updateCamera(camera_struct* c);
void updateCameraPreview(room_struct* r, camera_struct* c);
camera_struct* getPlayerCamera(void);
vect3D getUnitVector(camera_struct* c);

void changeBase(int32* tm, vect3D x, vect3D y, vect3D z, bool r);

void multMatrix33(int32* m1, int32* m2, int32* m);
void multMatrix44(int32* m1, int32* m2, int32* m);
void translateMatrix(int32* tm, int32 x, int32 y, int32 z);
vect3D clipPointFrustum(frustum_struct* f, vect3D* v, u8 vid, const u8 vn);

#endif