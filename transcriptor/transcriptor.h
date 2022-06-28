#ifndef H_TRANSCRIPTOR
#define H_TRANSCRIPTOR

#include <string.h>
#include <stdlib.h>
#include "../utils/tools.h"
#include "lang.h"

char *getIntHand( char *list ) 
{
    int length = strlen( list );
    int point = getPosition( list, '.' ); // the position of the "." in the number
    char 
        *result;
        result = ( char * ) malloc( sizeof( char ) * ( point + 1 ) );
        strncat( result, list, point );
        result[ point ] = '\0';
    return result;
}


char *getFloatHand( char *list ) 
{
    int point = getPosition( list, '.' );
    int length = strlen( list );
    if ( point == -1 ) {
        return NULL;
    }
    char *result;
    int i = 0;
        result = ( char* ) malloc( sizeof( char ) * ( length - point ) );
            for ( ; i < length - point - 1; i++ ) 
                result[ i ] = list[ point + i + 1 ];
            result[ length - 1 ] = '\0';    
    return result;
} 

char *shiftZero( char *list )
{
    if ( list[ 0 ] != '0' )
    {
        return list;
    }

    int 
        start = 0, 
        length = strlen( list );
            for ( ; start < length; start ++ ) 
            {
                if ( list[ start ] != '0' ) 
                {
                    return getResized( list, start, length ); 
                }
            }
    return NULL;
}

char *popZero( char *list )
{
    int 
        length = strlen( list );
    if ( list[ --length ] != '0' )
    {
        return list;
    }

    for ( ; length >= 0; length-- ) 
    {
        if ( list[ length ] != '0' ) 
        {
            return getResized( list, 0, length ); 
        }
    }
    return NULL;
}

char *getSign( char sign )
{
    if ( sign == '-' )
    {
        return createSlice( __SPECIALS[ 2 ], " " );
    } else if ( sign == '+' ) 
    {
        return createSlice( __SPECIALS[ 3 ], " " );
    }
    return createSlice( "", "" );
}

char *transcriptValue( long val )
{   
    if ( val < 10 ) 
    {
        return createSlice( __UNITY[ val ], "" );
    } 
    else if ( val % 10 == 0 && val < 100 ) 
    {
        return createSlice( __TENS[ ( val / 10 ) - 1 ], "" );
    } 
    else if ( val < 20 )
    {
        return createSlice( __TWENTIES[ ( val % 10 ) - 1 ], "" );   
    }
    else if ( val < 100 ) 
    {
        char *result;
        int tens = val / 10;
            result = createSlice( __TENS[ tens - ( tens == 7 || tens == 9 ? 2 : 1 ) ], " " );
            result = addSlice( result, __SPECIALS[ 0 ] );
            result = addSlice( result, " " );
            result = addSlice( result,  ( tens == 7 || tens == 9 ) ? __TWENTIES[ val % 10 - 1 ] : __UNITY[ val % 10 ] );
        return result;
    } 
    else if ( val < 1000 )
    {
        char 
            *result;
            result = ( val / 100 ) > 1 ? createSlice( __UNITY[ val / 100 ], " " ) : createSlice( "", "" );
                result = addSlice( result, __HUNDREDS[ 0 ] );
                if ( val % 100 ) 
                {
                    result = addSlice( result, " " );
                    result = addSlice( result, transcriptValue( val % 100 ) );
                }
        return result;
    }
    else if ( val < 1000000 )
    {
        char 
            *result;
            result = ( val / 1000 ) > 1 ? transcriptValue( val / 1000 ) : createSlice( "", "" );
                result = addSlice( result, " " );
                result = addSlice( result, __HUNDREDS[ 1 ] );
                if ( val % 1000 )
                {
                    result = addSlice( result, " " );
                    result = addSlice( result, transcriptValue( val % 1000 ) );
                }
        return result;
    }
    else if ( val < 1000000000 )
    {
        char 
            *result;
            result = transcriptValue( val / 1000000 );
                result = addSlice( result, " " );
                result = addSlice( result, __HUNDREDS[ 2 ] );
                if ( val % 1000000 )
                {
                    result = addSlice( result, " " );
                    result = addSlice( result, transcriptValue( val % 1000000 ) );
                }
        return result;
    }
    else 
    {
        char 
            *result;
            result = transcriptValue( val / 1000000000 );
                result = addSlice( result, " " );
                result = addSlice( result, __HUNDREDS[ 3 ] );
                if ( val % 1000000000 )
                {
                    result = addSlice( result, " " );
                    result = addSlice( result, transcriptValue( val % 1000000000 ) );
                }
        return result;
    }
} 

char *transcriptInt( char *data )
{
    data = shiftZero( data );
    return transcriptValue( data == NULL ? 0 : atol( data ) );
}

char *transcriptFloat( char *data )
{
    int i = 0, length;
    char 
        *result,
        *zero;
        data = popZero( data );

        if ( data == NULL ) 
        {
            return transcriptValue( 0 );
        }

        result = createSlice( "", "" );
        zero = transcriptValue( 0 );
        length = strlen( data );
    for ( ; i < length; i++ )
    {
        if ( data[ i ] == '0' )  
        {
            result = addSlice( result, zero );
            result = addSlice( result, " " );
        } else 
        {
            zero = getResized( data, i, length );
            if ( !strlen( zero ) )  
            {
                return result;
            }
            return addSlice( result, transcriptInt( zero ) );
        }
    }
}

char * transcript( char * data )
{
    char *sign, *intHand, *floatHand;
        if ( data[ 0 ] == '-' || data[ 0 ] == '+' ) 
        {
            sign = getSign( data[ 0 ] );
            data = getResized( data, 1, strlen( data ) );
        } else sign = createSlice( "", "" );
        intHand = getIntHand( data );
        floatHand = getFloatHand( data );

        sign = addSlice( sign, transcriptInt( intHand ) );
        if ( floatHand != NULL )
        {
            sign = addSlice( sign, " " );
            sign = addSlice( sign, __SPECIALS[ 1 ] );
            sign = addSlice( sign, " " );
            sign = addSlice( sign, transcriptFloat( floatHand ) );
        }
    return sign;
}

#endif 