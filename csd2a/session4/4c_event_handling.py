"""
Example demonstrating the use of Python dictionaries for creating
bundles of information describing playable events

A Python dictionary is a way of grouping information while preserving
both the key to each item and its value. We can use the key to access a
piece of information.

Events are things that happen due to actions from outside
(e.g. a user presses a button) or things that we want to happen, so
these are initiated by our program (e.g. a note that needs to sound at
some moment)
"""

import pygame
import time

# init  mixer module and load drumkit samples
pygame.init()
hihat_sample = pygame.mixer.Sound("../assets/hihat.wav")
snare_sample = pygame.mixer.Sound("../assets/snare.wav")
kick_sample = pygame.mixer.Sound("../assets/kick.wav")


snare_event = {
    "timestamp": 1000, # msec w.r.t start of program
    "sample_name": "snare", # name of instrument in text
    "sample": snare_sample, # reference to sound file
    "velocity": 82, # numeric MIDI-based, 0-127
    "duration_msec": 1000 # msec
}

kick_event = {
    "timestamp": 2000,
    "sample_name": "kick",
    "sample": kick_sample,
    "velocity": 71,
    "duration_msec": 1000
}

def handle_note_event(event):
    """handles note events by playing the referenced sample"""
    print("Handling note event, sample name:", event["sample_name"])
    sample = event["sample"]
    sample.set_volume(event["velocity"] / 127.0)
    sample.play()

# call the note handler for each event
# NOTE: ignoring timestamp in this example, simply wait 1 sec. in between
handle_note_event(snare_event)
time.sleep(1)

handle_note_event(kick_event)
time.sleep(1)
