$AddRegPart 1    ;
M03 S600         ;
T01 M06          ;
G21              ;
G00 X00 Z64
X24              ;
G03 X48 Z52 R12  ;
G01 X40 Z48      ;
G02 X24 Z40 R8   ;
G01 Z20          ;
G02 X32 Z16 R4   ;
G03 X48 Z8 R8    ;
G01 Z00          ;
G00 X52 Z0
Z64 X00          ;
M05              ;
T19 M06          ;
M03 S600         ;
G00 X0 Z64       ;
G01 X0 Z40       ;
G01 X0 Z64       ;
M05              ;
M30              ;
