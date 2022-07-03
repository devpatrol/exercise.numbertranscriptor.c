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

char *getString()
{
    char *result, item;
        result = createSlice( "", "" );
        scanf( "%c", &item );
        while ( item != '\n' )
        {
            result = addSlice( result, ( char[] ){ item } );
            scanf( "%c", &item );
        }
    return result;
}

int main( int argc, char const *argv[] )
{
    char *data;
        printf( "\n\n" );
        printf( ">>> Quelle Expression voulez-vous transcrire?" );
        printf( "\n" );
        printf( ">>> " );
            data = getString();
            data = number_transcriptor( data );
        printf( ">>> %s", data );
        printf( "\n\n" );
    return 0;
}
