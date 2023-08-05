# OLD #

# # Bootloader selection
# BOOTLOADER = rp2040

# # Build Options
# #   change yes to no to disable
# #
# BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
# MOUSEKEY_ENABLE = no       # Mouse keys
# EXTRAKEY_ENABLE = yes       # Audio control and System control
# CONSOLE_ENABLE = no         # Console for debug
# COMMAND_ENABLE = no         # Commands for debug and configuration
# NKRO_ENABLE = no            # Enable N-Key Rollover
# BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
# RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
# UNICODE_ENABLE = yes        # Unicode
# AUDIO_ENABLE = yes           # Audio output
# SPLIT_KEYBOARD = yes        # Use shared split_common code
# OLED_ENABLE = yes
# OLED_DRIVER = SSD1306
# WPM_ENABLE = yes
# LTO_ENABLE = yes
# SERIAL_DRIVER = vendor
# AUDIO_DRIVER = pwm_hardware





# NEW #

# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

ALLOW_WARNINGS = yes

# LTO must be disabled for RP2040 builds
LTO_ENABLE = no

# PIO serial/WS2812 drivers must be used on RP2040
SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
UNICODE_ENABLE = yes        # Unicode
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = yes        # Use shared split_common code
SWAP_HANDS_ENABLE = yes
# OLED_ENABLE = yes
# OLED_DRIVER = SSD1306
# WPM_ENABLE = yes



# OLED_DRIVER_ENABLE  = yes
TAP_DANCE_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
