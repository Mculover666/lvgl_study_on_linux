/**
 * @brief   基于lvgl的音乐播放器
 * @author  Mculover666
 * @date    2022-10-16
*/

#include "../../lv_study.h"

static lv_style_t tv_bm_style;
static lv_style_t control_panel_style;
static lv_style_t context_panel_style;

static lv_obj_t *music_bar;
static lv_obj_t *music_bar_start_label;
static lv_obj_t *music_bar_end_label;
static lv_obj_t *music_play_btn;
static lv_obj_t *music_next_btn;
static lv_obj_t *music_prev_btn;
static lv_obj_t *music_list;

char start_label_text[] = "00:00";
char end_label_text[] = "00:00";

LV_IMG_DECLARE(play_icon);
LV_IMG_DECLARE(prev_icon);
LV_IMG_DECLARE(next_icon);
LV_IMG_DECLARE(pause_icon);

/**
 * @brief   控制面板
*/
void control_panel_create(lv_obj_t *parent)
{
    lv_obj_t *panel = lv_obj_create(parent);

    lv_obj_set_size(panel, lv_pct(100), 120);
    lv_obj_align(panel, LV_ALIGN_BOTTOM_MID, 0, 0);

    lv_style_init(&control_panel_style);
    lv_style_set_bg_color(&control_panel_style, lv_color_black());
    lv_obj_add_style(panel, &control_panel_style, 0);

    //播放进度条
    music_bar = lv_bar_create(panel);
    lv_obj_set_width(music_bar, lv_pct(90));
    lv_obj_align(music_bar, LV_ALIGN_TOP_MID, 0, 0);

    //播放进度条文字
    music_bar_start_label = lv_label_create(panel);
    music_bar_end_label = lv_label_create(panel);
    lv_label_set_text_static(music_bar_start_label, start_label_text);
    lv_label_set_text_static(music_bar_end_label, end_label_text);
    lv_obj_align_to(music_bar_start_label, music_bar, LV_ALIGN_OUT_LEFT_MID, -10, 0);
    lv_obj_align_to(music_bar_end_label, music_bar, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    lv_obj_set_style_text_color(music_bar_start_label, lv_color_white(), 0);
    lv_obj_set_style_text_color(music_bar_end_label, lv_color_white(), 0);

    //播放按钮
    music_play_btn = lv_img_create(panel);
    lv_obj_set_size(music_play_btn, 48, 48);
    lv_obj_align(music_play_btn, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_img_set_src(music_play_btn, &play_icon);

    //下一曲按钮    
    music_next_btn = lv_img_create(panel);
    lv_obj_set_size(music_next_btn, 48, 48);
    lv_obj_align(music_next_btn, LV_ALIGN_BOTTOM_MID, 96, 0);
    lv_img_set_src(music_next_btn, &next_icon);

    //上一曲按钮
    music_prev_btn = lv_img_create(panel);
    lv_obj_set_size(music_prev_btn, 48, 48);
    lv_obj_align(music_prev_btn, LV_ALIGN_BOTTOM_MID, -96, 0);
    lv_img_set_src(music_prev_btn, &prev_icon);
}

/**
 * @brief   播放内容面板
*/
void context_panel_create(lv_obj_t *parent)
{
    lv_obj_t *panel = lv_obj_create(parent);

    lv_obj_set_size(panel, lv_pct(100), 375);
    lv_obj_align(panel, LV_ALIGN_TOP_MID, 0, 0);

    lv_style_init(&context_panel_style);
    lv_style_set_bg_color(&context_panel_style, lv_color_black());
    lv_obj_add_style(panel, &context_panel_style, 0);
}

/**
 * @brief   播放界面
*/
void tab_main_create(lv_obj_t *parent)
{
    //控制面板
    control_panel_create(parent);

    //内容面板
    context_panel_create(parent);
}

static void list_btn_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
        printf("btn clicked: %s\n", lv_list_get_btn_text(music_list, obj));
    }
}

/**
 * @brief   列表界面
*/
void tab_list_create(lv_obj_t *parent)
{
    int i;
    lv_obj_t* t;
    static lv_style_t list_btn_style;

    music_list = lv_list_create(parent);
    lv_obj_set_size(music_list, lv_pct(100), lv_pct(100));
    lv_obj_set_style_bg_color(music_list, lv_color_black(), 0);

    lv_style_init(&list_btn_style);
    lv_style_set_bg_color(&list_btn_style, lv_color_black());
    lv_style_set_text_color(&list_btn_style, lv_color_white());

    
    for (i = 0; i < 30; i++) {
        t = lv_list_add_btn(music_list, LV_SYMBOL_AUDIO, "item");
        lv_obj_add_style(t, &list_btn_style, 0);
        lv_obj_add_event_cb(t, list_btn_event_handler, LV_EVENT_CLICKED, NULL);
    }
}

/**
 * @brief   tabview
*/
void tv_create(lv_obj_t *parent)
{
    // 创建tabview
    lv_obj_t *tv = lv_tabview_create(parent, LV_DIR_TOP, 60);
    lv_obj_set_style_bg_color(tv, lv_color_black(), 0);
    lv_style_init(&tv_bm_style);
    lv_style_set_bg_color(&tv_bm_style, lv_color_black());
    lv_style_set_text_color(&tv_bm_style, lv_color_white());
    lv_obj_add_style(lv_tabview_get_tab_btns(tv), &tv_bm_style, 0);

    // 创建tab
    lv_obj_t *tab_main = lv_tabview_add_tab(tv, "MUSIC");
    lv_obj_t *tab_list = lv_tabview_add_tab(tv, "LIST");
    lv_obj_t *tab_about = lv_tabview_add_tab(tv, "ABOUT");

    tab_main_create(tab_main);
    tab_list_create(tab_list);
}

void music_ui_init(void)
{
    tv_create(lv_scr_act());
}