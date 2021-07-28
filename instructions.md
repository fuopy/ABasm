
## Opcode Summary

### Legend:
Symbol | Meaning
-|-
`0` | Literal 0 Bit
`1` | Literal 1 Bit
`r` | Destination Register
`a` | Parameter Register A
`A` | Parameter Register A with Special Register Values
`b` | Parameter Register B
`c` | Parameter Register C. Caveat: only four selectable
`i` | Immediate Value A
`k` | Immediate Value B
`x` | Single Bit Mask Value
`.` | Don't care bit

### Opcode Table:

ID     | Mask                | Mnenomic             | UI Alias      | Description
-------|---------------------|----------------------|---------------|-----------------------------------
**00** | `0rrr0000 iiiiiiii` | `loadi`              | Set ' '       | Load Immediate
**01** | `0rrr0001 iiiiiiii` | `addi`               | Add To ' '    | Add Immediate
**02** | `0rrr0010 iiiiiiii` | `subi`               | Subtr. To ' ' | Subtract Immediate
**03** | `0rrr0011 iiiiiiii` | `muli`               | MiltiplyTo' ' | Multiply Immediate
**04** | `0rrr0100 iiiiiiii` | `divi`               | DivideTo' '   | Divide Immediate
**05** | `0rrr0101 iiiiiiii` | `modi`               | ModuloTo' '   | Modulo Immediate
**06** | `0rrr0110 iiiiiiii` | `seqi`               | Skip= ' '     | Skip If Equal Immediate
**07** | `0rrr0111 iiiiiiii` | `snei`               | Skip=/= ' '   | Skip If Not Equal Immediate
**08** | `0rrr1000 iiiiiiii` | `slti`               | Skip< ' '     | Skip If Less Than Immediate
**09** | `0rrr1001 iiiiiiii` | `sgti`               | Skip> ' '     | Skip If Greater Than Immediate
**10** | `0rrr1010 iiiiiiii` | `loada`              | Load ' '      | Load Absolute
**11** | `0rrr1011 iiiiiiii` | `storea`             | Store ' '     | Store Absolute
**12** | `0rrr1100 00bbbaaa` | `loadr 0`            | Load ' '      | Load Register Mode 0
**13** | `0rrr1100 01bbbaaa` | `loadr 1`            | Load ' '      | Load Register Mode 1
**14** | `0rrr1100 10bbbaaa` | `loadr 2`            | Load ' '      | Load Register Mode 2
**--** | `0...1100 11......` | `--`                 | --            | reserved
**--** | `0...1101 ........` | `--`                 | --            | reserved
**15** | `0rrr1110 0000AAAA` | `skipr eq`           | Skip= ' '     | Skip Register Equal
**16** | `0rrr1110 0001AAAA` | `skipr ne`           | Skip=/= ' '   | Skip Register Not Equal
**17** | `0rrr1110 0010AAAA` | `skipr gt`           | Skip> ' '     | Skip Register Greater Than
**18** | `0rrr1110 0011AAAA` | `skipr lt`           | Skip< ' '     | Skip Register Less Than
**19** | `0rrr1110 0100AAAA` | `skipr ge`           | Skip>= ' '    | Skip Register Greater Than Or Equal
**20** | `0rrr1110 0101AAAA` | `skipr le`           | Skip<= ' '    | Skip Register Less Than Or Equal
**--** | `0...1110 0110....` | `--`                 | --            | reserved
**--** | `0...1110 0111....` | `--`                 | --            | reserved
**--** | `0...1110 1000....` | `--`                 | --            | reserved
**--** | `0...1110 1001....` | `--`                 | --            | reserved
**--** | `0...1110 1010....` | `--`                 | --            | reserved
**--** | `0...1110 1011....` | `--`                 | --            | reserved
**--** | `0...1110 1100....` | `--`                 | --            | reserved
**--** | `0...1110 1101....` | `--`                 | --            | reserved
**--** | `0...1110 1110....` | `--`                 | --            | reserved
**--** | `0...1110 1111....` | `--`                 | --            | reserved
**21** | `0rrr1111 0000AAAA` | `mathr load`         | Load ' '      | Register Load
**22** | `0rrr1111 0001AAAA` | `mathr add`          | Add To ' '    | Register Addition
**23** | `0rrr1111 0010AAAA` | `mathr sub`          | Subtr. To ' ' | Register Subtraction
**24** | `0rrr1111 0011AAAA` | `mathr rshift`       | R. Shift ' '  | Register Right Shift
**25** | `0rrr1111 0100AAAA` | `mathr lshift`       | L. Shift ' '  | Register Left Shift
**26** | `0rrr1111 0101AAAA` | `mathr mult`         | MiltiplyTo' ' | Register Multiply
**27** | `0rrr1111 0110AAAA` | `mathr div`          | DivideTo' '   | Register Divide
**28** | `0rrr1111 0111AAAA` | `mathr mod`          | ModuloTo' '   | Register Modulo
**29** | `0rrr1111 1000AAAA` | `mathr and`          | Bit AND ' '   | Register Bitwise AND
**30** | `0rrr1111 1001AAAA` | `mathr or`           | Bit OR ' '    | Register Bitwise OR
**31** | `0rrr1111 1010AAAA` | `mathr xor`          | Bit XOR ' '   | Register Bitwise XOR
**32** | `0rrr1111 1011AAAA` | `mathr ror`          | R. Rotate     | Register Bitwise Right Rotate
**33** | `0rrr1111 1100AAAA` | `mathr rol`          | L. Rotate     | Register Bitwise Left Rotate
**--** | `0...1111 1101....` | `--`                 |               | reserved
**--** | `0...1111 1110....` | `--`                 |               | reserved
**--** | `0...1111 1111....` | `--`                 |               | reserved
**34** | `11110000 ........` | `NoOp`               | NoOp          | No Operation
**35** | `11110001 iiiiiiii` | `FillScreen`         | FillScreen    | Fill the screen.
**36** | `11110010 kkbbbaaa` | `SetPixel`           | DrawPixel     | Set a pixel.
**37** | `11110011 ccbbbaaa` | `GetPixel`           | GetPixel      | Read a pixel from screen.
**38** | `11110100 ccbbbaaa` | `PlayTone`           | PlayTone      | Play an audio tone.
**39** | `11110101 ........` | `WaitForNextFrame`   | WaitForFrame  | Wait until the frame has been drawn.
**40** | `11110110 ..xxxxxx` | `SkipIfButtonsDown`  | SkipIfDown    | Skip the next instruction if buttons are held.
**41** | `11110111 ..xxxxxx` | `SkipIfButtonsUp`    | SkipIfUp      | Skip the next instruction if buttons are up.
**42** | `11111000 iiiiiiii` | `JumpAbsolute`       | JumpTo        | Jump PC to address absolute.
**43** | `11111010 .....aaa` | `JumpIndirect`       | JumpVia       | Jumps PC to address based on register value.
**44** | `11111011 ........` | `LoadRegisterValues` | --            | TODO
**45** | `11111100 ........` | `SaveRegisterValues` | --            | TODO
**46** | `11111100 iiiiiiii` | `PrintString`        | Print         | Prints a string.
**47** | `11111101 ........` | `UpdateDisplay`      | UpdateDisplay | Writes display buffer to screen.
**48** | `11111110 ........` | `Reserved`           | --            | Reserved.
**49** | `11111111 ........` | `Exit`               | Exit          | Exits the program.
**50** | `10000000 ........` | `BranchIfOverflow`   | --            | Branch if overflow flag is set.