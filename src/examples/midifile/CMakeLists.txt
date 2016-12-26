add_executable(midifile midifile.cpp)

target_link_libraries(midifile tse3)

if (WIN32)
	target_link_libraries(midifile Winmm)
endif()