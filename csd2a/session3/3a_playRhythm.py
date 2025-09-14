import pygame
import time

# expected input:
# first number: number of note durations
# from index 1 to index x: note durations
# last: bpm
# example: 4 1 0.5 1.5 0.5 120


# ___ retrieve all necessary values and lists necessary for playing rhythm ___
# TODO retrieve note durations from input

# TODO retrieve BPM and calculate corresponding quarternote duration

# TODO transform note durations to sequence of time durations (sec)

# init  mixer module and load sample
pygame.init()
sample = pygame.mixer.Sound('../assets/plop.wav')


# ___ play rhythm ___
sample.play()
time.sleep(sample.get_length())

# TODO play sample and pause according to time duration
