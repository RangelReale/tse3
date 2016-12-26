add_executable(contents contents.cpp)

target_link_libraries(contents tse3)

if (WIN32)
	target_link_libraries(contents Winmm)
endif()