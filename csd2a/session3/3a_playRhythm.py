import pygame
import time

# expected input:
# first number: number of note durations
# from index 1 to index x: note durations
# last: bpm
# example: 4 1 0.5 1.5 0.5 120


# ___ retrieve all necessary values and lists necessary for playing rhythm ___
# TODO retrieve note durations from input

note_durations = [1, 1, 2, 1]
num_notes = len(note_durations)

# TODO retrieve BPM
bpm = 120

# calculate corresponding quarternote duration in time
quarternote_dur = 60 / bpm

# TODO transform note durations to sequence of time durations (sec)
time_durations = []

for note_dur in note_durations:
    time_dur = note_dur * quarternote_dur
    time_durations.append(time_dur)

print("note_durations: ", note_durations)
print("time_durations: ", time_durations)

# init  mixer module and load sample
pygame.init()
sample = pygame.mixer.Sound('../assets/plop.wav')

# ___ play rhythm ___
# TODO play sample and pause according to time duration
for time_dur in time_durations:
    sample.play()
    time.sleep(time_dur)
