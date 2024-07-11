#include "st7701.h"

// static const char *TAG = "st7701";

// static void spi_soft_init(void)
// {
//     gpio_config_t io_conf1 = {
//         .mode = GPIO_MODE_OUTPUT,
//         .pin_bit_mask = 1ULL << GPIO_LCD_CS,
//     };
//     gpio_config(&io_conf1);
//     gpio_set_level(GPIO_LCD_CS, 1);

//     gpio_config_t io_conf2 = {
//         .mode = GPIO_MODE_OUTPUT,
//         .pin_bit_mask = 1ULL << GPIO_LCD_SCK,
//     };
//     gpio_config(&io_conf2);
//     gpio_set_level(GPIO_LCD_SCK, 1);

//     gpio_config_t io_conf3 = {
//         .mode = GPIO_MODE_OUTPUT,
//         .pin_bit_mask = 1ULL << GPIO_LCD_SDA,
//     };
//     gpio_config(&io_conf3);
//     gpio_set_level(GPIO_LCD_SDA, 1);
// }

// static void spi_soft_write_9bits(uint16_t data)
// {
//     uint8_t i;
//     LCD_CS_Clr();
//     for (i = 0; i < 9; i++)
//     {
//         LCD_SCK_Clr();
//         if (data & 0x100)
//             LCD_SDA_Set();
//         else
//             LCD_SDA_Clr();
//         LCD_SCK_Set();
//         data <<= 1;
//     }
//     LCD_CS_Set();
//     ;
// }

// static void st7701_write_cmd(uint8_t cmd)
// {
//     uint16_t temp = 0;
//     temp = temp | cmd;
//     spi_soft_write_9bits(temp);
// }

// static void st7701_write_data(uint8_t data)
// {
//     uint16_t temp = 0x100;
//     temp = temp | data;
//     spi_soft_write_9bits(temp);
// }

// void st7701_reg_init(void)
// {
//     spi_soft_init(); // GPIO init
//     ESP_LOGI(TAG, "st7701 register init");

//     // PAGE1
//     st7701_write_cmd(0xFF);
//     st7701_write_data(0x77);
//     st7701_write_data(0x01);
//     st7701_write_data(0x00);
//     st7701_write_data(0x00);
//     st7701_write_data(0x10);

//     st7701_write_cmd(0xC0);
//     st7701_write_data(0x3B);
//     st7701_write_data(0x00);

//     st7701_write_cmd(0xC1);
//     st7701_write_data(0x0D);
//     st7701_write_data(0x02);

//     st7701_write_cmd(0xC2);
//     st7701_write_data(0x31);
//     st7701_write_data(0x05);

//     st7701_write_cmd(0xCd);
//     st7701_write_data(0x08);

//     st7701_write_cmd(0xB0);
//     st7701_write_data(0x00); // Positive Voltage Gamma Control
//     st7701_write_data(0x11);
//     st7701_write_data(0x18);
//     st7701_write_data(0x0E);
//     st7701_write_data(0x11);
//     st7701_write_data(0x06);
//     st7701_write_data(0x07);
//     st7701_write_data(0x08);
//     st7701_write_data(0x07);
//     st7701_write_data(0x22);
//     st7701_write_data(0x04);
//     st7701_write_data(0x12);
//     st7701_write_data(0x0F);
//     st7701_write_data(0xAA);
//     st7701_write_data(0x31);
//     st7701_write_data(0x18);

//     st7701_write_cmd(0xB1);
//     st7701_write_data(0x00); // Negative Voltage Gamma Control
//     st7701_write_data(0x11);
//     st7701_write_data(0x19);
//     st7701_write_data(0x0E);
//     st7701_write_data(0x12);
//     st7701_write_data(0x07);
//     st7701_write_data(0x08);
//     st7701_write_data(0x08);
//     st7701_write_data(0x08);
//     st7701_write_data(0x22);
//     st7701_write_data(0x04);
//     st7701_write_data(0x11);
//     st7701_write_data(0x11);
//     st7701_write_data(0xA9);
//     st7701_write_data(0x32);
//     st7701_write_data(0x18);

