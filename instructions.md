# Opcode Summary

## Legend:

Symbol | Meaning
-------|----------------------------------------------------
`0`    | Literal 0 Bit
`1`    | Literal 1 Bit
`r`    | Destination Register
`a`    | Parameter Register A
`A`    | Parameter Register A with Special Register Values
`b`    | Parameter Register B
`c`    | Parameter Register C. Caveat: only four selectable
`i`    | Immediate Value A
`k`    | Immediate Value B
`x`    | Single Bit Mask Value
`.`    | Don't care bit

## Opcode Table:

ID     | UI | Decode | Mask                | Mnenomic             | Description
-------|----|--------|---------------------|----------------------|-----------------------------------
**00** | 00 | 00     | `00000rrr iiiiiiii` | `loadi`              | Load Immediate
**01** | 03 | 08     | `00001rrr iiiiiiii` | `addi`               | Add Immediate
**02** | 04 | 10     | `00010rrr iiiiiiii` | `subi`               | Subtract Immediate
**03** | 05 | 18     | `00011rrr iiiiiiii` | `muli`               | Multiply Immediate
**04** | 06 | 20     | `00100rrr iiiiiiii` | `divi`               | Divide Immediate
**05** | 07 | 28     | `00101rrr iiiiiiii` | `modi`               | Modulo Immediate
**06** | 15 | 30     | `00110rrr iiiiiiii` | `seqi`               | Skip If Equal Immediate
**07** | 16 | 38     | `00111rrr iiiiiiii` | `snei`               | Skip If Not Equal Immediate
**08** | 17 | 40     | `01000rrr iiiiiiii` | `slti`               | Skip If Less Than Immediate
**09** | 18 | 48     | `01001rrr iiiiiiii` | `sgti`               | Skip If Greater Than Immediate
**10** | 01 | 50     | `01010rrr iiiiiiii` | `loada`              | Load Absolute
**11** | 02 | 58     | `01011rrr iiiiiiii` | `storea`             | Store Absolute
**12** | 01 | 60, 00 | `01100rrr 00bbbaaa` | `loadr 0`            | Load Register Mode 0
**13** | 01 | 60, 40 | `01100rrr 01bbbaaa` | `loadr 1`            | Load Register Mode 1
**14** | 01 | 60, 80 | `01100rrr 10bbbaaa` | `loadr 2`            | Load Register Mode 2
**--** | -- | 60, C0 | `01100... 11......` | `--`                 | reserved
**--** | -- | 68     | `01101... ........` | `--`                 | reserved
**15** | 15 | 70, 00 | `01110rrr 0000AAAA` | `skipr eq`           | Skip Register Equal
**16** | 16 | 70, 10 | `01110rrr 0001AAAA` | `skipr ne`           | Skip Register Not Equal
**17** | 18 | 70, 20 | `01110rrr 0010AAAA` | `skipr gt`           | Skip Register Greater Than
**18** | 17 | 70, 30 | `01110rrr 0011AAAA` | `skipr lt`           | Skip Register Less Than
**19** | 20 | 70, 40 | `01110rrr 0100AAAA` | `skipr ge`           | Skip Register Greater Than Or Equal
**20** | 19 | 70, 50 | `01110rrr 0101AAAA` | `skipr le`           | Skip Register Less Than Or Equal
**--** | -- | 70, 60 | `01110... 0110....` | `--`                 | reserved
**--** | -- | 70, 70 | `01110... 0111....` | `--`                 | reserved
**--** | -- | 70, 80 | `01110... 1000....` | `--`                 | reserved
**--** | -- | 70, 90 | `01110... 1001....` | `--`                 | reserved
**--** | -- | 70, A0 | `01110... 1010....` | `--`                 | reserved
**--** | -- | 70, B0 | `01110... 1011....` | `--`                 | reserved
**--** | -- | 70, C0 | `01110... 1100....` | `--`                 | reserved
**--** | -- | 70, D0 | `01110... 1101....` | `--`                 | reserved
**--** | -- | 70, E0 | `01110... 1110....` | `--`                 | reserved
**--** | -- | 70, F0 | `01110... 1111....` | `--`                 | reserved
**21** | 01 | 78, 00 | `01111rrr 0000AAAA` | `mathr load`         | Register Load
**22** | 03 | 78, 10 | `01111rrr 0001AAAA` | `mathr add`          | Register Addition
**23** | 04 | 78, 20 | `01111rrr 0010AAAA` | `mathr sub`          | Register Subtraction
**24** | 08 | 78, 30 | `01111rrr 0011AAAA` | `mathr rshift`       | Register Right Shift
**25** | 09 | 78, 40 | `01111rrr 0100AAAA` | `mathr lshift`       | Register Left Shift
**26** | 05 | 78, 50 | `01111rrr 0101AAAA` | `mathr mult`         | Register Multiply
**27** | 06 | 78, 60 | `01111rrr 0110AAAA` | `mathr div`          | Register Divide
**28** | 07 | 78, 70 | `01111rrr 0111AAAA` | `mathr mod`          | Register Modulo
**29** | 12 | 78, 80 | `01111rrr 1000AAAA` | `mathr and`          | Register Bitwise AND
**30** | 13 | 78, 90 | `01111rrr 1001AAAA` | `mathr or`           | Register Bitwise OR
**31** | 14 | 78, A0 | `01111rrr 1010AAAA` | `mathr xor`          | Register Bitwise XOR
**32** | 10 | 78, B0 | `01111rrr 1011AAAA` | `mathr ror`          | Register Bitwise Right Rotate
**33** | 11 | 78, C0 | `01111rrr 1100AAAA` | `mathr rol`          | Register Bitwise Left Rotate
**--** |    | 78, D0 | `01111... 1101....` | `--`                 | reserved
**--** |    | 78, E0 | `01111... 1110....` | `--`                 | reserved
**--** |    | 78, F0 | `01111... 1111....` | `--`                 | reserved
**34** | 26 | F0     | `11110000 ........` | `NoOp`               | No Operation
**35** | 29 | F1     | `11110001 iiiiiiii` | `FillScreen`         | Fill the screen.
**36** | 28 | F2     | `11110010 kkbbbaaa` | `SetPixel`           | Set a pixel.
**37** | 27 | F3     | `11110011 ccbbbaaa` | `GetPixel`           | Read a pixel from screen.
**38** | 33 | F4     | `11110100 ccbbbaaa` | `PlayTone`           | Play an audio tone.
**39** | 32 | F5     | `11110101 ........` | `WaitForNextFrame`   | Wait until the frame has been drawn.
**40** | 21 | F6     | `11110110 ..xxxxxx` | `SkipIfButtonsDown`  | Skip the next instruction if buttons are held.
**41** | 22 | F7     | `11110111 ..xxxxxx` | `SkipIfButtonsUp`    | Skip the next instruction if buttons are up.
**42** | 23 | F8     | `11111000 iiiiiiii` | `JumpAbsolute`       | Jump PC to address absolute.
**43** | 24 | FA     | `11111010 .....aaa` | `JumpIndirect`       | Jumps PC to address based on register value.
**44** | -- | FB     | `11111011 ........` | `LoadRegisterValues` | TODO
**45** | -- | FC     | `11111100 ........` | `SaveRegisterValues` | TODO
**46** | 30 | FC     | `11111100 iiiiiiii` | `PrintString`        | Prints a string.
**47** | 31 | FD     | `11111101 ........` | `UpdateDisplay`      | Writes display buffer to screen.
**48** | -- | FE     | `11111110 ........` | `Reserved`           | Reserved.
**49** | 25 | FF     | `11111111 ........` | `Exit`               | Exits the program.
**50** | -- | 80     | `10000000 ........` | `BranchIfOverflow`   | Branch if overflow flag is set.

## UI Mapping

ID     | UI String
-------|-------------
**00** | Set ' '
**01** | Load ' '
**02** | Store ' '
**03** | Add To ' '
**04** | Subtr. To ' '
**05** | MultiplyTo ' '
**06** | DivideTo ' '
**07** | ModuloTo ' '
**08** | R. Shift ' '
**09** | L. Shift ' '
**10** | R. Rotate ' '
**11** | L. Rotate ' '
**12** | Bit AND ' '
**13** | Bit OR ' '
**14** | Bit XOR ' '
**15** | Skip = ' '
**16** | Skip =/= ' '
**17** | Skip < ' '
**18** | Skip > ' '
**19** | Skip <= ' '
**20** | Skip >= ' '
**21** | SkipIfDown
**22** | SkipIfUp
**23** | JumpTo
**24** | JumpVia
**25** | Exit
**26** | NoOp
**27** | GetPixel
**28** | DrawPixel
**29** | FillScreen
**30** | Print
**31** | UpdateDisplay
**32** | WaitForFrame
**33** | PlayTone
