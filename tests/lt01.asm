@1
D=A
@SP
A=M
M=D
@SP
M=M+1


@LCL
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1


@SP
AM=M-1
D=M
@SP
AM=M-1
D=M-D
@JLT_TRUE_0
D;JLT
D=0
@JLT_FALSE_0
0;JMP
(JLT_TRUE_0)
D=-1
(JLT_FALSE_0)
@SP
A=M
M=D
@SP
M=M+1


@0
M=M-1
A=M
D=M
@13
M=D
@0
D=A
@THIS
A=M
D=A+D
@14
M=D
@13
D=M
@14
A=M
M=D


@9
D=A
@SP
A=M
M=D
@SP
M=M+1


@0
D=A
@SP
A=M
M=D
@SP
M=M+1


@SP
AM=M-1
D=M
@SP
AM=M-1
D=M-D
@JLT_TRUE_1
D;JLT
D=0
@JLT_FALSE_1
0;JMP
(JLT_TRUE_1)
D=-1
(JLT_FALSE_1)
@SP
A=M
M=D
@SP
M=M+1


@0
M=M-1
A=M
D=M
@13
M=D
@1
D=A
@THIS
A=M
D=A+D
@14
M=D
@13
D=M
@14
A=M
M=D


@ARG
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1


@0
D=A
@SP
A=M
M=D
@SP
M=M+1


@SP
AM=M-1
D=M
@SP
AM=M-1
D=M-D
@JLT_TRUE_2
D;JLT
D=0
@JLT_FALSE_2
0;JMP
(JLT_TRUE_2)
D=-1
(JLT_FALSE_2)
@SP
A=M
M=D
@SP
M=M+1


@0
M=M-1
A=M
D=M
@13
M=D
@2
D=A
@THIS
A=M
D=A+D
@14
M=D
@13
D=M
@14
A=M
M=D


@3
D=A
@SP
A=M
M=D
@SP
M=M+1


@THAT
D=M
@0
A=A+D
D=M
@SP
A=M
M=D
@SP
M=M+1


@SP
AM=M-1
D=M
@SP
AM=M-1
D=M-D
@JLT_TRUE_3
D;JLT
D=0
@JLT_FALSE_3
0;JMP
(JLT_TRUE_3)
D=-1
(JLT_FALSE_3)
@SP
A=M
M=D
@SP
M=M+1


@0
M=M-1
A=M
D=M
@13
M=D
@3
D=A
@THIS
A=M
D=A+D
@14
M=D
@13
D=M
@14
A=M
M=D


