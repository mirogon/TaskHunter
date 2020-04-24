list(APPEND _source_files main.cpp global.cpp task.cpp taskhunter.cpp)

add_executable(TaskHunter ${_source_files})

find_path(M1LIB_INCLUDEDIR NAMES m1_libraries HINTS ENV M1LIB)

target_include_directories(TaskHunter PUBLIC ${M1LIB_INCLUDEDIR})
