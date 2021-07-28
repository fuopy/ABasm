
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

ID | Mask | Opcode | Description
-|-|-|-
**00** | `0rrr0000 iiiiiiii` | `loadi` | Load Immediate
**01** | `0rrr0001 iiiiiiii` | `addi` | Add Immediate
**02** | `0rrr0010 iiiiiiii` | `subi` | Subtract Immediate
**03** | `0rrr0011 iiiiiiii` | `muli` | Multiply Immediate
**04** | `0rrr0100 iiiiiiii` | `divi` | Divide Immediate
**05** | `0rrr0101 iiiiiiii` | `modi` | Modulo Immediate
**06** | `0rrr0110 iiiiiiii` | `seqi` | Skip If Equal Immediate
**07** | `0rrr0111 iiiiiiii` | `snei` | Skip If Not Equal Immediate
**08** | `0rrr1000 iiiiiiii` | `slti` | Skip If Less Than Immediate
**09** | `0rrr1001 iiiiiiii` | `sgti` | Skip If Greater Than Immediate
**10** | `0rrr1010 iiiiiiii` | `loada` | Load Absolute
**11** | `0rrr1011 iiiiiiii` | `storea` | Store Absolute
**12** | `0rrr1100 00bbbaaa` | `loadr 0` | Load Register Mode 0
**13** | `0rrr1100 01bbbaaa` | `loadr 1` | Load Register Mode 1
**14** | `0rrr1100 10bbbaaa` | `loadr 2` | Load Register Mode 2
**--** | `0...1100 11......` | `--` | reserved
**--** | `0...1101 ........` | `--` | reserved
**16** | `0rrr1110 0000AAAA` | `skipr eq` | Skip Register Equal
**17** | `0rrr1110 0001AAAA` | `skipr ne` | Skip Register Not Equal
**18** | `0rrr1110 0010AAAA` | `skipr gt` | Skip Register Greater Than
**19** | `0rrr1110 0011AAAA` | `skipr lt` | Skip Register Less Than
**20** | `0rrr1110 0100AAAA` | `skipr ge` | Skip Register Greater Than Or Equal
**21** | `0rrr1110 0101AAAA` | `skipr le` | Skip Register Less Than Or Equal
**--** | `0...1110 0110....` | `--` | reserved
**--** | `0...1110 0111....` | `--` | reserved
**--** | `0...1110 1000....` | `--` | reserved
**--** | `0...1110 1001....` | `--` | reserved
**--** | `0...1110 1010....` | `--` | reserved
**--** | `0...1110 1011....` | `--` | reserved
**--** | `0...1110 1100....` | `--` | reserved
**--** | `0...1110 1101....` | `--` | reserved
**--** | `0...1110 1110....` | `--` | reserved
**--** | `0...1110 1111....` | `--` | reserved
**32** | `0rrr1111 0000AAAA` | `mathr load` | Register Load
**33** | `0rrr1111 0001AAAA` | `mathr add` | Register Addition
**34** | `0rrr1111 0010AAAA` | `mathr sub` | Register Subtraction
**35** | `0rrr1111 0011AAAA` | `mathr rshift` | Register Right Shift
**36** | `0rrr1111 0100AAAA` | `mathr lshift` | Register Left Shift
**37** | `0rrr1111 0101AAAA` | `mathr mult` | Register Multiply
**38** | `0rrr1111 0110AAAA` | `mathr div` | Register Divide
**39** | `0rrr1111 0111AAAA` | `mathr mod` | Register Modulo
**40** | `0rrr1111 1000AAAA` | `mathr and` | Register Bitwise AND
**41** | `0rrr1111 1001AAAA` | `mathr or` | Register Bitwise OR
**42** | `0rrr1111 1010AAAA` | `mathr xor` | Register Bitwise XOR
**43** | `0rrr1111 1011AAAA` | `mathr ror` | Register Bitwise Right Rotate
**44** | `0rrr1111 1100AAAA` | `mathr rol` | Register Bitwise Left Rotate
**--** | `0...1111 1101....` | `--` | reserved
**--** | `0...1111 1110....` | `--` | reserved
**--** | `0...1111 1111....` | `--` | reserved
**45** | `11110000 ........` | `NoOp` | No Operation
**46** | `11110001 iiiiiiii` | `FillScreen` | Fill the screen.
**47** | `11110010 kkbbbaaa` | `SetPixel` | Set a pixel.
**48** | `11110011 ccbbbaaa` | `GetPixel` | Read a pixel from screen.
**49** | `11110100 ccbbbaaa` | `PlayTone` | Play an audio tone.
**50** | `11110101 ........` | `WaitForNextFrame` | Wait until the frame has been drawn.
**51** | `11110110 ..xxxxxx` | `SkipIfButtonsDown` | Skip the next instruction if buttons are held.
**52** | `11110111 ..xxxxxx` | `SkipIfButtonsUp` | Skip the next instruction if buttons are up.
**53** | `11111000 iiiiiiii` | `JumpAbsolute` | Jump PC to address absolute.
**54** | `11111010 .....aaa` | `JumpIndirect` | Jumps PC to address based on register value.
**55** | `11111011 ........` | `LoadRegisterValues` | TODO
**56** | `11111100 ........` | `SaveRegisterValues` | TODO
**57** | `11111100 iiiiiiii` | `PrintString` | Prints a string.
**58** | `11111101 ........` | `UpdateDisplay` | Writes display buffer to screen.
**59** | `11111110 ........` | `Reserved` | Reserved.
**60** | `11111111 ........` | `Exit` | Exits the program.
**61** | `10000000 ........` | `BranchIfOverflow` | Branch if overflow flag is set.