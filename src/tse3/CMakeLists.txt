SET ( LIB_SRCS
DisplayParams.cpp Error.cpp FileBlockParser.cpp Filter.cpp TSE2MDL.cpp FlagTrack.cpp KeySigTrack.cpp Metronome.cpp Midi.cpp MidiCommandFilter.cpp MidiData.cpp MidiEcho.cpp MidiFile.cpp MidiFilter.cpp MidiMapper.cpp MidiParams.cpp Mixer.cpp Mutex.cpp Notifier.cpp Panic.cpp Part.cpp Phrase.cpp PhraseEdit.cpp PhraseList.cpp Playable.cpp RepeatTrack.cpp MidiScheduler.cpp Serializable.cpp Song.cpp TempoTrack.cpp TimeSigTrack.cpp Track.cpp Transport.cpp TSE3.cpp TSE3MDL.cpp
)

SET ( LIB_INCS
DisplayParams.h Error.h EventTrack.h FileBlockParser.h Filter.h TSE2MDL.h FlagTrack.h KeySigTrack.h Metronome.h Midi.h MidiCommandFilter.h MidiData.h MidiEcho.h MidiFile.h MidiFilter.h MidiMapper.h MidiParams.h Mixer.h Mutex.h Notifier.h Panic.h Part.h Phrase.h PhraseEdit.h PhraseList.h Playable.h Progress.h RepeatTrack.h MidiScheduler.h Serializable.h Song.h TempoTrack.h TimeSigTrack.h Track.h Transport.h TSE3.h TSE3MDL.h
)

ADD_LIBRARY(tse3 STATIC ${LIB_SRCS} ${LIB_INCS})