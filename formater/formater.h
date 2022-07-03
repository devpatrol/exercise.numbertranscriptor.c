#ifndef H_FORMATER
#define H_FORMATER

#include <string.h>
#include "../analyser/analyser.h"
#include "../transcriptor/transcriptor.h"
#include "../utils/tools.h"

char *formatPart( char *data )
{
    int i = 0, length = strlen( data ), numb = -1, factor = 0, start = 0;
    char *part, *result = createSlice( "", "" );

    for ( ; i < length; i++ )
    {

        if ( isNumber( data[ i ] ) && !factor ) 
        {
            if ( numb == -1 )
            {
                numb = i;
            }
        } 
        else
        {
            if ( numb != -1 && !factor && data[ i ] != '.' )
            {
                part = getResized( data, numb, i-1 );
                result = addSlice( result, transcript( part ) );
                result = addSlice( result, " " );
                numb = -1;
            }

            if ( data[ i ] == '(' || data[ i ] == ')' ) {
                if ( data[ i ] == '('  )
                {
                    if ( !factor ) 
                    {
                        start = i;
                    }
                    factor++;
                } 
                else
                {
                    factor--;
                    if ( !factor )
                    {
                        part = getResized( data, start + 1, i - 1 );
                        result = addSlice( result, transcriptSymbol( data[ start ] ) );
                        result = addSlice( result, " " );
                        result = addSlice( result, formatPart( part ) );
                    }
                }
            }
            else if ( data[ i ] != '.' && !factor )
            {
                result = addSlice( result, transcriptSymbol( data[ i ] ) );
                result = addSlice( result, " " );
            }
        }
    }

    if ( numb != -1 )
    {
        part = getResized( data, numb, length - 1 );
        result = addSlice( result, transcript( part ) );
        result = addSlice( result, " " );
    }

    return result;
}

char *format( char *data )
{
    int res = getPosition( data, '=' );
    char *result, *sub;
        if ( res == -1 )
        {
            return formatPart( data );
        }

        result = createSlice( "", "" );

        sub = getResized( data, 0, res - 1 );
        result = addSlice( result, formatPart( sub ) );

        result = addSlice( result, transcriptSymbol( data[ res ] ) );
        result = addSlice( result, " " );

        sub = getResized( data, res + 1 , strlen( data ) - 1 );
        result = addSlice( result, formatPart( sub ) );
    return result;
}

#endif