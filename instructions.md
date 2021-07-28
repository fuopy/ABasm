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

ID     | UI | Mask                | Mnenomic             | Description
-------|----|---------------------|----------------------|-----------------------------------
**00** | 00 | `0rrr0000 iiiiiiii` | `loadi`              | Load Immediate
**01** | 03 | `0rrr0001 iiiiiiii` | `addi`               | Add Immediate
**02** | 04 | `0rrr0010 iiiiiiii` | `subi`               | Subtract Immediate
**03** | 05 | `0rrr0011 iiiiiiii` | `muli`               | Multiply Immediate
**04** | 06 | `0rrr0100 iiiiiiii` | `divi`               | Divide Immediate
**05** | 07 | `0rrr0101 iiiiiiii` | `modi`               | Modulo Immediate
**06** | 15 | `0rrr0110 iiiiiiii` | `seqi`               | Skip If Equal Immediate
**07** | 16 | `0rrr0111 iiiiiiii` | `snei`               | Skip If Not Equal Immediate
**08** | 17 | `0rrr1000 iiiiiiii` | `slti`               | Skip If Less Than Immediate
**09** | 18 | `0rrr1001 iiiiiiii` | `sgti`               | Skip If Greater Than Immediate
**10** | 01 | `0rrr1010 iiiiiiii` | `loada`              | Load Absolute
**11** | 02 | `0rrr1011 iiiiiiii` | `storea`             | Store Absolute
**12** | 01 | `0rrr1100 00bbbaaa` | `loadr 0`            | Load Register Mode 0
**13** | 01 | `0rrr1100 01bbbaaa` | `loadr 1`            | Load Register Mode 1
**14** | 01 | `0rrr1100 10bbbaaa` | `loadr 2`            | Load Register Mode 2
**--** | -- | `0...1100 11......` | `--`                 | reserved
**--** | -- | `0...1101 ........` | `--`                 | reserved
**15** | 15 | `0rrr1110 0000AAAA` | `skipr eq`           | Skip Register Equal
**16** | 16 | `0rrr1110 0001AAAA` | `skipr ne`           | Skip Register Not Equal
**17** | 18 | `0rrr1110 0010AAAA` | `skipr gt`           | Skip Register Greater Than
**18** | 17 | `0rrr1110 0011AAAA` | `skipr lt`           | Skip Register Less Than
**19** | 20 | `0rrr1110 0100AAAA` | `skipr ge`           | Skip Register Greater Than Or Equal
**20** | 19 | `0rrr1110 0101AAAA` | `skipr le`           | Skip Register Less Than Or Equal
**--** | -- | `0...1110 0110....` | `--`                 | reserved
**--** | -- | `0...1110 0111....` | `--`                 | reserved
**--** | -- | `0...1110 1000....` | `--`                 | reserved
**--** | -- | `0...1110 1001....` | `--`                 | reserved
**--** | -- | `0...1110 1010....` | `--`                 | reserved
**--** | -- | `0...1110 1011....` | `--`                 | reserved
**--** | -- | `0...1110 1100....` | `--`                 | reserved
**--** | -- | `0...1110 1101....` | `--`                 | reserved
**--** | -- | `0...1110 1110....` | `--`                 | reserved
**--** | -- | `0...1110 1111....` | `--`                 | reserved
**21** | 01 | `0rrr1111 0000AAAA` | `mathr load`         | Register Load
**22** | 03 | `0rrr1111 0001AAAA` | `mathr add`          | Register Addition
**23** | 04 | `0rrr1111 0010AAAA` | `mathr sub`          | Register Subtraction
**24** | 08 | `0rrr1111 0011AAAA` | `mathr rshift`       | Register Right Shift
**25** | 09 | `0rrr1111 0100AAAA` | `mathr lshift`       | Register Left Shift
**26** | 05 | `0rrr1111 0101AAAA` | `mathr mult`         | Register Multiply
**27** | 06 | `0rrr1111 0110AAAA` | `mathr div`          | Register Divide
**28** | 07 | `0rrr1111 0111AAAA` | `mathr mod`          | Register Modulo
**29** | 12 | `0rrr1111 1000AAAA` | `mathr and`          | Register Bitwise AND
**30** | 13 | `0rrr1111 1001AAAA` | `mathr or`           | Register Bitwise OR
**31** | 14 | `0rrr1111 1010AAAA` | `mathr xor`          | Register Bitwise XOR
**32** | 10 | `0rrr1111 1011AAAA` | `mathr ror`          | Register Bitwise Right Rotate
**33** | 11 | `0rrr1111 1100AAAA` | `mathr rol`          | Register Bitwise Left Rotate
**--** |    | `0...1111 1101....` | `--`                 | reserved
**--** |    | `0...1111 1110....` | `--`                 | reserved
**--** |    | `0...1111 1111....` | `--`                 | reserved
**34** | 26 | `11110000 ........` | `NoOp`               | No Operation
**35** | 29 | `11110001 iiiiiiii` | `FillScreen`         | Fill the screen.
**36** | 28 | `11110010 kkbbbaaa` | `SetPixel`           | Set a pixel.
**37** | 27 | `11110011 ccbbbaaa` | `GetPixel`           | Read a pixel from screen.
**38** | 33 | `11110100 ccbbbaaa` | `PlayTone`           | Play an audio tone.
**39** | 32 | `11110101 ........` | `WaitForNextFrame`   | Wait until the frame has been drawn.
**40** | 21 | `11110110 ..xxxxxx` | `SkipIfButtonsDown`  | Skip the next instruction if buttons are held.
**41** | 22 | `11110111 ..xxxxxx` | `SkipIfButtonsUp`    | Skip the next instruction if buttons are up.
**42** | 23 | `11111000 iiiiiiii` | `JumpAbsolute`       | Jump PC to address absolute.
**43** | 24 | `11111010 .....aaa` | `JumpIndirect`       | Jumps PC to address based on register value.
**44** | -- | `11111011 ........` | `LoadRegisterValues` | TODO
**45** | -- | `11111100 ........` | `SaveRegisterValues` | TODO
**46** | 30 | `11111100 iiiiiiii` | `PrintString`        | Prints a string.
**47** | 31 | `11111101 ........` | `UpdateDisplay`      | Writes display buffer to screen.
**48** | -- | `11111110 ........` | `Reserved`           | Reserved.
**49** | 25 | `11111111 ........` | `Exit`               | Exits the program.
**50** | -- | `10000000 ........` | `BranchIfOverflow`   | Branch if overflow flag is set.

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
