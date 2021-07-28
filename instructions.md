
ID | Opcode | Description
-|-|-
0  | loadi | Load Immediate
1  | addi | Add Immediate
2  | subi | Subtract Immediate
3  | muli | Multiply Immediate
4  | divi | Divide Immediate
5  | modi | Modulo Immediate
6  | seqi | Skip If Equal Immediate
7  | snei | Skip If Not Equal Immediate
8  | slti | Skip If Less Than Immediate
9  | sgti | Skip If Greater Than Immediate
10 | loada | Load Absolute
11 | storea | Store Absolute
12 | loadr 0 | Load Register Mode 0
13 | loadr 1 | Load Register Mode 1
14 | loadr 2 | Load Register Mode 2
15 | loadr 3 | reserved
16 | skipr eq | Skip Register Equal
17 | skipr ne | Skip Register Not Equal
18 | skipr gt | Skip Register Greater Than
19 | skipr lt | Skip Register Less Than
20 | skipr ge | Skip Register Greater Than Or Equal
21 | skipr le | Skip Register Less Than Or Equal
22 | skipr 6 | reserved
23 | skipr 7 | reserved
24 | skipr 8 | reserved
25 | skipr 9 | reserved
26 | skipr A | reserved
27 | skipr B | reserved
28 | skipr C | reserved
29 | skipr D | reserved
30 | skipr E | reserved
31 | skipr F | reserved
32 | mathr load | Register Load
33 | mathr add | Register Addition
34 | mathr sub | Register Subtraction
35 | mathr rshift | Register Right Shift
36 | mathr lshift | Register Left Shift
37 | mathr mult | Register Multiply
38 | mathr div | Register Divide
39| mathr mod | Register Modulo
40 | mathr and | Register Bitwise AND
41 | mathr or | Register Bitwise OR
42 | mathr xor | Register Bitwise XOR
43 | mathr ror | Register Bitwise Right Rotate
44 | mathr rol | Register Bitwise Left Rotate
45 | NoOp | No Operation
46 | FillScreen | Fill the screen.
47 | SetPixel | Set a pixel.
48 | GetPixel | Read a pixel from screen.
49 | PlayTone | Play an audio tone.
50 | WaitForNextFrame | Wait until the frame has been drawn.
51 | SkipIfButtonsDown | Skip the next instruction if buttons are held.
52 | SkipIfButtonsUp | Skip the next instruction if buttons are up.
53 | JumpAbsolute | Jump PC to address absolute.
54 | JumpIndirect | Jumps PC to address based on register value.
55 | LoadRegisterValues | TODO
56 | SaveRegisterValues | TODO
57 | PrintString | Prints a string.
58 | UpdateDisplay | Writes display buffer to screen.
59 | Reserved | Reserved.
60 | Exit | Exits the program.
61 | BranchIfOverflow | Branch if overflow flag is set.