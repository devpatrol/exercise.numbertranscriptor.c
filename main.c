#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "analyser/analyser.h"
#include "formater/formater.h"
#include "utils/tools.h"

char *number_transcriptor( char *data )
{
    char *result, *err;
        result = createSlice( data, "" );
        err = analyse( result );

        if ( err != NULL ) 
        {
            return err;
        }

    return format( result );
}

int main( int argc, char const *argv[] )
{
    char *data;
        printf( ">>> Quelle Expression voulez-vous transcrire?" );
        printf( ">>> " );
    char 
        *arr = number_transcriptor( "25(4*5)*(45*6) * 25" );
        printf( "%s \n", arr );
    return 0;
}
