/**
 * @brief   lvgl label 学习demo
 * @author  Mculover666
 * @date    2022-09-10
*/

#include "../../lv_study.h"

/**
 * @brief 添加默认label
*/
void lv_study_label_1_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);
}

/**
 * @brief 设置label文本，文本会动态申请内存
*/
void lv_study_label_1_2(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_label_set_text(label, "Hello World!");
}

/**
 * @brief 格式化设置label文本，文本会动态申请内存
*/
void lv_study_label_1_3(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_label_set_text_fmt(label, "%s:%d", "value", 88);
}

/**
 * @brief 静态设置label文本，该文本不会被label保存，需要确保label存在的时候，文本处于可用状态
*/
void lv_study_label_1_4(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_label_set_text_static(label, "Mculover666");
}

/**
 * @brief label显示文字换行
*/
void lv_study_label_1_5(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_label_set_text(label, "Mculover666\nHelloWorld");
}

/**
 * @brief 获取label文本
*/
void lv_study_label_1_6(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_label_set_text(label, "Hello World!");

    printf("text:[%s]\n", lv_label_get_text(label));
}

/**
 * @brief label默认长文本模式
*/
void lv_study_label_2_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_obj_set_size(obj, 200, 200);
    lv_obj_set_size(label, 100, 30);

    lv_label_set_text(label, "HelloWorld!1234567890!");
}

/**
 * @brief label设置长文本模式为显示省略号
*/
void lv_study_label_2_2(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_obj_set_size(obj, 200, 200);
    lv_obj_set_size(label, 100, 30);

    lv_label_set_long_mode(label, LV_LABEL_LONG_DOT);

    lv_label_set_text(label, "HelloWorld!1234567890!");
}

/**
 * @brief label设置长文本模式为来回滚动
*/
void lv_study_label_2_3(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_obj_set_size(obj, 200, 200);
    lv_obj_set_size(label, 100, 30);

    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL);

    lv_label_set_text(label, "HelloWorld!1234567890!");
}

/**
 * @brief label设置长文本模式为循环滚动
*/
void lv_study_label_2_4(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_obj_set_size(obj, 200, 200);
    lv_obj_set_size(label, 100, 30);

    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);

    lv_label_set_text(label, "HelloWorld!1234567890!");
}

/**
 * @brief label设置长文本模式为截断
*/
void lv_study_label_2_5(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_obj_set_size(obj, 200, 200);
    lv_obj_set_size(label, 100, 30);

    lv_label_set_long_mode(label, LV_LABEL_LONG_CLIP);

    lv_label_set_text(label, "HelloWorld!1234567890!");
}

/**
 * @brief label设置文本颜色
*/
void lv_study_label_3_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_obj_set_size(obj, 200, 200);
    lv_obj_set_size(label, 100, 30);
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(label, "HelloWorld!1234567890!");

    lv_obj_set_style_text_color(label, lv_color_hex(0x50fa7b), 0);
}

/**
 * @brief label设置背景色
*/
void lv_study_label_3_2(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_obj_set_size(obj, 200, 200);
    lv_obj_set_size(label, 100, 30);
    lv_label_set_text(label, "123");

    lv_obj_set_style_bg_color(label, lv_color_hex(0x50fa7b), 0);
    lv_obj_set_style_bg_opa(label, 100, 0);
}

/**
 * @brief label设置文字重新着色
*/
void lv_study_label_3_3(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_obj_set_size(obj, 200, 200);
    lv_obj_set_size(label, 100, 30);
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    
    lv_label_set_recolor(label, true);
    lv_label_set_text(label, "#50fa7b HelloWorld!# 1234567890!");
}

/**
 * @brief label显示单个图标
*/
void lv_study_label_4_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_label_set_text(label, LV_SYMBOL_OK);
}

/**
 * @brief label图标和字符串共用
*/
void lv_study_label_4_2(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_obj_set_size(obj, 200, 200);
    lv_obj_set_size(label, 100, 30);

    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);

    lv_label_set_text(label, LV_SYMBOL_USB "usb charing...");
}

/**
 * @brief label显示多个图标
*/
void lv_study_label_4_3(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label = lv_label_create(obj);

    lv_obj_set_size(obj, 200, 200);
    lv_obj_set_size(label, 100, 30);

    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);

    lv_label_set_text(label, LV_SYMBOL_GPS LV_SYMBOL_WIFI LV_SYMBOL_BLUETOOTH LV_SYMBOL_BELL LV_SYMBOL_BATTERY_FULL);
}

/**
 * @brief label设置不同的字体
*/
void lv_study_label_5_1(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_t *label1 = lv_label_create(obj);
    lv_obj_t *label2 = lv_label_create(obj);
    lv_obj_t *label3 = lv_label_create(obj);

    lv_obj_set_size(obj, 600, 600);

    lv_obj_set_pos(label1, 0, 0);
    lv_obj_set_pos(label2, 0, 100);
    lv_obj_set_pos(label3, 0, 200);

    lv_label_set_text(label1, "font14");
    lv_label_set_text(label2, "font28");
    lv_label_set_text(label3, "font48");

    lv_obj_set_style_text_font(label1, &lv_font_montserrat_14, 0);
    lv_obj_set_style_text_font(label2, &lv_font_montserrat_28, 0);
    lv_obj_set_style_text_font(label3, &lv_font_montserrat_48, 0);
}

/**
 * @brief label使用思源字体
*/
void lv_study_label_5_2(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_t *label1 = lv_label_create(obj);

    lv_obj_set_size(obj, 400, 200);

    lv_label_set_text(label1, "www.mculover666.cn 嵌入式宝藏站");
    lv_obj_set_style_text_font(label1, &lv_font_simsun_16_cjk, 0);
}

LV_FONT_DECLARE(source_han_sanssc_light_14);

/**
 * @brief label使用思源黑体-Light
*/
void lv_study_label_5_3(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_t *label1 = lv_label_create(obj);

    lv_obj_set_size(obj, 400, 200);

    lv_label_set_text(label1, "www.mculover666.cn 嵌入式宝藏站");
    lv_obj_set_style_text_font(label1, &source_han_sanssc_light_14, 0);
}

void lv_study_label(void)
{
    /* label text set and get */
    //lv_study_label_1_1();
    //lv_study_label_1_2();
    //lv_study_label_1_3();
    //lv_study_label_1_4();
    //lv_study_label_1_5();
    //lv_study_label_1_6();

    /* label long text mode */
    //lv_study_label_2_1();
    //lv_study_label_2_2();
    //lv_study_label_2_3();
    //lv_study_label_2_4();
    //lv_study_label_2_5();

    /* label style */
    //lv_study_label_3_1();
    //lv_study_label_3_2();
    //lv_study_label_3_3();

    /* lvgl icon */
    //lv_study_label_4_1();
    //lv_study_label_4_2();
    //lv_study_label_4_3();

    /* font */
    //lv_study_label_5_1();
    //lv_study_label_5_2();
    lv_study_label_5_3();

}