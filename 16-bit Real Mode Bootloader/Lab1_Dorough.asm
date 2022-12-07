;;; James Riley Dorough 03SEP21

org 0x7c00 ;;; This org code needs to be present due to the labels
mov si, output
mov ah, 0x0e

loop:
mov al, [si]
cmp al, 0h;;; You must add a compare instructure here looking for a certain character to know you are at the end of the string. 
je output
int 0x10;;; You must add the BIOS interrupt call instruction here to print a character to the screen
add si, 1;;; You must increment a certain register here using the proper assembly instruction to move to the next byte position
jmp loop

output:
db 'Welcome to CSIS-443', 0
;;; You must use the declare byte instruction here to define the string 'Welcome to CSIS-443' 
;;; with a terminating zero
;;; You must give it the assembly label of 'output' (without quotes)

times 510-($-$$) db 0
dw 0xaa55

