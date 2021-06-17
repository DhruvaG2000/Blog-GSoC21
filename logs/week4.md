---
sort: 5
---

# Week4

## Logs from June 12 to June 19

- Followed instructions from Deepak Khatri's Blog on Cape compat. layer and installed it one the BBAI.
- Tried using alsa to test audio both on BBAI and Black but no audio devices were detected, will need the BB-AUDI-02 overlay probably. 
- On the BB Black, loaded the BB-AUDI-02 overlay from uEnv.txt and then rebooted. After this aplay worked and I got the audio output. 
- Tried the same on the BB AI, however the AI would simply not boot up. After this, tested if uEnv was properly loading the overlays and also if CCL was working or not using the given PWM overlay, and that worked.
