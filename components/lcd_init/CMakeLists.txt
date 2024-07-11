idf_component_register(
                        SRCS "lcd_init.c"

                        INCLUDE_DIRS  "."
                        REQUIRES driver esp_lcd esp_timer

)