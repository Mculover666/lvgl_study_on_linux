/**
 * @brief   lvgl第一个app——天气
 * @author  Mculover666
 * @date    2022-09-13
*/

#include "lv_weather_ui.h"
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void *lv_weather_thread(void *args)
{
    long t;
    struct tm *ptm;
    int y,m,d,h,n,s, w;

    printf("lv weather thread start!\n");

    while (1) {
        /* 更新时间 */
        t = time(NULL);
        ptm = localtime(&t);

        y   =   ptm-> tm_year+1900;     //年
        m   =   ptm-> tm_mon+1;             //月
        d   =   ptm-> tm_mday;               //日
        h   =   ptm-> tm_hour;               //时
        n   =   ptm-> tm_min;                 //分
        s   =   ptm-> tm_sec;                 //秒
        w = ptm->tm_wday;   //周

        //printf("%d-%d-%d %d:%d:%d %d\n", y, m, d, h, n, s, w);
        weather_ui_update_time(h, n, s);
        weather_ui_update_date(m, d, w);
        sleep(1);
    }
}

void lv_weather_app(void)
{
    pthread_t id;

    /* 初始化前台界面 */
    weather_ui_init();

    /* 创建线程调度后台逻辑 */
    int res = pthread_create(&id, NULL, lv_weather_thread, NULL);
    assert(res == 0);
}
