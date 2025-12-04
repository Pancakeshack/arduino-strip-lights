arduino-cli compile --fqbn arduino:avr:nano sketches/blink -v
arduino-cli upload -p /dev/cu.usbserial-10 --fqbn arduino:avr:nano sketches/blink -v