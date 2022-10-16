/**
 * @brief   基于lvgl的音乐播放器
 * @author  Mculover666
 * @date    2022-10-16
*/

#include "lv_music_ui.h"
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void lv_music_app(void)
{
    /* 初始化前台界面 */
    music_ui_init();
}
