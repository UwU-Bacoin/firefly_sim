#ifndef FIREFLY_H_
    #define FIREFLY_H_

    #define F_THRESHOLD (25)
    #define FF_NULL (-1)
    #define FF_INTAKE (100)

    #define FF_RADIUS (2)
    #define FF_PERIMETER (FF_RADIUS * 2 + 1)
    #define FF_RADIUS_MAX_IN (FF_PERIMETER * FF_PERIMETER)

    #ifndef bool
        #include <stdbool.h>
    #endif

typedef struct firefly {
    double energy;
    double delta;
} firefly_t;

firefly_t *firefly_init(void);

char firefly_symbol(double energy_level);
void firefly_increment(firefly_t *ff);
#endif
