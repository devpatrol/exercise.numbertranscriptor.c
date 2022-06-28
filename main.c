#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transcriptor/transcriptor.h"
#include "utils/tools.h"

int main( int argc, char const *argv[] )
{
    int i = 0;
    char 
        *arr = transcript( "25480560.00025" );
        printf( "%s \n", arr );
    return 0;
}
