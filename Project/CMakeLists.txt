project(spaceDisaster)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/SplashScreen.cpp
        src/SplashScreen.h
        src/StartScene.cpp
        src/StartScene.h
        src/crewmate.cpp
        src/crewmate.h
        src/SpriteData.h
        src/PodScene.h
        src/PodScene.cpp
        src/ControlRoomScene.cpp
        src/ControlRoomScene.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )