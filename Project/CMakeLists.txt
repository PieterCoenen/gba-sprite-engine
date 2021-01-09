project(spaceDisaster)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/pod_scene.cpp
        src/pod_scene.h
        src/SplashScreen.cpp
        src/SplashScreen.h
        src/Item.cpp
        src/Item.h
        src/crewmate.cpp
        src/crewmate.h
        src/Element.cpp
        src/Element.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )