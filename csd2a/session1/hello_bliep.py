import pygame
import time

# init  mixer module
pygame.init()

# load and play the sample
sample = pygame.mixer.Sound('./plop.wav')
sample.play()

# wait till sound is done playing before exiting
time.sleep(sample.get_length())
