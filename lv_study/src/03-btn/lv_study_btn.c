/**
 * @brief   lvgl btn 学习demo
 * @author  Mculover666
 * @date    2022-09-14
*/

#include "../../lv_study.h"

/**
 * @brief 添加默认btn
*/
void lv_study_btn_1_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *btn = lv_btn_create(obj);
}

/**
 * @brief 修改btn样式
*/
void lv_study_btn_2_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_t *btn = lv_btn_create(obj);

    //修改背景颜色
    lv_obj_set_style_bg_color(btn, lv_color_black(), 0);
    //修改透明度
    lv_obj_set_style_bg_opa(btn, 50, 0);
}

static void btn_click_event_cb(lv_event_t * e)
{
    printf("btn click!\r\n");
}

/**
 * @brief 按钮点击事件处理
*/
void lv_study_btn_3_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_t *btn = lv_btn_create(obj);

    lv_obj_add_event_cb(btn, btn_click_event_cb, LV_EVENT_CLICKED, NULL);
}

/**
 * @brief 按钮添加文字
*/
void lv_study_btn_4_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_t *btn = lv_btn_create(obj);

    //注意这里父控件是btn
    lv_obj_t *btn_label = lv_label_create(btn);

    lv_label_set_text(btn_label, "Hello");
}

void lv_study_btn(void)
{
    /* create */
    //lv_study_btn_1_1();

    /* style */
    //lv_study_btn_2_1();

    /* event */
    //lv_study_btn_3_1();
    //lv_study_btn_3_2();

    /* text */
    lv_study_btn_4_1();    
}