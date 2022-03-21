# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no      # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes      # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
SLEEP_LED_ENABLE = no      # Breathing sleep LED during USB suspend
NKRO_ENABLE = no           # USB Nkey Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality on B7 by default
MIDI_ENABLE = no           # MIDI support
UNICODE_ENABLE = no        # Unicode
BLUETOOTH_ENABLE = no      # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no          # Audio output
SPLIT_KEYBOARD = yes       # Split common
LTO_ENABLE = yes           # Use Link Time Optimization
OLED_DRIVER_ENABLE = no    # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
SPACE_CADET_ENABLE = no    # Enables the use of Space Cadet
GRAVE_ESC_ENABLE = no      # Enables the use of grave key as escape key
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
CUSTOM_MATRIX = lite       # Split custom matrix

# Project specific files
SRC +=  common/bitc_led.c \
        common/remote_kb.c \
        matrix.c \
        uart.c
