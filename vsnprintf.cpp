/* vsnprintf example */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
void PrintFError ( const char * format, ... )
{
    char buffer[256] ;
    va_list args;
    snprintf(buffer,256,"himanshu");
    va_start (args, format);
    vsnprintf (buffer+strlen(buffer),256-strlen(buffer),format, args);
    perror (buffer);
    va_end (args);
}

int main ()
{
    FILE * pFile;
    char szFileName[]="myfile.txt";

    pFile = fopen (szFileName,"r");
    if (pFile == NULL)
        PrintFError ("Error opening '%s'",szFileName);
    else
    {
        //file successfully open
        fclose (pFile);
    }
    return 0;
}
