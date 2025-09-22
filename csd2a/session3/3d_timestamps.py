import pygame
import time

# set values and create lists necessary for playing rhythm
note_durations = [1, 0.5, 1, 0.5, 0.5]
bpm = 120
print("note_durations:", note_durations)

# calculate duration of a quarternote in seconds
quarternote_dur = 60.0 / bpm
print("bpm:", bpm, "quarternote_dur", quarternote_dur)

# transform note durations to sequence of time durations
time_durations = []
for note_dur in note_durations:
    time_durations.append(quarternote_dur * note_dur)

print("time_durations", time_durations)

# init  mixer module and load sample
pygame.init()
sample = pygame.mixer.Sound('../assets/plop.wav')

# transform time durations to a sequence of timestamps
timestamps = []
t = 0
for time_dur in time_durations:
    timestamps.append(t)
    t = t + time_dur

print(timestamps)
# retrieve the first time stamp (if it exist - else exit)
ts = timestamps.pop(0)
playing_rhythm = True
t_start = time.time()

while(playing_rhythm):
    t_delta = time.time() - t_start
    sample.play()

# TODO

# store the current time
# TODO

# iterate through time sequence and play sample
# TODO

# wait till last sample is done playing before exit
time.sleep(time_durations[-1])
