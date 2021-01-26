#include "ruch.h"

static size_t write_callback(void *data, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;

    Memory *mem = (Memory *) userp;

    char *ptr = NULL;

    if (mem->response != NULL)
        ptr = realloc(mem->response, mem->size + realsize + 1);
    else
        ptr = malloc(mem->size + realsize + 1);

    if (ptr == NULL)
        return 0;

    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0; 

    return realsize;
}

char * make_request(char *url){
    CURL *curl;
    CURLcode res;
    Memory chunk;
    chunk.size = 0;
    chunk.response = NULL;

    cJSON * odp;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_HEADER, 1L);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            fprintf(stderr, "Błąd! curl_easy_perform() niepowodzenie: %s\n", curl_easy_strerror(res));
        else
        {
            printf("%s", chunk.response);
            //odp=chunk.response;
            //char *string=cJSON_Print(chunk.response);
            //printf("%s", string);
        }
        return chunk.response;
        free(chunk.response);
        curl_easy_cleanup(curl);
    }
}

char *url;

char * explore(char *token)
{
    asprintf(&url,"http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/explore/%s",token);
    return make_request(url);
}
char * move(char *token)
{
    asprintf(&url,"http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/move/%s",token);
    return make_request(url);
}
char * rotate_right(char *token)
{
    asprintf(&url,"http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/%s/right",token);
    return make_request(url);
}
char * rotatr_left(char *token)
{
    asprintf(&url,"http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/%s/left",token);
    return make_request(url);
}