//#include <platform/cust_leds.h>
#include <cust_leds.h>
#include <platform/mt_pwm.h>
#include <platform/mt_gpio.h>

extern int DISP_SetBacklight(int level);

static struct cust_mt65xx_led cust_led_list[MT65XX_LED_TYPE_TOTAL] = {
	{"red",               MT65XX_LED_MODE_PMIC, MT65XX_LED_PMIC_NLED_ISINK0,{0}},   // have no hw, add as blue for android app need
	{"green",             MT65XX_LED_MODE_PMIC, MT65XX_LED_PMIC_NLED_ISINK1,{0}},
	{"blue",              MT65XX_LED_MODE_PMIC, MT65XX_LED_PMIC_NLED_ISINK0,{0}},
	{"jogball-backlight", MT65XX_LED_MODE_NONE, -1,{0}},
	{"keyboard-backlight",MT65XX_LED_MODE_NONE, -1,{0}},
	{"button-backlight",  MT65XX_LED_MODE_PMIC, MT65XX_LED_PMIC_BUTTON,{0}},
	{"lcd-backlight",     MT65XX_LED_MODE_PWM, PWM1,{1,5,1,1,0}},
};

struct cust_mt65xx_led *get_cust_led_list(void)
{
	return cust_led_list;
}

