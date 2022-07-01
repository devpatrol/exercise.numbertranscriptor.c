#ifndef H_ANALYSER
#define H_ANALYSER

#include <string.h>
#include "../utils/lang.h"
#include "../utils/tools.h"

char getNoneListMember( char *maches, char *list )
{
    int i = 0;
    char result = '\0';
        for ( i = 0; i < strlen( list ); i++ )
        {
            if ( getIndex( maches, list[ i ], 0 ) == -1 )
            {
                return list[ i ];
            }
        }
    return result;
}

char checkNoneNumber( char *data )
{
    return getNoneListMember( __NUMBERS, data );
}

int isNumber( char item )
{
    int 
        result = getIndex( __NUMBERS, item, 0 );
    return result > -1 ? 1 : 0;
}

char checkNoneCaracteres( char *data )
{
    return getNoneListMember( __SPECIAL_CARACTERES, data );
}

char checkNoneNumberAndCaracteres( char *data )
{
    return getNoneListMember( __NUMBERS_CARACTERES, data );
}

char *removeSpaceAndNotNeeded( char *data )
{
    char *result;
    int i = 0, j;
    int length = (int) strlen( data );
    int new_length = length;
        for ( ; i < length; i++ )
        {
            if ( data[ i ] == ' '  )
            {
                j = i;
                for ( ; j < new_length - 1; j++ )
                {
                    data[ j ] = data[ j + 1 ];
                }
                
                data[ --new_length ] = '\0';

                if ( i > 0 )
                {
                    if ( i + 1 < length )
                    {
                        if ( isNumber( data[ i - 1 ] ) && isNumber( data[ i ] ) )
                        {
                            result = createSlice( "Invalid entry ", (char []) { data[ i - 1 ] } );
                            result = addSlice( result, " " );
                            result = addSlice( result, (char []) { data[ i ] } );
                            return result;
                        } 
                        else if ( ( data[ i - 1 ] == '.' || data[ i ] == '.' ) && ( isNumber( data[ i - 1 ] ) || isNumber( data[ i ] ) ) )
                        {
                            result = createSlice( "Invalid entry ", (char []) { data[ i - 1 ] } );
                            result = addSlice( result, " " );
                            result = addSlice( result, (char []) { data[ i ] } );
                            return result;
                        } 
                    }
                }

                if ( data[ i ] == ' ' ) 
                {
                    return removeSpaceAndNotNeeded( data );
                }
            }
        }
    return NULL;
}

char *checkFormat( char *data )
{
    int length = (int) strlen( data ), i = 0;
    int sign = 0, equal = 0, innerNumber = 0, innerFloat = 0;
    int openingBraquet = 0, closingBraquet = 0, symbol = 0;
    char 
        *err, val;
            for ( ; i < length; i++ )
            {
                val = data[ i ];
                if ( val == ')' )
                {
                    closingBraquet++;
                    if ( openingBraquet < closingBraquet )
                    {
                        err = createSlice( "Error: ) without (", "" );
                        return err;
                    }
                }

                if ( val == '(' ) 
                {
                    openingBraquet++;
                    if ( innerNumber ) 
                    {
                        innerNumber--;
                    }

                    if ( innerFloat ) 
                    {
                        innerFloat--;
                    }
                }

                if ( isNumber( val ) )
                {
                    if ( !innerNumber )
                    {
                        innerNumber++;
                        if ( sign ) 
                        {
                            sign--;
                        }
                    }
                }

                if ( val == '.' )
                {
                    innerFloat++;
                    if ( !innerNumber || innerFloat > 1 )
                    {
                        err = createSlice( "Invalid float sign ", (char []) { val } );
                            err = createSlice( err, " at position" );
                            sprintf( err, "%s %d", err, i );
                        return err;
                    }
                }

                if ( val == '+' || val == '-' )
                {
                    sign++;
                    if ( sign >= 3 ) 
                    {
                        err = createSlice( "Invalid sign ", (char []) { val } );
                            err = createSlice( err, " at position" );
                            sprintf( err, "%s %d", err, i );
                        return err;
                    }

                    if ( symbol ) {
                        symbol--;
                    }
                }

                if ( val == '*' || val == '/' ) 
                {
                    symbol++;

                    if ( symbol > 1 )
                    {
                        err = createSlice( "Invalid sign ", (char []) { val } );
                            err = createSlice( err, " at position" );
                            sprintf( err, "%s %d", err, i );
                        return err;
                    }

                    if ( sign )
                    {
                        err = createSlice( "Invalid sign ", (char []) { val } );
                            err = createSlice( err, " at position" );
                            sprintf( err, "%s %d", err, i );
                        return err;   
                    }

                    if ( innerNumber ) 
                    {
                        innerNumber--;
                    }

                    if ( innerFloat ) 
                    {
                        innerFloat--;
                    }
                }
            }
    return NULL;
}

char *analyse( char *data )
{
    char 
        *err, sub;
            sub = checkNoneNumberAndCaracteres( data );

            if ( sub != '\0' )
            {
                err = createSlice( "", "" );
                    err = addSlice( err, "Invalid caractere: " );
                    err = addSlice( err, (char []) { sub } );
                return err;
            }

            err = removeSpaceAndNotNeeded( data );

            if ( err != NULL ) 
            {
                return err;
            }

            err = checkFormat( data );

            if ( err != NULL ) 
            {
                return err;
            }
    return err;
}

#endif