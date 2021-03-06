project(gba-sprite-engine)
set_property(SOURCE src/gba/sin_lut.s PROPERTY LANGUAGE C)
set_property(SOURCE src/gba/tonc_bios.s PROPERTY LANGUAGE C)
set_source_files_properties(src/gba/tonc_bios.s PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp")

add_library(${PROJECT_NAME}
        src/sprites/sprite_manager.cpp
        src/sprites/sprite.cpp
        src/palette/palette_manager.cpp
        src/palette/combined_palette.cpp
        src/allocator.cpp
        src/gba/sin_lut.s
        src/gba/tonc_bios.s
        src/sprites/sprite_builder.cpp
        src/sprites/affine_sprite.cpp
        src/gba_engine.cpp
        src/background/text_stream.cpp
        src/background/background.cpp
        src/effects/fade_out_scene.cpp
        src/sound_control.cpp src/scene.cpp src/timer.cpp include/libgba-sprite-engine/gbavector.h src/gbavector.cpp ../Project/src/main.cpp ../Project/src/crewmate.h ../Project/src/crewmate.cpp ../Project/src/StartScene.h ../Project/src/StartScene.cpp ../Project/src/PodScene.cpp ../Project/src/SpriteData.h ../Project/src/ControlRoomScene.cpp ../Project/src/ControlRoomScene.h ../ProjectAugustusPieterCoenen/src/SplashScreen.cpp ../ProjectAugustusPieterCoenen/src/SplashScreen.h ../ProjectAugustusPieterCoenen/src/StartScreen.cpp ../ProjectAugustusPieterCoenen/src/StartScreen.h ../ProjectAugustusPieterCoenen/src/main.cpp ../ProjectAugustusPieterCoenen/src/MainScene.cpp ../ProjectAugustusPieterCoenen/src/MainScene.h ../ProjectAugustusPieterCoenen/src/HouseScene.cpp ../ProjectAugustusPieterCoenen/src/HouseScene.h ../ProjectAugustusPieterCoenen/src/InventoryScene.cpp ../ProjectAugustusPieterCoenen/src/InventoryScene.h ../ProjectAugustusPieterCoenen/src/Farmer.cpp ../ProjectAugustusPieterCoenen/src/Farmer.h ../ProjectAugustusPieterCoenen/src/Crop.cpp ../ProjectAugustusPieterCoenen/src/Crop.h ../ProjectAugustusPieterCoenen/src/Tool.cpp ../ProjectAugustusPieterCoenen/src/Tool.h)

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE src)

install(TARGETS ${PROJECT_NAME} EXPORT GbaSpriteEngineTargets
        ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
