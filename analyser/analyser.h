#ifndef H_ANALYSER
#define H_ANALYSER

/**
    * @brief 
    * 
    * @param data 
    * @return char* 
    * *
    * this file will group all functions
    * required to check the validity of 
    * an input
*/

#include <string.h>
#include <stdio.h>
#include "../utils/lang.h"
#include "../utils/tools.h"



/**
    * @brief Get the None List Member object
    * 
    * @param maches 
    * @param list 
    * @return char 
    * *
    * this function willreturn the first member
    * of the second list wich is not inside 
    * the first one
*/

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

/**
    * @brief 
    * 
    * @param data 
    * @return char 
    * *
    * this function will be use to check
    * if all member of the parameter are
    * the numbers if these is not the right
    * this function will return the wrong caracter
*/
char checkNoneNumber( char *data )
{
    return getNoneListMember( __NUMBERS, data );
}

char checkNoneNumberAndCaracteres( char *data )
{
    return getNoneListMember( __NUMBERS_CARACTERES, data );
}

/**
    * @brief 
    * 
    * @param item 
    * @return int 
    * *
    * test if the char parameter is a number
    * then return 0 or 1 if that's right
*/
int isNumber( char item )
{
    int 
        result = getIndex( __NUMBERS, item, 0 );
    return result > -1 ? 1 : 0;
}

/**
    * @brief 
    * 
    * @param data 
    * @return char*
    * *
    * will remove all spaces inside 
    * an expression 
*/
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

/**
    * @brief Create a Error object
    * 
    * @param message 
    * @param error 
    * @param position 
    * @return char* 
    * *
    * this function will be use to create 
    * an error which will be render to the
    * user
*/
char *createError( char *message, char error, int position )
{
    char *err = createSlice( message, (char []) { error } );
        err = createSlice( err, " at position" );
        sprintf( err, "%s %d", err, position );
    return err;
}

/**
    * @brief 
    * 
    * @param data 
    * @return char* 
    * *
    * this function will be use to 
    * check the format of the expression
*/
char *checkFormat( char *data )
{
    int length = (int) strlen( data ), i = 0;
    int sign = 0, equal = 0, innerNumber = 0, innerFloat = 0;
    int openingBraquet = 0, closingBraquet = 0, symbol = 0;
    char 
        val, other;
            for ( ; i < length; i++ )
            {
                val = data[ i ];
                
                if ( val == '*' || val == '/' ) 
                {
                    symbol++;
                    if ( i == 0 || i == length - 1 || ( data[ i - 1 ] != ')' && !isNumber( data[ i - 1 ] ) ) || data[ i - 1 ] == '=' )
                    {
                        return createError( "Invalid operator ", val, i );
                    } 
                    else if ( innerNumber ) 
                    {
                        innerNumber--;
                        if ( innerFloat )
                        {
                            innerFloat--;
                        }
                    }
                }

                if ( isNumber( val ) ) 
                {
                    innerNumber++;
                }

                if ( val == '.' )
                {
                    innerFloat++;
                    if ( !innerNumber || innerFloat > 1 || i == length -1 || !isNumber( data[ i + 1 ] ) ) {
                        return createError( "Invalid Symbol: ", val, i );
                    }
                }

                if ( val == '(' || val == ')' )
                {
                    if ( innerNumber ) 
                    {
                        innerNumber--;
                        if ( innerFloat )
                        {
                            innerFloat--;
                        }
                    } 
                    
                    if ( val == '(' )
                    {
                        openingBraquet++;
                    } 
                    else if ( val == ')' )
                    {
                        closingBraquet++;
                        if ( i == 0 || !openingBraquet || openingBraquet < closingBraquet || data[ i - 1 ] == '(' ) 
                        {
                            return createError( "Invalid Symbol: ", val, i );
                        }
                    }
                }

                if ( val == '=' )
                {
                    equal++;
                    if ( equal > 1 || i == 0 || i == length - 1 )
                    {
                        return createError( "Invalid equality: ", val, i );
                    }
                }

                if ( val == '+' || val == '-' )
                {
                    if ( i > 0 ) 
                    {
                        if ( i == length - 1 )
                        {
                            return createError( "Invalid sign: ", val, i );
                        }
                        else if ( !isNumber( data[ i - 1 ] ) && !isNumber( data[ i + 1 ] ) ) {
                            if ( data[ i + 1 ] != '(' )
                            {
                                return createError( "Invalid sign: ", val, i );   
                            }
                        }
                    }
                }
            }

            if ( openingBraquet != closingBraquet ) 
            {
                return createError( "Invalid Symbol: ", '(', i );   
            }
    return NULL;
}

/**
    * @brief 
    * 
    * @param data 
    * @return char* 
    * *
    * will change data in removing spaces
    * and if there is an error, the error,
    * will be returned
*/
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