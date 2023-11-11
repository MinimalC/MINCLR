# Gemeinfrei. Public Domain.

.macro function name
.global \name
.type \name,@function
\name:
.endm

.macro hidden_function name
.hidden \name
.global \name
.type \name,@function
\name:
.endm

.macro end_function name
.size \name,.-\name
.endm

.macro call_function name
call  \name##@PLT
.endm
