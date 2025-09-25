# Session 4

## Repos
See the **git_command_line_overview.md** in main folder regarding the essential git commands.
Also see https://education.github.com/git-cheat-sheet-education.pdf

Number of commits per week
```
./repo_pull.sh
./repo_commits.sh 09-22-2025
```

Again, the reminder for those who do not use git (often enough) yet; we are using git because of:
- learning to work with version control
- insight in process
  - insights in learning process
  - enable quick code sharing when discussing questions during sessions & trouble shooting
  - provide evidence against plagiarism

Therefore, **git is mandatory --> no git / no proper git workflow --> no final grade**. See "beoordelingscriteria.pdf" in main folder.

NOTE: Do not worry if you still find Git a hurdle. Since working with git is new to many of you, we are bit more forgiving and understanding this first second year course.

## Hoe gaat het? & Hoe is het gegaan met de opdrachten
<img src="program_flow.png" alt="isolated" width="500"/>

- Eindopdracht, het omzetten van stappen / pseudo code naar python code
  - het generatie dele
  - functies
  - dictionaries

- Hoe is het gegaan met het zelfstandig doornemen en leren werken met functies? Zijn hier nog vragen over? _--> vragen verzamelen voor straks_

## Content
### Dictionary recap
  - csd2a/slides/Sessie_4-Events.pdf _@D: for now, skip the other data structures slides_

  - **Example 4c** Demonstrates the usage of a dictionary for an event. By using dictionaries, you can combine the timestamp, reference to a sample, duration and other values in one data structure (a data structure refers to a type of container, like a list, a set, a queue, a dictionary). Using a dictionary for an event instead of a list allows you to retrieve the values by using keys. This improves readability, see the example below.

  ```python
  # an event stored in a list
  event = [1000, "snare", snare, 82, 500]
  # retrieving a value is error prone
  timestamp = event[0]

  # an event stored in a dictionary
  event = {
      "timestamp": 1000,
      "instrumentname": "snare",
      "sample": snare,
      "velocity": 82,
      "duration": 500
  }
  timestamp = event["timestamp"]
  ```
  - **Example 4d** Example demonstrating how to sort a list with dictionaries
  _@D: short in time? skip this!_

  - **Example 4e** Contains an introduction to dictionaries - intended for self-study, **see opdrachten.md**
  - - **Example 4f** Contains an example where a function creates and returns a dictionary  - intended for self-study, **see opdrachten.md**

###
- losse python files, code modulair opzetten mbv functies & losse files
  _Wat breng je in welke files onder?_
- example 5a demonstrates how to import another local python description

### UI
- example 5b, short example that demonstrates validation of user input
- example 5c, two functions that are probably required for the main assignment

### Assignments next week -
**What is doable?** - depends on current state projects, progress and current
understanding of python. --> **TODO** discuss together

## Session 6 --> MIDI
Midi directory with some standard copied examples is already there though.
