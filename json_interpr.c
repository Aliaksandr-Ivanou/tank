#include "ruch.h"
#include "../cJSON/cJSON.h"

char * supports_full_hd(char * monitor)
{
    printf("tut1\n");
    char * string = NULL;
    cJSON *list = NULL;
    cJSON *dane = NULL;
    cJSON *odpowidz = cJSON_Parse(monitor); 
    string=cJSON_Print(odpowidz);
    printf("%s\n",string);
    if (odpowidz == NULL)
    {
        char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        goto end;
    }


    list = cJSON_GetObjectItemCaseSensitive(odpowidz, "list");
    cJSON_ArrayForEach(dane,list)
    {
        cJSON *x = cJSON_GetObjectItemCaseSensitive(dane, "x");
        cJSON *y = cJSON_GetObjectItemCaseSensitive(dane, "y");
        cJSON *type = cJSON_GetObjectItemCaseSensitive(dane, "type");
        printf("piszu\n");
        string = cJSON_Print(type);
        printf("tut\n");
        printf("%s\n",string);
    }
end:
    cJSON_Delete(dane);
}