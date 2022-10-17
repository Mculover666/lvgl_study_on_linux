/**
 * @brief   lvgl list 学习demo
 * @author  Mculover666
 * @date    2022-10-17
*/

#include "../../lv_study.h"

/**
 * @brief 创建默认的list
*/
void lv_study_list_1_1(void)
{
    lv_obj_t *list = lv_list_create(lv_scr_act());
}

/**
 * @brief 修改list大小
*/
void lv_study_list_1_2(void)
{
    lv_obj_t *list = lv_list_create(lv_scr_act());

    lv_obj_set_size(list, lv_pct(50), lv_pct(100));
}

/**
 * @brief 添加按钮列表项
*/
void lv_study_list_2_1(void)
{
    lv_obj_t *list = lv_list_create(lv_scr_act());

    lv_obj_t* item1 = lv_list_add_btn(list, LV_SYMBOL_AUDIO, "item1");
    lv_obj_t* item2 = lv_list_add_btn(list, LV_SYMBOL_AUDIO, "item2");
    lv_obj_t* item3 = lv_list_add_btn(list, LV_SYMBOL_AUDIO, "item3");
}

/**
 * @brief 添加标签列表项
*/
void lv_study_list_2_2(void)
{
    lv_obj_t *list = lv_list_create(lv_scr_act());

    lv_obj_t* item1 = lv_list_add_text(list, "item1");
    lv_obj_t* item2 = lv_list_add_text(list, "item2");
    lv_obj_t* item3 = lv_list_add_text(list, "item3");
}

/**
 * @brief 列表项滚动
*/
void lv_study_list_2_3(void)
{
    lv_obj_t *list = lv_list_create(lv_scr_act());

    lv_obj_set_size(list, 300, 60);

    lv_obj_t* item1 = lv_list_add_btn(list, LV_SYMBOL_AUDIO, "item1");
    lv_obj_t* item2 = lv_list_add_btn(list, LV_SYMBOL_AUDIO, "item2");
    lv_obj_t* item3 = lv_list_add_btn(list, LV_SYMBOL_AUDIO, "item3");
}

/**
 * @brief 修改list控件背景色
*/
void lv_study_list_3_1(void)
{
    lv_obj_t *list = lv_list_create(lv_scr_act());

    lv_obj_t* item1 = lv_list_add_btn(list, LV_SYMBOL_AUDIO, "item1");
    lv_obj_t* item2 = lv_list_add_btn(list, LV_SYMBOL_AUDIO, "item2");
    lv_obj_t* item3 = lv_list_add_btn(list, LV_SYMBOL_AUDIO, "item3");

    lv_obj_set_style_bg_color(list, lv_color_black(), 0);
}

/**
 * @brief 修改list控件按钮样式
*/
void lv_study_list_3_2(void)
{
    static lv_style_t list_btn_style;

    lv_style_init(&list_btn_style);
    lv_style_set_bg_color(&list_btn_style, lv_color_black());
    lv_style_set_text_color(&list_btn_style, lv_color_white());

    lv_obj_t *list = lv_list_create(lv_scr_act());
    lv_obj_t* item1 = lv_list_add_btn(list, LV_SYMBOL_AUDIO, "item1");
    lv_obj_t* item2 = lv_list_add_btn(list, LV_SYMBOL_AUDIO, "item2");
    lv_obj_t* item3 = lv_list_add_btn(list, LV_SYMBOL_AUDIO, "item3");

    lv_obj_add_style(item1, &list_btn_style, 0);
    lv_obj_add_style(item2, &list_btn_style, 0);
    lv_obj_add_style(item3, &list_btn_style, 0);
}

static lv_obj_t *list_event_demo;

static void list_btn_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
        printf("btn clicked: %s\n", lv_list_get_btn_text(list_event_demo, obj));
    }
}

/**
 * @brief list控件的按钮点击事件处理
*/
void lv_study_list_4_1(void)
{
    list_event_demo = lv_list_create(lv_scr_act());
    lv_obj_t* item1 = lv_list_add_btn(list_event_demo, LV_SYMBOL_AUDIO, "item1");
    lv_obj_add_event_cb(item1, list_btn_event_handler, LV_EVENT_CLICKED, NULL);
    lv_obj_t* item2 = lv_list_add_btn(list_event_demo, LV_SYMBOL_AUDIO, "item2");
    lv_obj_add_event_cb(item2, list_btn_event_handler, LV_EVENT_CLICKED, NULL);
    lv_obj_t* item3 = lv_list_add_btn(list_event_demo, LV_SYMBOL_AUDIO, "item3");
    lv_obj_add_event_cb(item3, list_btn_event_handler, LV_EVENT_CLICKED, NULL);
}

void lv_study_list(void)
{
    /* create */
    //lv_study_list_1_1();
    //lv_study_list_1_2();

    /* add item */
    //lv_study_list_2_1();
    //lv_study_list_2_2();
    //lv_study_list_2_3();

    /* style */
    //lv_study_list_3_1();
    //lv_study_list_3_2();

    /* event */
    lv_study_list_4_1();
}