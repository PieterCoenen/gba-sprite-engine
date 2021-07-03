project(HarvestMoonClone)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/SplashScreen.cpp
        src/SplashScreen.h
        src/StartScreen.cpp
        src/StartScreen.h
        src/MainScene.cpp
        src/MainScene.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )