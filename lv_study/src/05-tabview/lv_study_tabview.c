/**
 * @brief   lvgl tabview 学习demo
 * @author  Mculover666
 * @date    2022-10-16
*/

#include "../../lv_study.h"

/**
 * @brief 创建tabview，标签栏在顶部
*/
void lv_study_tabview_1_1(void)
{
    lv_obj_t *tabview = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, lv_pct(10));
}

/**
 * @brief 创建tabview，标签栏在左侧
*/
void lv_study_tabview_1_2(void)
{
    lv_obj_t *tabview = lv_tabview_create(lv_scr_act(), LV_DIR_LEFT, lv_pct(20));
}

/**
 * @brief 修改tabview大小
*/
void lv_study_tabview_1_3(void)
{
    lv_obj_t *tabview = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, lv_pct(10));

    lv_obj_set_size(tabview, lv_pct(90), lv_pct(90));
}

/**
 * @brief 添加tab页面
*/
void lv_study_tabview_2_1(void)
{
    lv_obj_t *tv = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, lv_pct(10));

    lv_obj_t *tab1 = lv_tabview_add_tab(tv, "tab1");
    lv_obj_t *tab2 = lv_tabview_add_tab(tv, "tab2");
    lv_obj_t *tab3 = lv_tabview_add_tab(tv, "tab3");
}

/**
 * @brief tab页面中添加内容
*/
void lv_study_tabview_2_2(void)
{
    lv_obj_t *tv = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, lv_pct(10));

    lv_obj_t *tab1 = lv_tabview_add_tab(tv, "tab1");
    lv_obj_t *tab2 = lv_tabview_add_tab(tv, "tab2");
    lv_obj_t *tab3 = lv_tabview_add_tab(tv, "tab3");

    lv_obj_t *label = lv_label_create(tab1);
    lv_label_set_text(label, "Hello World!");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t *btn = lv_btn_create(tab2);
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t *bar = lv_bar_create(tab3);
    lv_obj_align(bar, LV_ALIGN_CENTER, 0, 0);
}

/**
 * @brief 修改标签栏样式
*/
void lv_study_tabview_3_1(void)
{
    static lv_style_t tv_bm_style;

    lv_obj_t *tv = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, lv_pct(10));
    lv_obj_t *tv_bm = lv_tabview_get_tab_btns(tv);

    lv_obj_t *tab1 = lv_tabview_add_tab(tv, "tab1");
    lv_obj_t *tab2 = lv_tabview_add_tab(tv, "tab2");
    lv_obj_t *tab3 = lv_tabview_add_tab(tv, "tab3");

    lv_style_init(&tv_bm_style);
    lv_style_set_bg_color(&tv_bm_style, lv_color_black());
    lv_style_set_text_color(&tv_bm_style, lv_color_white());
    lv_obj_add_style(tv_bm, &tv_bm_style, 0);
}

/**
 * @brief 修改内容栏样式
*/
void lv_study_tabview_3_2(void)
{
    static lv_style_t tv_ctx_style;

    lv_obj_t *tv = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, lv_pct(10));

    lv_obj_t *tab1 = lv_tabview_add_tab(tv, "tab1");
    lv_obj_t *tab2 = lv_tabview_add_tab(tv, "tab2");
    lv_obj_t *tab3 = lv_tabview_add_tab(tv, "tab3");

    lv_style_init(&tv_ctx_style);
    lv_style_set_bg_color(&tv_ctx_style, lv_color_black());
    lv_style_set_text_color(&tv_ctx_style, lv_color_white());
    lv_obj_add_style(tv, &tv_ctx_style, 0);
}

static void tabview_changed_callback(lv_event_t * e)
{
    printf("tv changed! cur tab is %d\n", lv_tabview_get_tab_act(e->current_target));
}

/**
 * @brief 标签栏变动事件
*/
void lv_study_tabview_4_1(void)
{
    lv_obj_t *tv = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, lv_pct(10));

    lv_obj_t *tab1 = lv_tabview_add_tab(tv, "tab1");
    lv_obj_t *tab2 = lv_tabview_add_tab(tv, "tab2");
    lv_obj_t *tab3 = lv_tabview_add_tab(tv, "tab3");

    lv_obj_add_event_cb(tv, tabview_changed_callback, LV_EVENT_VALUE_CHANGED ,NULL);
}

void lv_study_tabview(void)
{
    /* create */
    //lv_study_tabview_1_1();
    //lv_study_tabview_1_2();
    //lv_study_tabview_1_3();

    /* add tab */
    //lv_study_tabview_2_1();
    //lv_study_tabview_2_2();

    /* style */
    //lv_study_tabview_3_1();
    //lv_study_tabview_3_2();

    /* event */
    lv_study_tabview_4_1();
}