#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ruch.h"


int main(int argc, char **argv)
{
    char *token = argc < 2 ? "qwerty_9" : argv[1];
    char *url;
    asprintf(&url,"http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/reset/%s",token);
    make_request(url);
    printf("%s\n",supports_full_hd(explore(token)));
    return 0;
}