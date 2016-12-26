add_executable(recording recording.cpp)

target_link_libraries(recording tse3)

if (WIN32)
	target_link_libraries(recording Winmm)
endif()