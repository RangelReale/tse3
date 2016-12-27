#
# BASE
#

SET ( LIB_SRCS
DisplayParams.cpp Error.cpp FileBlockParser.cpp Filter.cpp TSE2MDL.cpp FlagTrack.cpp KeySigTrack.cpp Metronome.cpp Midi.cpp MidiCommandFilter.cpp MidiData.cpp MidiEcho.cpp MidiFile.cpp MidiFilter.cpp MidiMapper.cpp MidiParams.cpp Mixer.cpp Mutex.cpp Notifier.cpp Panic.cpp Part.cpp Phrase.cpp PhraseEdit.cpp PhraseList.cpp Playable.cpp RepeatTrack.cpp MidiScheduler.cpp Serializable.cpp Song.cpp TextTrack.cpp TempoTrack.cpp TimeSigTrack.cpp Track.cpp Transport.cpp TSE3.cpp TSE3MDL.cpp
)


SET ( LIB_INCS
DisplayParams.h Error.h EventTrack.h FileBlockParser.h Filter.h TSE2MDL.h FlagTrack.h KeySigTrack.h Metronome.h Midi.h MidiCommandFilter.h MidiData.h MidiEcho.h MidiFile.h MidiFilter.h MidiMapper.h MidiParams.h Mixer.h Mutex.h Notifier.h Panic.h Part.h Phrase.h PhraseEdit.h PhraseList.h Playable.h Progress.h RepeatTrack.h MidiScheduler.h Serializable.h Song.h TempoTrack.h TextTrack.h TimeSigTrack.h Track.h Transport.h TSE3.h TSE3MDL.h
)

#
# UTIL
#

SET (LIB_SRCS ${LIB_SRCS}
util/Demidify.cpp util/MidiScheduler.cpp util/MulDiv.cpp util/NoteNumber.cpp util/Phrase.cpp 
util/PowerQuantise.cpp util/Song.cpp util/Snap.cpp util/Track.cpp
)

SET ( LIB_INCS ${LIB_INCS}
util/Demidify.h util/MidiScheduler.h util/MulDiv.h util/NoteNumber.h util/Phrase.h util/PowerQuantise.h util/Song.h util/Snap.h util/Track.h
)

#
# CMD
#

SET (LIB_SRCS ${LIB_SRCS}
cmd/CommandGroup.cpp cmd/CommandHistory.cpp cmd/FlagTrack.cpp cmd/Song.cpp cmd/Track.cpp cmd/Part.cpp cmd/Phrase.cpp
)

SET ( LIB_INCS ${LIB_INCS}
cmd/Command.h cmd/CommandGroup.h cmd/CommandHistory.h cmd/FlagTrack.h cmd/Song.h cmd/Track.h cmd/Part.h cmd/Phrase.h
)

#
# PLT
#

SET (LIB_INCS ${LIB_INCS}
plt/Factory.h
)


# ** WIN32 **

if (WIN32)

SET (LIB_SRCS ${LIB_SRCS}
plt/Factory_Win32.cpp plt/Win32.cpp
)

SET ( LIB_INCS ${LIB_INCS}
plt/Win32.h
)

endif(WIN32)

# ** LINUX **

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")

SET (LIB_SRCS ${LIB_SRCS}
plt/Factory_Unix.cpp plt/Alsa-0.9.cpp
)

SET ( LIB_INCS ${LIB_INCS}
plt/Alsa.h
)

endif()

#
# APP
#

SET (LIB_SRCS ${LIB_SRCS}
app/Application.cpp app/Choices.cpp app/Modified.cpp app/PartSelection.cpp app/PartDisplay.cpp app/Record.cpp app/TrackSelection.cpp
)

SET ( LIB_INCS ${LIB_INCS}
app/Application.h app/Choices.h app/Modified.h app/PartSelection.h app/PartDisplay.h app/Record.h app/TrackSelection.h
)

#
# INS
#

SET (LIB_SRCS ${LIB_SRCS}
ins/Destination.cpp ins/Instrument.cpp
)

SET ( LIB_INCS ${LIB_INCS}
ins/Destination.h ins/Instrument.h
)

#
# LISTEN (.h only)
#

#
# FILE
#

SET (LIB_SRCS ${LIB_SRCS}
file/DisplayParams.cpp file/FlagTrack.cpp file/KeySigTrack.cpp file/MidiFilter.cpp file/MidiParams.cpp file/Part.cpp file/PhraseList.cpp 
file/Song.cpp file/TempoTrack.cpp file/TimeSigTrack.cpp file/Track.cpp file/Write.cpp file/XML.cpp
)

SET ( LIB_INCS ${LIB_INCS}
file/XML.h file/Write.h
)


#
# ** LIBRARY **
#

ADD_LIBRARY(tse3 STATIC ${LIB_SRCS} ${LIB_INCS})