//     // PAGE1
//     st7701_write_cmd(0xFF);
//     st7701_write_data(0x77);
//     st7701_write_data(0x01);
//     st7701_write_data(0x00);
//     st7701_write_data(0x00);
//     st7701_write_data(0x11);

//     st7701_write_cmd(0xB0);
//     st7701_write_data(0x60); // Vop=4.7375v
//     st7701_write_cmd(0xB1);
//     st7701_write_data(0x32); // VCOM=32
//     st7701_write_cmd(0xB2);
//     st7701_write_data(0x07); // VGH=15v
//     st7701_write_cmd(0xB3);
//     st7701_write_data(0x80);
//     st7701_write_cmd(0xB5);
//     st7701_write_data(0x49); // VGL=-10.17v
//     st7701_write_cmd(0xB7);
//     st7701_write_data(0x85);
//     st7701_write_cmd(0xB8);
//     st7701_write_data(0x21); // AVDD=6.6 & AVCL=-4.6
//     st7701_write_cmd(0xC1);
//     st7701_write_data(0x78);
//     st7701_write_cmd(0xC2);
//     st7701_write_data(0x78);

//     st7701_write_cmd(0xE0);
//     st7701_write_data(0x00);
//     st7701_write_data(0x1B);
//     st7701_write_data(0x02);

//     st7701_write_cmd(0xE1);
//     st7701_write_data(0x08);
//     st7701_write_data(0xA0);
//     st7701_write_data(0x00);
//     st7701_write_data(0x00);
//     st7701_write_data(0x07);
//     st7701_write_data(0xA0);
//     st7701_write_data(0x00);
//     st7701_write_data(0x00);
//     st7701_write_data(0x00);
//     st7701_write_data(0x44);
//     st7701_write_data(0x44);

//     st7701_write_cmd(0xE2);
//     st7701_write_data(0x11);
//     st7701_write_data(0x11);
//     st7701_write_data(0x44);
//     st7701_write_data(0x44);
//     st7701_write_data(0xED);
//     st7701_write_data(0xA0);
//     st7701_write_data(0x00);
//     st7701_write_data(0x00);
//     st7701_write_data(0xEC);
//     st7701_write_data(0xA0);
//     st7701_write_data(0x00);
//     st7701_write_data(0x00);

//     st7701_write_cmd(0xE3);
//     st7701_write_data(0x00);
//     st7701_write_data(0x00);
//     st7701_write_data(0x11);
//     st7701_write_data(0x11);

//     st7701_write_cmd(0xE4);
//     st7701_write_data(0x44);
//     st7701_write_data(0x44);

//     st7701_write_cmd(0xE5);
//     st7701_write_data(0x0A);
//     st7701_write_data(0xE9);
//     st7701_write_data(0xD8);
//     st7701_write_data(0xA0);
//     st7701_write_data(0x0C);
//     st7701_write_data(0xEB);
//     st7701_write_data(0xD8);
//     st7701_write_data(0xA0);
//     st7701_write_data(0x0E);
//     st7701_write_data(0xED);
//     st7701_write_data(0xD8);
//     st7701_write_data(0xA0);
//     st7701_write_data(0x10);
//     st7701_write_data(0xEF);
//     st7701_write_data(0xD8);
//     st7701_write_data(0xA0);

//     st7701_write_cmd(0xE6);
//     st7701_write_data(0x00);
//     st7701_write_data(0x00);
//     st7701_write_data(0x11);
//     st7701_write_data(0x11);

//     st7701_write_cmd(0xE7);
//     st7701_write_data(0x44);
//     st7701_write_data(0x44);

//     st7701_write_cmd(0xE8);
//     st7701_write_data(0x09);
//     st7701_write_data(0xE8);
//     st7701_write_data(0xD8);
//     st7701_write_data(0xA0);
//     st7701_write_data(0x0B);
//     st7701_write_data(0xEA);
//     st7701_write_data(0xD8);
//     st7701_write_data(0xA0);
//     st7701_write_data(0x0D);
//     st7701_write_data(0xEC);
//     st7701_write_data(0xD8);
//     st7701_write_data(0xA0);
//     st7701_write_data(0x0F);
//     st7701_write_data(0xEE);
//     st7701_write_data(0xD8);
//     st7701_write_data(0xA0);

