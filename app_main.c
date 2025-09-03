void app_main(void){
    Led_Init();

    while(1){
        Led_Flash(50);
        vTaskDelay(pdMS_TO_TICKS(10));
    }

    Key_Init();

    while(1){
        if(Key0_Read_State() == KEY_STATE_PRESS){
            ESP_LOGI(TAG, "KEY 0 PRESS");
            ESP_LOGI(TAG, "free internal heap size = %ld", esp_get_free_internal_heap_size());
        }

        if(Key1_Read_State() == KEY_STATE_PRESS){
            ESP_LOGI(TAG, "KEY 1 PRESS");
            printf("free heap size = %ld\r\n", esp_get_free_heap_size());
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    printf("hello yahboom\n");
    ESP_LOGI(TAG, "Nicce to meet you!");
    Beep_Init();
    vTaskDelay(pdMS_TO_TICKS(1000));

    while(1)
    {
        Beep_On_Time(500);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}