
def get_tone(note):
    """returns the value from note dictionary corresponding to the key "tone" """
    return note["tone"]


def get_duration(note):
    """returns the value from note dictionary corresponding to the key "duration" """
    return note["duration"]


def create_note(tone, duration, velocity):
    return {
        "tone": tone,
        "duration": duration,
        "velocity": velocity
    }

# list of note dictionaries
notes = [
    create_note(60, 1, 100),
    create_note(62, 1.5, 80),
    create_note(64, 0.5, 90),
    create_note(60, 2, 65)
]





print("--- note List ---")
for note in notes:
    print(note)

# sorting by tone
notes.sort(key=get_tone)
print("--- note List sorted by tone ---")
for note in notes:
    print(note)

# sorting by duration
notes.sort(key=get_duration)
print("--- note List sorted by duration ---")
for note in notes:
    print(note)
