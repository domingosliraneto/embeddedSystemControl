#include "pwm.h"

PWM::PWM(gpio_num_t pin, uint16_t freq)
{
    ledc_timer.bit_num = LEDC_TIMER_13_BIT;
    ledc_timer.freq_hz = 5000;
    ledc_timer.speed_mode = LEDC_HIGH_SPEED_MODE;
    ledc_timer.timer_num = LEDC_TIMER_0;
    // Set configuration of timer0 for high speed channels
    ledc_timer_config(&ledc_timer);

	ledc_channel.duty       = 0; 
	ledc_channel.channel    = LEDC_CHANNEL_0;
	ledc_channel.gpio_num   = pin;
	ledc_channel.timer_sel  = LEDC_TIMER_0;
	ledc_channel.speed_mode = LEDC_HIGH_SPEED_MODE;
	ledc_channel_config(&ledc_channel);
}

void PWM::update(uint16_t duty)
{
	ledc_channel.duty       = duty; 
	ledc_set_duty(ledc_channel.speed_mode, ledc_channel.channel, duty);
	ledc_update_duty(ledc_channel.speed_mode, ledc_channel.channel);
}