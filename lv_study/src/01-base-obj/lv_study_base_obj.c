#include "../../lv_study.h"

static void show_obj_size(lv_obj_t *obj)
{
    lv_coord_t w = lv_obj_get_width(obj);
    lv_coord_t h = lv_obj_get_height(obj);

    printf("w is %d, h is %d\n", w, h);
}

/**
 * @brief   验证默认获取到的屏幕对象的大小
*/
void lv_study_base_obj_1_1(void)
{
    lv_obj_t *scr_act = lv_scr_act();

    show_obj_size(scr_act);
}

/**
 * @brief   验证默认对象创建的效果
*/
void lv_study_base_obj_1_2(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    //note: "w is 0, h is 0", why?
    show_obj_size(obj);
}

/**
 * @brief   设置对象大小——按像素点
*/
void lv_study_base_obj_1_3(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_set_size(obj, 400, 300);

    //note: "w is 0, h is 0", why?
    show_obj_size(obj);
}

/**
 * @brief   设置对象大小和位置——按百分比
*/
void lv_study_base_obj_1_4(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_set_size(obj, lv_pct(50), lv_pct(50));
    lv_obj_set_pos(obj, lv_pct(20), lv_pct(20));
}

/**
 * @brief   验证设置对象大小设置超出屏幕后的效果
*/
void lv_study_base_obj_1_5(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_set_size(obj, 1500, 1500);

    //note: "w is 0, h is 0", why?
    show_obj_size(obj);
}

/**
 * @brief   设置对象位置为负数
*/
void lv_study_base_obj_1_6(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_set_size(obj, lv_pct(50), lv_pct(50));
    lv_obj_set_pos(obj,  -200 , -200);
}

/**
 * @brief   默认添加多个对象
*/
void lv_study_base_obj_2_1(void)
{
    lv_obj_t *obj1 = lv_obj_create(lv_scr_act());
    lv_obj_t *obj2 = lv_obj_create(lv_scr_act());
    lv_obj_t *obj3 = lv_obj_create(lv_scr_act());
}

/**
 * @brief   在父控件内部对齐
*/
void lv_study_base_obj_2_2(void)
{
    lv_obj_t *obj1 = lv_obj_create(lv_scr_act());
    lv_obj_t *obj2 = lv_obj_create(lv_scr_act());
    lv_obj_t *obj3 = lv_obj_create(lv_scr_act());
    lv_obj_t *obj4 = lv_obj_create(lv_scr_act());
    lv_obj_t *obj5 = lv_obj_create(lv_scr_act());

    lv_obj_set_align(obj1, LV_ALIGN_TOP_LEFT);
    lv_obj_set_align(obj2, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_align(obj3, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_align(obj4, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_set_align(obj5, LV_ALIGN_CENTER);
}

/**
 * @brief   在中心控件外部对齐
*/
void lv_study_base_obj_2_3(void)
{
    lv_obj_t *obj1 = lv_obj_create(lv_scr_act());
    lv_obj_t *obj2 = lv_obj_create(lv_scr_act());
    lv_obj_t *obj3 = lv_obj_create(lv_scr_act());
    lv_obj_t *obj4 = lv_obj_create(lv_scr_act());
    lv_obj_t *obj5 = lv_obj_create(lv_scr_act());

    lv_obj_set_align(obj5, LV_ALIGN_CENTER);

    lv_obj_align_to(obj1, obj5, LV_ALIGN_OUT_TOP_MID, 0, 0);
    lv_obj_align_to(obj2, obj5, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
    lv_obj_align_to(obj3, obj5, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_align_to(obj4, obj5, LV_ALIGN_OUT_LEFT_MID, 0, 0);
}

/**
 * @brief   对象添加样式
*/
void lv_study_base_obj_3_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    static lv_style_t style;

    lv_obj_set_align(obj, LV_ALIGN_CENTER);

    lv_style_init(&style);

    //设置背景颜色
    lv_style_set_bg_color(&style, lv_color_hex(0x000000));
    //设置背景透明度
    lv_style_set_bg_opa(&style, 50);

    lv_obj_add_style(obj, &style, 0);
}

/**
 * @brief   对象添加样式——按下时样式改变
*/
void lv_study_base_obj_3_2(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    static lv_style_t style;

    lv_obj_set_align(obj, LV_ALIGN_CENTER);

    lv_style_init(&style);

    //设置背景颜色
    lv_style_set_bg_color(&style, lv_color_hex(0x000000));
    //设置背景透明度
    lv_style_set_bg_opa(&style, 50);

    lv_obj_add_style(obj, &style, LV_STATE_PRESSED);
}

/**
 * @brief   设置border的边界和颜色
*/
void lv_study_base_obj_3_3(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    static lv_style_t style;

    lv_obj_set_align(obj, LV_ALIGN_CENTER);

    lv_style_init(&style);

    lv_style_set_border_color(&style, lv_color_hex(0x000000));
    lv_style_set_border_width(&style, 5);

    lv_obj_add_style(obj, &style, 0);
}

/**
 * @brief   直接设置对象的默认样式
*/
void lv_study_base_obj_3_4(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    static lv_style_t style;

    lv_obj_set_align(obj, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), 0);
}

static void press_event_cb(lv_event_t * e)
{
    printf("press!\r\n");
}

/**
 * @brief   对象点击回调事件
*/
void lv_study_base_obj_4_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_set_align(obj, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(obj, press_event_cb, LV_EVENT_CLICKED, NULL);
}

void lv_study_base_obj(void)
{
    /* position and size */
    //lv_study_base_obj_1_1();
    //lv_study_base_obj_1_2();
    //lv_study_base_obj_1_3();
    //lv_study_base_obj_1_4();
    //lv_study_base_obj_1_5();
    //lv_study_base_obj_1_6();

    /* align */
    //lv_study_base_obj_2_1();
    //lv_study_base_obj_2_2();
    //lv_study_base_obj_2_3();

    /* style */
    //lv_study_base_obj_3_1();
    //lv_study_base_obj_3_2();
    //lv_study_base_obj_3_3();
    //lv_study_base_obj_3_4();

    /* event */
    lv_study_base_obj_4_1();
}

