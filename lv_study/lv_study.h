/**
 * @file    lv_study.h
 */

#ifndef LV_STUDY_H
#define LV_STUDY_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "../lvgl/lvgl.h"
#endif


#include "src/01-base-obj/lv_study_base_obj.h"
#include "src/02-label/lv_study_label.h"
#include "src/03-btn/lv_study_btn.h"
#include "src/04-bar/lv_study_bar.h"
#include "src/05-tabview/lv_study_tabview.h"
#include "src/06-list/lv_study_list.h"

#include "src/weather-app/lv_weather_app.h"

/*********************
 *      DEFINES
 *********************/
/*Test  lvgl version*/
#if LV_VERSION_CHECK(8, 0, 0) == 0
#error "lv_demo: Wrong lvgl version"
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/


/**********************
 *      MACROS
 **********************/


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_STUDY_H*/
