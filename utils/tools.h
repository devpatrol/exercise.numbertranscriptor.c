#ifndef H_TOOLS
#define H_TOOLS

#include <string.h>
#include <stdlib.h>

int getIndex( char *list, char el, int start ) 
{
    int i = start;
        for( ; i < strlen( list ); i++ ) 
        {
            if ( list[ i ] == el )
                return i;
        }
    return -1;
}

int getPosition( char *list, char el ) 
{
    return getIndex( list, el, 1 );
}

char *getResized( char *list, int start, int end )
{
    char *result;
    int i = 0;
        result = (char *) malloc( sizeof( char ) * ( end - start + 2 ) );
        for( ; i < end - start + 1; i++ ) 
            result[ i ] = list[ start + i ];
        result[ end - start + 1 ] = '\0';
    return result;
}

char *createSlice( char *str1, char *str2 )
{
    int length = strlen( str1 ) + strlen( str2 ) + 1;
    char *result;
        result = (char *) malloc( sizeof( char ) * length );
            strcat( result, str1 );
            strcat( result, str2 );
        result[ length - 1 ] = '\0';
    return result;
}

char *addSlice( char *str1, char *str2 )
{
    int length = (int) strlen( str1 ) + (int) strlen( str2 ) + 1;
        str1 = ( char * ) realloc( str1, sizeof( char ) * length );
        strcat( str1, str2 );
    return str1;
}

#endif