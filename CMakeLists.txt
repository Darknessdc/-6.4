cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

##使用libgl和nanoGUI作为编辑界面
set(APP_NAME wovenfill)
project(${APP_NAME})

### Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

### Compilation flags: adapt to your needs ###
if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /bigobj") ### Enable parallel compilation
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR} )
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR} )
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /w") # disable all warnings (not ideal but...)
  
  list(APPEND LIBIGL_DEFINITIONS "-DEIGEN_DONT_ALIGN")     #remove eigen error
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") #### use a modern C++ compiler that supports c++11
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../" )
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w") # disable all warnings (not ideal but...)
endif()

#######################Project Setting########################
FILE(GLOB SRC_SOURCES	*.cpp *.c ) 
FILE(GLOB SRC_HEADERS	*.h *.hpp )
set(SRC_LIST ${SRC_SOURCES} 
             ${SRC_HEADERS} 			 
) 


set(PROJECT_INCLUDE_DIRS ${${APP_NAME}_SOURCE_DIR}/include)
set(PROJECT_LIBRARY_DIRS ${${APP_NAME}_SOURCE_DIR}/lib)

include_directories(  
  ${PROJECT_INCLUDE_DIRS}  
  ${CMAKE_CURRENT_BINARY_DIR}
)
  
link_directories(  
  ${PROJECT_LIBRARY_DIRS}  
)

add_executable (${APP_NAME}  
                ${SRC_LIST}
)

##target_link_libraries (${APP_NAME} ${EXTRA_LIB})