//     st7701_write_cmd(0xEB);
//     st7701_write_data(0x02);
//     st7701_write_data(0x00);
//     st7701_write_data(0xE4);
//     st7701_write_data(0xE4);
//     st7701_write_data(0x88);
//     st7701_write_data(0x00);
//     st7701_write_data(0x40);

//     st7701_write_cmd(0xEC);
//     st7701_write_data(0x3C);
//     st7701_write_data(0x00);

//     st7701_write_cmd(0xED);
//     st7701_write_data(0xAB);
//     st7701_write_data(0x89);
//     st7701_write_data(0x76);
//     st7701_write_data(0x54);
//     st7701_write_data(0x02);
//     st7701_write_data(0xFF);
//     st7701_write_data(0xFF);
//     st7701_write_data(0xFF);
//     st7701_write_data(0xFF);
//     st7701_write_data(0xFF);
//     st7701_write_data(0xFF);
//     st7701_write_data(0x20);
//     st7701_write_data(0x45);
//     st7701_write_data(0x67);
//     st7701_write_data(0x98);
//     st7701_write_data(0xBA);

//     st7701_write_cmd(0x36);
//     st7701_write_data(0x00);

//     //-----------VAP & VAN---------------
//     st7701_write_cmd(0xFF);
//     st7701_write_data(0x77);
//     st7701_write_data(0x01);
//     st7701_write_data(0x00);
//     st7701_write_data(0x00);
//     st7701_write_data(0x13);

//     st7701_write_cmd(0xE5);
//     st7701_write_data(0xE4);

//     st7701_write_cmd(0xFF);
//     st7701_write_data(0x77);
//     st7701_write_data(0x01);
//     st7701_write_data(0x00);
//     st7701_write_data(0x00);
//     st7701_write_data(0x00);

//     st7701_write_cmd(0x3A); // 0x70 RGB888, 0x60 RGB666, 0x50 RGB565
//     st7701_write_data(0x60);

//     st7701_write_cmd(0x21); // Display Inversion On

//     st7701_write_cmd(0x11); // Sleep Out
//     vTaskDelay(pdMS_TO_TICKS(100));

//     st7701_write_cmd(0x29); // Display On
//     vTaskDelay(pdMS_TO_TICKS(50));
// }

/*设备句柄*/
spi_device_handle_t device_handle;
/*事务传输*/
spi_transaction_t spi_transaction = {
    .rxlength = 0,
    .length = 0,
};

void my_spi_init()
{
    esp_err_t ret;
    spi_bus_config_t bus_config = {
        .mosi_io_num = GPIO_LCD_SDA, // MOSI
        .sclk_io_num = GPIO_LCD_SCK, // SCLK
        .quadwp_io_num = GPIO_NUM_NC,
        .quadhd_io_num = GPIO_NUM_NC,
        .max_transfer_sz = SOC_SPI_MAXIMUM_BUFFER_SIZE,
    };

    ret = spi_bus_initialize(SPI3_HOST, &bus_config, 0); // 初始化 SPI 总线
    ESP_ERROR_CHECK(ret);
    spi_device_interface_config_t dev_config = {
        .command_bits = 1,                  // 1bit命令数据
        .address_bits = 8,                  // 8bit地址数据
        .clock_speed_hz = 20 * 1000 * 1000, // 20MHz
        .mode = 0,                          // SPI模式0
        .spics_io_num = GPIO_LCD_CS,        // 片选脚
        .queue_size = 1,                    // 事务队列的大小
    };

    // 添加 SPI 设备
    ret = spi_bus_add_device(SPI3_HOST, &dev_config, &device_handle);
    ESP_ERROR_CHECK(ret);
}

