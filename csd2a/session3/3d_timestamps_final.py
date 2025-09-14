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


# transform time durations to a sequence of timestamps
timestamp_seq = []
# use the sum of the durations to calculate the timestamp for each note
sum = 0
for time_dur in time_durations:
    timestamp_seq.append(sum)
    sum = sum + time_dur

print("timestamp_seq:", timestamp_seq)

# init  mixer module and load sample
pygame.init()
sample = pygame.mixer.Sound('../assets/plop.wav')

# retrieve the first time stamp
if timestamp_seq:
    ts = timestamp_seq.pop(0)
else:
    # list contains no items
    print("no timestamps --> exit")
    exit()

# store the current time
time_zero = time.time()
print("time zero:", time_zero)

# iterate through time sequence and play sample
while True:
    now = time.time() - time_zero
    # check if we passed the next timestamp,
    # if so, play sample and fetch new timestamp
    if(now >= ts):
        sample.play()
        if timestamp_seq:
            ts = timestamp_seq.pop(0)
        else:
            # no new timestamp available --> break while loop
            break

    time.sleep(0.001)

# wait till last sample is done playing before exit
time.sleep(time_durations[-1])
