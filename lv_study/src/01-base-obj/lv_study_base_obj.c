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
void lv_study_base_obj1(void)
{
    lv_obj_t *scr_act = lv_scr_act();

    show_obj_size(scr_act);
}

/**
 * @brief   验证默认对象创建的效果
*/
void lv_study_base_obj2(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    //note: "w is 0, h is 0", why?
    show_obj_size(obj);
}

/**
 * @brief   验证设置对象大小后的效果
*/
void lv_study_base_obj3(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_set_size(obj, 400, 300);

    //note: "w is 0, h is 0", why?
    show_obj_size(obj);
}

/**
 * @brief   验证设置对象大小设置超出屏幕后的效果
*/
void lv_study_base_obj4(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());

    lv_obj_set_size(obj, 1500, 1500);

    //note: "w is 0, h is 0", why?
    show_obj_size(obj);
}

void lv_study_base_obj(void)
{
    //lv_study_base_obj1();
    //lv_study_base_obj2();
    //lv_study_base_obj3();
    lv_study_base_obj4();
}

