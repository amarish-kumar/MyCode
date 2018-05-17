#!/bin/bash

systemctl --user enable pulseaudio && systemctl --user start pulseaudio
echo "Sound enabled"
