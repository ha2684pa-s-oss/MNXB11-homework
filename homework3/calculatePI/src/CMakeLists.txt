add_executable(main main.cxx)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(main PRIVATE ${ROOT_CFLAGS_LIST})
target_link_libraries(main PRIVATE ${ROOT_LIBS_LIST})
