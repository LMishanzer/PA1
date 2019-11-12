#ifndef __PROGTEST__
#include <math.h>
#include <float.h>
#include <assert.h>
#include <stdio.h>
#include "functions.c"
#endif /* __PROGTEST__ */

#ifndef __PROGTEST__

int main ( void )
{
    double x1, y1, x2, y2;

    x1 = 60;
    y1 = 40;
    x2 = 70;
    y2 = 50;

    assert ( clipLine ( 10, 20, 90, 100, &x1, &y1, &x2, &y2 )
             && almostEqual ( x1, 60 )
             && almostEqual ( y1, 40 )
             && almostEqual ( x2, 70 )
             && almostEqual ( y2, 50 ) );

    x1 = 0;
    y1 = 50;
    x2 = 20;
    y2 = 30;
    assert ( clipLine ( 90, 100, 10, 20, &x1, &y1, &x2, &y2 )
             && almostEqual ( x1, 10 )
             && almostEqual ( y1, 40 )
             && almostEqual ( x2, 20 )
             && almostEqual ( y2, 30 ) );

    x1 = 0;
    y1 = 30;
    x2 = 120;
    y2 = 150;
    assert ( clipLine ( 10, 20, 90, 100, &x1, &y1, &x2, &y2 )
             && almostEqual ( x1, 10 )
             && almostEqual ( y1, 40 )
             && almostEqual ( x2, 70 )
             && almostEqual ( y2, 100 ) );

    x1 = -10;
    y1 = -10;
    x2 = -20;
    y2 = -20;
    assert ( ! clipLine ( 10, 20, 90, 100, &x1, &y1, &x2, &y2 ) );

    x1 = 0;
    y1 = 30;
    x2 = 20;
    y2 = 10;
    assert ( clipLine ( 10, 20, 90, 100, &x1, &y1, &x2, &y2 )
             && almostEqual ( x1, 10 )
             && almostEqual ( y1, 20 )
             && almostEqual ( x2, 10 )
             && almostEqual ( y2, 20 ) );

    x1 = 0;
    y1 = 0.3553;
    x2 = 10.45;
    y2 = 0;
    assert ( clipLine ( 0.95, 0.323, 1, 1, &x1, &y1, &x2, &y2 )
             && almostEqual ( x1, 0.95 )
             && almostEqual ( y1, 0.323 )
             && almostEqual ( x2, 0.95 )
             && almostEqual ( y2, 0.323 ) );

    x1 = -2039;
    y1 = -996;
    x2 = -553;
    y2 = 162;
    assert(clipLine ( -553, 162, 190, 741, &x1, &y1, &x2, &y2 )
           && almostEqual ( x1, -553 )
           && almostEqual ( y1, 162 )
           && almostEqual ( x2, -553 )
           && almostEqual ( y2, 162 ) );

    x1 = -1463;
    y1 = -886;
    x2 = -1463;
    y2 = -1161;
    assert(!clipLine ( 509, -611, 1495, -336, &x1, &y1, &x2, &y2 ));

    x1 = -100;
    y1 = 0;
    x2 = 0;
    y2 = -10;
    assert(!clipLine ( -1, 1, 1, -1, &x1, &y1, &x2, &y2 ));

    return 0;
}
#endif /* __PROGTEST__ */