/*写命令*/
void spi_write_cmd(uint8_t cmd)
{
    spi_transaction.cmd = 0;
    spi_transaction.addr = cmd;
    // spi_device_transmit(device_handle, &spi_transaction); // 使用SPI发送数据
    spi_device_polling_transmit(device_handle, &spi_transaction); // 轮询事务
}

/*写数据*/
void spi_write_data(uint8_t cmd)
{
    spi_transaction.cmd = 1;
    spi_transaction.addr = cmd;
    // spi_device_transmit(device_handle, &spi_transaction); // 使用SPI发送数据
    spi_device_polling_transmit(device_handle, &spi_transaction); // 轮询事务
}

void st7701_reg_init(void)
{
    my_spi_init();

    spi_write_cmd(0xFF);
    spi_write_data(0x77);
    spi_write_data(0x01);
    spi_write_data(0x00);
    spi_write_data(0x00);
    spi_write_data(0x10);

    spi_write_cmd(0xC0);
    spi_write_data(0x3B);
    spi_write_data(0x00);

    spi_write_cmd(0xC1);
    spi_write_data(0x0D);
    spi_write_data(0x02);

    spi_write_cmd(0xC2);
    spi_write_data(0x31);
    spi_write_data(0x05);

    spi_write_cmd(0xCd);
    spi_write_data(0x08);

    spi_write_cmd(0xB0);
    spi_write_data(0x00); // Positive Voltage Gamma Control
    spi_write_data(0x11);
    spi_write_data(0x18);
    spi_write_data(0x0E);
    spi_write_data(0x11);
    spi_write_data(0x06);
    spi_write_data(0x07);
    spi_write_data(0x08);
    spi_write_data(0x07);
    spi_write_data(0x22);
    spi_write_data(0x04);
    spi_write_data(0x12);
    spi_write_data(0x0F);
    spi_write_data(0xAA);
    spi_write_data(0x31);
    spi_write_data(0x18);

    spi_write_cmd(0xB1);
    spi_write_data(0x00); // Negative Voltage Gamma Control
    spi_write_data(0x11);
    spi_write_data(0x19);
    spi_write_data(0x0E);
    spi_write_data(0x12);
    spi_write_data(0x07);
    spi_write_data(0x08);
    spi_write_data(0x08);
    spi_write_data(0x08);
    spi_write_data(0x22);
    spi_write_data(0x04);
    spi_write_data(0x11);
    spi_write_data(0x11);
    spi_write_data(0xA9);
    spi_write_data(0x32);
    spi_write_data(0x18);

    // PAGE1
    spi_write_cmd(0xFF);
    spi_write_data(0x77);
    spi_write_data(0x01);
    spi_write_data(0x00);
    spi_write_data(0x00);
    spi_write_data(0x11);

    spi_write_cmd(0xB0);
    spi_write_data(0x60); // Vop=4.7375v
    spi_write_cmd(0xB1);
    spi_write_data(0x32); // VCOM=32
    spi_write_cmd(0xB2);
    spi_write_data(0x07); // VGH=15v
    spi_write_cmd(0xB3);
    spi_write_data(0x80);
    spi_write_cmd(0xB5);
    spi_write_data(0x49); // VGL=-10.17v
    spi_write_cmd(0xB7);
    spi_write_data(0x85);
    spi_write_cmd(0xB8);
    spi_write_data(0x21); // AVDD=6.6 & AVCL=-4.6
    spi_write_cmd(0xC1);
    spi_write_data(0x78);
    spi_write_cmd(0xC2);
    spi_write_data(0x78);

    spi_write_cmd(0xE0);
    spi_write_data(0x00);
    spi_write_data(0x1B);
    spi_write_data(0x02);

    spi_write_cmd(0xE1);
    spi_write_data(0x08);
    spi_write_data(0xA0);
    spi_write_data(0x00);
    spi_write_data(0x00);
    spi_write_data(0x07);
    spi_write_data(0xA0);
    spi_write_data(0x00);
    spi_write_data(0x00);
    spi_write_data(0x00);
    spi_write_data(0x44);
    spi_write_data(0x44);

    spi_write_cmd(0xE2);
    spi_write_data(0x11);
    spi_write_data(0x11);
    spi_write_data(0x44);
    spi_write_data(0x44);
    spi_write_data(0xED);
    spi_write_data(0xA0);
    spi_write_data(0x00);
    spi_write_data(0x00);
    spi_write_data(0xEC);
    spi_write_data(0xA0);
    spi_write_data(0x00);
    spi_write_data(0x00);

    spi_write_cmd(0xE3);
    spi_write_data(0x00);
    spi_write_data(0x00);
    spi_write_data(0x11);
    spi_write_data(0x11);

    spi_write_cmd(0xE4);
    spi_write_data(0x44);
    spi_write_data(0x44);

    spi_write_cmd(0xE5);
    spi_write_data(0x0A);
    spi_write_data(0xE9);
    spi_write_data(0xD8);
    spi_write_data(0xA0);
    spi_write_data(0x0C);
    spi_write_data(0xEB);
    spi_write_data(0xD8);
    spi_write_data(0xA0);
    spi_write_data(0x0E);
    spi_write_data(0xED);
    spi_write_data(0xD8);
    spi_write_data(0xA0);
    spi_write_data(0x10);
    spi_write_data(0xEF);
    spi_write_data(0xD8);
    spi_write_data(0xA0);

    spi_write_cmd(0xE6);
    spi_write_data(0x00);
    spi_write_data(0x00);
    spi_write_data(0x11);
    spi_write_data(0x11);

    spi_write_cmd(0xE7);
    spi_write_data(0x44);
    spi_write_data(0x44);

    spi_write_cmd(0xE8);
    spi_write_data(0x09);
    spi_write_data(0xE8);
    spi_write_data(0xD8);
    spi_write_data(0xA0);
    spi_write_data(0x0B);
    spi_write_data(0xEA);
    spi_write_data(0xD8);
    spi_write_data(0xA0);
    spi_write_data(0x0D);
    spi_write_data(0xEC);
    spi_write_data(0xD8);
    spi_write_data(0xA0);
    spi_write_data(0x0F);
    spi_write_data(0xEE);
    spi_write_data(0xD8);
    spi_write_data(0xA0);

    spi_write_cmd(0xEB);
    spi_write_data(0x02);
    spi_write_data(0x00);
    spi_write_data(0xE4);
    spi_write_data(0xE4);
    spi_write_data(0x88);
    spi_write_data(0x00);
    spi_write_data(0x40);

    spi_write_cmd(0xEC);
    spi_write_data(0x3C);
    spi_write_data(0x00);

    spi_write_cmd(0xED);
    spi_write_data(0xAB);
    spi_write_data(0x89);
    spi_write_data(0x76);
    spi_write_data(0x54);
    spi_write_data(0x02);
    spi_write_data(0xFF);
    spi_write_data(0xFF);
    spi_write_data(0xFF);
    spi_write_data(0xFF);
    spi_write_data(0xFF);
    spi_write_data(0xFF);
    spi_write_data(0x20);
    spi_write_data(0x45);
    spi_write_data(0x67);
    spi_write_data(0x98);
    spi_write_data(0xBA);

    spi_write_cmd(0x36);
    spi_write_data(0x00);

    //-----------VAP & VAN---------------
    spi_write_cmd(0xFF);
    spi_write_data(0x77);
    spi_write_data(0x01);
    spi_write_data(0x00);
    spi_write_data(0x00);
    spi_write_data(0x13);

    spi_write_cmd(0xE5);
    spi_write_data(0xE4);

    spi_write_cmd(0xFF);
    spi_write_data(0x77);
    spi_write_data(0x01);
    spi_write_data(0x00);
    spi_write_data(0x00);
    spi_write_data(0x00);

    spi_write_cmd(0x3A); // 0x70 RGB888, 0x60 RGB666, 0x50 RGB565
    spi_write_data(0x60);

    spi_write_cmd(0x21); // Display Inversion On

    spi_write_cmd(0x11); // Sleep Out
    vTaskDelay(pdMS_TO_TICKS(100));

    spi_write_cmd(0x29); // Display On
    vTaskDelay(pdMS_TO_TICKS(50));
}
