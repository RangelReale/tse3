add_executable(scale scale.cpp)

target_link_libraries(scale tse3)

if (WIN32)
	target_link_libraries(scale Winmm)
endif()