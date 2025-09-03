void Led_Init(void)
{
    //zero-initialize the config structure
    gpio_config_t io_conf = {};
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set (e.g., GPIO18/19)
    io_conf.pin_bit_mask = (1ULL << LED_GPIO);
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_cinfig(&io_conf);
    //turn off LED
    Led_off();
}

void Led_On(void)
{
    gpio_set_level(LED_GPIO, LED_ACTIVE_LEVEL);
}

void Led_Off(void)
{
    gpio_set_level(LED_GPIO, !LED_ACTIVE_LEVEL);
}

void Led_Flash(uint16_t interval)
{
    static uint16_t state = 0;
    static uint16_t count = 0;
    count++;
    if(count >= interval)
    {
        count = 0;
        state = (state + 1) % 2;
        Led_State(state);
    }
}

Led_Init();

while(1)
{
    Led_Flash(50);

    vTaskDelay(pdMS_TO_TICKS(10));
}