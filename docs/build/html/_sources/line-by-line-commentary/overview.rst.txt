Line By Line Commentary
=======================

Programmer Forward
------------------
I have not even been "coding coding" for a year. Last summer, I began learning
C++ because it was the language used for every open source project that I wanted
to contribute to, Musescore, LMMS, and Blender.

I had began my journey in Robotics my Freshman year; however, at the time, we
only had one good programmer, the legendary Evan Seils, and given the double load of
programming the robot and a video game(BEST robotics), I would simply be told to look up a
tutorial and Codecademy. I did not contribute a single line that year and ended
up taking a break.

This year, I too was faced with the same situation as well. I would be unable for a
majority of the initial season give any in-depth instruction to those who wanted
to learn. The reason why I am writing this in a highly verbose manner is so
future programmers of Makerspace and beyond will be able to see example of good
programming and what this does.

It wasn't until last year that I resolved to learn programming in depth. I owe
everything to learncpp.com because not only does it teach the language, but the
tools used such as compilers and ide's and what really happens when you press
the build button.

I also finally learned how to really use git and github. (It's not just cloud
storage *badum* *pshhh* )

And also the masochistic endeavor of switching to Fedora and not Debian Linux
from Windows.

Most of you would believe it, but I have never programmed for Robotics until the
second week of January. But because I had experience in reading the naturally
terrible documentation of the APIs, I was able to fare well.

This is the product of only a few month's work. And will always have room to
improve.

Finally,
Hail Vim
(Yes, I am using the terminal to write this lol)

Arturita Code Features
-------------
Arturita's code contains multiple functionalities:
* Motor Abstraction
* Custom Differential Drive that is better than WPILIB's(read the Drive Rant)
* Interfaces
* Recording and Playback Utility
* Custom SSV Parsing (Space Separated Values)
* .rcd XboxController Format
* Input abstraction layer
* High Modularity
* C++ high performance

Arturita's code uses the following:
* Multithreading
* L-value References
* References
* Function Pointers
* "Multiple" Inheritance(Most of you would call the Interfaces)
* Abstract Classes
* Classes
* Static Variables
* File Reading and Writing


Major Portations Arturtia's code will eventually be migrated to a separate library that will be
Gradle-friendly and whatnot.

Organization
------------
There are multiple ways to present code. There will be multiple portions covered
by different presentations.

The reason for this is if I were to present the code in execution order, one
would have to jump to and fro.

Most people prefer a linear book. So I will have to include multiple paths of
execution in order to present the code in detail.

First, the general architecture will be discussed. Then we will go in execution
order.
We will first start with tele-op and then go into autonomous.
The library will be discussed in detail and finally any unused features.


Prerequisites
-------------
I do not write this to insult anyone's intelligence, but this code does use
features in C++ that are considered "strange" and usually brushed over in
tutorials for good reason. I intend to simply have this disclose what will be
discussed. Veteran C++ programmers will understand :)

C++ is a massive language. It can go as deep as the "C"(sea, ha ha ha funny
joke, please laugh).

You need to know only the basic features of C++, the intermediate and advanced
topics will be explained. However, for some, this may not be enough. This is
simply a list of what one needs to look up.

 The basic features of object oriented programming and
references will suffice a large portion.

Intermediate topics such as abstract classes and "multiple inheritance"(not the
evil one. It's called Interfaces in Java. Yes you've heard it here, Java does
support multiple inheritance. They just call it interfaces". It's like how Java
likes to call "namespaces" object oriented design. 

Multithreading and function pointers will be used in small sections. These topics are highly advanced;
with interesting syntax. Their gist will be explained and will be enough to
comprehend the code. 
