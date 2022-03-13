#ifndef __SMINIT_H__
#define __SMINIT_H__

struct CollisionMesh;
struct MarioMesh;
struct RenderState;

extern uint8_t *utils_read_file_alloc( const char *path, size_t *fileLength );
extern int SM_Init();

#endif
