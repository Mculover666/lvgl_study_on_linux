/**
 * @brief   lvgl第一个app——天气
 * @author  Mculover666
 * @date    2022-09-13
*/

#include "../../lv_study.h"

LV_FONT_DECLARE(source_han_sanssc_normal_20);
LV_FONT_DECLARE(ibm_plex_mono_regular_64);
LV_FONT_DECLARE(ibm_plex_mono_regular_32);

LV_IMG_DECLARE(weather_fine);
LV_IMG_DECLARE(weather_temp_logo);
LV_IMG_DECLARE(weather_humi_logo);

static lv_style_t default_style;
static lv_style_t chFont_style;
static lv_style_t clock_hour_style;
static lv_style_t clock_sec_style;

static lv_obj_t *city_label;
static lv_obj_t *level_btn;
static lv_obj_t *level_btn_label;
static lv_obj_t *txt_label;
static lv_obj_t *clock_hour_label;
static lv_obj_t *clock_sec_label;
static lv_obj_t *date_label;
static lv_obj_t *weather_img;
static lv_obj_t *temp_img;
static lv_obj_t *humi_img;

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
    lv_label_set_text(label, "最低气温12℃");
    lv_obj_set_width(label, strlen("最低气温12℃")*8);

    //长文本滚动模式
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text_fmt(label, "最低气温%d℃,最高气温%d℃,%s%d级.", 15, 20, "西北风", 0);

    //设置位置
    lv_obj_align(label, LV_ALIGN_TOP_LEFT, 0, 50);
}

void weather_level_btn_init(lv_obj_t *btn, lv_obj_t *label)
{
    /* btn */
    //orange
    lv_obj_set_style_bg_color(btn, lv_color_make(0xFF, 0Xa5, 0X00), 0);
    lv_obj_set_style_border_width(btn, 0, 0);
    lv_obj_set_pos(btn, 75, 15);
    lv_obj_set_size(btn, 50, 25);

    /* label */
    lv_obj_add_style(label, &chFont_style, 0);
    lv_label_set_recolor(label, true);
    lv_label_set_text(label, "良");
    lv_obj_set_align(label, LV_ALIGN_CENTER);
}

void weather_clock_hour_label_init(lv_obj_t *label)
{
    //字体样式
    lv_style_init(&clock_hour_style);
    lv_style_set_text_color(&clock_hour_style, lv_color_white());
    lv_style_set_text_opa(&clock_hour_style, LV_OPA_COVER);
    lv_style_set_text_font(&clock_hour_style, &ibm_plex_mono_regular_64);

    lv_obj_add_style(label, &clock_hour_style, 0);

    //使能重新着色
    lv_label_set_recolor(label, true);

    lv_label_set_text_fmt(label, "%02d#ffa500 %02d#", 10, 52);

    //设置位置
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 0, -20);
}

void weather_clock_sec_label_init(lv_obj_t *label)
{
    //字体样式
    lv_style_init(&clock_sec_style);
    lv_style_set_text_color(&clock_sec_style, lv_color_white());
    lv_style_set_text_opa(&clock_sec_style, LV_OPA_COVER);
    lv_style_set_text_font(&clock_sec_style, &ibm_plex_mono_regular_32);

    lv_obj_add_style(label, &clock_sec_style, 0);

    //使能重新着色
    lv_label_set_recolor(label, true);

    lv_label_set_text_fmt(label, "%02d", 00);

    //设置位置
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 165, -10);
}

void weather_date_label_init(lv_obj_t *label)
{
    //字体样式
    lv_obj_add_style(label, &chFont_style, 0);

    //使能重新着色
    lv_label_set_recolor(label, true);

    lv_label_set_text_fmt(label, "%2d月%2d日周%s", 9, 15, "四");

    //设置位置
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 10, 25);
}

void weather_level_img_init(lv_obj_t *img)
{
    lv_img_set_src(img, &weather_fine);

    lv_obj_align(img, LV_ALIGN_TOP_RIGHT, -10, 10);
}

void weather_temp_init(lv_obj_t *img)
{
    lv_img_set_src(img, &weather_temp_logo);

    lv_obj_align(img, LV_ALIGN_LEFT_MID, 10, 60);
}

void weather_humi_init(lv_obj_t *img)
{
    lv_img_set_src(img, &weather_humi_logo);

    lv_obj_align(img, LV_ALIGN_LEFT_MID, 6, 100);
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
    level_btn = lv_btn_create(scr_new);
    level_btn_label = lv_label_create(level_btn);
    weather_level_btn_init(level_btn, level_btn_label);

    /* 天气提示文本 */
    txt_label = lv_label_create(scr_new);
    weather_txt_label_init(txt_label);

    /* 时钟 */
    clock_hour_label = lv_label_create(scr_new);
    weather_clock_hour_label_init(clock_hour_label);
    clock_sec_label = lv_label_create(scr_new);
    weather_clock_sec_label_init(clock_sec_label);

    /* 日期 */
    date_label = lv_label_create(scr_new);
    weather_date_label_init(date_label);

    /* 天气图标 */
    weather_img = lv_img_create(scr_new);
    weather_level_img_init(weather_img);

    /* 温度指示条 */
    temp_img = lv_img_create(scr_new);
    weather_temp_init(temp_img);

    /* 湿度指示条 */
    humi_img = lv_img_create(scr_new);
    weather_humi_init(humi_img);
    
    //加载屏幕
    lv_scr_load(scr_new);
}

void lv_weather_app(void)
{
    weather_ui_init();
}

