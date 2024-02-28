#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    struct tm tm;
    char buf[255];
    memset(&tm, 0, sizeof(struct tm));
    // "*-* 8:0"
    strptime("*-*-* *:*:00","%y-%m-%d %H:%M:%S", &tm);
    strftime(buf, sizeof(buf), "%y-%m-%d %H:%M:%S", &tm);
    printf("%s\n", buf);
}