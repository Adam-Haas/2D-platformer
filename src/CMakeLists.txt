include_directories(${PROJECT_SOURCE_DIR}/include)

set(SDL2_PATH "C:/MinGW_dev_libs/SDL2-2.0.12/x86_64-w64-mingw32")
set(SDL2_IMAGE_PATH "C:/MinGW_dev_libs/SDL2_image-2.0.5/x86_64-w64-mingw32")

set(SOURCE
        main.cpp
        RenderWindow.cpp
        Entity.cpp
        GameObject.cpp
        )

#Find the SDL2 libs and include them
find_package(SDL2 REQUIRED)
include_directories( ${SDL2_INCLUDE_DIR} )
find_package(SDL2_image REQUIRED)
include_directories( ${SDL2_IMAGE_INCLUDE_DIRS} )

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${SDL2_PATH}/bin"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${SDL2_IMAGE_PATH}/bin"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)