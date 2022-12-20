#ifndef GIF_H_
    #define GIF_H_

    #ifndef meadow_t
        #include "meadow.h"
    #endif

    #ifndef ge_GIF
        #include "gifenc.h"
    #endif

ge_GIF *create_gif(meadow_t *meadow);
void add_frame(ge_GIF *gif, meadow_t *meadow, population_t *pop);
#endif
