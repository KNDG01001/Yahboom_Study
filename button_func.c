void key_Init(void){
    //zero-initialize the config structure
    gpio_config_t io_conf = {};
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as input mode
    io_conf.mode = GPIO_MODE_INPUT;
    //bit mask of the pins that you want to set (e.g., GPIO0/4)
    io_conf.pin_bit_mask = ((1ULL << KEY_GPIO_BOOT0) | (1ULL << KEY_GPIO_USER1));
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //enable pull-up mode
    io_conf.pull_up_en = 1;
    //configure GPIO with the given settings
    gpio_config(&io_conf);
}

//Determin wheter key1 is pressed
//If it pressed, it returns KEY_STATE_PRESS
//If it is released, it returns KEY_STATE_RELEASE
static uint8_t key1_is_Pressed(void){
    uint8_t key_state = KEY_STATE_RELEASE;
    if(!gpio_get_level(KEY_GPIO_USER1)){
        key_state = KEY_STATE_PRESS;
    }

    return key_state;
}

uint8_t Key1_Read_State(void){
    static uint16_t key_state = 0;

    if(Key1_is_Pressed() == KEY_STATE_PRESS){
        if(key_state < 3){
            key_state++;
        }
    }
    else{
        key_state = 0;
    }
    if(key_state == 2){
        return KEY_STATE_PRESS;
    }
    return KEY_STATE_RELEASE;
}

