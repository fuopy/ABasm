## Description
ABasm is an Arduboy game that lets you program your own Arduboy games, on your Arduboy! It uses an assembly language-style of programming with its own bytecode format.

## Instructions

To quickly get up and running, hold left on boot to load up the example program. From there you can use the D-Pad to select an opcode. Hold A and press Up or Down to change a parameter. Hold B to open the menu bar, and release B to choose an option.

## Media

<blockquote class="twitter-video" data-lang="en"><p lang="en" dir="ltr">Makin&#39; games for the Arduboy, on the Arduboy! <a href="https://twitter.com/hashtag/gamedev?src=hash">#gamedev</a> <a href="https://twitter.com/hashtag/assembly?src=hash">#assembly</a> <a href="https://twitter.com/hashtag/virtualmachine?src=hash">#virtualmachine</a> <a href="https://t.co/QHreqbxjKu">pic.twitter.com/QHreqbxjKu</a></p>&mdash; fuopy (@fuopy) <a href="https://twitter.com/fuopy/status/745530961450827776">June 22, 2016</a></blockquote>
<script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script>

## Installation

* Download the [Souce Code ZIP](https://github.com/fuopy/ABasm) from GitHub
* Rename the extracted "ABasm-master" folder to "ABasm"
* Open ABasm.ino with Arduino IDE 1.6.12+
* Click the upload button to install to your Arduboy

## Tips

* The cursor position in the menubar is stored. This is useful for repeating an operation, such as Delete+MoveJumps
* Hold LEFT on boot to load the default program
* Hold DOWN on boot to start with an empty program

## Developer's Notice

I have released this under the label "Developer Preview 1." As a hobby, I've been working on figuring out different ways of describing the types of games I'd like to make. This was created in an attempt to capture something I really want to see more of-- portable game development. While I'm pretty happy to share this project with everyone, I know I need to do many more redesigns before I can be satisfied. Either way, I hope you enjoy it! I'd love to hear feedback from anyone attempting to create something with it. And I definitely want to hear any sort of criticism about the bytecode format (or anything else you see!)