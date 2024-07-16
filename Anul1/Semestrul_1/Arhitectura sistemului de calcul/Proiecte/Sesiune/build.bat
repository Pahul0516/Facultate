nasm -f obj p1.asm
nasm -f obj p2.asm
alink p1.obj p2.obj -oPE -subsys console -entry start