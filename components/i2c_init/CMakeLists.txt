idf_component_register(
                        SRCS "i2c_lcd.c"

                        INCLUDE_DIRS  "."
                        REQUIRES driver esp_lcd esp_timer

)