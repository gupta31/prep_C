#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include<stdlib.h>
bool is_delim(char c, char *delim)
{
    while(*delim != '\0')
    {
        if(c == *delim)
            return true;
        delim++;
    }
    return false;
}

char *my_strtok(const char * const srcBuffer, const char *const delim)
{
    static char *copySrcString = NULL; // Create copy of the original String
    static char *token_string = NULL; // start of the next search
    static char *tmp = NULL; //store beg address


    if (srcBuffer != NULL)
    {
        const unsigned int srcBufferLen = strlen(srcBuffer);

        copySrcString = (copySrcString == NULL)?calloc(sizeof(char), srcBufferLen +1):copySrcString;
        if(*copySrcString == 0)
        {
            tmp = copySrcString;
            
            memcpy(copySrcString,srcBuffer,srcBufferLen);
        }
    }
    

    if(!srcBuffer)
    {
        copySrcString = token_string;
    }
    if(!copySrcString)
    {
        tmp = NULL;
        token_string = NULL;
        return NULL;
    }

    while(1)
    {
        if(is_delim(*copySrcString, delim))
        {
            copySrcString++;
            continue;
        }
        if(*copySrcString == '\0')
        {
            free(tmp);
            copySrcString = NULL;
            token_string = NULL;
            return NULL;
        }
        break;
    }

    char *ret = copySrcString;
    while(1)
    {
        if(*copySrcString == '\0')
        {
            token_string = copySrcString;
            return ret;
        }
        if(is_delim(*copySrcString, delim))
        {
            *copySrcString = '\0';
            token_string = copySrcString + 1;
            return ret;
        }
        copySrcString++;
    }
}

int main()
{
    char srcBuffer[] = "Sanchi-gupta-hello-world";
    char *delim = "-";
    char *copySrcString = my_strtok(srcBuffer, delim);
    while(copySrcString)
    {
        printf("%s\n", copySrcString);
        copySrcString = my_strtok(NULL, delim);
    }

    //printf("Original String %s\n", srcBuffer);

    return 0;
}
