Autocorrection will falsely trigger when a typo is a substring of a correctly spelled word.
To check for this, install the english_words package and rerun this script:
  python3 -m pip install english_words
// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
  88888888888 888      d8b                .d888 d8b 888               d8b
      888     888      Y8P               d88P"  Y8P 888               Y8P
      888     888                        888        888
      888     88888b.  888 .d8888b       888888 888 888  .d88b.       888 .d8888b
      888     888 "88b 888 88K           888    888 888 d8P  Y8b      888 88K
      888     888  888 888 "Y8888b.      888    888 888 88888888      888 "Y8888b.
      888     888  888 888      X88      888    888 888 Y8b.          888      X88
      888     888  888 888  88888P'      888    888 888  "Y8888       888  88888P'
                                                        888                 888
                                                        888                 888
                                                        888                 888
     .d88b.   .d88b.  88888b.   .d88b.  888d888 8888b.  888888 .d88b.   .d88888
    d88P"88b d8P  Y8b 888 "88b d8P  Y8b 888P"      "88b 888   d8P  Y8b d88" 888
    888  888 88888888 888  888 88888888 888    .d888888 888   88888888 888  888
    Y88b 888 Y8b.     888  888 Y8b.     888    888  888 Y88b. Y8b.     Y88b 888
     "Y88888  "Y8888  888  888  "Y8888  888    "Y888888  "Y888 "Y8888   "Y88888
         888
    Y8b d88P
     "Y88P"
*******************************************************************************/

#pragma once

// Autocorrection dictionary (9 entries):
//   :docke:   -> docker
//   :dokcer:  -> docker
//   :doker:   -> docker
//   :iamges:  -> images
//   :rimages: -> images
//   :riamges: -> images
//   :dmkae:   -> dmake
//   lenght    -> length
//   widht     -> width

#define AUTOCORRECT_MIN_LENGTH 5 // "widht"
#define AUTOCORRECT_MAX_LENGTH 9 // ":rimages:"
#define DICTIONARY_SIZE 146

static const uint8_t autocorrect_data[DICTIONARY_SIZE] PROGMEM = {
    0x6C, 0x07, 0x00, 0x17, 0x7A, 0x00, 0x00, 0x48, 0x11, 0x00, 0x15, 0x2A, 0x00, 0x16, 0x48, 0x00,
    0x00, 0x44, 0x18, 0x00, 0x0E, 0x22, 0x00, 0x00, 0x0E, 0x10, 0x07, 0x2C, 0x00, 0x83, 0x61, 0x6B,
    0x65, 0x00, 0x06, 0x12, 0x07, 0x2C, 0x00, 0x80, 0x72, 0x00, 0x08, 0x00, 0x46, 0x33, 0x00, 0x0E,
    0x3E, 0x00, 0x00, 0x0E, 0x12, 0x07, 0x2C, 0x00, 0x84, 0x63, 0x6B, 0x65, 0x72, 0x00, 0x12, 0x07,
    0x2C, 0x00, 0x83, 0x63, 0x6B, 0x65, 0x72, 0x00, 0x08, 0x0A, 0x00, 0x44, 0x52, 0x00, 0x10, 0x5F,
    0x00, 0x00, 0x10, 0x0C, 0x15, 0x2C, 0x00, 0x87, 0x69, 0x6D, 0x61, 0x67, 0x65, 0x73, 0x00, 0x04,
    0x0C, 0x00, 0x6C, 0x69, 0x00, 0x15, 0x70, 0x00, 0x00, 0x85, 0x6D, 0x61, 0x67, 0x65, 0x73, 0x00,
    0x2C, 0x00, 0x87, 0x69, 0x6D, 0x61, 0x67, 0x65, 0x73, 0x00, 0x0B, 0x00, 0x47, 0x83, 0x00, 0x0A,
    0x8A, 0x00, 0x00, 0x0C, 0x1A, 0x00, 0x81, 0x74, 0x68, 0x00, 0x11, 0x08, 0x0F, 0x00, 0x81, 0x74,
    0x68, 0x00
};

