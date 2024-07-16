nasm -f obj sir1.asm
nasm -f obj sir2.asm
alink sir1.obj sir2.obj -oPE -subsys console -entry start