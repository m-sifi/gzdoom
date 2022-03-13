#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

extern "C"
{
#include "libsm64.h"
}
#include "sm_init.h"

typedef struct CollisionMesh
{
    size_t num_vertices;
    float *position;
    float *normal;
    uint16_t *index;

    uint8_t vao;
    uint8_t position_buffer;
    uint8_t normal_buffer;
}
CollisionMesh;

typedef struct MarioMesh
{
    size_t num_vertices;
    uint16_t *index;

    uint8_t vao;
    uint8_t position_buffer;
    uint8_t normal_buffer;
    uint8_t color_buffer;
    uint8_t uv_buffer;
}
MarioMesh;

typedef struct RenderState
{
    CollisionMesh collision;
    MarioMesh mario;
    uint8_t world_shader;
    uint8_t mario_shader;
    uint8_t mario_texture;
}
RenderState;

uint8_t *utils_read_file_alloc( const char *path, size_t *fileLength )
{
    FILE *f = fopen( path, "rb" );

    if( !f ) return NULL;

    fseek( f, 0, SEEK_END );
    size_t length = (size_t)ftell( f );
    rewind( f );
    uint8_t *buffer = (uint8_t *)malloc( length + 1 );
    fread( buffer, 1, length, f );
    buffer[length] = 0;
    fclose( f );

    if( fileLength ) *fileLength = length;

    return buffer;
}

int SM_Init()
{
    size_t romSize;

    uint8_t *rom = utils_read_file_alloc( "baserom.us.z64", &romSize );

    if( rom == NULL )
    {
        printf("\nFailed to read ROM file \"baserom.us.z64\"\n\n");
        return 0;
    }

    uint8_t *texture = (uint8_t *)malloc( 4 * SM64_TEXTURE_WIDTH * SM64_TEXTURE_HEIGHT );

    sm64_global_terminate();
    sm64_global_init( rom, texture, NULL );
    sm64_static_surfaces_load( surfaces, surfaces_count );
    uint32_t marioId = sm64_mario_create( 0, 1000, 0 );

    free( rom );

    return 1;
}