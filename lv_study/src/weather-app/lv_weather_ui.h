#ifndef LV_WEATHER_UI
#define LV_WEATHER_UI

#ifdef __cplusplus
extern "C" {
#endif

void weather_ui_init(void);
void weather_ui_update_time(int h, int m, int s);
void weather_ui_update_date(int year, int month, int day);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LV_WEATHER_UI */
