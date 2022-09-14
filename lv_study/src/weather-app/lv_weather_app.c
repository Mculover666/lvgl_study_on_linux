/**
 * @brief   lvgl第一个app——天气
 * @author  Mculover666
 * @date    2022-09-13
*/

#include "../../lv_study.h"

LV_FONT_DECLARE(source_han_sanssc_normal_20);

static lv_style_t default_style;
static lv_style_t chFont_style;

static lv_obj_t *city_label;
static lv_obj_t *txt_label;

void weather_city_label_init(lv_obj_t *label)
{
    //字体样式
    lv_style_init(&chFont_style);
    lv_style_set_text_opa(&chFont_style, LV_OPA_COVER);
    lv_style_set_text_color(&chFont_style, lv_color_white());
    lv_style_set_text_font(&chFont_style, &source_han_sanssc_normal_20);
    lv_obj_add_style(label, &chFont_style, 0);

    //使能重新着色
    lv_label_set_recolor(label, true);

    //设置默认文字
    lv_label_set_text(label, "上海");

    //设置位置
    lv_obj_align(label, LV_ALIGN_TOP_LEFT, 20, 15);
}

void weather_txt_label_init(lv_obj_t *label)
{
    //字体样式
    lv_obj_add_style(label, &chFont_style, 0);

    //使能重新着色
    lv_label_set_recolor(label, true);

    //设置默认文字
    lv_label_set_text(txt_label, "最低气温12℃");
    lv_obj_set_width(txt_label, strlen("最低气温12℃")*8);

    //长文本滚动模式
    lv_label_set_long_mode(txt_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text_fmt(txt_label, "最低气温%d℃,最高气温%d℃,%s%d级.", 15, 20, "西北风", 0);

    //设置位置
    lv_obj_align(label, LV_ALIGN_TOP_LEFT, 0, 50);
}

void weather_ui_init(void)
{
    lv_obj_t *scr = lv_scr_act();
    if (!scr) {
        return;
    }

    /* 清空当前页面 */
    lv_obj_clean(scr);

    /* 创建屏幕 */
    lv_obj_t *scr_new = lv_obj_create(NULL);
    lv_style_init(&default_style);
    lv_style_set_bg_color(&default_style, lv_color_black());
    lv_obj_add_style(scr_new, &default_style, 0);

    /* 城市 */
    city_label = lv_label_create(scr_new);
    weather_city_label_init(city_label);

    /* 空气质量等级 */
    txt_label = lv_label_create(scr_new);
    weather_txt_label_init(txt_label);

    /* 天气提示文本 */


    //加载屏幕
    lv_scr_load(scr_new);
}

void lv_weather_app(void)
{
    weather_ui_init();
}

