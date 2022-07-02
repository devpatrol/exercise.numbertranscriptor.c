#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "transcriptor/transcriptor.h"
#include "analyser/analyser.h"
#include "utils/tools.h"

int main( int argc, char const *argv[] )
{
    int i = 0;
    /*char 
        *arr = transcript( "25480560.00025" );
        printf( "%s \n", arr );*/
    
    char 
        *err,
        *data = createSlice( "+1*4.55+(45+1)-((4-3)*(4/-6))=-6(255*-6/2)", "" );
            err = analyse( data );
        printf( ":%s:\n", err == NULL ? "NULL" : err );
        printf( ":%s:\n", data );
    return 0;
}
