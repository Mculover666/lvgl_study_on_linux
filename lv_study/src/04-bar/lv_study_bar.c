/**
 * @brief   lvgl bar 学习demo
 * @author  Mculover666
 * @date    2022-10-04
*/

#include "../../lv_study.h"

/**
 * @brief 添加默认bar
*/
void lv_study_bar_1_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *bar = lv_bar_create(obj);
}

/**
 * @brief 设置bar的宽度
*/
void lv_study_bar_2_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *bar = lv_bar_create(obj);

    lv_obj_set_width(bar, 50);
}

/**
 * @brief 设置bar的高度
*/
void lv_study_bar_2_2(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *bar = lv_bar_create(obj);

    lv_obj_set_width(bar, 50);
    lv_obj_set_height(bar, 30);
}

/**
 * @brief 垂直放置的进度条
*/
void lv_study_bar_2_3(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *bar = lv_bar_create(obj);

    lv_obj_set_size(bar, 10, 60);
}

/**
 * @brief 获取bar的所有值
*/
void lv_study_bar_3_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *bar = lv_bar_create(obj);

    lv_obj_set_width(bar, 50);

    printf("cur value: %d\n", lv_bar_get_value(bar));
    printf("start value: %d\n", lv_bar_get_start_value(bar));
    printf("min value: %d\n", lv_bar_get_min_value(bar));
    printf("max value: %d\n", lv_bar_get_max_value(bar));
    printf("cur mode: %d\n", lv_bar_get_mode(bar));
}

/**
 * @brief 设置bar的当前值
*/
void lv_study_bar_3_2(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *bar = lv_bar_create(obj);

    lv_obj_set_width(bar, 50);

    lv_bar_set_value(bar, 60, LV_ANIM_OFF);
}

/**
 * @brief 设置bar的模式
*/
void lv_study_bar_3_3(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *bar = lv_bar_create(obj);

    lv_obj_set_width(bar, 50);

    lv_bar_set_range(bar, -50, 50);
    lv_bar_set_mode(bar, LV_BAR_MODE_RANGE);
    lv_bar_set_value(bar, 0, LV_ANIM_OFF);
}

/**
 * @brief 设置bar的起始值
*/
void lv_study_bar_3_4(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *bar = lv_bar_create(obj);

    lv_obj_set_width(bar, 50);

    lv_bar_set_value(bar, 60, LV_ANIM_OFF);
    lv_bar_set_start_value(bar, 30, LV_ANIM_OFF);
}

/**
 * @brief 设置bar的背景
*/
void lv_study_bar_4_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_t *bar = lv_bar_create(obj);
    static lv_style_t main_style;

    lv_obj_set_width(bar, 50);
    lv_bar_set_value(bar, 60, LV_ANIM_OFF);

    lv_style_init(&main_style);
    lv_style_set_bg_color(&main_style, lv_color_black());
    lv_obj_add_style(bar, &main_style, LV_PART_MAIN);
}

/**
 * @brief 设置bar的指针样式
*/
void lv_study_bar_4_2(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_t *bar = lv_bar_create(obj);
    static lv_style_t indi_style;

    lv_obj_set_width(bar, 50);
    lv_bar_set_value(bar, 60, LV_ANIM_OFF);

    lv_style_init(&indi_style);
    lv_style_set_bg_color(&indi_style, lv_color_black());
    lv_obj_add_style(bar, &indi_style, LV_PART_INDICATOR);
}

static void bar_draw_finish_event_cb(lv_event_t * e)
{
    printf("draw finish!");
}

/**
 * @brief 设置bar的事件
*/
void lv_study_bar_5_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_t *bar = lv_bar_create(obj);

    lv_obj_set_width(bar, 50);
    lv_bar_set_value(bar, 60, LV_ANIM_OFF);

    lv_obj_add_event_cb(bar, bar_draw_finish_event_cb, LV_EVENT_DRAW_PART_END, NULL);
}


void lv_study_bar(void)
{
    /* create */
    //lv_study_bar_1_1();

    /* size */
    //lv_study_bar_2_1();
    //lv_study_bar_2_2();
    //lv_study_bar_2_3();

    /* value */
    //lv_study_bar_3_1();
    //lv_study_bar_3_2();
    //lv_study_bar_3_3();
    //lv_study_bar_3_4();

    /* style */
    //lv_study_bar_4_1();
    //lv_study_bar_4_2();

    /* event */
    lv_study_bar_5_1();
}