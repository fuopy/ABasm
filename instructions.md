
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
`i` | Immediate Value
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
**--** | `0rrr1100 11bbbaaa` | `--` | reserved
**--** | `0rrr1101 ....aaaa` | `--` | reserved
**16** | `0rrr1110 ....aaaa` | `skipr eq` | Skip Register Equal
**17** | `0rrr1110 ....aaaa` | `skipr ne` | Skip Register Not Equal
**18** | `0rrr1110 ....aaaa` | `skipr gt` | Skip Register Greater Than
**19** | `0rrr1110 ....aaaa` | `skipr lt` | Skip Register Less Than
**20** | `0rrr1110 ....aaaa` | `skipr ge` | Skip Register Greater Than Or Equal
**21** | `0rrr1110 ....aaaa` | `skipr le` | Skip Register Less Than Or Equal
**22** | `0rrr1110 ....aaaa` | `skipr 6` | reserved
**23** | `0rrr1110 ....aaaa` | `skipr 7` | reserved
**24** | `0rrr1110 ....aaaa` | `skipr 8` | reserved
**25** | `0rrr1110 ....aaaa` | `skipr 9` | reserved
**26** | `0rrr1110 ....aaaa` | `skipr A` | reserved
**27** | `0rrr1110 ....aaaa` | `skipr B` | reserved
**28** | `0rrr1110 ....aaaa` | `skipr C` | reserved
**29** | `0rrr1110 ....aaaa` | `skipr D` | reserved
**30** | `0rrr1110 ....aaaa` | `skipr E` | reserved
**31** | `0rrr1110 ....aaaa` | `skipr F` | reserved
**32** | `0rrr1111 ........` | `mathr load` | Register Load
**33** | `0rrr1111 ........` | `mathr add` | Register Addition
**34** | `0rrr1111 ........` | `mathr sub` | Register Subtraction
**35** | `0rrr1111 ........` | `mathr rshift` | Register Right Shift
**36** | `0rrr1111 ........` | `mathr lshift` | Register Left Shift
**37** | `0rrr1111 ........` | `mathr mult` | Register Multiply
**38** | `0rrr1111 ........` | `mathr div` | Register Divide
**39** | `0rrr1111 ........` | `mathr mod` | Register Modulo
**40** | `0rrr1111 ........` | `mathr and` | Register Bitwise AND
**41** | `0rrr1111 ........` | `mathr or` | Register Bitwise OR
**42** | `0rrr1111 ........` | `mathr xor` | Register Bitwise XOR
**43** | `0rrr1111 ........` | `mathr ror` | Register Bitwise Right Rotate
**44** | `0rrr1111 ........` | `mathr rol` | Register Bitwise Left Rotate
**45** | `1....... ........` | `NoOp` | No Operation
**46** | `1....... ........` | `FillScreen` | Fill the screen.
**47** | `1....... ........` | `SetPixel` | Set a pixel.
**48** | `1....... ........` | `GetPixel` | Read a pixel from screen.
**49** | `1....... ........` | `PlayTone` | Play an audio tone.
**50** | `1....... ........` | `WaitForNextFrame` | Wait until the frame has been drawn.
**51** | `1....... ........` | `SkipIfButtonsDown` | Skip the next instruction if buttons are held.
**52** | `1....... ........` | `SkipIfButtonsUp` | Skip the next instruction if buttons are up.
**53** | `1....... ........` | `JumpAbsolute` | Jump PC to address absolute.
**54** | `1....... ........` | `JumpIndirect` | Jumps PC to address based on register value.
**55** | `1....... ........` | `LoadRegisterValues` | TODO
**56** | `1....... ........` | `SaveRegisterValues` | TODO
**57** | `1....... ........` | `PrintString` | Prints a string.
**58** | `1....... ........` | `UpdateDisplay` | Writes display buffer to screen.
**59** | `1....... ........` | `Reserved` | Reserved.
**60** | `1....... ........` | `Exit` | Exits the program.
**61** | `1....... ........` | `BranchIfOverflow` | Branch if overflow flag is set.