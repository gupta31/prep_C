#include <stdio.h>
#include<stdlib.h>

typedef enum{false,true} bool;
bool is_delim(char c, const char *delim)
{
    while(*delim != '\0')
    {
        if(c == *delim)
            return true;
        delim++;
    }
    return false;
}
char *my_strcpy(char * dest,const char * src)
{
    int i;
    for(int i=0;src[i]!='\0';i++)
    {
        dest[i]=src[i];
    }
    dest[i]='\0';
    return dest;
}

char *my_strtok(const char * const src, const char *const delim)
{
    static char *copySrcString = NULL; // Create copy of the original String
    static char *token_string = NULL; // start of the next search
    static char *tmp = NULL; //store beg address


    if (src != NULL)
    {
        copySrcString = (copySrcString == NULL)?malloc(sizeof(char)*25):NULL;
        if(*copySrcString == 0)
        {
            tmp = copySrcString;
            
            my_strcpy(copySrcString,src);
        }
    }
    

    if(!src)
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
    char src[] = "Sanchi-gupta-hello-world";
    char *delim = "-";
    char *copySrcString = my_strtok(src, delim);
    while(copySrcString)
    {
        printf("%s\n", copySrcString);
        copySrcString = my_strtok(NULL, delim);
    }

    printf("Original String: %s\n", src);

    return 0;
}

