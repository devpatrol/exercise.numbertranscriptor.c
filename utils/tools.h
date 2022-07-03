#ifndef H_TOOLS
#define H_TOOLS

#include <string.h>
#include <stdlib.h>

/**
    * @brief Get the Index object
    * 
    * @param list 
    * @param el 
    * @param start 
    * @return int 
    * *
    * this function will return the index of an element
    * in a char array
*/
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

/**
    * @brief Get the Position object
    * 
    * @param list 
    * @param el 
    * @return int
    * *
    * return the position of an element 
*/
int getPosition( char *list, char el ) 
{
    return getIndex( list, el, 1 );
}

/**
    * @brief Get the Resized object
    * 
    * @param list 
    * @param start 
    * @param end 
    * @return char* 
    * *
    * return a substring stroncated from a string
*/
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

/**
    * @brief Create a Slice object
    * 
    * @param str1 
    * @param str2 
    * @return char* 
    * *
    * this function will create a temporary
    * string
*/
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

/**
    * @brief 
    * 
    * @param str1 
    * @param str2 
    * @return char* 
    * * 
    * this function will add a string to the 
    * temporary string
*/
char *addSlice( char *str1, char *str2 )
{
    int length = (int) strlen( str1 ) + (int) strlen( str2 ) + 1;
        str1 = ( char * ) realloc( str1, sizeof( char ) * length );
        strcat( str1, str2 );
    return str1;
}

#endif