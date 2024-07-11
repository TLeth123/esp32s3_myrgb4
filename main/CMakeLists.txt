set(UI ./ui)
file(GLOB_RECURSE UI_SOURCES ${UI}/*.c)


idf_component_register(SRCS "main.c"
                            ${UI_SOURCES}

                    INCLUDE_DIRS "."
                                ${UI}
                                
                                )
