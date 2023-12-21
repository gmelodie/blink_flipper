Compile and copy to flipper:
```bash
./fbt fap_blink && cp ./build/f7-firmware-D/.extapps/blink.fap /media/$USER/FLIPPER\ SD/apps/

./fbt fap_draw && cp ./build/f7-firmware-D/.extapps/draw.fap /media/$USER/FLIPPER\ SD/apps/
```

Next steps:
- Make draw change letters of string
- Make code accept input (back button to close)
- Interact with GPIO input
- Create more complicated circuits
