add_executable(ports ports.cpp)

target_link_libraries(ports tse3)

if (WIN32)
	target_link_libraries(ports Winmm)
endif()