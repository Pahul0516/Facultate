nasm modul2.asm -fwin32 -o modul2.obj

cl /Z7 main2.c /link modul2.obj