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

## Opcode Formats:

ID | Meaning
---|-------------------------------
00 | No paramters
01 | Number
02 | Address
03 | Button Map
04 | Register
05 | Register, Register, Number
06 | Register, Register, Small Register
07 | Register, Register
08 | Special Register

Note that opcodes on the zero plane always have an implicit destination register parameter.

## Opcode Table:

ID     | UI | Format | Decode | Mask            | Lookup     | Mnenomic             | Description
-------|----|----|--------|---------------------|------------|----------------------|-----------------------------------
**00** | 00 | 01 | 00     | `00000rrr iiiiiiii` | `0000xxxx` | `loadi`              | Load Immediate
**01** | 03 | 01 | 08     | `00001rrr iiiiiiii` | `0001xxxx` | `addi`               | Add Immediate
**02** | 04 | 01 | 10     | `00010rrr iiiiiiii` | `0010xxxx` | `subi`               | Subtract Immediate
**03** | 05 | 01 | 18     | `00011rrr iiiiiiii` | `0011xxxx` | `muli`               | Multiply Immediate
**04** | 06 | 01 | 20     | `00100rrr iiiiiiii` | `0010xxxx` | `divi`               | Divide Immediate
**05** | 07 | 01 | 28     | `00101rrr iiiiiiii` | `0101xxxx` | `modi`               | Modulo Immediate
**06** | 15 | 01 | 30     | `00110rrr iiiiiiii` | `0110xxxx` | `seqi`               | Skip If Equal Immediate
**07** | 16 | 01 | 38     | `00111rrr iiiiiiii` | `0111xxxx` | `snei`               | Skip If Not Equal Immediate
**08** | 17 | 01 | 40     | `01000rrr iiiiiiii` | `1000xxxx` | `slti`               | Skip If Less Than Immediate
**09** | 18 | 01 | 48     | `01001rrr iiiiiiii` | `1001xxxx` | `sgti`               | Skip If Greater Than Immediate
**10** | 01 | 01 | 50     | `01010rrr iiiiiiii` | `1010xxxx` | `loada`              | Load Absolute
**11** | 02 | 01 | 58     | `01011rrr iiiiiiii` | `1011xxxx` | `storea`             | Store Absolute
**12** | 01 | 07 | 60, 00 | `01100rrr 00bbbaaa` | `110000xx` | `loadr 0`            | Load Register Mode 0
**13** | 01 | 07 | 60, 40 | `01100rrr 01bbbaaa` | `110001xx` | `loadr 1`            | Load Register Mode 1
**14** | 01 | 07 | 60, 80 | `01100rrr 10bbbaaa` | `110010xx` | `loadr 2`            | Load Register Mode 2
**--** | -- | -- | 60, C0 | `01100... 11......` | `110011xx` | `--`                 | reserved
**--** | -- | -- | 68     | `01101... ........` | `1101xxxx` | `--`                 | reserved
**15** | 15 | 08 | 70, 00 | `01110rrr 0000AAAA` | `11100000` | `skipr eq`           | Skip Register Equal
**16** | 16 | 08 | 70, 10 | `01110rrr 0001AAAA` | `11100001` | `skipr ne`           | Skip Register Not Equal
**17** | 18 | 08 | 70, 20 | `01110rrr 0010AAAA` | `11100010` | `skipr gt`           | Skip Register Greater Than
**18** | 17 | 08 | 70, 30 | `01110rrr 0011AAAA` | `11100011` | `skipr lt`           | Skip Register Less Than
**19** | 20 | 08 | 70, 40 | `01110rrr 0100AAAA` | `11100100` | `skipr ge`           | Skip Register Greater Than Or Equal
**20** | 19 | 08 | 70, 50 | `01110rrr 0101AAAA` | `11100101` | `skipr le`           | Skip Register Less Than Or Equal
**--** | -- | -- | 70, 60 | `01110... 0110....` | `11100110` | `--`                 | reserved
**--** | -- | -- | 70, 70 | `01110... 0111....` | `11100111` | `--`                 | reserved
**--** | -- | -- | 70, 80 | `01110... 1000....` | `11101000` | `--`                 | reserved
**--** | -- | -- | 70, 90 | `01110... 1001....` | `11101001` | `--`                 | reserved
**--** | -- | -- | 70, A0 | `01110... 1010....` | `11101010` | `--`                 | reserved
**--** | -- | -- | 70, B0 | `01110... 1011....` | `11101011` | `--`                 | reserved
**--** | -- | -- | 70, C0 | `01110... 1100....` | `11101100` | `--`                 | reserved
**--** | -- | -- | 70, D0 | `01110... 1101....` | `11101101` | `--`                 | reserved
**--** | -- | -- | 70, E0 | `01110... 1110....` | `11101110` | `--`                 | reserved
**--** | -- | -- | 70, F0 | `01110... 1111....` | `11101111` | `--`                 | reserved
**21** | 01 | 08 | 78, 00 | `01111rrr 0000AAAA` | `11110000` | `mathr load`         | Register Load
**22** | 03 | 08 | 78, 10 | `01111rrr 0001AAAA` | `11110001` | `mathr add`          | Register Addition
**23** | 04 | 08 | 78, 20 | `01111rrr 0010AAAA` | `11110010` | `mathr sub`          | Register Subtraction
**24** | 08 | 08 | 78, 30 | `01111rrr 0011AAAA` | `11110011` | `mathr rshift`       | Register Right Shift
**25** | 09 | 08 | 78, 40 | `01111rrr 0100AAAA` | `11110100` | `mathr lshift`       | Register Left Shift
**26** | 05 | 08 | 78, 50 | `01111rrr 0101AAAA` | `11110101` | `mathr mult`         | Register Multiply
**27** | 06 | 08 | 78, 60 | `01111rrr 0110AAAA` | `11110110` | `mathr div`          | Register Divide
**28** | 07 | 08 | 78, 70 | `01111rrr 0111AAAA` | `11110111` | `mathr mod`          | Register Modulo
**29** | 12 | 08 | 78, 80 | `01111rrr 1000AAAA` | `11111000` | `mathr and`          | Register Bitwise AND
**30** | 13 | 08 | 78, 90 | `01111rrr 1001AAAA` | `11111001` | `mathr or`           | Register Bitwise OR
**31** | 14 | 08 | 78, A0 | `01111rrr 1010AAAA` | `11111010` | `mathr xor`          | Register Bitwise XOR
**32** | 10 | 08 | 78, B0 | `01111rrr 1011AAAA` | `11111011` | `mathr ror`          | Register Bitwise Right Rotate
**33** | 11 | 08 | 78, C0 | `01111rrr 1100AAAA` | `11111100` | `mathr rol`          | Register Bitwise Left Rotate
**--** | -- | -- | 78, D0 | `01111... 1101....` | `11111101` | `--`                 | reserved
**--** | -- | -- | 78, E0 | `01111... 1110....` | `11111110` | `--`                 | reserved
**--** | -- | -- | 78, F0 | `01111... 1111....` | `11111111` | `--`                 | reserved
**34** | 26 | 00 | F0     | `11110000 ........` | `01110000` | `NoOp`               | No Operation
**35** | 29 | 01 | F1     | `11110001 iiiiiiii` | `01110001` | `FillScreen`         | Fill the screen.
**36** | 28 | 06 | F2     | `11110010 kkbbbaaa` | `01110010` | `SetPixel`           | Set a pixel.
**37** | 27 | 05 | F3     | `11110011 ccbbbaaa` | `01110011` | `GetPixel`           | Read a pixel from screen.
**38** | 33 | 05 | F4     | `11110100 ccbbbaaa` | `01110100` | `PlayTone`           | Play an audio tone.
**39** | 32 | 00 | F5     | `11110101 ........` | `01110101` | `WaitForNextFrame`   | Wait until the frame has been drawn.
**40** | 21 | 03 | F6     | `11110110 ..xxxxxx` | `01110110` | `SkipIfButtonsDown`  | Skip the next instruction if buttons are held.
**41** | 22 | 03 | F7     | `11110111 ..xxxxxx` | `01110111` | `SkipIfButtonsUp`    | Skip the next instruction if buttons are up.
**42** | 23 | 01 | F8     | `11111000 iiiiiiii` | `01111000` | `JumpAbsolute`       | Jump PC to address absolute.
**43** | 24 | 04 | FA     | `11111010 .....aaa` | `01111010` | `JumpIndirect`       | Jumps PC to address based on register value.
**44** | -- | -- | FB     | `11111011 ........` | `01111011` | `LoadRegisterValues` | TODO
**45** | -- | -- | FC     | `11111100 ........` | `01111100` | `SaveRegisterValues` | TODO
**46** | 30 | 01 | FC     | `11111100 iiiiiiii` | `01111100` | `PrintString`        | Prints a string.
**47** | 31 | 00 | FD     | `11111101 ........` | `01111101` | `UpdateDisplay`      | Writes display buffer to screen.
**48** | -- | -- | FE     | `11111110 ........` | `01111110` | `Reserved`           | Reserved.
**49** | 25 | 00 | FF     | `11111111 ........` | `01111111` | `Exit`               | Exits the program.
**50** | -- | -- | 80     | `10000000 ........` | `00000000` | `BranchIfOverflow`   | Branch if overflow flag is set.

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
