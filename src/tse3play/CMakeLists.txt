add_executable(tse3play tse3play.cpp tse3play.h main.cpp)

target_link_libraries(tse3play tse3)

if (WIN32)
	target_link_libraries(tse3play Winmm)
endif()