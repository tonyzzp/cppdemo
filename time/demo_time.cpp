#include <stdio.h>
#include "help.h"
#include <time.h>

int main()
{
    printf("hello demo_time\n");

    time_t now = time(0);
    printf("time() = %ld\n", now);

    time_t c = clock();
    printf("clock() = %ld\n", c);

    tm *l_time = localtime(&now);
    printf("localtime() = %04d-%02d-%02d %02d:%02d:%02d\n", l_time->tm_year + 1900, l_time->tm_mon + 1, l_time->tm_mday, l_time->tm_hour, l_time->tm_min, l_time->tm_sec);

    tm *gm_time = gmtime(&now);
    printf("gmtime(now) = %04d-%02d-%02d %02d:%02d:%02d\n", gm_time->tm_year + 1900, gm_time->tm_mon + 1, gm_time->tm_mday, gm_time->tm_hour, gm_time->tm_min, gm_time->tm_sec);

    {
        struct tm t;
        t.tm_year = 2022 - 1900;
        t.tm_mon = 11 - 1;
        t.tm_mday = 25;
        t.tm_hour = 0;
        t.tm_min = 0;
        t.tm_sec = 0;
        time_t v = mktime(&t);
        printf("mktime(2022-11-25) = %ld, wday=%d\n", v, t.tm_wday);
    }

    {
        time_t t = 0;
        tm *gm_time = gmtime(&t);
        printf("gmtime(0) = %04d-%02d-%02d %02d:%02d:%02d\n", gm_time->tm_year + 1900, gm_time->tm_mon + 1, gm_time->tm_mday, gm_time->tm_hour, gm_time->tm_min, gm_time->tm_sec);
    }

    {
        char buf[20];
        time_t now = time(0);
        tm* m = localtime(&now);
        strftime(buf, 20, "%Y-%m-%d %H:%M:%S", m);
        printf("strftime() = %s\n", buf);
    }

    return 0;
}